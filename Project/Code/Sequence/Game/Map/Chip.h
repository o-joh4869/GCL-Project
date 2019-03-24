#pragma once
#include"../../../Tool/Vector2.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Map {

	//これを継承して様々なマスを作成する

	class Chip {
	protected:
		Chip(bool passFlag = true) :
			mPassFlag(passFlag),
			grHandle(MakeScreen(64, 64, TRUE))
		{
		}
	public:
		virtual void update() {} //動くもの等あればここで記述
		virtual void draw() const {} //動いた結果をgrHandleに反映させる
		virtual ~Chip() {
			DeleteGraph(grHandle);
		}

	private:
		bool mPassFlag; //Unitが通れるかどうか
	public:
		const int grHandle; //64*64のグラフィック drawはこれに描画する ClearDrawScreenやSetDrawScreenは自分で呼ぶこと 裏画面に戻すこと
		bool getPassFlag() {
			return mPassFlag;
		}
		
	};
}}}