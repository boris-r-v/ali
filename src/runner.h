#ifndef ali_runner
#define ali_runner
#include <list>
#include <memory>
#include <functional>
#include <boost/asio.hpp>

namespace ali
{
    typedef std::list< std::function< void () > > InvArr;
    class Runner
    {
	    boost::asio::deadline_timer timer_;
	    boost::posix_time::time_duration duration_;
	    InvArr methods_;

	    void one_tic();
	public:
	    Runner( boost::posix_time::time_duration _d );
	    ~Runner() = default;

	    void add_method( std::function< void () > );
	    void run( );
    };

    std::shared_ptr<ali::Runner> create_runner( boost::posix_time::time_duration );    
}
#endif // ali_runner
