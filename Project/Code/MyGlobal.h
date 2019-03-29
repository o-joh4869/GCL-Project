#pragma once
#include"Tool/Vector2.h"

constexpr Vector2<int> gWindowSize(960, 540);
constexpr Vector2<int> gWindowSizeL(640, 540); //�������̃T�C�Y

namespace Sequence { namespace Game { namespace Map {
	extern const Vector2<int> ChipSize;
	extern const Vector2<int> MapSize; //�}�b�v�S�̂̃T�C�Y�B
	extern const Vector2<int> ScrollLimit; //�}�b�v�X�N���[�����R�x�B�����傫���قǉ��悪�L����
}}}