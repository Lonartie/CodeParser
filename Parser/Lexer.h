//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include "TokenLexer.h"
#include <memory>
#include <deque>
#include <functional>

template <typename T, typename U>
class Lexer
{
public:

	/*type definitions*/
	
	using UPtr = std::unique_ptr<Lexer<T, U>>;
	using LexerFunc = std::function<void()>;
	using LexerObj = void*;
	using LexerDeletor = std::function<void()>;
	using TToken = typename U::type;
	
	/*ctors*/

	Lexer(std::unique_ptr<U> tokenizer);
	virtual ~Lexer();
	
	/*methods*/

	std::deque<T> run(const QString& source);	
	const U& tokenizer() const;
	U& tokenizer();

	/*registration funcions*/

	template <typename L, typename ... Args>
	void registerTokenLexer(Args&& ... args);

private:

	/*control flow*/

	bool accept(const std::deque<TToken>& v);
	const TToken& acceptAny();
	void next();
	const TToken& last();
	const std::deque<TToken>& current();

	void invalidate();
	
private:

	/*members*/

	std::unique_ptr<U> m_tokenizer;
	std::deque<LexerFunc> m_lexerFuncs;
	std::deque<LexerObj> m_lexerObjs;
	std::deque<LexerDeletor> m_lexerDeletors;

	std::deque<T> m_result;
	std::deque<TToken> m_tokens;
	std::deque<TToken> m_current;
	
	std::size_t m_cursorBegin = 0;
	std::size_t m_cursorEnd = 1;
};

template <typename T, typename U>
Lexer<T, U>::Lexer(std::unique_ptr<U> tokenizer)
	: m_tokenizer(std::move(tokenizer))
{}

template <typename T, typename U>
Lexer<T, U>::~Lexer()
{
	for (auto& deletor : m_lexerDeletors)
		deletor();
}

template <typename T, typename U>
std::deque<T> Lexer<T, U>::run(const QString& source)
{
	m_result.clear();
	m_tokens = m_tokenizer->tokenize(source);
	m_cursorBegin = 0;
	m_cursorEnd = 1;

	if (m_tokens.empty())
		return {};

	for (auto& lexer : m_lexerFuncs)
		lexer();

	return m_result;
}

template <typename T, typename U>
const U& Lexer<T, U>::tokenizer() const
{
	return *m_tokenizer;
}

template <typename T, typename U>
U& Lexer<T, U>::tokenizer()
{
	return *m_tokenizer;
}

template <typename T, typename U>
template <typename L, typename ...Args>
void Lexer<T, U>::registerTokenLexer(Args&& ... args)
{
	L* lexer = new L(std::forward<Args>(args)...);

	lexer->m_acceptFunc = [this](const U& v) { return this->accept(v); };
	lexer->m_acceptAnyFunc = [this]() { return this->acceptAny(); };
	lexer->m_nextFunc = [this]() { this->next(); };
	lexer->m_lastFunc = [this]() { return this->last(); };
	lexer->m_currentFunc = [this]() { return this->current(); };
	
	LexerFunc func = [lexer]() { lexer->run(); };
	LexerDeletor deletor = [lexer]() { delete lexer; };

	m_lexerObjs.push_back(lexer);
	m_lexerFuncs.push_back(std::move(func));
	m_lexerDeletors.push_back(std::move(deletor));
}

template <typename T, typename U>
bool Lexer<T, U>::accept(const std::deque<TToken>& v)
{
	return v == m_current;
}

template <typename T, typename U>
const typename Lexer<T, U>::TToken& Lexer<T, U>::acceptAny()
{
	const TToken& v = m_current.back();
	m_cursorBegin += m_current.size();
	m_cursorEnd = m_cursorBegin + 1;
	invalidate();
	return v;
}

template <typename T, typename U>
void Lexer<T, U>::next()
{
	m_cursorEnd++;
	invalidate();
}

template <typename T, typename U>
const typename Lexer<T, U>::TToken& Lexer<T, U>::last()
{
	// TODO implementation
}

template <typename T, typename U>
const std::deque<typename Lexer<T, U>::TToken>& Lexer<T, U>::current()
{
	return m_current;
}

template <typename T, typename U>
void Lexer<T, U>::invalidate()
{
	m_current = std::deque<TToken>(m_tokens.begin() + m_cursorBegin, m_tokens.begin() + m_cursorEnd);
}
