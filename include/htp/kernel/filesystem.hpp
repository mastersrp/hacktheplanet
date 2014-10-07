/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#ifndef HTP_KERNEL_FILESYSTEM_HPP
#define HTP_KERNEL_FILESYSTEM_HPP
#include <htp/config.hpp>
#include <fastcxx/types/string.hpp>
#include <set>
#include <irrlicht/irrlicht.h>

BEGIN_HTP_NAMESPACE
	namespace kernel {
		class filesystem {
			public:
				filesystem( char *argv[] );
				filesystem( char *argv );

				virtual ~filesystem();
				virtual void insertDevice( irr::IrrlichtDevice *device );
				virtual int setWritePath( const char *path );
				virtual fastcxx::String getFile( const char *file );

				bool exists( const char *path );
				bool is_path( const char *path );
				bool is_file( const char *file );

				virtual irr::io::IFileSystem *getFileSystemCore();
			private:
				std::set< char* >			fileList;
				fastcxx::String				writePath;
				irr::IrrlichtDevice			*device;
				irr::io::IFileSystem		*FileSystem;
		};
	}
END_HTP_NAMESPACE

#endif /* HTP_KERNEL_FILESYSTEM_HPP */
