#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsEmployee.h"


class clsDeleteEmpScreen :protected clsScreen
{


private:
	static void printEmpInfo(clsEmployee Em)
	{
		cout << "\n\t\t Card Employee \n";
		cout << "\t________________________________________\n";
		cout << "\t Full Name    : " << Em.FullName() << endl;
		cout << "\t EmployeeNum  : " << Em.EmpNumber() << endl;
		cout << "\t Title        : " << Em.Title << endl;
		cout << "\t Location Work: " << Em.LocationWork << endl;
		cout << "\t Year Service : " << Em.YearService << endl;
		cout << "\t Salary       : " << Em.Salary << endl;
		cout << "\t________________________________________\n";
	}

	static void _PerformDelete()
	{
		char Answer;
		string Num_Emp = clsInput::ReadString("Enter Employee Number : ");
		while (!clsEmployee::IsExist(Num_Emp))
		{
			Num_Emp = clsInput::ReadString("Employee Not Exist  Enter Employee Number Again : ");
		}
		clsEmployee Emp1 = clsEmployee::Find(Num_Emp);
		printEmpInfo(Emp1);

		cout << "\n\t\t Are You Sure Delete This Employee y | n ? : ";
		cin >> Answer;
		if (Answer =='y' || Answer == 'Y')
		{
			if (Emp1.Delete()) {

				cout << "\n\t\t Delete Seccessfully \n";
				Emp1 = clsEmployee::clsEmpty();
				printEmpInfo(Emp1);
			}
			else
			{
				cout << "\n\t\t Delete Failed \n";
			}
		
		}
	}


public:

	static void ShowDeleteScreen()
	{
		system("cls");
		DrawMainTitle("Delete Screen ");
		_PerformDelete();
	}

};

