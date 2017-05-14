#include <runner.h>
#include <content.h>
#include <init_visitor.h>

ali::Runner& ali::Runner::Instance()
{
    static Runner __theRunnerInstance;
    return __theRunnerInstance;
}

void ali::Runner::run()
{
    ALI_LOG<< "---------ali main loop run---------" << ALI_E;
    while ( 1 )
    {
	tic();
	sleep(1);
    }

}

void ali::Runner::tic()
{
    for ( auto i : ali::Content::Instance().get_items() )
	i.second -> tic();
}

