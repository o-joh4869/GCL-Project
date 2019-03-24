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

	private:
		static Vector2<int> mPoint;

		static std::vector<ButtonInfo> mButtonLog;
		
		friend Manager;
	};
	extern Mouse &gMouse;
}