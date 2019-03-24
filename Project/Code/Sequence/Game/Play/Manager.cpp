#include"Manager.h"
#include"../State.h"
#include"../Result/Manager.h"
#include"../../Title/Manager.h"
#include"../../../Input/Key.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Play {

	Manager::Manager(Sequence::Game::State *state) :
		mState(state)
	{}

	Manager::~Manager() {

	}
	Sequence::Base *Manager::update() {

		DrawFormatString(0, 0, 0xffffff, "Play");
		if (Input::gKey[KEY_INPUT_BACK] == -1) return (new Sequence::Title::Manager(mState->state));
		else if (Input::gKey[KEY_INPUT_SPACE] == -1) return (new Game::Result::Manager(mState));
		else return this;
	}
}}}