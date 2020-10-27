//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include <QString>
#include <memory>
#include <deque>

template <typename T, typename U>
class Lexer
{
public:
	using UPtr = std::unique_ptr<Lexer<T, U>>;
	Lexer(std::unique_ptr<U> tokenizer) : m_tokenizer(std::move(tokenizer)) {}
	virtual ~Lexer() = default;
	virtual std::deque<T> group() = 0;

	const U& tokenizer() const { return *m_tokenizer; }
	U& tokenizer() { return *m_tokenizer; }
	
private:
	std::unique_ptr<U> m_tokenizer;
};
