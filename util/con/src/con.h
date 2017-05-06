#ifndef _util_con_h_
#define _util_con_h_

#include <conBase.hh>

namespace util{
    class con: public util::conBase
    {
	public:
	    con( xmlpp::Element const* );
	    virtual ~con() = default;
	
	    virtual void third_up_( );	    
	    virtual void second_up_( );
	    virtual void first_up_( );


    };
};

#endif // _util_con_h_

