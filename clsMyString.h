#pragma once
#pragma once

#include <iostream>
#include "clsDynamicArray.h";
#include "clsMyQueueArr.h"
#include <stack>
#include <queue>;

using namespace std;



class clsMyString
{

protected:
	string _Value;
	stack <string> _Undo;
	stack <string>  _Redo;


public:
	

	void setValue(string value)
	{
	
		_Undo.push(_Value);
		_Value = value;
	}
	string getValue()
	{
		return _Value;
	}
	_declspec(property(get = getValue, put = setValue)) string Value;

	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
		
		
		

	}

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Value = _Redo.top();
			_Redo.pop();
		}
		
	}

};