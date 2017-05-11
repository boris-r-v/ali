#include <runner.h>
#include <content.h>

ali::Runner& ali::Runner::Instance()
{
    static Runner __theRunnerInstance;
    return __theRunnerInstance;
}

void ali::Runner::run()
{
    while ( 1 )
    {
	ali::Content::Instance().tic();
	sleep(1);
    }

}