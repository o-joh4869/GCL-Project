#include"Wall.h"

namespace Sequence { namespace Game { namespace Map {

	Wall::Wall() :
		Chip(false)
	{
		SetDrawScreen(grHandle);
		ClearDrawScreen();
		DrawBox(4, 4, 60, 60, 0x00ff00, TRUE);
		SetDrawScreen(DX_SCREEN_BACK);
	}

}}}