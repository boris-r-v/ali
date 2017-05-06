#ifndef ali_loader_lib
#define ali_loader_lib
#include <map>
#include <itemfactory.h>

namespace ali
{
	class LibLoader
	{
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
		LibLoader( ) = default;
		~LibLoader( );
	    
		ItemFactory* load_lib( std::string const& fabric_name );
		
	};    

}
#endif //ali_loader_lib

