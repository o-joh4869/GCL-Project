#include"State.h"

namespace Sequence { namespace Game {

	State::State(Sequence::State *state) :
		state(state)
	{
	}

	State::~State() {

	}
}}