#include <memory>
#include <core.h>

int main (int argc, char** argv )
{
    xmlpp::DomParser parser; //FIX Почему-то если поле класса Core - то парсинг сегфорлится

    std::unique_ptr <ali::Core> core( new ali::Core( parser ) );

    const char* path = "ali.xml";
    if ( 2 == argc )
	path = argv[1];

    core->load ( path );
    core->init();
    core->run();
}
