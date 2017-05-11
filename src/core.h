#ifndef ALI_CORE
#define ALI_CORE

#include <boost/noncopyable.hpp>
#include <libxml++/libxml++.h>
#include <loader_lib.h>	
#include <content.h>	
#include <runner.h>	

namespace ali
{
    class Core: public boost::noncopyable
    {
	    xmlpp::DomParser &dom_;
	    ali::LibLoader& loader_;
	    ali::Content& content_; 
	    ali::Runner& runner_; 

	    void load_xml( char const* );
	    void load_element ( xmlpp::Element const* node );
	    ali::ItemFactory const* load_factory( Glib::ustring const& prefix, Glib::ustring const& name  );
	    void load_so ( ali::ItemFactory const*, xmlpp::Element const* _node );

	public:
	    Core() = delete;
	    Core( xmlpp::DomParser& );
	    ~Core() = default;

	    void load( char const* );
	    void run ( );

    };
}


#endif // ALI_CORE