#ifndef ali_itemimpl
#define ali_itemimpl

#include <map>
#include <ali.h>
#include <string>
#include <libxml++/libxml++.h>

namespace ali
{
    class Init_Visitor;
    class ItemImpl
    {
	    xmlpp::Element const* xml_node_ptr_;

	    typedef std::map<std::string, std::string> Attrs;
	    Attrs attrs_; 

	    virtual void accept( Init_Visitor& ) = 0;

	public:
	    ItemImpl( ) = default;
    	    virtual ~ItemImpl() = 0;
    	    ItemImpl( xmlpp::Element const* );

	    virtual std::string id() const = 0;

	    xmlpp::Element const* xml_node(){ return xml_node_ptr_; }
	
	friend class Init_Visitor;
    };
}

#endif //ali_itemimpl
