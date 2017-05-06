#ifndef ali_itemfactory
#define ali_itemfactory

#include <ali.h>
#include <itemimpl.h>
#include <memory>

namespace ali
{
	class ItemFactory
	{
	    public:
		ItemFactory() = default;
		virtual ~ItemFactory() = default;
	        virtual std::shared_ptr<ali::ItemImpl> createItem( xmlpp::Element const* _n ) = 0;
	};
	typedef ItemFactory* (*CreateFunction) ( );
}

#endif //ali_itemfactory
