#include <ali.h>
#include <core.h>

ali::Core::Core( xmlpp::DomParser& _p ): 
    dom_ ( _p ),
    runner_ ( ali::Runner::Instance() ),
    content_ ( ali::Content::Instance() ),
    loader_ ( ali::LibLoader::Instance() )
{
}

void ali::Core::load( char const* _path )
{
    load_xml( _path );
}

void ali::Core::run ( )
{
    runner_.run();
}

void ali::Core::load_xml( char const* _path )
{
    try
    {
	dom_.parse_file( _path );   
        xmlpp::Element* root = dom_.get_document()->get_root_node();
	load_element( root );
    }
    catch ( std::exception const& _e )
    {
	ALI_ERROR << _e.what() << ALI_E;
    }
}

void ali::Core::load_element ( xmlpp::Element const* _node )
{
    Glib::ustring name = _node -> get_name();
    Glib::ustring prefix = _node -> get_namespace_prefix();
    if ( "text" != name ) 
	load_so( load_factory( prefix, name ), _node );

    for ( xmlpp::Element const* ch = static_cast<xmlpp::Element const*>(_node->get_first_child() ); ch; ch =  static_cast<xmlpp::Element const*>( ch -> get_next_sibling() ) )
	load_element( ch );
}

ali::ItemFactory const* ali::Core::load_factory( Glib::ustring const& prefix, Glib::ustring const& name  )
{
    std::string lib_name( "libutil_EmptyLogic" );
    if ( !prefix.empty() )
	lib_name = "lib" + prefix + "_" + name;

    ALI_LOG << "Load DLL: " << lib_name << ALI_E;     
    return loader_.load_lib( lib_name );
}


void ali::Core::load_so ( ali::ItemFactory const* _f, xmlpp::Element const* _n )
{
    if ( _f ) 
	content_.add_item( _f->create_item( _n  ) );
}

