#pragma once
#include"../../../Tool/Vector2.h"
namespace Sequence { namespace Game { namespace Map {

	//������p�����ėl�X�ȃ}�X���쐬����

	class Chip {
	public:
		Chip(bool passFlag = true) :
			mPassFlag(passFlag)
		{}
		virtual void update() {} //�������̂�����΂����ŋL�q
		virtual void draw(const Vector2<int> &pos, const float &magnification) const {}
		virtual ~Chip() = default;

	private:
		bool mPassFlag; //Unit���ʂ�邩�ǂ���
	
	public:
		bool getPassFlag() {
			return mPassFlag;
		}
	};
}}}