#pragma once

namespace Input {
	class Manager {
	private:
		Manager() = delete;
		~Manager() = delete;
	public:
		static void update();
	};
}