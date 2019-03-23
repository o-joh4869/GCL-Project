#pragma once
namespace Tool {
	template<class T>
	class SingletonTemplate {
	public:
		SingletonTemplate()
		{
			if (mExistFlag) throw "SingletonTemplate / constructor error";
			else mExistFlag = true;
		}
		~SingletonTemplate() {
			if (mExistFlag) mExistFlag = false;
		}
		SingletonTemplate(const SingletonTemplate&) = delete;
		SingletonTemplate &operator=(const SingletonTemplate&) = delete;
	private:
		static bool mExistFlag;
	};

	template<class T>
	bool SingletonTemplate<T>::mExistFlag = false;
}