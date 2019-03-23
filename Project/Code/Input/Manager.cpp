#include"Manager.h"
#include"Key.h"
#include"Mouse.h"

namespace Input {
	void Manager::update() {
		Key::get().update();
		Mouse::get().update();
	}
}