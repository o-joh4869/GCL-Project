#pragma once
#include <vector>
#include <functional>
#include "DxLib.h"
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

		
		// �}�E�X�{�^���̃��O�p�\����
		struct ButtonInfo {
			int Button;
			Vector2<int> Pos;
			int LogType;

			ButtonInfo(int _button, Vector2<int> _pos, int _logType) :
				Button(_button),
				Pos(_pos),
				LogType(_logType) {}

		};
		
		// �}�E�X�{�^�����O�̔z����擾
		inline const std::vector<ButtonInfo>& getButtonLog() {
			return mButtonLog;
		}

		// �֐��I�u�W�F�N�g�̏����𖞂������W�ŁAbuttonType�Ŏw�肵���}�E�X�̃{�^����buttonState�Ɏw�肵����ԕω������x�������擾����
		int getButtonChangeCount(std::function<bool(const Vector2<int>)> func, int buttonType = MOUSE_INPUT_LEFT, int buttonState = MOUSE_INPUT_LOG_DOWN) const;

	private:
		static Vector2<int> mPoint;

		static std::vector<ButtonInfo> mButtonLog;
		
		friend Manager;
	};
	extern Mouse &gMouse;
}