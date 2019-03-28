#pragma once
#include<vector>

namespace Sequence { namespace Game {
	class State;
	namespace Map {
		class Chip;
		class Manager;
	}

namespace Unit {

	class Base;

	class Manager {
	private:
		Manager(Map::Manager *map);
		Manager(const Manager&) = delete;
		Manager &operator=(const Manager&) = delete;
		~Manager();
	public:
		void update();

		//Map::Manager::draw‚æ‚èæ‚ÉŒÄ‚Ô‚±‚Æ
		void draw() const;

	private:
		std::vector<Base*> mUnit;
		std::vector<std::vector<Map::Chip*>> &mMapChip;
		const int mMapGrHandle;

		friend State;
	};
}}}