#include <core.h>
#include <init_visitor.h>
#include <loader.h>	
#include <runner.h>	

void ali::Core::load( char const* _path )
{
    ali::Loader::Instance().load( _path );
}

void ali::Core::init()
{
    ali::Init_Visitor _iv;
    _iv.collect_impls();
    _iv.init_impls();
}

void ali::Core::run ( )
{
    ali::Runner::Instance().run();
}

