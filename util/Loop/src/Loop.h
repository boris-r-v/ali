#ifndef _util_Loop_h_
#define _util_Loop_h_

#include <LoopBase.hh>

namespace util{
    class Loop: public util::LoopBase
    {

	    void activate( );
	    virtual void accept( ali::Init_Visitor& );	
	    
	    void periodic();
	public:
	    Loop( xmlpp::Element const* );
	    virtual ~Loop() = default;
	    
    };
};

#endif // _util_Loop_h_

