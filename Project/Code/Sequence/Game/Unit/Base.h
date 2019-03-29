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
		Vector2<int> mPos; //�}�b�v���ł̈ʒu
		const int mAgility; //�f����(���Ԍ���)
		int mBP; //�s���ɔ����ď������
		const int mIniBP; //����BP
		ActionTable *mActionTable;

	public:
		const int grHandle; //�����`�悷��
		void setPos(const Vector2<int> &pos) {
			mPos = pos;
		}
		const auto &getPos() const {
			return mPos;
		}
		const auto &getActionTable() {
			return (*mActionTable);
		}
		virtual void draw() {} //MapChip���l���[�V������t����Ƃ��͂����ɋL�q

		//ActionTable�ŕۑ�����string�ɑΉ����Ċe�s���̏������������֐����Ăяo��
		virtual void action(const std::string &actionKey, std::vector<Map::Chip*> &chip, std::vector<Unit::Base*> &unit) {}
	};

}}}