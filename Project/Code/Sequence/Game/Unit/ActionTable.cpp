#include"ActionTable.h"

namespace Sequence { namespace Game { namespace Unit {

	ActionTable::ActionTable(const std::string &header) :
		mHeader(header),
		mList()
	{

	}

	void ActionTable::add(const std::string &header) {
		mList.emplace_back(ActionTable(header));
	}

}}}