#pragma once
namespace Sequence { namespace Game { namespace Map {

	//これを継承して特殊なマスを作成する
	//しばらくは特殊なマスは必要なさそうなのでこのクラスを直接用いる

	class Chip {
	public:
		Chip(bool passFlag = true) :
			mPassFlag(passFlag)
		{}
		virtual void update() {}
		virtual void draw() const {}
		virtual ~Chip() = default;

	private:
		bool mPassFlag; //Unitが通れるかどうか
	
	public:
		bool getPassFlag() {
			return mPassFlag;
		}
	};
}}}