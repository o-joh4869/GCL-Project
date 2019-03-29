#pragma once
#include"Base.h"
#include<map>
#include<functional>

namespace Sequence { namespace Game {

	namespace Map {
		class Chip;
	}

namespace Unit {
	class Sample : public Base {
	public:
		Sample();
		virtual ~Sample() = default;

		virtual void draw() override;

		virtual void action(const std::string &actionKey, std::vector<Map::Chip*> &chip, std::vector<Unit::Base*> &unit) override;

	private:
		std::map<std::string, std::function<void(std::vector<Map::Chip*> &chip, std::vector<Unit::Base*> &unit)>> mActionList;

		void mAttack(std::vector<Map::Chip*> &chip, std::vector<Unit::Base*> &unit);
	};
}}}