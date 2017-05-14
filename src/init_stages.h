#ifndef _ali_init_stages
#define _ali_init_stages

namespace ali
{
    enum class Init { Stage_1 = 1, Stage_2 = 2, Stage_3 = 3, Stage_4 = 4, Stage_5 = 5, Stage_6 = 6, Stage_7 = 7, Stage_8 = 8, Stage_9 = 9};
    typedef std::map< ali::Init, std::list< std::function< void () > > > InitStageMap;

}
#endif //_ali_init_stages
