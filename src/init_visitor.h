#ifndef _ali_init_visitor
#define _ali_init_visitor

#include <map>
#include <list>
#include <functional>
#include <init_stages.h>

namespace ali
{
    class Init_Visitor
    {
	    InitStageMap map_;

	    void collect_impls( );
	    void init_impls( );

	public:
	    Init_Visitor() = default;
	    ~Init_Visitor() = default;
    
	    void add_init_stage( ali::Init, std::function< void () > );


	friend class Core;
    };

}
#endif //_ali_init_visitor
