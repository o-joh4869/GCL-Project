#pragma once
namespace Sequence { namespace Game { namespace Map {

	//������p�����ē���ȃ}�X���쐬����
	//���΂炭�͓���ȃ}�X�͕K�v�Ȃ������Ȃ̂ł��̃N���X�𒼐ڗp����

	class Chip {
	public:
		Chip(bool passFlag = true) :
			mPassFlag(passFlag)
		{}
		virtual void update() {}
		virtual void draw() const {}
		virtual ~Chip() = default;

	private:
		bool mPassFlag; //Unit���ʂ�邩�ǂ���
	
	public:
		bool getPassFlag() {
			return mPassFlag;
		}
	};
}}}