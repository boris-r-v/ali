#ifndef ALI_CORE
#define ALI_CORE

#include <boost/noncopyable.hpp>

namespace ali
{
    class Core: public boost::noncopyable
    {
	public:
	    Core() = default;
	    ~Core() = default;

	    void load( char const* );
	    void init ( );
	    void run ( );

    };
}


#endif // ALI_CORE