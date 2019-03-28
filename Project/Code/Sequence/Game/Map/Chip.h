#pragma once
#include"../../../Tool/Vector2.h"
#include<DxLib.h>

#include"../../../MyGlobal.h"

namespace Sequence { namespace Game { namespace Map {

	//これを継承して様々なマスを作成する

	class Chip {
	protected:
		Chip(bool passFlag = true, const int &passCost = 1) :
			mPassFlag(passFlag),
			grHandle(MakeScreen(ChipSize.x, ChipSize.y, TRUE)),
			mPassCost(passCost)
		{
		}
	public:
		virtual bool update() { return false; } //動くもの等あればここで記述＆grHandleの更新 grHandleの中身を書き換えたらtrueを返す
		virtual ~Chip() {
			DeleteGraph(grHandle);
		}

	private:
		bool mPassFlag; //Unitが通れるかどうか
		int mPassCost; //Unitが通るときに消費するBP
	public:
		const int grHandle; //64*64のグラフィック drawはこれに描画する ClearDrawScreenやSetDrawScreenは自分で呼ぶこと 裏画面に戻すこと
		bool getPassFlag() const {
			return mPassFlag;
		}
		
	};
}}}