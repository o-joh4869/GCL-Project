#pragma once
#include"../../../Tool/Vector2.h"
namespace Sequence { namespace Game { namespace Unit {

	class Base {
	protected:
		Base(int speed, int BP) : 
			mAgility(speed),
			mIniBP(BP),
			mBP(BP)
		{

		}

		Vector2<int> mPos; //マップ内での位置
		const int mAgility; //素早さ(順番決め)
		int mBP; //行動に伴って消費するやつ
		const int mIniBP; //初期BP

	public:
		virtual void update() {}
	};

}}}