#pragma once

#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsScreen.h"
#include "clsLoginLogOut.h"
using namespace std;




class clsShowRej_LogScreen :protected clsScreen
{


private:




	static void printhead()
	{
		cout << "\n_________________________________________________________________";
		cout << "_________________________________\n";
		cout << "\n\|" << left << setw(15) << "Full Name" << "|" << setw(10) << "Emp.Num" << "|" << setw(10) << "Title";
		cout << "|" << setw(10) << "Location" << "|" << setw(25) << "Login" << "|" << setw(25) << "Logout";
		cout << "\n_________________________________________________________________";
		cout << "_________________________________\n";
	}


	static void printSingleRejLog(clsLoginLogOut C)
	{
		cout << "|" << left << setw(15) << C.FullName() << "|" << setw(10) << C.EmpNumber() << "|" << setw(10) << C.Title;
		cout << "|" << setw(10) << C.LocationWork << "|" << setw(25) << C.LogIn << "|" <<setw(25)<< C.Logout << " \n";

	}



public:

	static void ShowLogRejecterScreen()
	{
		system("cls");
		stack <clsLoginLogOut> SLog = clsLoginLogOut::LoadDataFromLoFile();
		string sub = "[" + to_string(SLog.size()) + "] Opretions ";
		DrawMainTitle("List Customer Screen ", sub);

		if (SLog.size() == 0)
		{
			cout << "\nSorrey Emtpy Data\n\n";
		}
		else
		{
			printhead();
			while (!SLog.empty())
			{
				printSingleRejLog(SLog.top());
				SLog.pop();
			}
			
		}
		cout << "_________________________________________________________________";
		cout << "_________________________________\n";
	}
	


};

