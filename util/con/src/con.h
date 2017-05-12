#ifndef _util_con_h_
#define _util_con_h_

#include <conBase.hh>

namespace util{
    class con: public util::conBase
    {

	    void activate( );
	    virtual void accept( ali::Init_Visitor& );	

	public:
	    con( xmlpp::Element const* );
	    virtual ~con() = default;
	    


    };
};

#endif // _util_con_h_

