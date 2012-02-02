/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <htp/kernel/filesystem.hpp>
#include <physfs.h>
#include <boost/filesystem.hpp>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>

BEGIN_HTP_NAMESPACE
	namespace kernel {
		filesystem::filesystem( char *argv[] )
		{
			PHYSFS_init( argv[0] );
		}

		filesystem::filesystem( char *argv )
		{
			PHYSFS_init( argv );
		}

		filesystem::~filesystem()
		{
		}

		int filesystem::setWritePath( std::string path )
		{
			boost::filesystem::path p (path.c_str());
			try
			{
				if( exists( path ) )
				{
					if( is_file( path ) )
					{
						return 300;
					} else if ( is_path( path ) ) {
						typedef std::vector<boost::filesystem::path> vec;
						vec v;

						copy( boost::filesystem::directory_iterator(p), boost::filesystem::directory_iterator(), std::back_inserter(v) );

						std::sort(v.begin(), v.end() );
						for( vec::const_iterator it (v.begin()); it != v.end(); ++it )
						{
							std::cout << " " << *it << std::endl;
						}
						return 200;
					}
				} else {
					return 404;
				}
			}
			catch ( const boost::filesystem::filesystem_error &ex )
			{
				std::cout << ex.what() << std::endl;
				return 1;
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

		template <class FS>
		bool filesystem::exists( FS path )
		{
			return boost::filesystem::exists( path );
		}

		template <class FS>
		bool filesystem::is_path( FS path )
		{
			return boost::filesystem::is_directory( path );
		}

		template <class FS>
		bool filesystem::is_file( FS file )
		{
			return boost::filesystem::is_regular_file( file );
		}
	}
END_HTP_NAMESPACE
