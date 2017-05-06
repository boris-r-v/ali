#include <itemimpl.h>

ali::ItemImpl::ItemImpl( xmlpp::Element const* _p )
{
    xml_node_ptr_ = _p;
//    for( auto at : _p->get_attributes() )
//	attrs_.insert(std::make_pair(at->get_name(), at->get_value() ) );
    ALI_LOG << " ItemImpl Alive " << ALI_E;
}

void ali::ItemImpl::tic()
{
    ALI_LOG << id() << " tic" << ALI_E;
}