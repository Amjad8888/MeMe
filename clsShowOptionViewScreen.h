#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsViewInfoJopScreen.h"
#include "clsViewPersonInfoScreen.h"
#include "clsUpdateJopInfoScreen.h"

class clsShowOptionViewScreen :protected clsScreen
{

	
private:

	enum eOptionView
	{
		eJopInfo = 1, ePersonalInfo = 2, eALLInfo =3 ,Exit = 4
	};

	static void GoBackToMainMenue()
	{
		cout << "\n\n";
		system("pause");
		ShowOptionView();
	}

	static void ShowJopInfo()
	{
		clsViewInfoJopScreen::ShowViewJopScreen();
	}

	static void ShowPersonInfo()
	{
		clsViewPersonInfoScreen::ShowViewPersonInfoScreen();
	}

	static void ShowAllInfo()
	{
		cout << "\n\t Will Be Soon\n";
	}


	static void _PerformMainMenue(eOptionView Op)
	{

		switch (Op)
		{
		case clsShowOptionViewScreen::eJopInfo:
			system("cls");
			ShowJopInfo();
			GoBackToMainMenue();
			break;
		case clsShowOptionViewScreen::ePersonalInfo:
			system("cls");
			ShowPersonInfo();
			GoBackToMainMenue();
			break;
		case clsShowOptionViewScreen::eALLInfo:
			system("cls");
			ShowAllInfo();
			GoBackToMainMenue();
			break;
		case clsShowOptionViewScreen::Exit:
			break;
		default:
			break;
		}
	}

public:

	static void ShowOptionView()
	{
		system("cls");
		DrawMainTitle("Option View Secreen");
		cout << "\n \t\t\t [1] : Jop Info . \n";
		cout << "   \t\t\t [2] : Personal Info . \n";
		cout << "   \t\t\t [3] : ALL Info . \n";
		cout << "   \t\t\t [4] : Exit . \n";
		cout << "   \t\t\t____________________________________________________\n";
		_PerformMainMenue((eOptionView)clsInput::_ReadNumber("\t\tEnter Option [1 - 4] : ", 1, 4));
	}

};

