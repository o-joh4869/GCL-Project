#pragma once
#include<list>

namespace Time {
	constexpr unsigned int FrameRate = 60;
	class Manager {
	public:
		//�R���X�g���N�^��
		Manager();
		Manager(Manager *);
		Manager(const Manager &) = delete; //�R�s�[�֎~
		Manager &operator= (const Manager &) = delete; //�R�s�[�֎~
		~Manager();

	private:
		//private�����o�ϐ�
		const unsigned int &m_baseNow; //��̊K�w�̎���
		unsigned int m_ini; //���������̏�̊K�w�̎���
		unsigned int m_now; //������������̎���(ms)
		unsigned int m_dur; //�O�̃t���[���Ƃ̎��ԍ�(ms)
		unsigned int m_stopFrame; //stop�֐��ɂ���̊K�w�Ƃ̃Y��(F)
		unsigned int m_leftStopFrame; //stop�֐��Ŏw�肳�ꂽ�l(F)��ۑ����邾���B�ēx���Ԃ�i�ߎn�߂���0�ɂȂ�

		//�����o�֐�
		void m_update(); //m_now����ύX
	public:
		void stop(const unsigned int &stopFrame); //m_leftStopFrame����������
		void stop(); //start����܂�stop
		void start(); //stop����Ă����̂�stopFrame�ɂ�����炸���̒n�_���瓮����
		void init(); //��̊K�w�̏��������ă����o�����ׂď�����Ԃɖ߂�
		float getDur() const; //m_dur���t���[�������Z��������
		double getNow() const; //m_now���t���[�������Z�������� m_now���傫���Ȃ�ƌ덷���傫���Ȃ�̂Œ���
		unsigned int getNowCount() const; //���݂̐�Ύ��Ԃ��擾

	public:
		//static�ȃ����o�֐�
		static void update();

	private:
		//static�ȃ����o�ϐ�
		static unsigned int m_g_now;
		static const unsigned int m_g_ini;
		static unsigned int m_g_dur;

		//update�֐��֘A
		static std::list<Time::Manager*> mList;
		std::list<Time::Manager*>::iterator mItr;

	public:
		//operator
		bool operator==(const unsigned int &o) const;
		bool operator!=(const unsigned int &o) const {
			return !((*this) == o);
		}
		bool operator>(const unsigned int &o) const;
		bool operator<(const unsigned int &o) const;
		bool operator>=(const unsigned int &o) const {
			return !((*this) < o);
		}
		bool operator<=(const unsigned int &o) const {
			return !((*this) > o);
		}
	};
}

inline bool operator==(const unsigned int &o1, const Time::Manager &o2) {
	return (o2 == o1);
}
inline bool operator!=(const unsigned int &o1, const Time::Manager &o2) {
	return (o2 != o1);
}
inline bool operator>(const unsigned int &o1, const Time::Manager &o2) {
	return (o2 < o1);
}
inline bool operator<(const unsigned int &o1, const Time::Manager &o2) {
	return (o2 > o1);
}
inline bool operator>=(const unsigned int &o1, const Time::Manager &o2) {
	return (o2 <= o1);
}
inline bool operator<=(const unsigned int &o1, const Time::Manager &o2) {
	return (o2 >= o1);
}
