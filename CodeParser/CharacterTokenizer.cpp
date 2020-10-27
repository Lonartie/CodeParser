//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#include "CharacterTokenizer.h"

std::deque<QChar> CharacterTokenizer::tokenize(const QString& source)
{
	std::deque<QChar> result;

	for (auto& ch : source)
		result.push_back(ch);

	return result;
}
