//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#include "CppLexer.h"
#include "CppStringLexer.h"
#include <stack>


CppLexer::CppLexer(CharacterTokenizer::UPtr tokenizer)
	: Lexer<CppToken, CharacterTokenizer>(std::move(tokenizer))
{
	registerTokenLexer<CppStringLexer>();
}
