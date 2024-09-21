#pragma once
#include <iostream>
#include "clsDate.h";
#include <fstream>
#include "clsInput.h"
#include "clsScreen.h"

#include "clsEmployee.h"
#include <string>

using namespace std;

class clsAddNewScreen : protected clsScreen
{

private:
	
static	void _ReadEmployeeInfo(clsEmployee &E)
	{
		E.FirstName = clsInput::ReadString("Enter First Name : ");
		E.LastName = clsInput::ReadString("Enter Last Name   : ");
		E.Phone = clsInput::ReadString("Enter Phone          : ");
		E.Email = clsInput::ReadString("Enter Email : ");

		E.Title = clsInput::ReadString("Enter Title          : ");
		E.LocationWork = clsInput::ReadString("Enter Work Place : ");
		E.Salary = clsInput::_ReadDblNumber("Enter Salary : ");
		E.YearBegin = clsInput::_ReadNumber("Enter Year Employment : ");
		E.YearService = clsDate().Year - E.YearBegin;

		E.YearBorn = clsInput::_ReadNumber("Enter Year Born: ");
		E.Age = clsDate().Year - E.YearBorn;
		E.Gender = clsInput::ReadString("Enter Gender : ");
		E.Case = clsInput::ReadString("Enter Case : ");
		E.NumberKids = clsInput::_ReadNumber("Enter Number Kids : ");
		E.Address.Province = clsInput::ReadString("Enter Province : ");
		E.Address.City = clsInput::ReadString("Enter City : ");
		E.Address.LocalityNumber = clsInput::_ReadNumber("Enter Locality Number : ");
		E.Address.AlleyNumber = clsInput::_ReadNumber("Enter Alley Number : ");
		E.Address.HouseNumber = clsInput::_ReadNumber("Enter Number House : ");
		E.Address.PointGuide = clsInput::ReadString("enter Point Guide : ");
	}





static void printEmployInfo(clsEmployee Em)
{
	cout << "\n\t\t Card Employee \n";
	cout << "\t________________________________________\n";
	cout << "\t Full Name    : " << Em.FullName() << endl;
	cout << "\t EmployeeNum  : " << Em.EmpNumber()<<endl;
	cout << "\t Phone        : " << Em.Phone << endl;
	cout << "\t Email        : " << Em.Email << endl;

	cout << "\t Title        : " << Em.Title << endl;
	cout << "\t Age          : " << Em.Age << endl;
	cout << "\t Location Work: " << Em.LocationWork << endl;
	cout << "\t Year Service : " << Em.YearService << endl;
	cout << "\t Salary       : " << Em.Salary << endl;

	cout << "\t Gender       : " << Em.Gender << endl;
	cout << "\t Case         : " << Em.Case << endl;
	cout << "\t Number Kids  : " << Em.NumberKids << endl;
	cout << "\t Province     : " << Em.Address.Province << endl;
	cout << "\t City         : " << Em.Address.City << endl;
	cout << "\t Locality Num : " << Em.Address.LocalityNumber << endl;
	cout << "\t Alley Number : " << Em.Address.AlleyNumber << endl;
	cout << "\t House Number : " << Em.Address.HouseNumber << endl;
	cout << "\t Guide Point  : " << Em.Address.PointGuide << endl;
	cout << "\t________________________________________\n";
}

	static void _PerformAddNew()
	{
		string EmpNumber = clsInput::ReadString("please Enter Employee Number : ");
		while (clsEmployee::IsExist(EmpNumber))
		{
			EmpNumber = clsInput::ReadString("Sorrey This Employ Already Exist Enter Again  : ");
		}
		clsEmployee Employee1 = clsEmployee::AddModeEmployee(EmpNumber);

		_ReadEmployeeInfo(Employee1);
		printEmployInfo(Employee1);

		clsEmployee::ensave Save = Employee1.Save();
		if (Save ==clsEmployee::ensave::enSaveSeccessflly)
		{
			cout << "\n\t\t Adding Seccefully \n";
		}
		else
		{
			cout << "\n\t Adding Failed\n";
		}
	}




public:

	static void ShowAddNewScreen()
	{
		DrawMainTitle("Add New Screen ");
		_PerformAddNew();
	}


};

