#include <ali.h>
#include <content.h>

ali::Content& ali::Content::Instance()
{
    static Content __theContentInstance;
    return __theContentInstance;
}

void ali::Content::add_item( std::shared_ptr<ali::ItemImpl> _sp )
{
    if ( true == items_.insert( std::make_pair(_sp->id(), _sp ) ).second ) return;

    std::cerr << "ali::Content - duplicate id." << std::endl;
    exit( (int)ali::rcode::ERROR );
}

void ali::Content::tic()
{
    for ( auto i : items_ )
	i.second -> tic();
}

void ali::Content::init()
{
    ALI_LOG<< "---------begin first_up---------" << ALI_E;
    for ( auto i : items_ )
	i.second -> first_up_();
    ALI_LOG<< "---------done first_up---------" << ALI_E;
        
    ALI_LOG<< "---------begin second_up---------" << ALI_E;
    for ( auto i : items_ )
	i.second -> second_up_();
    ALI_LOG<< "---------done second_up---------" << ALI_E;

    ALI_LOG<< "---------begin third_up---------" << ALI_E;
    for ( auto i : items_ )
	i.second -> third_up_();
    ALI_LOG<< "---------done third_up---------" << ALI_E;
}

