#pragma once

#include <iostream>
#include "clsDate.h";
#include <fstream>
#include "clsInput.h"
#include "clsEmployee.h"
#include "clsLoginLogOut.h"
#include "clsScreen.h"



class clsLogOutScreen :protected clsScreen
{

private:
	static void _performLogout()
	{
		string NumEmp = clsInput::ReadString("Enter Employee Number : ");
		while (!clsLoginLogOut::IsExistLog(NumEmp))
		{
			NumEmp = clsInput::ReadString("Not Exist Enter Another Employee Number : ");
		}

	
		clsLoginLogOut L1 = clsLoginLogOut::FindLog(NumEmp);
		
		L1.Logout = clsDate::GetSystemDateTimeString();

		
		clsLoginLogOut::ensaveL Save = L1.Save();
		if (Save == clsLoginLogOut::SaveLogout)
		{
			cout << "\n \t Logout seccessfully \n";
		}


	}

public:
	static void ShowLogoutScreen()
	{
		DrawMainTitle("Logout Screen");
		_performLogout();
	}


};

