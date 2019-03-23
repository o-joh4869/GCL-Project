#pragma once
namespace Sequence {
	class Base;
	class State;
	class Manager {
	public:
		Manager();
		Manager(const Manager&) = delete;
		Manager &operator=(const Manager&) = delete;
		~Manager();
		void update();
	private:
		State *mState;
		Base *mSeq;
	};
}