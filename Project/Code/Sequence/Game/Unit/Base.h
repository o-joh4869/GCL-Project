#pragma once
#include"../../../Tool/Vector2.h"
#include<DxLib.h>
namespace Sequence { namespace Game {

	namespace Map {
		extern const Vector2<int> ChipSize;
	}

namespace Unit {

	class Base {
	protected:
		Base(int agility, int BP) :
			mAgility(agility),
			mBP(BP),
			mIniBP(BP),
			grHandle(MakeScreen(Game::Map::ChipSize.x, Game::Map::ChipSize.y, TRUE))
		{
		}

		Vector2<int> mPos; //マップ内での位置
		const int mAgility; //素早さ(順番決め)
		int mBP; //行動に伴って消費するやつ
		const int mIniBP; //初期BP

	public:
		const int grHandle; //これを描画する
		void setPos(const Vector2<int> &pos) {
			mPos = pos;
		}
		const auto &getPos() const {
			return mPos;
		}
		virtual void update() {} //MapChip同様モーションを付けるときはここに記述
	};

}}}