#pragma once
#include"../../../Tool/Vector2.h"
namespace Sequence { namespace Game { namespace Map {

	//これを継承して様々なマスを作成する

	class Chip {
	public:
		Chip(bool passFlag = true) :
			mPassFlag(passFlag)
		{}
		virtual void update() {} //動くものがあればここで記述
		virtual void draw(const Vector2<int> &pos, const float &magnification) const {}
		virtual ~Chip() = default;

	private:
		bool mPassFlag; //Unitが通れるかどうか
	
	public:
		bool getPassFlag() {
			return mPassFlag;
		}
	};
}}}