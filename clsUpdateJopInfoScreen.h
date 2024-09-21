#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsEmployee.h"




class clsUpdateJopInfoScreen :protected clsScreen
{
	

	

private:
	static void printEmpInfo(clsEmployee Em)
	{
		cout << "\n\t\t Card Employee \n";
		cout << "\t________________________________________\n";
		cout << "\t Full Name    : " << Em.FullName() << endl;
		cout << "\t EmployeeNum  : " << Em.EmpNumber() << endl;
		cout << "\t Title        : " << Em.Title <<       endl;
		cout << "\t Location Work: " << Em.LocationWork<< endl;
		cout << "\t Year Service : " << Em.YearService << endl;
		cout << "\t Salary       : " << Em.Salary <<      endl;
		cout << "\t________________________________________\n";
	}

	static void _UpdateData(clsEmployee &E)
	{
		
		E.FirstName = clsInput::ReadString("Enter First Name : ");
		E.LastName = clsInput::ReadString("Enter Last NAme : ");
		E.Title = clsInput::ReadString("Enter Title : ");
		E.LocationWork = clsInput::ReadString("Enter Location : ");
		E.Salary = clsInput::_ReadDblNumber("Enter Salary : ");
		E.YearBegin = clsInput::_ReadNumber("Enter Year Begin : ");
		E.YearService = clsDate().Year - E.YearBegin;
	}




	static void _UpdateJopInfo()
	{
		string Emp_Num;
		char Answer = 'n';
		Emp_Num = clsInput::ReadString("please Enter Employee Number : ");
		while (!clsEmployee::IsExist(Emp_Num))
		{
			Emp_Num = clsInput::ReadString("This Emoloyee Not Exist please Enter Again please : ");
		}
		clsEmployee Emp1 = clsEmployee::Find(Emp_Num);
		printEmpInfo(Emp1);
		cout << "\n\t\t Are you Sure Update This Employee  y | n ? : ";
		cin >> Answer;
		

		if (Answer =='y' || Answer =='Y')
		{
			_UpdateData(Emp1);
			clsEmployee::ensave Save = Emp1.Save();
			if (Save == clsEmployee::ensave::enSaveSeccessflly)
			{
				printEmpInfo(Emp1);
				cout << "\n\n\t\t Update Seccessfully \n";
			}

		}

	}


public:

	static void ShoeUpdateJopInfo()
	{
		system("cls");
		DrawMainTitle("Update Jop Info ");
		_UpdateJopInfo();
	}

};

