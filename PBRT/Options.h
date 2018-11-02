#pragma once

#include <string>

namespace pbrt {


	struct Options {
		int nThreads = 0;
		bool quickRender = false;
		bool quiet = false;
		bool verbose = false;
		std::string imageFile;
	};

}