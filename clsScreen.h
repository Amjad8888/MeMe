#pragma once
#include <iostream>


using namespace std;

class clsScreen
{



public:

	static void DrawMainTitle(string Title, string Sub = "")
	{
		string _Title;
		string _Sub = "";
		if (Sub != "")
		{
			_Sub = Sub;
		}
		_Title = Title;
		cout << "\n\t\t\t __________________________________________________\n";
		cout << "\n\t\t\t\t\t " << _Title << endl;
		cout << "\t\t\t\t\t " << _Sub;
		cout << "\n\t\t\t __________________________________________________\n";

	}

	static void DeniedMassage()
	{
		system("cls");
		cout << "\n\t__________________________________________________________\n";

		cout << "\n \t\tSorrey You Dont Have Permission To Access ";
		cout << "\n\t__________________________________________________________\n";
	}

	// static bool IsPermissionToAccess(clsUser::enpermission P)
//	{

	//	if (CurrentUser.CheckPermission(P))
		//{
		//	return true;
	//	}
		//else
		//{
			//DeniedMassage();
			//return false;
		//}
	//}


};

