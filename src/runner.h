#ifndef ali_runner
#define ali_runner
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>

namespace ali
{
    class Runner: public boost::noncopyable
    {
	    Runner( );
	    void tic();

	    boost::asio::io_service io_;
	    boost::asio::deadline_timer timer_;
	    void one_sec_tic();
	public:
	    static Runner& Instance();
	    ~Runner() = default;

	    void run();

	    boost::asio::io_service& io();
	    boost::asio::io_service const& io() const;
	    
    };
}
#endif // ali_runner
