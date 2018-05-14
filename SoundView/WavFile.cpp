#include "stdafx.h"
#include "WavFile.h"


WavFile::WavFile()
	:headerLoaded(false)
	
{
	

}


WavFile::~WavFile()
{
}

WavFile& WavFile::assign(std::string fileName)
{	
	this->fileName = fileName;
	return *this;
}

int WavFile::getNumChannels()
{
	loadHeaderIfNeed();
	return header.numChannels;
}

void WavFile::loadHeaderIfNeed()
{
	if (!headerLoaded)
		loadHeader();
}

void WavFile::loadHeader() {
	checkFileAssigned();
	std::ifstream(fileName, std::ios::in | std::ios::binary) >> header;
	headerLoaded = true;
}

void WavFile::checkFileAssigned() { 
	if (fileName.empty())
		throw FileNotAssignedException();
}
