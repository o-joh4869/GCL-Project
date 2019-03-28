#pragma once
namespace Sequence {
	class State;
namespace Game {
	class Manager;
	namespace Map {
		class Manager;
	}
	namespace Unit {
		class Manager;
	}

	class State {
	private:
		State(Sequence::State *state);
		State(const State&) = delete;
		State &operator=(const State&) = delete;
		~State();
	public:
		Sequence::State *state; //Sequence::Manager::mState‚Æ“¯‚¶
		Map::Manager *map;
		Unit::Manager *unit;
		friend Manager;
	};
}}