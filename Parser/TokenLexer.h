//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include <functional>
#include <deque>

template <typename T, typename U>
class TokenLexer
{
public:
	using AcceptFunc = std::function<bool(const std::deque<U>&)>;
	using AcceptAnyFunc = std::function<const U&()>;
	using NextFunc = std::function<void()>;
	using LastFunc = std::function<const U&()>;
	using CurrentFunc = std::function<const std::deque<U>&()>;
	
public:
	virtual ~TokenLexer() = default;
	virtual void run() = 0;

protected:
	bool accept(const std::deque<U>& tokens);
	const U& acceptAny();
	void next();
	const U& last();
	const std::deque<U>& current();
	
private:
	template<typename _T, typename _U>
	friend class Lexer;
	
	AcceptFunc m_acceptFunc;
	AcceptAnyFunc m_acceptAnyFunc;
	NextFunc m_nextFunc;
	LastFunc m_lastFunc;
	CurrentFunc m_currentFunc;

};

template <typename T, typename U>
bool TokenLexer<T, U>::accept(const std::deque<U>& tokens)
{
	return m_acceptFunc(tokens);
}

template <typename T, typename U>
const U& TokenLexer<T, U>::acceptAny()
{
	return m_acceptAnyFunc();
}

template <typename T, typename U>
void TokenLexer<T, U>::next()
{
	return m_nextFunc();
}

template <typename T, typename U>
const U& TokenLexer<T, U>::last()
{
	return m_lastFunc();
}

template <typename T, typename U>
const std::deque<U>& TokenLexer<T, U>::current()
{
	return m_currentFunc();
}
