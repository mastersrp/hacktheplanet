/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <htp/kernel/filesystem.hpp>
#include <boost/filesystem.hpp>
#include <string>
#include <set>

BEGIN_HTP_NAMESPACE
	namespace kernel {
		filesystem::filesystem()
		{
		}

		filesystem::~filesystem()
		{
		}

		int filesystem::setWritePath( std::string path )
		{
			if( is_path( path ) == true )
			{
				this->writePath = path;
				return 0;
			}
			return 1;
		}

		std::string filesystem::getFile( std::string file )
		{
			if( fileList.find( file ) != fileList.end() )
			{
				return file;
			} else {
				return (std::string)"";
			}
		}

		bool filesystem::is_path( std::string path )
		{
			return boost::filesystem::is_directory( path );
		}

		bool filesystem::is_file( std::string file )
		{
			return boost::filesystem::is_regular_file( file );
		}
	}
END_HTP_NAMESPACE
