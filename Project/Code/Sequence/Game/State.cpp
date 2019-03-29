#include"State.h"
#include"Map/Manager.h"
#include"Unit/Manager.h"

namespace Sequence { namespace Game {

	State::State(Sequence::State *state) :
		state(state),
		map(new Map::Manager()),
		unit(new Unit::Manager(map))
	{
	}

	State::~State() {
		delete map;
		delete unit;
	}
}}