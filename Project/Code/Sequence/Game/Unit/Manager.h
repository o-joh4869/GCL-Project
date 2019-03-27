#pragma once
#include<vector>

namespace Sequence { namespace Game {
	class State;
namespace Unit {

	class Base;

	class Manager {
	private:
		Manager();
		Manager(const Manager&) = delete;
		Manager &operator=(const Manager&) = delete;
		~Manager();
	public:
		void update();
		void draw() const;
		void redraw();

	private:
		std::vector<Base*> unit;

		friend State;
	};

}}}