#ifndef ali_loader_lib
#define ali_loader_lib
#include <map>
#include <itemfactory.h>
#include <boost/noncopyable.hpp>

namespace ali
{
	class LibLoader: public boost::noncopyable
	{
		LibLoader( ) = default;

		struct So
		{
		    ali::ItemFactory*	factory_;
		    void*		library_;
		    So( )=default;
		    ~So( )=default;
		    So( ItemFactory* _if, void* b );
		};

		typedef std::map<std::string, So > Libs;
		Libs	_in_libs;				

	    public:
		static LibLoader& Instance();
		~LibLoader( );
	    
		ItemFactory* load_lib( std::string const& fabric_name );
	};    

}
#endif //ali_loader_lib

