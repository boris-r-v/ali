#include <runner.h>

ali::Runner::Runner( ali::Content& _c ):
    content_ ( _c )
{
}

void ali::Runner::run()
{
    while ( 1 )
    {
	content_.tic();
	sleep(1);
    }

}