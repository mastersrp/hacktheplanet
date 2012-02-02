/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#ifndef HTP_KERNEL_FILESYSTEM_HPP
#define HTP_KERNEL_FILESYSTEM_HPP
#include <htp/config.hpp>
#include <string>
#include <set>

BEGIN_HTP_NAMESPACE
	namespace kernel {
		class filesystem {
			public:
				filesystem( char *argv[] );
				filesystem( char *argv );

				virtual ~filesystem();
				virtual int setWritePath( std::string path );
				virtual std::string getFile( std::string file );

				template <class FS> bool exists( FS path );
				template <class FS> bool is_path( FS path );
				template <class FS> bool is_file( FS file );
			private:
				std::set< std::string >		fileList;
				std::string					writePath;
		};
	}
END_HTP_NAMESPACE

#endif /* HTP_KERNEL_FILESYSTEM_HPP */
