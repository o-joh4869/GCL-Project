#include"State.h"
#include<DxLib.h>

namespace Sequence {
	State::State() {
		backPicHandle = LoadGraph("images/�w�i.png");
	}

	State::~State() {
		DeleteGraph(backPicHandle);
	}
}