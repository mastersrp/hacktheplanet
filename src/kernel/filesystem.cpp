/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <htp/kernel/filesystem.hpp>
#include <fastcxx/filesystem.hpp>
#include <fastcxx/types/string.hpp>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
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

		int filesystem::setWritePath( const char *path )
		{
			std::cout << path << std::endl;
			fastcxx::Filesystem *fs = new fastcxx::Filesystem();
			if( fastcxx::filesystem::exists( path ) ) {
				if( fastcxx::filesystem::is_file( path ) ) {
					return 300;
				} else if ( fastcxx::filesystem::is_directory( path ) ) {
					fastcxx::filesystem::Directory *directory = fs->dopen( path );
					std::vector< char* > *dir = directory->Read();
					std::vector< char* >::iterator dirit;
					for( dirit=dir->begin(); dirit < dir->end(); dirit++ )
					{
						irr::core::stringw str = irr::core::stringw( (const char*)*dirit );
						const char *file = *dirit;
						if( fastcxx::filesystem::is_file( file ) ) {
							this->FileSystem->addFileArchive( str );
						}
					}
				}
			}
		}

		fastcxx::String filesystem::getFile( const char *filename )
		{
			char *file;
			strcpy(file, filename);
			if( fileList.find( file ) != fileList.end() )
			{
				return (fastcxx::String)file;
			} else {
				return (fastcxx::String)"";
			}
		}

		bool filesystem::exists( const char *path )
		{
			return fastcxx::filesystem::exists( path );
		}

		bool filesystem::is_path( const char *path )
		{
			return fastcxx::filesystem::is_directory( path );
		}

		bool filesystem::is_file( const char *file )
		{
			return fastcxx::filesystem::is_file( file );
		}

		irr::io::IFileSystem	*filesystem::getFileSystemCore()
		{
			return this->FileSystem;
		}
	}
END_HTP_NAMESPACE
