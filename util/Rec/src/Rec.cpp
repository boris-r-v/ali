#include <Rec.h>

util::Rec::Rec( xmlpp::Element const* _p ): 
    util::RecBase ( _p )
{
    util::RecBase::apply_attrs();
}

void util::Rec::first_up_( )
{ //first stage of activation of element	
}

void util::Rec::second_up_( )
{ //second stage of activation of element	
}

void util::Rec::third_up_( )
{ //third stage of activation of element	
    ali::subs_tag( "time", std::bind( &util::Rec::rec_time, this, std::placeholders::_1 ) );
    ali::subs_tag( "ctime", std::bind( &util::Rec::rec_ctime, this, std::placeholders::_1 ) );
}


void util::Rec::rec_time( ali::Tag const& _t )
{
    std::cout << "rec_time: " << _t << std::endl;
}

void util::Rec::rec_ctime( ali::Tag const& _t )
{
    std::cout << "rec_ctime: " << _t << std::endl;
}
