//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include "CharacterTokenizer.h"
#include "CppToken.h"
#include "Lexer.h"

class CppLexer : public Lexer<CppToken, CharacterTokenizer>
{
public:
	CppLexer(CharacterTokenizer::UPtr tokenizer);

};
