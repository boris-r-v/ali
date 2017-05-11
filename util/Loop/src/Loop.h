#ifndef _util_Loop_h_
#define _util_Loop_h_

#include <LoopBase.hh>

namespace util{
    class Loop: public util::LoopBase
    {
	public:
	    Loop( xmlpp::Element const* );
	    virtual ~Loop() = default;
	
	    virtual void third_up_( );	    
	    virtual void second_up_( );
	    virtual void first_up_( );

	    virtual void tic( );


    };
};

#endif // _util_Loop_h_

