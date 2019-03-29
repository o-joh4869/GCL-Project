#include"Manager.h"
#include"Grass.h"
#include"Wall.h"
#include "../../../Input/Mouse.h"
#include<DxLib.h>

namespace Sequence { namespace Game { namespace Map {

	Manager::Manager()
	{

		mChip.resize(MapSize.x);
		for (int i = 0; i < mChip.size(); i++) {
			mChip[i].resize(MapSize.y);
		}

		for (int i = 0; i < MapSize.x; i++) {
			for (int j = 0; j < MapSize.y; j++) {
				if (i == 0 || j == 0 || i == MapSize.x - 1 || j == MapSize.y - 1) mChip[i][j] = new Wall();
				else mChip[i][j] = new Grass();
			}
		}

		mMapChipGrHandle = MakeScreen(ChipSize.x * MapSize.x, ChipSize.y * MapSize.y);
		mWholeMapGrHandle = MakeScreen(ChipSize.x * MapSize.x, ChipSize.y * MapSize.y);
		SetDrawScreen(mMapChipGrHandle);
		for (int i = 0; i < mChip.size(); i++) {
			for (int j = 0; j < mChip[0].size(); j++) {
				DrawGraph(i * ChipSize.x, j * ChipSize.y, mChip[i][j]->grHandle, FALSE); //mMapChipGrHandleの更新
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
		mSetMapPos();
		mRedraw();

	}

	void Manager::draw() const {
		DrawGraph(mMapPos.x, mMapPos.y, mWholeMapGrHandle, FALSE); //仮

	}

	void Manager::mRedraw() {
		SetDrawScreen(mMapChipGrHandle);
		for (int i = 0; i < mChip.size(); i++) {
			for (int j = 0; j < mChip[0].size(); j++) {
				if (mChip[i][j]->update())
					DrawGraph(i * ChipSize.x, j * ChipSize.y, mChip[i][j]->grHandle, FALSE); //mMapChipGrHandleの更新
			}
		}
		SetDrawScreen(mWholeMapGrHandle);
		DrawGraph(0, 0, mMapChipGrHandle, FALSE); //mMapWholeGrHandleの初期化
		SetDrawScreen(DX_SCREEN_BACK);
	}

	void Manager::mSetMapPos() {
		if (Input::gMouse.leftPressed({ 0, 0 }, gWindowSizeL)) {
			mMapPos += Input::gMouse.getDelta();
			if (mMapPos.x < gWindowSizeL.x / 2 - MapSize.x * ChipSize.x - ScrollLimit.x) mMapPos.x = gWindowSizeL.x / 2 - MapSize.x * ChipSize.x - ScrollLimit.x;
			if (mMapPos.x > gWindowSizeL.x / 2 + ScrollLimit.x) mMapPos.x = gWindowSizeL.x / 2 + ScrollLimit.x;
			if (mMapPos.y < gWindowSizeL.y / 2 - MapSize.y * ChipSize.y - ScrollLimit.y) mMapPos.y = gWindowSizeL.y / 2 - MapSize.y * ChipSize.y - ScrollLimit.y;
			if (mMapPos.y > gWindowSizeL.y / 2 + ScrollLimit.y) mMapPos.y = gWindowSizeL.y / 2 + ScrollLimit.y;
		}
	}

}}}