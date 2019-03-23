#include"Key.h"
#include<DxLib.h>

namespace Input {
	Key::Key() {
		for (int i = 0; i < 256; i++) {
			mState[i] = 0;
		}
	}
	void Key::update() {
		char buf[256];
		GetHitKeyStateAll(buf);
		for (int i = 0; i < 256; i++) {
			if (buf[i]) {
				mState[i]++;
				if (mState[i] == 0) mState[i]++;
			}
			else {
				if (mState[i] > 0) mState[i] = -1;
				else mState[i] = 0;
			}
		}
	}
	int Key::mState[256];
	Key &gKey = Key::get();
}