#pragma once
#include<vector>

namespace Sequence { namespace Game {
	class State;
namespace Map {
	class Chip;
	class Manager {
	private:
		Manager();
		Manager(const Manager&) = delete;
		Manager &operator=(const Manager&) = delete;
		~Manager();
	public:
		//�eChip��update�֐�����񂸂Ă� Unit�Ƃ���update�̌オ��������
		void update();

		void draw() const;
		void redraw() const; //�eChip�̃O���t�B�b�N�����̃N���X�̃O���t�B�b�N�ɔ��f
		
	private:
		std::vector<std::vector<Chip*>> mChip;
		int mGrHandle; //�}�b�v�S�̂�`�悷��O���t�B�b�N�ւ̃n���h��
		
		friend State;
	};
}}}