#pragma once

namespace Input {
	class Manager;
	class Key {
	private:
		Key();
		Key(const Key&) = delete;
		Key &operator=(const Key&) = delete;
		~Key() = default;

		static void update();
		static int mState[256];
	public:
		static Key &get() {
			static Key ins;
			return ins;
		}
		const int &operator[](const int &o) const {
			return mState[o];
		}

		friend Manager;
	};
	extern Key &gKey;
}