#include"Manager.h"
#include"State.h"
#include"Play/Manager.h"
#include"Base.h"
#include<DxLib.h>


namespace Sequence { namespace Game {

	Manager::Manager(Sequence::State *state) :
		mState(new State(state)),
		mSeq(new Play::Manager(mState))
	{

	}
	Manager::~Manager() {
		delete mState;
	}
	Sequence::Base *Manager::update() {

		Sequence::Base *p = mSeq->update();
		if (mSeq != p) {
			delete mSeq;
			mSeq = p;
			if(dynamic_cast<Sequence::Game::Base*>(p) == nullptr) return p;
		}
		return this;
	}
}}