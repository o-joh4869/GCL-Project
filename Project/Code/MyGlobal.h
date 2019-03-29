#pragma once
#include"Tool/Vector2.h"

constexpr Vector2<int> gWindowSize(960, 540);
constexpr Vector2<int> gWindowSizeL(640, 540); //左側区画のサイズ

namespace Sequence { namespace Game { namespace Map {
	extern const Vector2<int> ChipSize;
	extern const Vector2<int> MapSize; //マップ全体のサイズ。
	extern const Vector2<int> ScrollLimit; //マップスクロール自由度。数が大きいほど可動域が広がる
}}}