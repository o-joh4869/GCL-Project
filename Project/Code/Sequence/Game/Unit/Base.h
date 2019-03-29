#pragma once
#include"../../../Tool/Vector2.h"
#include<DxLib.h>

#include"ActionTable.h"

namespace Sequence { namespace Game {

	namespace Map {
		extern const Vector2<int> ChipSize;
	}

namespace Unit {

	class ActionTable;

	class Base {
	protected:
		Base(int agility, int BP) :
			mAgility(agility),
			mBP(BP),
			mIniBP(BP),
			grHandle(MakeScreen(Game::Map::ChipSize.x, Game::Map::ChipSize.y, TRUE)),
			mActionTable(new ActionTable(""))
		{
		}
	public:
		~Base() {
			delete mActionTable;
		}
	protected:
		Vector2<int> mPos; //マップ内での位置
		const int mAgility; //素早さ(順番決め)
		int mBP; //行動に伴って消費するやつ
		const int mIniBP; //初期BP
		ActionTable *mActionTable;

	public:
		const int grHandle; //これを描画する
		void setPos(const Vector2<int> &pos) {
			mPos = pos;
		}
		const auto &getPos() const {
			return mPos;
		}
		const auto &getActionTable() {
			return (*mActionTable);
		}
		virtual void draw() {} //MapChip同様モーションを付けるときはここに記述

		//ActionTableで保存したstringに対応して各行動の処理を書いた関数を呼び出す
		virtual void action(const std::string &actionKey, std::vector<Map::Chip*> &chip, std::vector<Unit::Base*> &unit) {}
	};

}}}