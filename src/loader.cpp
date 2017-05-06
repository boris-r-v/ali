#include <ali.h>
#include <loader.h>

ali::Loader::Loader( xmlpp::DomParser& _p ): dom_ ( _p )
{
}

void ali::Loader::load( char const* _path )
{
    load_xml( _path );
}

void ali::Loader::run ( )
{
    ALI_LOG << "----------ALI RUN-----------" << std::endl;
}

void ali::Loader::load_xml( char const* _path )
{
    try
    {
	dom_.parse_file( _path );   
        xmlpp::Node* root = dom_.get_document()->get_root_node();
	load_element( root );
    }
    catch ( std::exception const& _e )
    {
	ALI_ERROR << _e.what() << ALI_E;
    }
}

void ali::Loader::load_element ( xmlpp::Node const* node )
{
    Glib::ustring name = node -> get_name();
    Glib::ustring prefix = node -> get_namespace_prefix();
    if ( "text" != name ) 
	prepare_load_so( prefix, name );

    for ( xmlpp::Node const* ch = node->get_first_child(); ch; ch = ch -> get_next_sibling() )
	load_element( ch );
}

void ali::Loader::prepare_load_so( Glib::ustring const& prefix, Glib::ustring const& name  )
{
    std::string lib_name( "libutil_EmptyLogic" );
    if ( !prefix.empty() )
	lib_name = "lib" + prefix + "_" + name;

    ALI_LOG << "Load DLL: " << lib_name << ALI_E;     
    loader_.load_lib( lib_name );
}

