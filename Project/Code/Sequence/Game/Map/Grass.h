#pragma once
#include"Chip.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Map {

	class Grass : public Chip {
	public:
		Grass() : Chip() {
			SetDrawScreen(grHandle);
			DrawBox(0, 0, 32, 32, 0x00ff00, TRUE);
			DrawBox(0, 0, 32, 32, 0xff0000, FALSE);
			SetDrawScreen(DX_SCREEN_BACK);
		}
		virtual bool update() override { return false; }
		~Grass() = default;
	};

}}}