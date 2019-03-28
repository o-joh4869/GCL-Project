#pragma once
#include"Chip.h"

namespace Sequence { namespace Game { namespace Map {

	//â‘Î‚Éƒ†ƒjƒbƒg‚ª’Ê‚ê‚È‚¢•Ç
	class Wall : public Chip {
	public:
		Wall() : Chip() {
			SetDrawScreen(grHandle);
			DrawBox(0, 0, 32, 32, 0xaaaaaa, TRUE);
			DrawBox(0, 0, 32, 32, 0xff0000, FALSE);
			SetDrawScreen(DX_SCREEN_BACK);
		}
		virtual bool update() override { return false; }
		~Wall() = default;

	};
}}}