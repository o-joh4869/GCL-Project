#include"Mouse.h"

#include<DxLib.h>

namespace Input {

	Mouse::Mouse() {

	}

	void Mouse::update() {
		mPrePoint = mPoint;
		GetMousePoint(&mPoint.x, &mPoint.y);

		int tmpButton;
		Vector2<int> tmpPos;
		int tmpLogType;
		
		mButtonLog.clear();
		while (GetMouseInputLog2(&tmpButton, &tmpPos.x, &tmpPos.y, &tmpLogType) == 0) {
			mButtonLog.emplace_back( tmpButton, tmpPos, tmpLogType );
		}

		mMouseL.update();
		mMouseR.update();
		

	}

	int Mouse::setPoint(const Vector2<int> &point) {
		mPoint = point;
		return (SetMousePoint(point.x, point.y));
	}
	
	int Mouse::getButtonChangeCount(std::function<bool(const Vector2<int>)> func, int buttonType, int buttonState) const {
		int buttonCnt = 0;
		for (unsigned int i = 0; i < mButtonLog.size(); i++) {
			if (mButtonLog[i].Button == buttonType && mButtonLog[i].LogType == buttonState && func(mButtonLog[i].Pos)) {
				buttonCnt++;
			}
		}
		return buttonCnt;
	}

	void Mouse::ButtonState::update() {

		clicked = false;
		released = false;

		if (pressedDuration > 0) pressedDuration++;

		auto range = [](const Vector2<int> m) ->bool {
			return true;
		};

		int downNum = get().getButtonChangeCount(range, buttonType, MOUSE_INPUT_LOG_DOWN);
		int upNum = get().getButtonChangeCount(range, buttonType, MOUSE_INPUT_LOG_UP);

		if (downNum > 0) pressedDuration = 1;
		if (upNum > 0) {
			if (pressedDuration > 0) {
				clicked = true;
			}
			released = true;
			pressedDuration = 0;
		}

		pressed = pressedDuration > 0;

	}

	Vector2<int> Mouse::mPoint;
	Vector2<int> Mouse::mPrePoint;
	std::vector<Mouse::ButtonInfo> Mouse::mButtonLog;

	Mouse::ButtonState Mouse::mMouseL(MOUSE_INPUT_LEFT);
	Mouse::ButtonState Mouse::mMouseR(MOUSE_INPUT_RIGHT);

	Mouse &gMouse = Mouse::get();
}