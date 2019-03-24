#include"Mouse.h"

#include<DxLib.h>

namespace Input {

	Mouse::Mouse() {

	}

	void Mouse::update() {
		GetMousePoint(&mPoint.x, &mPoint.y);

		int tmpButton;
		Vector2<int> tmpPos;
		int tmpLogType;
		
		mButtonLog.clear();
		while (GetMouseInputLog2(&tmpButton, &tmpPos.x, &tmpPos.y, &tmpLogType) == 0) {
			mButtonLog.emplace_back( tmpButton, tmpPos, tmpLogType );
		}
		

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

	Vector2<int> Mouse::mPoint;
	std::vector<Mouse::ButtonInfo> Mouse::mButtonLog;

	Mouse &gMouse = Mouse::get();
}