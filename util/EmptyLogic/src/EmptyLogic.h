#ifndef _util_EmptyLogic_h_
#define _util_EmptyLogic_h_

#include <EmptyLogicBase.hh>

namespace util{
    class EmptyLogic: public util::EmptyLogicBase
    {

	    void activate( );
	    virtual void accept( ali::Init_Visitor& );	

	public:
	    EmptyLogic( xmlpp::Element const* );
	    virtual ~EmptyLogic() = default;
	    


    };
};

#endif // _util_EmptyLogic_h_

