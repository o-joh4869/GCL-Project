#include"State.h"
#include"Map/Manager.h"

namespace Sequence { namespace Game {

	State::State(Sequence::State *state) :
		state(state),
		map(new Map::Manager())
	{
	}

	State::~State() {
		delete map;
	}
}}