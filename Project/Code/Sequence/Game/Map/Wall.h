#pragma once
#include"Chip.h"

namespace Sequence { namespace Game { namespace Map {

	//ê‚ëŒÇ…ÉÜÉjÉbÉgÇ™í ÇÍÇ»Ç¢ï«
	class Wall : public Chip {
	public:
		Wall() : Chip() {
			SetDrawScreen(grHandle);
			DrawBox(0, 0, ChipSize.x, ChipSize.y, 0xaaaaaa, TRUE);
			DrawBox(0, 0, ChipSize.x, ChipSize.y, 0xff0000, FALSE);
			SetDrawScreen(DX_SCREEN_BACK);
		}
		virtual bool update() override { return false; }
		~Wall() = default;

	};
}}}