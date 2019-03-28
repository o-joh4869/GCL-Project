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

		Vector2<int> mPos; //�}�b�v���ł̈ʒu
		const int mAgility; //�f����(���Ԍ���)
		int mBP; //�s���ɔ����ď������
		const int mIniBP; //����BP

	public:
		int grHandle; //�����`�悷��

		virtual bool update() { return false; } //MapChip���l���[�V������t����Ƃ��͂����ɋL�q
	};

}}}