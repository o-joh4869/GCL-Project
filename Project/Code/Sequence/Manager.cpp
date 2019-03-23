#include"Manager.h"
#include"Base.h"
#include"State.h"
#include"Title/Manager.h"

namespace Sequence {
	Manager::Manager() : 
		mState(new State()),
		mSeq(new Title::Manager(mState))
	{}

	Manager::~Manager() {
		if (mSeq != nullptr) delete mSeq;
		delete mState;
	}

	void Manager::update() {
		Base *p = mSeq->update();
		if (mSeq != p) {
			delete mSeq;
			mSeq = p;
		}
	}
}