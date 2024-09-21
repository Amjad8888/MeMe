#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInput.h"
#include "clsEmployee.h"



class clsViewInfoJopScreen :protected clsScreen
{


private:

	static void printhead()
	{
		cout << "\n\t\t________________________________________________________________________________\n";
		
		cout << "\n\t\t|" << left << setw(15) << "Full Name" << "|" << setw(10) << "Emp.Number" << "|" << setw(10) << "Salary";
			cout<< "|" <<	setw(15) << "Title"<< "|" << setw(10) << "Location" << "|" << setw(15) << "Year Service";
		cout << "\n\t\t________________________________________________________________________________\n";
		
	}


	static void printSingleRecord(clsEmployee C)
	{
		cout << "\t\t|" << left << setw(15) << C.FullName() << "|" << setw(10) << C.EmpNumber() << "|";
			cout<< setw(10) << C.Salary <<"|" << setw(15) << C.Title;
		cout << "|" << setw(10) << C.LocationWork << "|" << setw(25) << C.YearService << "\n"; 

	}


public:

	static void ShowViewJopScreen()
	{
		system("cls");
		vector <clsEmployee> Vec = clsEmployee::LoadDataFromFile();
		string sub = "[" + to_string(Vec.size()) + "] Opretions ";
		DrawMainTitle("View Jop Info Screen ", sub);

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
		cout << "\t\t________________________________________________________________________________\n";
	
	}


};

