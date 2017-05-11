#ifndef ali_runner
#define ali_runner
#include <boost/noncopyable.hpp>

namespace ali
{
    class Runner: public boost::noncopyable
    {
	    Runner( ) = default;

	public:
	    static Runner& Instance();
	    ~Runner() = default;
	    void run();
    };
}
#endif // ali_runner
