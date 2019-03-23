#include"Manager.h"
#include"../State.h"
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

			return this;
		}
	}
}