#include <runner.h>
#include <content.h>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

ali::Runner& ali::Runner::Instance()
{
    static Runner __theRunnerInstance;
    return __theRunnerInstance;
}

ali::Runner::Runner():
    timer_(io_, boost::posix_time::seconds(1) )
{
}

void ali::Runner::run()
{
    ALI_LOG<< "---------ali main loop run---------" << ALI_E;
    timer_.async_wait( boost::bind( &Runner::one_sec_tic, this) );
    io_.run();
}

void ali::Runner::one_sec_tic()
{
    tic();
    timer_.expires_at( timer_.expires_at() + boost::posix_time::seconds(1));
    timer_.async_wait( boost::bind( &Runner::one_sec_tic, this) );
}

void ali::Runner::tic()
{
    for ( auto i : ali::Content::Instance().get_items() )
	i.second -> tic();
}

boost::asio::io_service& ali::Runner::io()
{
    return io_;
}

boost::asio::io_service const& ali::Runner::io() const
{
    return io_;
}

