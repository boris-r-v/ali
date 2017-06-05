#include <ali.h>
#include <runners.h>

ali::Runners& ali::Runners::Instance()
{
    static Runners __theRunnersInstance;
    return __theRunnersInstance;
}

void ali::Runners::one_tic()
{
}

boost::asio::io_service& ali::Runners::io()
{
    return io_;
}

void ali::Runners::run()
{
    if ( runners_.empty() )
    {
	add_periodic( std::bind( &ali::Runners::one_tic, this ) , boost::posix_time::seconds(1) );
	ALI_LOG<< "-*****add self--" << ALI_E;
    }
    ALI_LOG<< "---------ali main loop run---------" << ALI_E;
    io_.run();
}

void ali::Runners::add_periodic( std::function< void () > _m, boost::posix_time::time_duration _d )
{

std::cout << "***************ali::Runners::add_periodic" << std::endl;
    auto fnd = runners_.find( _d );
    if ( fnd != runners_.end() )
    {
	fnd->second->add_method (_m );
	return;
    }

    auto r = ali::create_runner( _d );
    r->add_method (_m );
    runners_.insert(std::make_pair( _d, r) );
}
