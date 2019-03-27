#include"Manager.h"
#include"Grass.h"
#include"Wall.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Map {

	Manager::Manager()
	{

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

		mGrHandle = MakeScreen(32 * width, 32 * hight);

		redraw();

	}

	Manager::~Manager() {
		DeleteGraph(mGrHandle);
	}

	void Manager::update() {
		bool flag = false;
		for (auto &i : mChip) {
			for (auto &j : i) {
				flag = flag || j->update();
			}
		}
		if (flag) redraw();
	}

	void Manager::draw() const {
		DrawGraph(10, 10, mGrHandle, FALSE); //âº
	}

	void Manager::redraw() const {
		SetDrawScreen(mGrHandle);
		for (int i = 0; i < mChip.size(); i++) {
			for (int j = 0; j < mChip[0].size(); j++) {
				DrawGraph(i * 32, j * 32, mChip[i][j]->grHandle, FALSE);
			}
		}
		SetDrawScreen(DX_SCREEN_BACK);
	}

}}}