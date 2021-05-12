#ifndef _@MODUL@_@ITEM@_h_
#define _@MODUL@_@ITEM@_h_

#include <@ITEM@Base.hh>

namespace @MODUL@{
    class @ITEM@: public @MODUL@::@ITEM@Base
    {

            void activate( );
            virtual void accept( ali::Init_Visitor& );        

        public:
            @ITEM@( xmlpp::Element const* );
            virtual ~@ITEM@() = default;
            


    };
};

#endif // _@MODUL@_@ITEM@_h_

