 ///
 /// @file    singleton_template.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-20 04:56:40
 ///

//单例模式的模板实现

#include <iostream>
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class Singleton
{
private:
	class AutoRelease
	{
	public:
		AutoRelease()  //class AutoRelease constructor
		{
			cout << "AutoRelease()" << endl;
		}
		~AutoRelease()  //class AutoRelease destructor
		{
			cout << "~AutoRelease()" << endl;
			if(_pInstance != NULL)
				delete _pInstance;
		}
	};
public:
	static T* getInstance();

private:
	Singleton();  //constructor
	~Singleton();  //destructor

private:
	static T* _pInstance;
	static AutoRelease _autoRelease;
	
};

template <typename T>
T* Singleton<T>::_pInstance = getInstance();  //线程安全，改成NULL,就不安全了

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;

template <typename T>
T* Singleton<T>::getInstance()
{
	_autoRelease;  //实例化，不加这条语句，不会执行析构函数，因为不调用的话，模板就不生成相应的代码
	if(_pInstance == NULL)
		_pInstance = new T;
	return _pInstance;
}


int main()
{
	int* p1 = Singleton<int>::getInstance();
	int* p2 = Singleton<int>::getInstance();

	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	
	char* p3 = Singleton<char>::getInstance();
	char* p4 = Singleton<char>::getInstance();

	printf("p3 = %p\n", p3);
	printf("p4 = %p\n", p4);

	return 0;
}

