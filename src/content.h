#ifndef ALI_CONTENT
#define ALI_CONTENT

#include <boost/noncopyable.hpp>
#include <itemimpl.h>
#include <memory>
#include <string>
#include <map>

namespace ali
{
    class Content: public boost::noncopyable
    {
	    Content() = default;

	    typedef std::map <std::string, std::shared_ptr<ali::ItemImpl> > Items;
	    Items items_;
	public:
	    static Content& Instance();
	    ~Content() = default;

	    void add_item( std::shared_ptr<ali::ItemImpl> );	  
	    void init();
	    void tic();
    };
}
#endif // ALI_CONTENT
