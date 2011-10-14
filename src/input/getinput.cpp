/* 
 * This file is part of the HackThePlanet project.
 * License is in the COPYING file.
 */
#include <config.hpp>
#include <htp/input.hpp>

std::string HTP::input::getcmdline()
{
	std::string cmdline;
	getline( std::cin, cmdline, '\n' );
	return cmdline;
}

int HTP::input::interpcmdline(std::string cmdline)
{
	return 0;
}
