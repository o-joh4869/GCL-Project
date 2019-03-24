#include"Manager.h"

namespace Sequence { namespace Game { namespace Map {

	Manager::Manager() {

		//âºÉTÉCÉYê›íË
		const int width = 10;
		const int hight = 10;
		mChip.resize(width);
		for (int i = 0; i < mChip.size(); i++) {
			mChip[i].resize(hight);
		}


	}

	Manager::~Manager() {

	}

	void Manager::update() {

	}

	void Manager::draw() const {

	}
}}}