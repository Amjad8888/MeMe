#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsEmployee.h"


class clsUpdatePersonInfoScreen :protected clsScreen
{


private:

	static void printEmployInfo(clsEmployee Em)
	{
		cout << "\n\t\t Card Employee \n";
		cout << "\t________________________________________\n";
		cout << "\t Full Name    : " << Em.FullName() << endl;
		cout << "\t EmployeeNum  : " << Em.EmpNumber() << endl;
		cout << "\t Phone        : " << Em.Phone << endl;
		cout << "\t Email        : " << Em.Email << endl;
		cout << "\t Age          : " << Em.Age << endl;
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


	static void  _UpdateData(clsEmployee &E)
	{
	
		E.FirstName = clsInput::ReadString("Enter First Name : ");
		E.LastName = clsInput::ReadString("Enter Last Name : ");
		E.Phone = clsInput::ReadString("Enter Phone          : ");
		E.Email = clsInput::ReadString("Enter Email : ");
		E.YearBorn = clsInput::_ReadNumber("Enter Year Born : ");
		E.Age = clsDate().Year - E.YearBorn;
		E.Gender = clsInput::ReadString("Enter Gender : ");
		E.Case = clsInput::ReadString("Enter Case : ");
		E.NumberKids = clsInput::_ReadNumber("Enter Number Kids : ");
		E.Address.Province = clsInput::ReadString("Enter Province : ");
		E.Address.City = clsInput::ReadString("Enter City : ");
		E.Address.LocalityNumber = clsInput::_ReadNumber("Enter Locality Number : ");
		E.Address.AlleyNumber = clsInput::_ReadNumber("Enter Alley Number : ");
		E.Address.HouseNumber = clsInput::_ReadNumber("Enter House Number : ");
		E.Address.PointGuide = clsInput::ReadString("Enter Point Guide : ");


	}




	static void _UpdatePersonInfo()
	{
		string Emp_Num;
		char Answer = 'n';
		Emp_Num = clsInput::ReadString("please Enter Employee Number : ");
		while (!clsEmployee::IsExist(Emp_Num))
		{
			Emp_Num = clsInput::ReadString("This Emoloyee Not Exist please Enter Again please : ");
		}
		clsEmployee Emp1 = clsEmployee::Find(Emp_Num);
		printEmployInfo(Emp1);
		cout << "\n\t\t Are you Sure Update This Employee  y | n ? : ";
		cin >> Answer;
		

		if (Answer == 'y' || Answer == 'Y')
		{
			_UpdateData(Emp1);
			clsEmployee::ensave Save = Emp1.Save();
			if (Save == clsEmployee::ensave::enSaveSeccessflly)
			{
				printEmployInfo(Emp1);
				cout << "\n\n\t\t Update Seccessfully \n";
			}

		}

	}

public:

	static void ShowUpdatePersonInfo()
	{
		system("cls");
		DrawMainTitle("Update Person Info ");
		_UpdatePersonInfo();
	}

};

