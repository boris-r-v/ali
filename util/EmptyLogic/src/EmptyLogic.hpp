#ifndef _util_EmptyLogic_h_
#define _util_EmptyLogic_h_

#include <EmptyLogicBase.hh>

namespace util{
    class EmptyLogic: public util::EmptyLogicBase
    {
	public:
	    EmptyLogic( xmlpp::Element const* );
	    virtual ~EmptyLogic() = default;
	
	    virtual void therd_up_( );	    
	    virtual void second_up_( );
	    virtual void first_up_( );


    };
};

#endif // _util_EmptyLogic_h_

