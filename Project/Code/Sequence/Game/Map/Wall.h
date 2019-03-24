#pragma once
#include"Chip.h"

namespace Sequence { namespace Game { namespace Map {

	//â‘Î‚Éƒ†ƒjƒbƒg‚ª’Ê‚ê‚È‚¢•Ç
	class Wall : public Chip {
	public:
		Wall();
		virtual void update() {}
		virtual void draw() const override {}
		~Wall() = default;

	};
}}}