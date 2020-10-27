//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#include "CppLexer.h"

CppLexer::CppLexer(CharacterTokenizer::UPtr tokenizer)
	: Lexer<CppToken, CharacterTokenizer>(std::move(tokenizer))
{
	registerStateLexer<CppStringLexer>();
}

std::deque<CppToken> CppLexer::group()
{
	std::deque<CppToken> result;
	std::stack<CppStates> states;
	

	return result;
}
