#include <EmptyLogic.h>

util::EmptyLogic::EmptyLogic( xmlpp::Element const* _p ): 
    util::EmptyLogicBase ( _p )
{
    util::EmptyLogicBase::apply_attrs();
}

void util::EmptyLogic::accept( ali::Init_Visitor& _iv )
{
    _iv.add_init_stage( ali::Init::Stage_1, std::bind( &util::EmptyLogic::activate, this ) );
}


void util::EmptyLogic::activate( )
{ //first stage of activation the element
}


