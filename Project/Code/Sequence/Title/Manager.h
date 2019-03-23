#pragma once
#include"../Base.h"

namespace Sequence {
	class State;
namespace Title {
	class Manager : public Sequence::Base {
	public:
		Manager(Sequence::State *state);
		Manager(const Manager&) = delete;
		Manager &operator=(const Manager&) = delete;
		virtual ~Manager();
		virtual Sequence::Base *update() override;
	private:
		Sequence::State *mState;
		int mLogoHandle;
	};
}}