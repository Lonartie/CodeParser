//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include "Token.h"

class CppToken : public Token
{
public:
	using UPtr = std::unique_ptr<CppToken>;
	
};
