#include "application.h"
#include <iostream>

application::application() = default;
application::~application() = default;

int application::run() {
	std::cout << "Starting application::run(). . ." << std::endl;
	return 0;
}
