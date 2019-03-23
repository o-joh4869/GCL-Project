#include"Manager.h"
#include"Key.h"

namespace Input {
	void Manager::update() {
		Key::get().update();
	}
}