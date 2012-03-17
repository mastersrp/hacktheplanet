/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <htp/kernel/filesystem.hpp>
#include <fastcxx/filesystem.hpp>
#include <fastcxx/types/string.hpp>
#include <iostream>
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
			if( fastcxx::filesystem::exists( path.c_str() ) ) {
				if( fastcxx::filesystem::is_file( path.c_str() ) ) {
					return 300;
				} else if ( fastcxx::filesystem::is_directory( path.c_str() ) ) {
					fastcxx::filesystem::Directory *directory = new fastcxx::filesystem::Directory()->dopen( path.c_str() );
					std::vector< std::string > *dir = directory->Read();
					std::vector< std::string >::iterator dirit;
					for( dirit=dir->begin(); dirit < dir->end(); dirit++ )
					{
						irr::core::stringw str = irr::core::stringw( *dirit->c_str() );
						const char *file = *dirit->c_str();
						if( fs->is_file( file ) ) {
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
			return fastcxx::filesystem::exists( path.c_str() );
		}

		bool filesystem::is_path( std::string path )
		{
			return fastcxx::filesystem::is_path( path.c_str() );
		}

		bool filesystem::is_file( std::string file )
		{
			return fastcxx::filesystem::is_file( path.c_str() );
		}

		irr::io::IFileSystem	*filesystem::getFileSystemCore()
		{
			return this->FileSystem;
		}
	}
END_HTP_NAMESPACE
