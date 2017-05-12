#include <@ITEM@.h>

@MODUL@::@ITEM@::@ITEM@( xmlpp::Element const* _p ): 
    @MODUL@::@ITEM@Base ( _p )
{
    @MODUL@::@ITEM@Base::apply_attrs();
}

void @MODUL@::@ITEM@::accept( ali::Init_Visitor& _iv )
{
    _iv.add_init_stage( 1, std::bind( &@MODUL@::@ITEM@::activate, this ) );
}


void @MODUL@::@ITEM@::activate( )
{ //first stage of activation the element
}


