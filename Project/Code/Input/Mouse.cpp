#include"Mouse.h"

#include<DxLib.h>

namespace Input {

	Mouse::Mouse() {

	}

	void Mouse::update() {
		GetMousePoint(&mPoint.x, &mPoint.y);
		mInput = GetMouseInput();

	}

	int Mouse::setPoint(const Vector2<int> &point) {
		mPoint = point;
		return (SetMousePoint(point.x, point.y));
	}

	Vector2<int> Mouse::mPoint;
	int Mouse::mInput;

	Mouse &gMouse = Mouse::get();
}