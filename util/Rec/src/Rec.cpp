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
}


