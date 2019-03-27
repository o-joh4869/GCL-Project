#pragma once
#include"Chip.h"


namespace Sequence { namespace Game { namespace Map {

	class Grass : public Chip {
	public:
		Grass() : Chip() {}
		virtual void update() override {}
		~Grass() = default;
	};

}}}