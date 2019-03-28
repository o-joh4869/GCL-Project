#pragma once
#include<vector>
#include<string>

namespace Sequence { namespace Game { namespace Unit {
	class Behavior {
	public:
		Behavior();
		virtual ~Behavior() = default;
	private:
		std::vector<Behavior*> mList;
		std::string tag;
	public:

	};
}}}