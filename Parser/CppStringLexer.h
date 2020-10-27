//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include "TokenLexer.h"
#include "CppStringToken.h"

class CppStringLexer : public TokenLexer<CppStringToken, QChar>
{
public:
	using UPtr = std::unique_ptr<CppStringLexer>;
	
public:
	
	
};
