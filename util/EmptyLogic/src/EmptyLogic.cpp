#include <EmptyLogic.h>

util::EmptyLogic::EmptyLogic( xmlpp::Element const* _p ): 
    util::EmptyLogicBase ( _p )
{
    util::EmptyLogicBase::apply_attrs();
}

void util::EmptyLogic::first_up_( )
{ //first stage of activation of element	
}

void util::EmptyLogic::second_up_( )
{ //second stage of activation of element	
}

void util::EmptyLogic::third_up_( )
{ //third stage of activation of element	
}


