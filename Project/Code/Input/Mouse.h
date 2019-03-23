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

		//フレームの最初のマウスの位置を取得
		static const auto &getPoint() {
			return mPoint;
		}

		//マウスカーソルの位置を変更
		static int setPoint(const Vector2<int> &point);
		
		//GetMousInput関数の返り値と同様
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