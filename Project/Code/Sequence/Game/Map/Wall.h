#pragma once
#include"Chip.h"

namespace Sequence { namespace Game { namespace Map {

	//絶対にユニットが通れない壁
	class Wall : public Chip {
	public:
		Wall();
		virtual void update() override {}
		~Wall() = default;

	};
}}}