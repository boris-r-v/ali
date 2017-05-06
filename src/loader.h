#ifndef ALI_LOADER
#define ALI_LOADER

#include <libxml++/libxml++.h>
#include <boost/noncopyable.hpp>
#include <loader_lib.h>	
#include <content.h>	
#include <runner.h>	

namespace ali
{
    class Loader: public boost::noncopyable
    {
	    xmlpp::DomParser& dom_;
	    ali::LibLoader loader_; //FIX later - сделать многопочный синглтон
	    ali::Content content_; 
	    ali::Runner runner_; 

	    void load_xml( char const* );
	    void load_element ( xmlpp::Element const* node );
	    ali::ItemFactory const* load_factory( Glib::ustring const& prefix, Glib::ustring const& name  );
	    void load_so ( ali::ItemFactory const*, xmlpp::Element const* _node );

	public:
	    Loader() = delete;
	    Loader( xmlpp::DomParser& );
	    ~Loader() = default;

	    void load( char const* );
	    void run ( );

    };
}


#endif // ALI_LOADER