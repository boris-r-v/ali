#ifndef ali_itemimpl
#define ali_itemimpl

#include <ali.h>
#include <libxml++/libxml++.h>

namespace ali
{
    class ItemImpl
    {
	    xmlpp::Element const* xml_node_ptr_;
	public:
	    ItemImpl( ) = default;
    	    virtual ~ItemImpl() = 0;
    	    ItemImpl( xmlpp::Element const* );

	    virtual void therd_up_( ) = 0;	    
	    virtual void second_up_( ) = 0;
	    virtual void first_up_( ) = 0;


	    xmlpp::Element const* xml_node(){ return xml_node_ptr_; }

    
    };
}

#endif //ali_itemimpl
