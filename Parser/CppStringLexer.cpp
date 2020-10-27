//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#include "CppStringLexer.h"

void CppStringLexer::run()
{
	if (!accept({'"'}))
		return;

	QString content;
	while (!accept({'"'}) && last() != "\\")
	{
		content.append(acceptAny());
	}

	return CppStringToken(content);
}