#ifndef ALI_CONTENT
#define ALI_CONTENT

#include <boost/noncopyable.hpp>
#include <itemimpl.h>
#include <memory>
#include <string>
#include <map>

namespace ali
{
    typedef std::map <std::string, std::shared_ptr<ali::ItemImpl> > Items;
    class Content: public boost::noncopyable
    {
	    Content() = default;

	    Items items_;
	public:
	    static Content& Instance();
	    ~Content() = default;

	    void add_item( std::shared_ptr<ali::ItemImpl> );	  
	    Items& get_items();
	    Items const& get_items() const;
    };
}
#endif // ALI_CONTENT
