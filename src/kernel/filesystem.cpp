/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <htp/kernel/filesystem.hpp>
#include <iostream>
#include <string>
#include <set>
#include <vector>
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
			kernel::Filesystem *fs = new kernel::Filesystem();
			if( kernel::filesystem::exists( path.c_str() ) ) {
				if( kernel::filesystem::is_file( path.c_str() ) ) {
					return 300;
				} else if ( kernel::filesystem::is_directory( path.c_str() ) ) {
					kernel::filesystem::Directory *directory = fs->dopen( path.c_str() );
					std::vector< char* > *dir = directory->Read();
					std::vector< char* >::iterator dirit;
					for( dirit=dir->begin(); dirit < dir->end(); dirit++ )
					{
						irr::core::stringw str = irr::core::stringw( (const char*)*dirit );
						const char *file = *dirit;
						if( kernel::filesystem::is_file( file ) ) {
							this->FileSystem->addFileArchive( str );
						}
					}
				}
			}
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
			return true;
		}

		bool filesystem::is_path( std::string path )
		{
			return true;
		}

		bool filesystem::is_file( std::string file )
		{
			return true;
		}

		irr::io::IFileSystem	*filesystem::getFileSystemCore()
		{
			return this->FileSystem;
		}
	}
END_HTP_NAMESPACE
