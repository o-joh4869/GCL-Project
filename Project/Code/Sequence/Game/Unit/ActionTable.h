#pragma once
#include<vector>
#include<string>

namespace Sequence { namespace Game { namespace Unit {

	class ActionTable {
	public:
		ActionTable(const std::string &header);
	private:
		const std::string mHeader; //表示する名前。呼び出しのキーにも使う。
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

		//要素を追加
		void add(const std::string &header);
	};
}}}