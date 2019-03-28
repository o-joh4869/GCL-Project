#include"Manager.h"
#include"../Map/Manager.h"

#include"Sample.h"

#include<algorithm>

namespace Sequence { namespace Game { namespace Unit {

	Manager::Manager(Map::Manager *map) : 
		mMapGrHandle(map->getWholeMapGrHandle()),
		mMapChip(map->getChip())
	{
		mUnit.emplace_back(new Sample());
		mUnit[0]->setPos(Vector2<int>(1, 1));
	}

	Manager::~Manager() {
		for (const auto &i : mUnit) {
			delete i;
		}
		mUnit.clear();
	}

	void Manager::update() {
		for (auto &i : mUnit) {
			i->update();
		}
	}

	void Manager::draw() const {
		SetDrawScreen(mMapGrHandle);

		for (const auto i : mUnit) {
			DrawGraph(i->getPos().x * 32, i->getPos().y * 32, i->grHandle, TRUE);
		}

		SetDrawScreen(DX_SCREEN_BACK);
	}
}}}