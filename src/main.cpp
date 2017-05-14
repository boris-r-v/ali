#include <memory>
#include <core.h>

int main (int argc, char** argv )
{
    std::unique_ptr <ali::Core> core( new ali::Core(  ) );
    
    const char* path = "ali.xml";
    if ( 2 == argc )
	path = argv[1];

    core->load ( path );
    core->init();
    core->run();
}
