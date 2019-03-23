#include"State.h"
#include<DxLib.h>

namespace Sequence {
	State::State() {
		backPicHandle = LoadGraph("images/îwåi.png");
	}

	State::~State() {
		DeleteGraph(backPicHandle);
	}
}