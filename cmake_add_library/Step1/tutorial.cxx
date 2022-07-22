#include <string>
#include <iostream>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <cmath>
#endif

int main(int argc, char* argv[]) {
	if(argc < 2) {
		std::cout << "Major Version Number: " << Tutorial_VERSION_MAJOR << std::endl;
		std::cout << "Minor Version Number: " << Tutorial_VERSION_MINOR << std::endl;
		std::cout << "Usage: " << argv[0] << " Number" << std::endl;
		return 0;
	}
	const double to_be_square_off = std::stod(argv[1]);
#ifdef USE_MYMATH
	const double out_value = mysqrt(to_be_square_off);
#else
	std::cout << "you're using sqrt function from the cmath lib" << std::endl;
	const double out_value = sqrt(to_be_square_off);
#endif
	std::cout << "after square off: " << out_value << std::endl;
	return 0;
}
