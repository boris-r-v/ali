#ifndef ali_itemimpl
#define ali_itemimpl

#include <map>
#include <ali.h>
#include <string>
#include <libxml++/libxml++.h>

namespace ali
{
    class ItemImpl
    {
	    xmlpp::Element const* xml_node_ptr_;

	    typedef std::map<std::string, std::string> Attrs;
	    Attrs attrs_; 
	public:
	    ItemImpl( ) = default;
    	    virtual ~ItemImpl() = 0;
    	    ItemImpl( xmlpp::Element const* );

	    virtual void third_up_( ) = 0;	    
	    virtual void second_up_( ) = 0;
	    virtual void first_up_( ) = 0;
	    virtual std::string id() const = 0;

	    xmlpp::Element const* xml_node(){ return xml_node_ptr_; }

	    virtual void tic();
    
    };
}

#endif //ali_itemimpl
