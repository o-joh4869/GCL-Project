#pragma once
#include"../../../Tool/Vector2.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Map {

	//������p�����ėl�X�ȃ}�X���쐬����

	class Chip {
	protected:
		Chip(bool passFlag = true) :
			mPassFlag(passFlag),
			grHandle(MakeScreen(64, 64, TRUE))
		{
		}
	public:
		virtual void update() {} //�������̓�����΂����ŋL�q
		virtual void draw() const {} //���������ʂ�grHandle�ɔ��f������
		virtual ~Chip() {
			DeleteGraph(grHandle);
		}

	private:
		bool mPassFlag; //Unit���ʂ�邩�ǂ���
	public:
		const int grHandle; //64*64�̃O���t�B�b�N draw�͂���ɕ`�悷�� ClearDrawScreen��SetDrawScreen�͎����ŌĂԂ��� ����ʂɖ߂�����
		bool getPassFlag() {
			return mPassFlag;
		}
		
	};
}}}