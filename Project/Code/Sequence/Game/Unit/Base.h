#pragma once
#include"../../../Tool/Vector2.h"
namespace Sequence { namespace Game { namespace Unit {

	class Base {
	protected:
		Base() {}

		Vector2<int> mPos; //マップ内での位置


	public:
		virtual void update() {}
		virtual void draw() const {}
	};

}}}