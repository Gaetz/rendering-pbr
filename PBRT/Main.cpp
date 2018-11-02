#pragma once
#include <vector>

#include "pbrt.h"

using namespace pbrt;


void pbrtInit(Options& options) {

}

void pbrtCleanup() {

}

bool pbrtParseFile(std::string f) {
	return true;
}

int main(int argc, char *argv[]) {
	Options options;
	std::vector<std::string> filenames;
	// > Process command line arguments
	pbrtInit(options);
	// > Process scene description
	if (filenames.size() == 0) {
		pbrtParseFile("-");
	}
	else
	{
		for (const std::string &f : filenames) {
			if (!pbrtParseFile(f)) {

			}
		}
	}

	pbrtCleanup();
	return 0;

}
