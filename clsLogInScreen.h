#pragma once
#include "clsPerson.h"
#include <iostream>
#include "clsDate.h";
#include <fstream>
#include "clsInput.h"
#include "clsEmployee.h"
#include "clsLoginLogOut.h"
#include "clsScreen.h"
using namespace std;

class clsLogInScreen :protected clsScreen
{


private:
	
	static void ReadDataLogin(clsLoginLogOut &L, clsEmployee E)
	{
		L.FirstName = E.FirstName;
		L.LastName = E.LastName;
		L.Title = E.Title;
		L.LocationWork = E.LocationWork;
		L.LogIn = clsDate::GetSystemDateTimeString();
	}

	static void _performLogin()
	{
		string NumEmp = clsInput::ReadString("Enter Employee Number : ");
		while (!clsEmployee::IsExist(NumEmp))
		{
			NumEmp = clsInput::ReadString("Not Exist Enter Another Employee Number : ");
		}

		clsEmployee F1 = clsEmployee::Find(NumEmp);
		
		
		clsLoginLogOut L = clsLoginLogOut::LoginMode(NumEmp);
		ReadDataLogin(L, F1);
	
		clsLoginLogOut::ensaveL Save =  L.Save();
		if (Save == clsLoginLogOut::SaveLogin)
		{
			cout << "\n \t Login seccessfully \n";
		}


	}

public:

	static void ShowLoginScreen()
	{
		DrawMainTitle("Login Screen");
		_performLogin();
	}



};

