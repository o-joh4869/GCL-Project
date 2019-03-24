#pragma once
#include"../Base.h"

namespace Sequence { namespace Game {
	class Base : public Sequence::Base {
	protected:
		Base() : 
			Sequence::Base()
		{}
	public:
		Sequence::Base *update() override { return nullptr; }
		virtual ~Base() = default;
	};
}}