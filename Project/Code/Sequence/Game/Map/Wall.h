#pragma once
#include"Chip.h"

namespace Sequence { namespace Game { namespace Map {

	//��΂Ƀ��j�b�g���ʂ�Ȃ���
	class Wall : public Chip {
	public:
		Wall();
		virtual void update() {}
		virtual void draw() const override {}
		~Wall() = default;

	};
}}}