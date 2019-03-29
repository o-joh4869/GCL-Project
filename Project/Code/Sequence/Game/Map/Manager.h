#pragma once
#include<vector>
#include<unordered_map>
#include"../../../Tool/Vector2.h"

namespace Sequence { namespace Game {
	class State;
namespace Map {
	class Chip;
	class Manager {
	private:
		Manager();
		Manager(const Manager&) = delete;
		Manager &operator=(const Manager&) = delete;
		~Manager();
	public:
		//各Chipのupdate関数を一回ずつ呼ぶ Unitとかのupdateの後がいいかも
		void update();

		void draw() const;

	private:

		void mRedraw();

		void mSetMapPos();

		std::vector<std::vector<Chip*>> mChip;
		int mMapChipGrHandle; //Chipを描画してまとめただけのグラフィック
		int mWholeMapGrHandle; //Chip以外のものもまとめたグラフィック、毎度更新

		Vector2<int> mMapPos; //マップの描写位置

	public:
		const auto getWholeMapGrHandle() {
			return mWholeMapGrHandle;
		}
		auto &getChip() {
			return mChip;
		}
		friend State;
	};
}}}