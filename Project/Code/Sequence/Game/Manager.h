#pragma once
#include"../Base.h"

namespace Sequence {
	class State;
namespace Game {
	class State;
	class Manager : public Sequence::Base {
	public:
		Manager(Sequence::State *state);
		Manager(const Manager&) = delete;
		Manager &operator=(const Manager&) = delete;
		~Manager();
		Sequence::Base *update() override;
	private:
		State *mState;
		Sequence::Base *mSeq;
	};
}}
