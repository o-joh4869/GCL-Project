#include"Manager.h"
#include"Grass.h"
#include"Wall.h"

namespace Sequence { namespace Game { namespace Map {

	Manager::Manager() {

		//âºÉTÉCÉYê›íË
		const int width = 10;
		const int hight = 10;
		mChip.resize(width);
		for (int i = 0; i < mChip.size(); i++) {
			mChip[i].resize(hight);
		}

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < hight; j++) {
				if (i == 0 || j == 0 || i == width - 1 || j == hight - 1) mChip[i][j] = new Wall();
				else mChip[i][j] = new Grass();
			}
		}

		//â°640

	}

	Manager::~Manager() {

	}

	void Manager::update() {
		for (auto &i : mChip) {
			for (auto &j : i) {
				j->update();
			}
		}
	}

	void Manager::draw() const {

	}
}}}