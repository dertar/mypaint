#pragma once
#include "stdafx.h"

/*
	The interface for save and load the data
*/

class IData
{
public:
	virtual std::string getData() const = 0;
	virtual void setData(const std::string &data) = 0;
};