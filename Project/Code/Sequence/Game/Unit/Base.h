#pragma once
#include"../../../Tool/Vector2.h"
#include<DxLib.h>
namespace Sequence { namespace Game { namespace Unit {

	class Base {
	protected:
		Base(int agility, int BP) :
			mAgility(agility),
			mBP(BP),
			mIniBP(BP),
			grHandle(MakeScreen(32, 32, TRUE))
		{
		}

		Vector2<int> mPos; //�}�b�v���ł̈ʒu
		const int mAgility; //�f����(���Ԍ���)
		int mBP; //�s���ɔ����ď������
		const int mIniBP; //����BP

	public:
		const int grHandle; //�����`�悷��
		void setPos(const Vector2<int> &pos) {
			mPos = pos;
		}
		const auto &getPos() const {
			return mPos;
		}
		virtual void update() {} //MapChip���l���[�V������t����Ƃ��͂����ɋL�q
	};

}}}