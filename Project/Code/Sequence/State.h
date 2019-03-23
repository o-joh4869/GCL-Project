#pragma once

namespace Sequence {
	class Manager;
	class State {
	public:
		State();
		State(const State&) = delete;
		State &operator=(const State&) = delete;
		~State();
	public:
		int backPicHandle;

		//friend Manager;
	};
}