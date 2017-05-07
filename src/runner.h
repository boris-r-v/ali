#ifndef ali_runner
#define ali_runner
#include <boost/noncopyable.hpp>
#include <content.h>

namespace ali
{
    class Runner: public boost::noncopyable
    {
	    ali::Content& content_;
	public:
	    Runner( ali::Content& );

	    void run();

    };
}
#endif // ali_runner
