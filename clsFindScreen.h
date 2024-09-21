#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsEmployee.h"



class clsFindScreen :protected clsScreen
{

private:

	static void printEmployInfo(clsEmployee Em)
	{
		cout << "\n\t\t\t *** Employee Info *** \n";
		cout << "\t\t________________________________________\n";
		cout << "\t\t |Full Name    : " << Em.FullName() << endl;
		cout << "\t\t |EmployeeNum  : " << Em.EmpNumber() << endl;
		cout << "\t\t |Title        : " << Em.Title << endl;
		cout << "\t\t |Age          : " << Em.Age << " Old" << endl;
		cout << "\t\t |Phone        : " << Em.Phone << endl;
		cout << "\t\t |Email        : " << Em.Email << endl;

		cout << "\t\t |Location Work: " << Em.LocationWork << endl;
		cout << "\t\t |Year Service : " << Em.YearService <<" Years" << endl;
		cout << "\t\t |Salary       : " << Em.Salary << " QD" << endl;

		cout << "\t\t |Gender       : " << Em.Gender << endl;
		cout << "\t\t |Case         : " << Em.Case << endl;
		cout << "\t\t |Number Kids  : " << Em.NumberKids << endl;
		cout << "\t\t |Province     : " << Em.Address.Province << endl;
		cout << "\t\t |City         : " << Em.Address.City << endl;
		cout << "\t\t |Locality Num : " << Em.Address.LocalityNumber << endl;
		cout << "\t\t |Alley Number : " << Em.Address.AlleyNumber << endl;
		cout << "\t\t |House Number : " << Em.Address.HouseNumber << endl;
		cout << "\t\t |Guide Point  : " << Em.Address.PointGuide << endl;
		cout << "\t\t________________________________________\n";
	}



	static void _PerformFind()
	{
		string Em_Num = clsInput::ReadString("Enter Employee Number : ");
		while (!clsEmployee::IsExist(Em_Num))
		{
			Em_Num = clsInput::ReadString("This Employee Not Exist  Enter Again : ");
		}
		clsEmployee Emp1 = clsEmployee::Find(Em_Num);
		printEmployInfo(Emp1);
 }

public:

	static void ShowFindScreen()
	{
		system("cls");
		DrawMainTitle("Find Screen ");
		_PerformFind();
	}

};

