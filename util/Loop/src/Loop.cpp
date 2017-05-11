#include <Loop.h>
#include <ali/tag.h>
#include <chrono>

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


void util::Loop::tic( )
{
    std::time_t ct = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
    ali::emit_tag( "time", ct );
    ali::emit_tag( "ctime", std::string ( ctime( &ct ) ) );
    ALI_LOG << "ctime: " << ctime( &ct ) << ALI_E;
}
