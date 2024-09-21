#pragma once
#include "clsMyQueue.h"
#include "clsDblLinkedList.h"
#include <iostream>
#include "clsMyStack.h"
using namespace std;


template <class T>

class clsDynamicArray
{
protected:

	T _Size;
	T* TemArry;

public:

	T* OriginalArray ;
	clsDynamicArray(T size = 0)
	{

		if (size<0)
		{
			_Size = 0;
		}
		_Size = size;
		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete []OriginalArray;
	}


	bool setItem(T index, T value)
	{
		if (index <0)
		{
			return false;
		}

		OriginalArray[index] = value;
		return true;
	}

	T Size()
	{
		return _Size;
	}


	bool IsEmpty()
	{
		return Size() == 0;
	}

	void print()
	{
		for (int i = 0; i < Size(); i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
	}


	void ReSize(T NewSize)
	{
		if (NewSize <0)
		{
			return;
		}

		if (NewSize<_Size)
		{
			_Size = NewSize;
		}
		TemArry = new T[NewSize];
		for (int i = 0; i < _Size; i++)
		{
			TemArry[i] = OriginalArray[i];
		}
		delete OriginalArray;
		OriginalArray = TemArry;
		_Size = NewSize;

	}

	T GetItem(T index )
	{
		return OriginalArray[index];
	}

	void Reverse()
	{ 
		int counter = 0;
		TemArry = new T[_Size];
		for (int i = Size(); i >0; i--)
		{
			TemArry[counter++] = OriginalArray[i-1];
		}
		delete[]OriginalArray;
		OriginalArray = TemArry;
	}

	void Clear()
	{
	
		_Size = 0;
		TemArry = new T[0];
		delete[]OriginalArray;
		OriginalArray = TemArry;
	}

	bool DeleteItem(T index)
	{
		if (index < 0)
		{
			return false;
		}
		_Size--;
		TemArry = new T[_Size];
		
		for (int i = 0; i <= index-1; i++)
		{
			TemArry[i] = OriginalArray[i];
		}

		for (int i = index+1; i < _Size+1; i++)
		{
			TemArry[i-1] = OriginalArray[i];
				//index++;
		}
		delete[] OriginalArray;
		OriginalArray = TemArry;
		return true;
		
	}

	bool  DeleteFirstItem()
	{
		return DeleteItem(0);
	}

	bool DeleteLastItem()
	{
		return DeleteItem(_Size - 1);
	}

	T Find(T value)
	{
		int counter = 0;
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value)
			{
				return i;
			}
			
		}
		return -1;
	}

	bool DeleteByItemValue(T value)
	{
		int index = Find(value);
		if (index ==-1)
		{
			return false;
		}
		else
		{
			return DeleteItem(index);
		}
	}

	bool InsertAt(T index, T value)
	{
		if (index <0)
		{
			return false;
		}
		_Size++;

		TemArry = new T[_Size];
		for (int i = 0; i <= index-1; i++)
		{
			TemArry[i] = OriginalArray[i];
		}
		TemArry[index] = value;
		for (int i = index+1; i < _Size; i++)
		{
			TemArry[i] = OriginalArray[i-1];
		}
		delete[] OriginalArray;
		 OriginalArray = TemArry  ;
		return true;
	}


	bool InsertAtBegining(T value)
	{
		return InsertAt(0, value);
	}

	bool InsertAfter(T index, T value)
	{
		if (index >=_Size)
		{
			return InsertAt(_Size - 1, value);
		}
		else
		{
			return InsertAt(index + 1, value);
		}
		
	}

	bool InsertBefore(T index, T value)
	{

		if (index < 1)
		{
			return InsertAt(0, value);
		}
		return InsertAt(index - 1, value);
	}

	bool InsertAtEnd(T value)
	{
		return InsertAt(_Size,value);
	}
};

