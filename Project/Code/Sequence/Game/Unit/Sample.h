#pragma once
#include"Base.h"

namespace Sequence { namespace Game { namespace Unit {
	class Sample : public Base {
	public:
		Sample();
		virtual ~Sample() = default;

		virtual void update() override;

	};
}}}