#include <con.h>

util::con::con( xmlpp::Element const* _p ): 
    util::conBase ( _p )
{
    util::conBase::apply_attrs();
}

void util::con::accept( ali::Init_Visitor& _iv )
{
    _iv.add_init_stage( 1, std::bind( &util::con::activate, this ) );
}


void util::con::activate( )
{ //first stage of activation the element
}


