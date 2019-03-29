#include"Sample.h"
#include<DxLib.h>

#include"ActionTable.h"

namespace Sequence { namespace Game { namespace Unit {

	Sample::Sample() :
		Base(2, 30)
	{
		SetDrawScreen(grHandle);

		DrawBox(4, 4, 28, 28, 0x0000ff, TRUE);

		SetDrawScreen(DX_SCREEN_BACK);

		mActionTable->add("Attack");
		(*mActionTable)[0].add("Punch");
		(*mActionTable)[0].add("Kick");
		(*mActionTable)[0].add("Fire");

		mActionTable->add("Move");
		mActionTable->add("Pass");

	}


	void Sample::draw() {

	}

	void Sample::action(const std::string &actionKey, std::vector<Map::Chip*> &chip, std::vector<Unit::Base*> &unit) {

	}
}}}