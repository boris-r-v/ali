#ifndef _ali_init_visitor
#define _ali_init_visitor

#include <map>
#include <list>
#include <functional>

namespace ali
{
    typedef std::map<int, std::list< std::function< void () > > > InitStageMap;

    class Init_Visitor
    {
	    InitStageMap map_;
	public:
	    Init_Visitor() = default;
	    ~Init_Visitor() = default;
    
	    void add_init_stage( unsigned, std::function< void () > );
	    void init_impls( );

    };

}
#endif //_ali_init_visitor
