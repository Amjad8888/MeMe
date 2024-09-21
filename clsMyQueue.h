#pragma once
#include "clsDblLinkedList.h"
#include <iostream>
using namespace std;

template <class T>


class MyQueue
{

protected:

	clsDblLinkedList <T> _MyList;


public:

	void push(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void print()
	{
		_MyList.print();
	}

	T  Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return GetItem(0);
	}

	T back()
	{
		return GetItem(Size());
	}

	void pop()
	{
		_MyList.DeleteFirst();
		
	}

	T GetItem(T index)
	{
		return _MyList.GetItem(index);
	}

	void Reverse()
	{
		_MyList.ReVerse();
	}

	void UpdateItem(T index, T value)
	{
		_MyList.UpdateNode(index, value);
	}

	void InsertAfter(T index, T value)
	{
		_MyList.InsertAfter(index, value);
	}
	void InsetAtFirst(T value)
	{
		_MyList.InsertAtBegging(value);
	}

	void InsetAtEnd(T value)
	{
		_MyList.InsertAtEnd(value);
	}
};


