#include <Loop.h>
#include <ali/tag.h>
#include <chrono>

util::Loop::Loop( xmlpp::Element const* _p ): 
    util::LoopBase ( _p )
{
    util::LoopBase::apply_attrs();
}

void util::Loop::accept( ali::Init_Visitor& _iv )
{
    _iv.add_init_stage( ali::Init::Stage_1, std::bind( &util::Loop::activate, this ) );
    _iv.add_periodic( boost::posix_time::seconds(1), std::bind( &util::Loop::periodic, this ) );
}


void util::Loop::activate( )
{ //first stage of activation the element

    ALI_LOG <<" util::Loop::title: " << title() << ALI_E;

}

void util::Loop::periodic( )
{
    std::time_t ct = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
    ali::emit_tag( "time", ct );
    ali::emit_tag( "ctime", std::string ( ctime( &ct ) ) );
    //ALI_LOG << "ctime: " << ctime( &ct ) << ALI_E;
}