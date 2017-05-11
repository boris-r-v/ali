#include <memory>
#include <core.h>

int main (int argc, char** argv )
{
    xmlpp::DomParser parser; //FIX Почему-то если поле класса Core - то парсинг сегфорлится

    std::unique_ptr <ali::Core> core( new ali::Core( parser ) );
    if ( 1 == argc )
	core->load ("ali.xml");
    else
	core->load ( argv[1] );

    core->run();
}
