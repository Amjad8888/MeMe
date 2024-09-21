#pragma once

#include <iostream>
#include "clsDynamicArray.h";

using namespace std;

template <class T>



class clsMyQueueArr
{



protected:

	clsDynamicArray <T> _MyArr;

public:


	void push(T item)
	{
		 _MyArr.InsertAtEnd(item);
	}

	void print()
	{
		_MyArr.print();
	}

	T front()
	{
		return _MyArr.GetItem(0);
	}

	T back()
	{
		return _MyArr.GetItem(size()-1);
	}

	void pop()
	{
		_MyArr.DeleteFirstItem();
	}

	T size()
	{
		return _MyArr.Size();
	}

	bool IsEmpty()
	{
		return _MyArr.IsEmpty();
	}

	T GetItem(T index)
	{
		return _MyArr.GetItem(index);
	}

	void ReSize(T NewSize)
	{
		_MyArr.ReSize(NewSize);
	}
	

	void AfterUpdate(T index, T value)
	{
		_MyArr.setItem(index, value);
	}

	void InsertAfter(T index, T value)
	{
		_MyArr.InsertAfter(index, value);
		
	}


	void InsertAtBegining(T value)
	{
		_MyArr.InsertAtBegining(value);
		
	}
	void InsertAt(T index, T value)
	{
		_MyArr.InsertAt(index, value);
	}

	void InsertAtEnd(T  value)
	{
		_MyArr.InsertAtEnd(value);
	
	}

	void InsertBefore(T index, T value)
	{
		_MyArr.InsertBefore(index,value);
	}

	void Reverse()
	{
		_MyArr.Reverse();
	}

	void ClearQ()
	{
		
		_MyArr.Clear();
		
	}

};

