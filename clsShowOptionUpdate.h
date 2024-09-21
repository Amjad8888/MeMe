#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsEmployee.h"
#include "clsUpdateJopInfoScreen.h"
#include "clsUpdatePersonInfoScreen.h"
#include "clsUpdateAllScreen.h"
class clsShowOptionUpdate :clsScreen
{

private:

	enum eOptionUpdate
	{
		eUpdateJopInfo = 1, eUpdatepersonInfo =2 , eUpdateAll =3, Exit =4
	};

	static void GoBackToMainMenue()
	{
		cout << "\n\n";
		system("pause");
		ShowUpdateOption();
	}

	static void ShowUpdateJop()
	{
		clsUpdateJopInfoScreen::ShoeUpdateJopInfo();
	}

	static void ShowUpdatePerson()
	{
		clsUpdatePersonInfoScreen::ShowUpdatePersonInfo();
	}

	static void ShowUpdateAll()
	{
		clsUpdateAllScreen::ShowUpdateAllInfo();
	}

	static void _performUpdateOption(eOptionUpdate Op)
	{
		switch (Op)
		{
		case clsShowOptionUpdate::eUpdateJopInfo:
			system("cls");
			ShowUpdateJop();
			GoBackToMainMenue();
			break;
		case clsShowOptionUpdate::eUpdatepersonInfo:
			system("cls");
			ShowUpdatePerson();
			GoBackToMainMenue();
		case clsShowOptionUpdate::eUpdateAll:
			system("cls");
			ShowUpdateAll();
			GoBackToMainMenue();
			break;
		case clsShowOptionUpdate::Exit:
			break;
		default:
			break;
		}
	}

public:

	static void ShowUpdateOption()
	{
		system("cls");
		DrawMainTitle("Option Update Secreen");
		cout << "\n \t\t\t [1] : Update Jop Info . \n";
		cout << "   \t\t\t [2] : Update Personal Info . \n";
		cout << "   \t\t\t [3] : Update All Info . \n";
		cout << "   \t\t\t [4] : Exit . \n";
		cout << "   \t\t\t____________________________________________________\n";
		_performUpdateOption((eOptionUpdate)clsInput::_ReadNumber("\t\tEnter Option [1 - 4] : ", 1, 4));
	}

};

