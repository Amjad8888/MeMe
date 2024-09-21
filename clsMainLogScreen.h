#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsShowRej_LogScreen.h"
#include "clsLogOutScreen.h"
#include "clsLogInScreen.h"


class clsMainLogScreen :protected clsScreen
{


private:

	enum eLog
	{
		eLogin =1, eLogou =2, eShowRej =3, Exit =4 
	};


	static void GoBackToMainMenue()
	{
		cout << "\n\n";
		system("pause");
		ShowLogScreen();
	}

	static void ShowLogin()
	{
		clsLogInScreen::ShowLoginScreen();
	}

	static void ShowLogout()
	{
		clsLogOutScreen::ShowLogoutScreen();
	}

	static void ShowListRej()
	{
		clsShowRej_LogScreen::ShowLogRejecterScreen();
	}


	static void _PerformMainMenue(eLog L)
	{
		switch (L)
		{
		case clsMainLogScreen::eLogin:
			system("cls");
			ShowLogin();
			GoBackToMainMenue();
			break;
		case clsMainLogScreen::eLogou:
			system("cls");
			ShowLogout();
			GoBackToMainMenue();
			break;
		case clsMainLogScreen::eShowRej:
			system("cls");
			ShowListRej();
			GoBackToMainMenue();
			break;
		case clsMainLogScreen::Exit:
			break;
		default:
			break;
		}
	}



public:

	static void ShowLogScreen()
	{
		system("cls");
		DrawMainTitle("Log Secreen");
		cout << "\n \t\t\t [1] : Login . \n";
		cout << "   \t\t\t [2] : Logout . \n";
		cout << "   \t\t\t [3] : Show List Rejecter . \n";
		cout << "   \t\t\t [4] : Exit . \n";
		cout << "   \t\t\t____________________________________________________\n";
		_PerformMainMenue((eLog)clsInput::_ReadNumber("\t\tEnter Option [1 - 4] : ", 1, 4));
	}


};

