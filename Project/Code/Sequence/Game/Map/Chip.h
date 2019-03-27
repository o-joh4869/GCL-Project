#pragma once
#include"../../../Tool/Vector2.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Map {

	//������p�����ėl�X�ȃ}�X���쐬����

	class Chip {
	protected:
		Chip(bool passFlag = true, const int &passCost = 1) :
			mPassFlag(passFlag),
			grHandle(MakeScreen(64, 64, TRUE)),
			mPassCost(passCost)
		{
		}
	public:
		virtual void update() {} //�������̓�����΂����ŋL�q��grHandle�̍X�V
		virtual ~Chip() {
			DeleteGraph(grHandle);
		}

	private:
		bool mPassFlag; //Unit���ʂ�邩�ǂ���
		int mPassCost; //Unit���ʂ�Ƃ��ɏ����BP
	public:
		const int grHandle; //64*64�̃O���t�B�b�N draw�͂���ɕ`�悷�� ClearDrawScreen��SetDrawScreen�͎����ŌĂԂ��� ����ʂɖ߂�����
		bool getPassFlag() const {
			return mPassFlag;
		}
		
	};
}}}