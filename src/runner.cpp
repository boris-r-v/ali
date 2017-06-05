#include <runner.h>
#include <runners.h>
#include <boost/bind.hpp>

ali::Runner::Runner( boost::posix_time::time_duration _d ):
    timer_( ali::Runners::Instance().io(), _d ),
    duration_( _d )
{
}

void ali::Runner::add_method( std::function< void () > _m )
{
    methods_.push_back( _m );
}

void ali::Runner::run( )
{
    timer_.async_wait( boost::bind( &Runner::one_tic, this ) );
}

void ali::Runner::one_tic()
{
    for ( auto m : methods_ )
	m();
    timer_.expires_at( timer_.expires_at() + duration_ );
    timer_.async_wait( boost::bind( &Runner::one_tic, this ) );
}

std::shared_ptr<ali::Runner> ali::create_runner( boost::posix_time::time_duration _d )
{
    return std::shared_ptr<ali::Runner>( new ali::Runner( _d ) );
}