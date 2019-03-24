#pragma once
#include"../Base.h"

namespace Sequence { namespace Game {
	class State;
namespace Play {
	class Manager : public Sequence::Game::Base {
	public:
		Manager(Sequence::Game::State *state);
		Manager(const Manager&) = delete;
		Manager &operator=(const Manager&) = delete;
		~Manager();
		Sequence::Base *update() override;
	private:
		Sequence::Game::State *mState;
	};
}}}