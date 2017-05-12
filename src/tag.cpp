#include <tag.h>

ali::TagType ali::Tag::get_type() const
{
    return static_cast<ali::TagType>(value_.which());
}

std::string const& ali::Tag::get_name() const
{
    return name_;
}

bool ali::Tag::get_boolean() const
{
    if ( get_type() == TAG_BOOLEAN ) return boost::get<boolean_type>( value_ );
    if ( get_type() == TAG_NUMERIC ) return boost::get<numeric_type>( value_ );
    throw TagWrongTypeException( *this, TAG_BOOLEAN );
    
}
double ali::Tag::get_numeric() const
{
    if ( get_type() != TAG_NUMERIC ) throw TagWrongTypeException( *this, TAG_NUMERIC );
    return boost::get<numeric_type>( value_ );
}
std::string ali::Tag::get_string() const
{
    if ( get_type() != TAG_STRING ) throw TagWrongTypeException( *this, TAG_STRING );
    return boost::get<string_type>( value_ );
}
/*-------------------------------------------*/
std::ostream& ali::operator << ( std::ostream& _s, Tag const& _t)
{
    _s << "{'name':'" << _t.get_name() << "', 'value':'";
    switch( _t.get_type() )
    {
	case TAG_BOOLEAN:
	    _s << _t.get<ali::Tag::boolean_type>( );
	    break;
	case TAG_NUMERIC:
	    _s << _t.get<ali::Tag::numeric_type>( );
	    break;
	case TAG_STRING:
	    _s << _t.get<ali::Tag::string_type>( );
	    break;
	default:
	    _s << "unknown type";
	    break;
    }
    _s <<"', 'type':'"<<TagTypeName[ _t.get_type()] <<"'}";
    return _s;
}
/*-------------------------------------------*/
ali::TagWrongTypeException::TagWrongTypeException( Tag const& _t, TagType _tt ) throw()
    :msg ( "Wrong cast while extracting data from tag: \"" + _t.get_name() + "\" tag-type is:\"" + TagTypeName[_t.get_type()] + "\", try cast to : \"" +  TagTypeName[_tt] + "\"." )
{
}
ali::TagWrongTypeException::~TagWrongTypeException( ) throw()
{
}
const char* ali::TagWrongTypeException::what() const throw()
{
    return msg.c_str();
}
/*-------------------------------------------*/
ali::TagService& ali::TagService::Instance()
{
    static ali::TagService __theTagServiceInstance;
    return __theTagServiceInstance;
}

void ali::TagService::add_reciever( std::string const& _tag_name, std::function< void ( ali::Tag const&) > _func ) 
{
    lock_.lock();
    map_[_tag_name].push_back( _func );
    lock_.unlock();
}

void ali::TagService::emit_tag( Tag const& _t )
{
    auto fnd = map_.find ( _t.get_name() );
    if ( fnd != map_.end() )
    {     
        lock_.lock();
	for ( auto  i : fnd->second )
	    i(_t);
	lock_.unlock();
    }
}

void ali::subs_tag (std::string const& _name, std::function< void ( ali::Tag const&) > _func )
{ 
    ali::TagService::Instance().add_reciever( _name, _func ); 
}     
