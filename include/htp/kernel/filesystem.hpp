/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <string>
#include <set>

BEGIN_HTP_NAMESPACE
	namespace kernel {
		class filesystem {
			public:
				filesystem();
				virtual ~filesystem();
				virtual int setWritePath( std::string path );
				virtual std::string getFile( std::string file );

				virtual bool is_path( std::string path );
				virtual bool is_file( std::string file );
			private:
				std::set< std::string >		fileList;
				std::string					writePath;
		};
	}
END_HTP_NAMESPACE
