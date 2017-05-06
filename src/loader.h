#ifndef ALI_LOADER
#define ALI_LOADER

#include <libxml++/libxml++.h>
#include <boost/noncopyable.hpp>
#include <loader_lib.h>	

namespace ali
{
    class Loader: public boost::noncopyable
    {
	    xmlpp::DomParser& dom_;
	    ali::LibLoader loader_; //FIX later - сделать многопочный синглтон

	    void load_xml( char const* );
	    void load_element ( xmlpp::Node const* node );
	    void prepare_load_so( Glib::ustring const& prefix, Glib::ustring const& name  );

	public:
	    Loader() = delete;
	    Loader( xmlpp::DomParser& );
	    ~Loader() = default;

	    void load( char const* );
	    void run ( );

    };
}


#endif // ALI_LOADER