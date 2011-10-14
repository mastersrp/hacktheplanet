/*
 * This file is part of the HackThePlanet project.
 * License is in the COPYING file.
 */
#include <config.hpp>
#include <iostream>
#include <string>

namespace HTP {
	namespace input {
		std::string getcmdline();
		int interpcmdline(std::string cmdline);
	}
}
