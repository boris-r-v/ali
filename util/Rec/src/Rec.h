#ifndef _util_Rec_h_
#define _util_Rec_h_

#include <RecBase.hh>
#include <ali/tag.h>

namespace util{
    class Rec: public util::RecBase
    {
	    void rec_time( ali::Tag const& );
	    void rec_ctime( ali::Tag const& );

	public:
	    Rec( xmlpp::Element const* );
	    virtual ~Rec() = default;
	
	    virtual void third_up_( );	    
	    virtual void second_up_( );
	    virtual void first_up_( );

    };
};

#endif // _util_Rec_h_

