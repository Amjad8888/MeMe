#pragma once
#include <iostream>
#include "clsScreen.h"

#include <string>
#include "clsInput.h"
#include "clsAddNewScreen.h"
#include "clsMainLogScreen.h"
#include "clsShowOptionViewScreen.h"
#include "clsShowOptionUpdate.h"
#include "clsDeleteEmpScreen.h"
#include "clsFindScreen.h"

class clsMainEmployeeScreen :protected clsScreen
{





private:


	enum eMainMenue
	{
		eAddNew =1, eUpdate =2, eDelete =3, eFind =4, eShowList =5, eLog =6, Exit =7
	};

	static void GoBackToMainMenue()
	{
		cout << "\n\n";
		system("pause");
		ShowMainMenueScreen();
	}

	static void ShowAddNew()
	{
		clsAddNewScreen::ShowAddNewScreen();
	}

	static void ShowUpdate()
	{
		clsShowOptionUpdate::ShowUpdateOption();
	}

	static void ShowDelete()
	{
		clsDeleteEmpScreen::ShowDeleteScreen();
	}

	static void ShowFind()
	{
		clsFindScreen::ShowFindScreen();
	}

	static void ShowList()
	{
		clsShowOptionViewScreen::ShowOptionView();
	}

	static void ShowLog()
	{
		clsMainLogScreen::ShowLogScreen();
	}


	


	static void _PerformMainMenue(eMainMenue Op)
	{
		switch (Op)
		{
		case clsMainEmployeeScreen::eAddNew:
			system("cls");
			ShowAddNew();
			GoBackToMainMenue();
			break;
		case clsMainEmployeeScreen::eUpdate:
			system("cls");
			ShowUpdate();
			GoBackToMainMenue();
			break;
		case clsMainEmployeeScreen::eDelete:
			system("cls");
			ShowDelete();
			GoBackToMainMenue();
			break;
		case clsMainEmployeeScreen::eFind:
			system("cls");
			ShowFind();
			GoBackToMainMenue();
			break;
		case clsMainEmployeeScreen::eShowList:
			system("cls");
			ShowList();
			GoBackToMainMenue();
			break;
		case clsMainEmployeeScreen::eLog:
			system("cls");
			ShowLog();
			GoBackToMainMenue();
			break;
		case clsMainEmployeeScreen::Exit:
			break;
		default:
			break;
		}
	}

public:

	static void ShowMainMenueScreen()
	{

		system("cls");
		DrawMainTitle("Main Menue Secreen");
		cout << "\n \t\t\t [1] : Add New . \n";
		cout << "   \t\t\t [2] : Update . \n";
		cout << "   \t\t\t [3] : Delete  . \n";
		cout << "   \t\t\t [4] : Find . \n";
		cout << "   \t\t\t [5] : Show List . \n";
		cout << "   \t\t\t [6] : Login | Logout . \n";
		cout << "   \t\t\t [7] : Exit . \n";
		cout << "   \t\t\t____________________________________________________\n";
		_PerformMainMenue((eMainMenue)clsInput::_ReadNumber("\t\tEnter Option [1 - 7] : ", 1, 7));

	};


};

