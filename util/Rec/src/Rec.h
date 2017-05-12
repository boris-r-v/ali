#ifndef _util_Rec_h_
#define _util_Rec_h_

#include <RecBase.hh>
#include <ali/tag.h>

namespace util{
    class Rec: public util::RecBase
    {

	    void activate( );
	    virtual void accept( ali::Init_Visitor& );	

	    void rec_time( ali::Tag const& );
	    void rec_ctime( ali::Tag const& );

	public:
	    Rec( xmlpp::Element const* );
	    virtual ~Rec() = default;
	    


    };
};

#endif // _util_Rec_h_

