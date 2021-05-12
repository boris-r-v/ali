
methodAccessSpec="""
        public:
    """
methodDef = """            //access for @NAME@
                virtual @TYPE@ @NAME@( );
                virtual void @NAME@( @TYPE@ );
    """
attrAccessSpec = """
        protected: //attributes
    """
attrDef = """                @TYPE@ @NAME@_;
    """

methodStub ="""
//access for @NAME@;
@TYPE@ @MODUL@::@ITEM@Base::@NAME@( )
{
    return @NAME@_;
}
void @MODUL@::@ITEM@Base::@NAME@( @TYPE@ _v)
{
    @NAME@_ = _v;"""
methodStubString="""
    //signal("@NAME@", _v);    
}"""
methodStubDouble="""
    //char buff[32];snprintf(buff,sizeof(buff),"%f", _v );
    //signal("@NAME@", buff);    
}"""
methodStubLong="""
    //char buff[32];snprintf(buff,sizeof(buff),"%ld", _v );
    //signal("@NAME@", buff);    
}"""
methodStubInt="""
    //char buff[32];snprintf(buff,sizeof(buff),"%d", _v );
    //signal("@NAME@", buff);    
}"""
methodStubBool="""
    //char buff[32];snprintf(buff,sizeof(buff),"%d", _v );
    //signal("@NAME@", buff);    
}"""

setAttrString = """
    if ( "@NAME@" == _n )
    {
        @NAME@( _v );
        return true;    
    }
"""
setAttrDouble = """
    if ( "@NAME@" == _n )
    {
        @NAME@( atof( _v.c_str() ) );
        return true;    
    }
"""
setAttrInt = """
    if ( "@NAME@" == _n )
    {
        @NAME@( atoi( _v.c_str() ) );
        return true;    
    }
"""
setAttrLong = """
    if ( "@NAME@" == _n )
    {
        @NAME@( atoll( _v.c_str() ) );
        return true;    
    }
"""
setAttrBool = """
    if ( "@NAME@" == _n )
    {
        @NAME@( atoi( _v.c_str() ) );
        return true;    
    }
"""

setAttr_1 = """
bool @MODUL@::@ITEM@Base::set_attr( std::string const&  _n, std::string const& _v )
{
"""
setAttr_2 = """
    return false;
}
"""

getAttrString="""
    if ( "@NAME@" == _n )
    {
        _v = @NAME@_;
        return true;
    }
"""
getAttrDouble="""
    if( "@NAME@" == _n )
    { 
        char buff[32];snprintf(buff,sizeof(buff),"%f", @NAME@_ );
        _v = buff;
        return true;
    }
"""

getAttrInt="""
    if( "@NAME@" == _n )
    { 
        char buff[32];snprintf(buff,sizeof(buff),"%d", @NAME@_ );
        _v = buff;
        return true;
    }
"""
getAttrLong="""
    if( "@NAME@" == _n )
    {
         char buff[32];snprintf(buff,sizeof(buff),"%ld", @NAME@_ );
        _v = buff;
        return true;
    }
"""
getAttrBool="""
    if( "@NAME@" == _n )
    { 
        char buff[32];snprintf(buff,sizeof(buff),"%d", (int)@NAME@_ );
        _v = buff;
        return true;
    }
"""
getAttr_1 = """
bool @MODUL@::@ITEM@Base::get_attr( const std::string&  _n, std::string& _v )
{
"""
getAttr_2 = """
    return false;
}
"""

checkAttr_1="""

bool @MODUL@::@ITEM@Base::has_attr( const std::string&  _n )    
{
"""

checkAttr_2="""
    if ("@NAME@" == _n ) return true;    
"""
checkAttr_3 = """
    return false;
}
"""





