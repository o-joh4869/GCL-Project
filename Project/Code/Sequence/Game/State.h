#pragma once
namespace Sequence {
	class State;
namespace Game {
	class Manager;
	class State {
	private:
		State(Sequence::State *state);
		State(const State&) = delete;
		State &operator=(const State&) = delete;
		~State();
	public:
		Sequence::State *state; //Sequence::Manager::mState‚Æ“¯‚¶

		friend Manager;
	};
}}