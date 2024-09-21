
#pragma once
#include <iostream>
using namespace std;
#include <cstdlib> 



class clsOpretions
{

	enum eOpretions
	{
		Add =1, Sub = 2, Multyplay = 3, Devided =4
	};

protected:
	float  _N1;
	float _N2;


	eOpretions _OPtype;

public:

	clsOpretions()
	{

	}
	clsOpretions(float N1,float N2, int OpType)
	{
		_N1 = N1;
		_N2 = N2;
		_OPtype = (eOpretions)OpType;
	}

	
	
 	float ShowResult()
	{
		
		switch (_OPtype)
		{
		case clsOpretions::Add:
			return _N1 + _N2;
			break;
		case clsOpretions::Sub:
			return _N1 > _N2 ? _N1 - _N2 : _N2 - _N1;
			break;
		case clsOpretions::Multyplay:
			_N1 == 0 ? _N1 = 1 : _N1;
			_N2 == 0 ? _N2 = 1 : _N2;
			return (float)_N1 * _N2;
		

			break;
		case clsOpretions::Devided:
			return  (float)_N1 / _N2;
			break;
		default:
			break;
		}

	}

	string NameOp()
	{
		switch (_OPtype)
		{
		case clsOpretions::Add:
			return "Adding ";
			break;
		case clsOpretions::Sub:
			return "Subtruct";

			break;
		case clsOpretions::Multyplay:
			return "Mul";
			break;
		case clsOpretions::Devided:
			return "Devide";
			break;
		default:
			break;
		}
	}

};

