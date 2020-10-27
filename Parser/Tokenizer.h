//--------------------------------------------------------------------------------------------------
//
// Copyright (C) 2020 LaVision GmbH.  All Rights Reserved.
//
//--------------------------------------------------------------------------------------------------
#pragma once
#include <QString>
#include <memory>
#include <deque>

template <typename T>
class Tokenizer
{
public:
	using UPtr = std::unique_ptr<Tokenizer<T>>;
	using type = T;
	virtual ~Tokenizer() = default;
	virtual std::deque<T> tokenize(const QString& source) = 0;
};
