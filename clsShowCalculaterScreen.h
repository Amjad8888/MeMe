
#pragma once
#include <iostream>
using namespace std;
#include <cstdlib> 
#include "clsOpretions.h"

class clsShowCalculaterScreen :protected clsOpretions
{

private:
	

	float _N1;
	float _N2;
	float _PrevRsult = 0;
	int _Optype;
	float _Result =0;
	
	float ReadNumber(string massage)
	{
		float M;
		cout << massage ;
		cin >> M;
		return M;
	}


	void _printStart()
	{
		cout << "\n\t\t\t Calculator\n";
		cout << "\n\t ____________________________________________\n";
		_N1 = ReadNumber("\n\tEnter Number1 : ");
		_N2 = ReadNumber("\n\tEnter Number2 : ");
		_Optype = ReadNumber("\n\tChoose Opretion Type Add[1],Sub[2],Mul[3],Dev[4] :");
		cout << "\t ____________________________________________\n";
	}

public:

	
	
	void ShowCalculator()
	{
		char Answer = 'n';
		
		do
		{
			system("cls");

			_printStart();
			clsOpretions Result = clsOpretions(_N1, _N2, _Optype);
			_PrevRsult = _Result;
			_Result = Result.ShowResult();
			cout << "\n\t\t\t Result \n";
			cout << "\n\t ____________________________________________\n";

			cout << "\t\tOpretion Type : " << Result.NameOp() << endl;
			cout << "\t\tResult   : " << _Result << endl;
			cout << "\t\tprevResult : " << _PrevRsult << endl;
			cout << "\t ____________________________________________\n";
			cout << "\n\t\t Do you Want Countino y | n : ";
			cin >> Answer;

		} while (Answer =='Y'  || Answer =='y');
	
	}

	
};

