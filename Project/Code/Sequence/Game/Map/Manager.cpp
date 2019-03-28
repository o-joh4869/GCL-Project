#include"Manager.h"
#include"Grass.h"
#include"Wall.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Map {

	Manager::Manager()
	{

		//仮サイズ設定
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

		mMapChipGrHandle = MakeScreen(32 * width, 32 * hight);
		mWholeMapGrHandle = MakeScreen(32 * width, 32 * hight);
		SetDrawScreen(mMapChipGrHandle);
		for (int i = 0; i < mChip.size(); i++) {
			for (int j = 0; j < mChip[0].size(); j++) {
				DrawGraph(i * 32, j * 32, mChip[i][j]->grHandle, FALSE); //mMapChipGrHandleの更新
			}
		}
		SetDrawScreen(mWholeMapGrHandle);
		DrawGraph(0, 0, mMapChipGrHandle, FALSE); //mMapWholeGrHandleの初期化
		SetDrawScreen(DX_SCREEN_BACK);

	}

	Manager::~Manager() {
		DeleteGraph(mMapChipGrHandle);
		DeleteGraph(mWholeMapGrHandle);
	}

	void Manager::update() {
		mRedraw();

	}

	void Manager::draw() const {
		DrawGraph(10, 10, mWholeMapGrHandle, FALSE); //仮

	}

	void Manager::mRedraw() {
		SetDrawScreen(mMapChipGrHandle);
		for (int i = 0; i < mChip.size(); i++) {
			for (int j = 0; j < mChip[0].size(); j++) {
				if (mChip[i][j]->update())
					DrawGraph(i * 32, j * 32, mChip[i][j]->grHandle, FALSE); //mMapChipGrHandleの更新
			}
		}
		SetDrawScreen(mWholeMapGrHandle);
		DrawGraph(0, 0, mMapChipGrHandle, FALSE); //mMapWholeGrHandleの初期化
		SetDrawScreen(DX_SCREEN_BACK);
	}

}}}