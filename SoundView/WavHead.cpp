#include "stdafx.h"
#include "WavHead.h"

std::istream & operator>>(std::istream & is, WavHead& val)
{
	is.read((char*)&val, sizeof(WavHead));
	return is;
}
