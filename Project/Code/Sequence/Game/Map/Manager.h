#pragma once
#include<vector>
#include<unordered_map>
#include"../../../Tool/Vector2.h"

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

	private:

		void mRedraw();

		std::vector<std::vector<Chip*>> mChip;
		int mMapChipGrHandle; //Chip��`�悵�Ă܂Ƃ߂������̃O���t�B�b�N
		int mWholeMapGrHandle; //Chip�ȊO�̂��̂��܂Ƃ߂��O���t�B�b�N�A���x�X�V

	public:
		const auto getWholeMapGrHandle() {
			return mWholeMapGrHandle;
		}
		auto &getChip() {
			return mChip;
		}
		friend State;
	};
}}}