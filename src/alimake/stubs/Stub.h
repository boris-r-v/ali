#ifndef _@MODUL@_@ITEM@_h_
#define _@MODUL@_@ITEM@_h_

#include <@ITEM@Base.hh>

namespace @MODUL@{
    class @ITEM@: public @MODUL@::@ITEM@Base
    {
	public:
	    @ITEM@( xmlpp::Element const* );
	    virtual ~@ITEM@() = default;
	
	    virtual void therd_up_( );	    
	    virtual void second_up_( );
	    virtual void first_up_( );


    };
};

#endif // _@MODUL@_@ITEM@_h_

