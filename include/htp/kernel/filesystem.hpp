/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#ifndef HTP_KERNEL_FILESYSTEM_HPP
#define HTP_KERNEL_FILESYSTEM_HPP
#include <htp/config.hpp>
#include <string>
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
				virtual int setWritePath( std::string path );
				virtual std::string getFile( std::string file );

				bool exists( std::string path );
				bool is_path( std::string path );
				bool is_file( std::string file );

				virtual irr::io::IFileSystem *getFileSystemCore();
			private:
				std::set< std::string >		fileList;
				std::string					writePath;
				irr::IrrlichtDevice			*device;
				irr::io::IFileSystem		*FileSystem;
		};
	}
END_HTP_NAMESPACE

#endif /* HTP_KERNEL_FILESYSTEM_HPP */
