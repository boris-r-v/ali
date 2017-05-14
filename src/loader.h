#ifndef ALI_LOADER
#define ALI_LOADER

#include <boost/noncopyable.hpp>
#include <libxml++/libxml++.h>

namespace ali
{
    class ItemFactory; 
    class Loader: public boost::noncopyable
    {
	    Loader() = default;

	    xmlpp::DomParser dom_;

	    void load_xml( char const* );
	    void load_element ( xmlpp::Element const* node );
	    ali::ItemFactory const* load_factory( Glib::ustring const& prefix, Glib::ustring const& name  );
	    void load_so ( ali::ItemFactory const*, xmlpp::Element const* _node );

	public:
	    static Loader& Instance();
	    ~Loader() = default;

	    void load( char const* );

    };
}
#endif //ALI_LOADER
