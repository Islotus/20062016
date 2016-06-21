 ///
 /// @file    que_tempalet.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-20 05:42:48
 ///

//队列模板 的实现
//约定：(循环队列)
//初始化时front = rear = 0;
//队空时：front = rear
//队满时：(rear + 1)%maxsize = front

#include <iostream>
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;


template <typename T>
class Queue
{
public:
	Queue();  //无参构造函数
	Queue(int cap);  //有参构造函数
	~Queue();
	bool enqueue(T ch);  //入队
	bool dequeue();  //出队
	bool isempty();  //队是否为空
	bool isfull();  //队是否为满

private:  //_capacity和_queuearr的初始化顺序不能颠倒，因为_queuearr要用到_capacity.
	//如果不给_capacity初值，默认为1，这样会产生内存泄露
	int _capacity;   //
		//因为用数组实现，所以给定一个队列大小，也可以用链表实现，以后再说
	T* _queuearr;  //指针
	int _headpos;  //队头位置
	int _tailpos;  //队尾位置
};
template <typename T>
Queue<T>::Queue()  //实现无参构造函数
:_capacity(5)
,_queuearr(new T [_capacity])
,_headpos(0)
,_tailpos(0)
{
	cout << "Queue()" << endl;
}

template <typename T>
Queue<T>::Queue(int cap)  //实现有参构造函数
:_capacity(cap)
,_queuearr(new T [_capacity])
,_headpos(0)
,_tailpos(0)
{
	printf("first:_queuearr = %p\n",_queuearr);
	cout << "Queue(int)" << endl;
}

template <typename T>
Queue<T>::~Queue()  //析构函数
{
	
	printf("second:_queuearr = %p\n",_queuearr);
	delete [] _queuearr;
	cout << "~Queue()" << endl;
}

template <typename T>
bool Queue<T>::enqueue(T ch)  //实现入队
{
	if(!isfull())  //队不满
	{
		_queuearr[_tailpos] = ch;  //先入队
		_tailpos = (_tailpos + 1)%_capacity;
//		++_tailpos;  //队尾再向后移动一位
//		cout << "enqueue(char)" << endl;
		return true;
	}
	else  //队满
	{
		cout << "queue is full" << endl;
		return false;
	}
	
}

template <typename T>
bool Queue<T>::dequeue()  //实现出队
{
	if(!isempty())  //队不空
	{
		cout << _queuearr[_headpos];  //先出队
		_headpos = (_headpos + 1)%_capacity;
//		++_headpos;  //再后移一位
//		cout << "dequeue()" << endl;
		return true;
	}
	else  //队空
	{
		cout << "queue is empty" << endl;
		return false;
	}
}
 
template <typename T>
bool Queue<T>::isempty()  //队列是否为空
{
	return (_headpos == _tailpos) ? true : false;
}

template <typename T>
bool Queue<T>::isfull()  //队列是否为满
{
	return ((_tailpos + 1)%_capacity == _headpos) ? true : false;
}

int main()
{
	int i = 0;
#if 1
//char型
	Queue<char> que(5);
	for(char ch = 'a' ;i < 4; ++i)  //入队
	{
		que.enqueue(ch);
		ch = ch +1;
	}
	for(i = 0; i < 5; ++i)  //出队
	{
		que.dequeue();
		cout << " ";
//		cout << endl;
	}
	cout << endl;

	for(char ch = 'a',i = 0 ;i < 4; ++i)
	{
		que.enqueue(ch);
		ch = ch +1;
	}
	que.enqueue('e');
#endif
//int型
	Queue<int> que1(5);
	 i = 0;
	for(;i < 4; ++i)  //入队
	{
		que1.enqueue(i);
	}
	for(i = 0; i < 5; ++i)  //出队
	{
		que1.dequeue();
		cout << " ";
//		cout << endl;
	}
	cout << endl;
	for(i = 0 ;i < 4; ++i)
	{
		que1.enqueue(i);
	}
	que1.enqueue(1);


	return 0;
}
