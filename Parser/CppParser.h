//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include "CppToken.h"
#include "Parser.h"

class CppParser : public Parser<CppToken, QChar>
{
public:
	CppParser();
	~CppParser();
};
