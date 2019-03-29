#include"Sample.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Unit {

	Sample::Sample() :
		Base(2, 30)
	{
		SetDrawScreen(grHandle);

		DrawBox(4, 4, 28, 28, 0x0000ff, TRUE);

		SetDrawScreen(DX_SCREEN_BACK);
	}

	void Sample::update() {

	}
}}}