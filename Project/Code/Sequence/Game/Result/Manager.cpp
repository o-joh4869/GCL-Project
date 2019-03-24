#include"Manager.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Result {
	Manager::Manager(Sequence::Game::State *state) :
		mState(state)
	{}
	Manager::~Manager() {

	}
	Sequence::Base *Manager::update() {

		DrawFormatString(0, 0, 0xffffff, "Result");

		return this;
	}
}}}