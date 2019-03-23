#pragma once

namespace Sequence {
	class Base {
	protected:
		Base() {}
	public:
		virtual Base *update() = 0;
		virtual ~Base() = default;
	};
}