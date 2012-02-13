/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <htp/kernel/filesystem.hpp>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <string>
#include <set>
#include <irrlicht/irrlicht.h>

BEGIN_HTP_NAMESPACE
	namespace kernel {
		filesystem::filesystem( char *argv[] )
		{
			
		}

		filesystem::filesystem( char *argv )
		{
			
		}

		filesystem::~filesystem()
		{
		}

		void filesystem::insertDevice( irr::IrrlichtDevice *device )
		{
			this->FileSystem = device->getFileSystem();
		}

		int filesystem::setWritePath( std::string path )
		{
			std::cout << path << std::endl;
			boost::filesystem::path p (path.c_str());
			try
			{
				if( exists( path ) )
				{
					if( is_file( path ) )
					{
						return 300;
					} else if ( is_path( path ) ) {

						boost::filesystem::directory_iterator it(path), eod;
						BOOST_FOREACH( const boost::filesystem::path &p, std::make_pair(it, eod) )
						{
							if( is_file( p.string() ) ) {
								if( boost::algorithm::ends_with( p.string(), ".zip" ) ) {
									std::cout << "[FS] Adding filesystem: " << p << std::endl;
									//this->device->getFileSystem()->addFileArchive( p.string().c_str(), false, false );
									this->FileSystem->addFileArchive( p.string().c_str(), false, false );
								}
							}
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

		bool filesystem::exists( std::string path )
		{
			return boost::filesystem::exists( path );
		}

		bool filesystem::is_path( std::string path )
		{
			return boost::filesystem::is_directory( path );
		}

		bool filesystem::is_file( std::string file )
		{
			return boost::filesystem::is_regular_file( file );
		}

		irr::io::IFileSystem	*filesystem::getFileSystemCore()
		{
			return this->FileSystem;
		}
	}
END_HTP_NAMESPACE
