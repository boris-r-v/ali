#include <loader.h>	
#include <loader_lib.h>	
#include <content.h>	
#include <itemfactory.h>

ali::Loader& ali::Loader::Instance()
{
    static Loader __theLoaderInstance;
    return __theLoaderInstance;
}

void ali::Loader::load( char const* _path )
{
    load_xml( _path );
}

void ali::Loader::load_xml( char const* _path )
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

void ali::Loader::load_element ( xmlpp::Element const* _node )
{
    Glib::ustring name = _node -> get_name();
    Glib::ustring prefix = _node -> get_namespace_prefix();
    if ( "text" != name ) 
	load_so( load_factory( prefix, name ), _node );

    for ( xmlpp::Element const* ch = static_cast<xmlpp::Element const*>(_node->get_first_child() ); ch; ch =  static_cast<xmlpp::Element const*>( ch -> get_next_sibling() ) )
	load_element( ch );
}

ali::ItemFactory const* ali::Loader::load_factory( Glib::ustring const& prefix, Glib::ustring const& name  )
{
    std::string lib_name( "libutil_EmptyLogic" );
    if ( !prefix.empty() )
	lib_name = "lib" + prefix + "_" + name;

    ALI_LOG << "Load DLL: " << lib_name << ALI_E;     
    return ali::LibLoader::Instance().load_lib( lib_name );
}


void ali::Loader::load_so ( ali::ItemFactory const* _f, xmlpp::Element const* _n )
{
    if ( _f ) 
	ali::Content::Instance().add_item( _f->create_item( _n  ) );
    else
    {
        std::cerr<<"Loader - load fails - reinstall scada base software."<<std::endl;
	exit ( static_cast<int>(ali::rcode::ERROR) );
    }
}
