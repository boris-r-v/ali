#ifndef ali_runners
#define ali_runners
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <runner.h>

namespace ali
{
    typedef std::map<boost::posix_time::time_duration, std::shared_ptr<ali::Runner> > runner_map_t;
    class Runners: public boost::noncopyable
    {
	    boost::asio::io_service io_;
	    runner_map_t runners_;

    	    Runners()=default;
	    void one_tic();
	public:
	    static Runners& Instance();
	    ~Runners() = default;

	    void run();
	    boost::asio::io_service& io();
	    void add_periodic( std::function< void () >, boost::posix_time::time_duration );
    };
}
#endif // ali_runners
