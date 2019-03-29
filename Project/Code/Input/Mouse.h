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

		//フレームの最初のマウスの位置を取得
		static const auto &getPoint() {
			return mPoint;
		}

		//マウスカーソルの位置を変更
		static int setPoint(const Vector2<int> &point);

		
		// マウスボタンのログ用構造体
		struct ButtonInfo {
			int Button;
			Vector2<int> Pos;
			int LogType;

			ButtonInfo(int _button, Vector2<int> _pos, int _logType) :
				Button(_button),
				Pos(_pos),
				LogType(_logType) {}

		};
		
		// マウスボタンログの配列を取得
		inline const std::vector<ButtonInfo>& getButtonLog() {
			return mButtonLog;
		}

		// 関数オブジェクトの条件を満たす座標で、buttonTypeで指定したマウスのボタンがbuttonStateに指定した状態変化を何度したか取得する
		int getButtonChangeCount(std::function<bool(const Vector2<int>)> func, int buttonType = MOUSE_INPUT_LEFT, int buttonState = MOUSE_INPUT_LOG_DOWN) const;

		// １フレーム前からのマウス座標の差分を返す
		Vector2<int> getDelta() const {
			return mPoint - mPrePoint;
		}

		// 左上 p1 、右下 p2 の矩形の中にマウス座標が含まれているかを返す
		bool isMouseOver(Vector2<int> p1, Vector2<int> p2) const {
			return p1.x <= mPoint.x && mPoint.x < p2.x && p1.y <= mPoint.y && mPoint.y < p2.y;
		}

		// マウスボタン状況
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

		// 左上座標 p1 、右下座標 p2 の矩形範囲内でマウス左ボタンがクリックされたかどうかを返す
		bool leftClicked(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize, bool eraseFlag = true) const {
			if (mMouseL.clicked) mMouseL.clicked = !eraseFlag;
			return isMouseOver(p1, p2) && mMouseL.clicked;
		}
		// 左上座標 p1 、右下座標 p2 の矩形範囲内でマウス左ボタンが押されているかどうかを返す
		bool leftPressed(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize) const {
			return isMouseOver(p1, p2) && mMouseL.pressed;
		}
		// 左上座標 p1 、右下座標 p2 の矩形範囲内でマウス左ボタンが離されたかどうかを返す
		bool leftReleased(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize, bool eraseFlag = true) const {
			if (mMouseL.released) mMouseL.released = !eraseFlag;
			return isMouseOver(p1, p2) && mMouseL.released;
		}

		// 左上座標 p1 、右下座標 p2 の矩形範囲内でマウス右ボタンがクリックされたかどうかを返す
		bool rightClicked(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize, bool eraseFlag = true) const {
			if (mMouseR.clicked) mMouseR.clicked = !eraseFlag;
			return isMouseOver(p1, p2) && mMouseR.clicked;
		}
		// 左上座標 p1 、右下座標 p2 の矩形範囲内でマウス右ボタンが押されているかどうかを返す
		bool rightPressed(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize) const {
			return isMouseOver(p1, p2) && mMouseR.pressed;
		}
		// 左上座標 p1 、右下座標 p2 の矩形範囲内でマウス右ボタンが離されたかどうかを返す
		bool rightReleased(Vector2<int> p1 = { 0, 0 }, Vector2<int> p2 = gWindowSize, bool eraseFlag = true) const {
			if (mMouseR.clicked) mMouseR.released = !eraseFlag;
			return isMouseOver(p1, p2) && mMouseR.released;
		}

		// マウス左ボタンが何フレーム押されているかを返す
		int leftPressedDuration() const {
			return mMouseL.pressedDuration;
		}
		// マウス右ボタンが何フレーム押されているかを返す
		int rightPressedDuration() const {
			return mMouseR.pressedDuration;
		}

	private:
		static Vector2<int> mPoint;
		// １フレーム前のマウス座標
		static Vector2<int> mPrePoint;

		static std::vector<ButtonInfo> mButtonLog;

		// 左ボタン
		static ButtonState mMouseL;
		// 右ボタン
		static ButtonState mMouseR;
		
		friend Manager;
	};
	extern Mouse &gMouse;
}