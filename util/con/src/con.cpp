#include <con.h>

util::con::con( xmlpp::Element const* _p ): 
    util::conBase ( _p )
{
}

void util::con::first_up_( )
{ //first stage of activation of element	
    util::conBase::applyAttrs( );
}

void util::con::second_up_( )
{ //second stage of activation of element	
}

void util::con::third_up_( )
{ //third stage of activation of element	
}


