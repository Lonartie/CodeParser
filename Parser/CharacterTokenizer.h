//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include "Tokenizer.h"

class CharacterTokenizer : public Tokenizer<QChar>
{
public:
	using UPtr = std::unique_ptr<CharacterTokenizer>;
	
public:
	~CharacterTokenizer() override = default;
	std::deque<QChar> tokenize(const QString& source) override;
};
