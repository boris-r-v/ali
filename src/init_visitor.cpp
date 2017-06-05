#include <ali.h>
#include <init_visitor.h>
#include <content.h>
#include <runners.h>


void ali::Init_Visitor::add_periodic( boost::posix_time::time_duration _d, std::function< void () > _m )
{
    ali::Runners::Instance().add_periodic( _m, _d );
}

void ali::Init_Visitor::add_init_stage( ali::Init _n,  std::function< void () > _f )
{
    map_[_n].push_back( _f );
}

void ali::Init_Visitor::collect_impls( )
{
    for ( auto i : ali::Content::Instance().get_items() )
	i.second -> accept( *this );
}

void ali::Init_Visitor::init_impls( )
{
    for ( auto i : map_ )
    {
	ALI_LOG << "**************** Init Stage: " << static_cast<unsigned>(i.first) << " begin **************** " << ALI_E;
	for ( auto ii : i.second )
	    ii();
	ALI_LOG << "**************** Init Stage: " << static_cast<unsigned>(i.first) << " end   **************** " << ALI_E;
    }
}


