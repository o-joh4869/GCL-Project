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
		
		//�}�b�v��`�悷��
		void draw() const;
		
	private:
		std::vector<std::vector<Chip*>> mChip;

		friend State;
	};
}}}