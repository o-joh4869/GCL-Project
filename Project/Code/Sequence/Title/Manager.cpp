#include"Manager.h"
#include"../State.h"
#include"../Game/Manager.h"
#include"../../Input/Key.h"
#include<DxLib.h>

namespace Sequence {
	namespace Title {

		Manager::Manager(Sequence::State *state) :
			mState(state)
		{
			SetTransColor(0, 0, 0);
			mLogoHandle = LoadGraph("images/Title/ƒƒS.bmp");
		}

		Manager::~Manager() {
			DeleteGraph(mLogoHandle);
		}

		Sequence::Base *Manager::update() {

			DrawGraph(0, 0, mState->backPicHandle, FALSE);
			DrawGraph(0, 0, mLogoHandle, TRUE);

			if (Input::gKey[KEY_INPUT_SPACE] == -1) return (new Sequence::Game::Manager(mState));
			else return this;
		}
	}
}