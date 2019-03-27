#pragma once
#include<vector>

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
		void redraw() const; //各Chipのグラフィックをこのクラスのグラフィックに反映
		
	private:
		std::vector<std::vector<Chip*>> mChip;
		int mGrHandle; //マップ全体を描画するグラフィックへのハンドル
		
		friend State;
	};
}}}