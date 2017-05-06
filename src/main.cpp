#include <memory>
#include <loader.h>

#include <libxml++/libxml++.h>

int main (int argc, char** argv )
{
    xmlpp::DomParser parser;

    std::unique_ptr <ali::Loader> loader( new ali::Loader( parser ) );
    if ( 1 == argc )
	loader->load ("ali.xml");
    else
	loader->load ( argv[1] );
    loader->run();
}
