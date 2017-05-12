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

ali::Items& ali::Content::get_items()
{
    return items_;
}

ali::Items const& ali::Content::get_items() const
{
    return items_;
}
