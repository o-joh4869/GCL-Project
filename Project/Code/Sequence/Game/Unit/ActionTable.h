#pragma once
#include<vector>
#include<string>

namespace Sequence { namespace Game { namespace Unit {

	class ActionTable {
	public:
		ActionTable(const std::string &header);
	private:
		const std::string mHeader; //�\�����閼�O�B�Ăяo���̃L�[�ɂ��g���B
		std::vector<ActionTable> mList;
	public:
		const auto &getHeader() {
			return mHeader;
		}
		const auto &getList() {
			return mList;
		}
		auto &operator[](int o) {
			return mList[o];
		}

		//�v�f��ǉ�
		void add(const std::string &header);
	};
}}}