#ifndef ali_common
#define ali_common

#include <iostream>

namespace ali
{
    enum class return_code{ OK, ERROR };
    typedef return_code rcode;
    
/*    class logger : public std::ostream
    {
	logger() : std::ostream ( std::cout.rbuf() ) {};
	~logger() = default;
    };
*/
}

#define ALI_LOG std::cout<<"ALI::LOG: "
#define ALI_DEBUG std::cout<<"ALI::DEBUG: "
#define ALI_ERROR std::cout<<"ALI::ERROR: file:"<<__FILE__<<" line: "<<__LINE__<<" || defenition: "
#define ALI_E std::endl
#define ALI_END std::endl
#define ALI_ENDL std::endl


#endif // ali_common