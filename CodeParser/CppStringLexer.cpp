//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#include "CppStringLexer.h"

Token test()
{
	if (!accept('"'))
		return Empty;

	QString content;
	while (!accept('"') && last() != "\\")
	{
		content << last();
		next();
	}

	return CppStringToken(content);
}