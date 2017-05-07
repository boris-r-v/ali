#include <Loop.h>

util::Loop::Loop( xmlpp::Element const* _p ): 
    util::LoopBase ( _p )
{
    util::LoopBase::apply_attrs();
}

void util::Loop::first_up_( )
{ //first stage of activation of element	
    ALI_LOG <<" ^^^^ " << title() << ALI_E;
}

void util::Loop::second_up_( )
{ //second stage of activation of element	
}

void util::Loop::third_up_( )
{ //third stage of activation of element	
}


