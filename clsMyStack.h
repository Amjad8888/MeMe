#pragma once
#include "clsDblLinkedList.h"
#include "clsMyQueue.h"
#include <iostream>
using namespace std;

template <class T>


class clsMyStack : public MyQueue <T>
{

protected:
	

public:

	void push(T value)
	{
		MyQueue<int> ::InsetAtFirst(value);
	}

	void pop()
	{
		MyQueue<int>::pop();
	}

	void print()
	{
		MyQueue<int>::print();
	}
	T Size()
	{
		return MyQueue<int>::Size();
	}

	T top()
	{
		return MyQueue<int>::front();
	}

	T Bottom()
	{
		return MyQueue<int>::GetItem(Size()-1);
	}

	void Reverse()
	{
		MyQueue<int>::Reverse();
	}

	void Update(T index,T value)
	{
		MyQueue<int>::UpdateItem(index,value);
	}

	T GetItem(T index)
	{
		return MyQueue<int>::GetItem(index);
	}

	void InsertAfter(T index, T value)
	{
		MyQueue<int>::InsertAfter(index, value);
	}

	void InsertAtFirst(T value)
	{
		MyQueue<int>::InsetAtFirst(value);
}
};

