#include <loader_lib.h>
#include <dlfcn.h>
#include <itemfactory.h>
#include <cstddef>

ali::LibLoader& ali::LibLoader::Instance()
{
    static LibLoader __theLibLoaderInstance;
    return __theLibLoaderInstance;
}

ali::LibLoader::So::So(ItemFactory* _if, void* _lib):
	factory_ (_if),
	library_ (_lib)
{
}	

ali::LibLoader::~LibLoader()
{
    for(Libs::iterator b = _in_libs.begin(); b != _in_libs.end(); ++b)
    {
	delete b->second.factory_;
	dlclose( b->second.library_ );
    }
}

ali::ItemFactory* ali::LibLoader::load_lib( std::string const& fabric_name )
{
    Libs::iterator fnd = _in_libs.find( fabric_name );
    if( fnd != _in_libs.end() )
    {
    	return fnd->second.factory_;
    }
    else 
    {
	std::string lib_name = fabric_name + ".so";
	void* lib = dlopen ( lib_name.c_str(), RTLD_LAZY );
	if( lib )
	{
	    CreateFunction cFunc = (CreateFunction) dlsym( lib, fabric_name.c_str() );
	    std::cout<<"loading lib: "<<lib_name<<" invoke method: "<<fabric_name<<std::endl;
	    if( cFunc )
	    {
	    	ItemFactory* retval =  cFunc();
	    	_in_libs[ fabric_name ] = So( retval, lib );
		return retval;
	    }
	    std::cout<<"LibLoader::loadLib cant find "<<dlerror()<<std::endl;
	    return nullptr;
	}
	else
	{
	    if ( "libutil_EmptyLogic" !=  fabric_name )
	    {
	        char* error = dlerror();
		std::cout<<"LibLoader::load_lib cant load library: "<<error<<std::endl<<"Load libutil_EmptyLogic"<<std::endl;
	        return load_lib ("libutil_EmptyLogic");
	    }
	    else
	    {
		std::cerr<<"LibLoader::load_lib cant find libutil_EmptyLogic"<<std::endl;
		exit ( (int)ali::rcode::ERROR);
	    }
	}
	
    }
    return nullptr;    
}

