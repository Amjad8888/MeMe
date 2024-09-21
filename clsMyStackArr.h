#pragma once

#include <iostream>
#include "clsDynamicArray.h";
#include "clsMyQueueArr.h"
using namespace std;

template <class T>

class clsMyStackArr : public clsMyQueueArr<T>
{

public:

	void push(T value)
	{
		clsMyQueueArr<int>::InsertAtFront(value);

	}



	void pop()
	{
		clsMyQueueArr<int>::pop();
	}

	T Top()
	{
		return clsMyQueueArr<int>::front();
	}

	T Bottom()
	{
		return clsMyQueueArr<int>::back();
	}


};

