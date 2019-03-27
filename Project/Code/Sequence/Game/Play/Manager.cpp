#include"Manager.h"
#include"../State.h"
#include"../Result/Manager.h"
#include"../../Title/Manager.h"
#include"../../../Input/Key.h"
#include<DxLib.h>

#include"../Map/Manager.h"

namespace Sequence { namespace Game { namespace Play {

	Manager::Manager(Sequence::Game::State *state) :
		mState(state)
	{}

	Manager::~Manager() {

	}
	Sequence::Base *Manager::update() {

		mState->map->update();
		mState->map->draw();

		return this;
	}
}}}