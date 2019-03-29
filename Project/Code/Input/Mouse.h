#pragma once
#include <vector>
#include <functional>
#include "DxLib.h"
#include "../MyGlobal.h"
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

		// �P�t���[���O����̃}�E�X���W�̍�����Ԃ�
		Vector2<int> getDelta() const {
			return mPoint - mPrePoint;
		}

		// ���� p1 �A�E�� p2 �̋�`�̒��Ƀ}�E�X���W���܂܂�Ă��邩��Ԃ�
		bool isMouseOver(Vector2<int> p1, Vector2<int> p2) const {
			return p1.x <= mPoint.x && mPoint.x < p2.x && p1.y <= mPoint.y && mPoint.y < p2.y;
		}

		// �}�E�X�{�^����
		struct ButtonState {

			int buttonType;

			int pressedDuration;
			bool clicked;
			bool pressed;
			bool released;

			ButtonState(int _buttonType) :
				buttonType(_buttonType),
				pressedDuration(0),
				clicked(false),
				pressed(false),
				released(false) {}

			void update();

		};

		// ������W p1 �A�E�����W p2 �̋�`�͈͓��Ń}�E�X���{�^�����N���b�N���ꂽ���ǂ�����Ԃ�
		bool leftClicked(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize, bool eraseFlag = true) const {
			if (mMouseL.clicked) mMouseL.clicked = !eraseFlag;
			return isMouseOver(p1, p2) && mMouseL.clicked;
		}
		// �}�E�X���{�^����������Ă��邩�ǂ�����Ԃ�
		bool leftPressed() const {
			return mMouseL.pressed;
		}
		// ������W p1 �A�E�����W p2 �̋�`�͈͓��Ń}�E�X���{�^����������Ă��邩�ǂ�����Ԃ�
		bool leftPressed(Vector2<int> p1, Vector2<int> p2) const {
			return isMouseOver(p1, p2) && mMouseL.pressed;
		}
		// ������W p1 �A�E�����W p2 �̋�`�͈͓��Ń}�E�X���{�^���������ꂽ���ǂ�����Ԃ�
		bool leftReleased(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize, bool eraseFlag = true) const {
			if (mMouseL.released) mMouseL.released = !eraseFlag;
			return isMouseOver(p1, p2) && mMouseL.released;
		}

		// ������W p1 �A�E�����W p2 �̋�`�͈͓��Ń}�E�X�E�{�^�����N���b�N���ꂽ���ǂ�����Ԃ�
		bool rightClicked(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize, bool eraseFlag = true) const {
			if (mMouseR.clicked) mMouseR.clicked = !eraseFlag;
			return isMouseOver(p1, p2) && mMouseR.clicked;
		}
		// �}�E�X�E�{�^����������Ă��邩�ǂ�����Ԃ�
		bool rightPressed() const {
			return mMouseR.pressed;
		}
		// ������W p1 �A�E�����W p2 �̋�`�͈͓��Ń}�E�X�E�{�^����������Ă��邩�ǂ�����Ԃ�
		bool rightPressed(Vector2<int> p1, Vector2<int> p2) const {
			return isMouseOver(p1, p2) && mMouseR.pressed;
		}
		// ������W p1 �A�E�����W p2 �̋�`�͈͓��Ń}�E�X�E�{�^���������ꂽ���ǂ�����Ԃ�
		bool rightReleased(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize, bool eraseFlag = true) const {
			if (mMouseR.clicked) mMouseR.released = !eraseFlag;
			return isMouseOver(p1, p2) && mMouseR.released;
		}

		// �}�E�X���{�^�������t���[��������Ă��邩��Ԃ�
		int leftPressedDuration() const {
			return mMouseL.pressedDuration;
		}
		// �}�E�X�E�{�^�������t���[��������Ă��邩��Ԃ�
		int rightPressedDuration() const {
			return mMouseR.pressedDuration;
		}

	private:
		static Vector2<int> mPoint;
		// �P�t���[���O�̃}�E�X���W
		static Vector2<int> mPrePoint;

		static std::vector<ButtonInfo> mButtonLog;

		// ���{�^��
		static ButtonState mMouseL;
		// �E�{�^��
		static ButtonState mMouseR;
		
		friend Manager;
	};
	extern Mouse &gMouse;
}