#pragma once
#include"../../../Tool/Vector2.h"
namespace Sequence { namespace Game { namespace Unit {

	class Base {
	protected:
		Base() {}

		Vector2<int> mPos; //�}�b�v���ł̈ʒu


	public:
		virtual void update() {}
		virtual void draw() const {}
	};

}}}