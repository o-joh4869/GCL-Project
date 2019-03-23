#pragma once
#include"../Tool/Vector2.h"

namespace Input {
	class Manager;
	class Mouse {
	private:
		Mouse();
		Mouse(const Mouse&) = delete;
		Mouse &operator=(const Mouse&) = delete;
		~Mouse() = default;

		static void update();
	public:
		static Mouse &get() {
			static Mouse ins;
			return ins;
		}

		//�t���[���̍ŏ��̃}�E�X�̈ʒu���擾
		static const auto &getPoint() {
			return mPoint;
		}

		//�}�E�X�J�[�\���̈ʒu��ύX
		static int setPoint(const Vector2<int> &point);
		
		//GetMousInput�֐��̕Ԃ�l�Ɠ��l
		static const auto &getInput() {
			return mInput;
		}

	private:
		static Vector2<int> mPoint;
		static int mInput;
		
		friend Manager;
	};
	extern Mouse &gMouse;
}