#include <ali.h>
#include <init_visitor.h>


void ali::Init_Visitor::add_init_stage( unsigned _n,  std::function< void () > _f )
{
    map_[_n].push_back( _f );
}

void ali::Init_Visitor::init_impls( )
{
    for ( auto i : map_ )
    {
	ALI_LOG << "**************** Init Stage: " << i.first << " begin **************** " << ALI_E;
	for ( auto ii : i.second )
	    ii();
	ALI_LOG << "**************** Init Stage: " << i.first << " end   **************** " << ALI_E;
    }
}


