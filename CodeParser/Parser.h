//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include "Lexer.h"
#include <QString>
#include <memory>
#include <deque>

template <typename T, typename U>
class Parser
{
public:
	using UPtr = std::unique_ptr<Parser<T, U>>;
	Parser(std::unique_ptr<U> lexer) : m_lexer(lexer) {}
	virtual ~Parser() = default;
	virtual std::deque<T> parse(const QString& source) = 0;

	const U& lexer() const { return *m_lexer; }
	U& lexer() { return *m_lexer; }
	
private:
	std::unique_ptr<U> m_lexer;
};
