#pragma once
#include "WavHead.h"
#include <string>
#include "FileNotAssignedException.h"
#include <fstream>

struct WavFile
{
	WavFile();
	~WavFile();

	WavFile& assign(std::string fileName);

	int getNumChannels();

private:
	WavHead header;
	bool headerLoaded;
	std::string fileName;
	std::filebuf fb;
	void loadHeaderIfNeed();

	void loadHeader();
	void checkFileAssigned();

};