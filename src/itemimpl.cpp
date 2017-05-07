#include <itemimpl.h>

ali::ItemImpl::ItemImpl( xmlpp::Element const* _p )
{
    xml_node_ptr_ = _p;
}

void ali::ItemImpl::tic()
{
    ALI_LOG << id() << " tic" << ALI_E;
}