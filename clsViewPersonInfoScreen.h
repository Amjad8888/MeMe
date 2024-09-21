#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsEmployee.h"



class clsViewPersonInfoScreen :protected clsScreen
{


private:
	static void printhead()
	{
		cout << "\n___________________________________________________________________________________________";
			cout<<"____________________________________________________________\n";

		cout << "\n|" << left << setw(15) << "Full Name" << "|" << setw(5) << "Age" << "|" << setw(7) << "Gender";
		cout << "|" << setw(10) << "Case" << "|" << setw(10) << "Num.Kids" ;
		cout << "|" << setw(11) << "Phone" << "|" << setw(20) << "Email";
		cout << "|" << setw(10) << "Province";
		cout << "|" << setw(10) << "City" << "|" << setw(10) << "Local.Num" << "|" << setw(10) << "Alley.Num";
		cout << "|" << setw(10) << "House.Num" << "|" << setw(10) << "PointGuide" ;
		cout << "\n___________________________________________________________________________________________";
		cout << "____________________________________________________________\n";

	}

	static void printSingleRecord(clsEmployee C)
	{
		cout << "|" << left << setw(15) << C.FullName() << "|" << setw(5) << C.Age << "|";
		cout << setw(7) << C.Gender << "|" << setw(10) << C.Case;
		cout << "|" << setw(10) << C.NumberKids;
		cout << "|" << setw(11) << C.Phone << "|" << setw(20) << C.Email;
		cout<< "|" << setw(10) << C.Address.Province;
		cout << "|" << setw(10) << C.Address.City << "|" << setw(10) << C.Address.LocalityNumber ;
		cout << "|" << setw(10) << C.Address.AlleyNumber << "|" << setw(10) << C.Address.HouseNumber; 
		cout << "|" << setw(10) << C.Address.PointGuide<< "\n";
	}


public:

	static void ShowViewPersonInfoScreen()
	{
		system("cls");
		vector <clsEmployee> Vec = clsEmployee::LoadDataFromFile();
		string sub = "[" + to_string(Vec.size()) + "] Opretions ";
		DrawMainTitle("View person Info Screen ", sub);

		if (Vec.size() == 0)
		{
			cout << "\nSorrey Emtpy Data\n\n";
		}
		else
		{
			printhead();
			for (clsEmployee& C : Vec)
			{
				printSingleRecord(C);
			}

		}
		cout << "\n___________________________________________________________________________________________";
		cout << "____________________________________________________________\n";

	}


	


};

