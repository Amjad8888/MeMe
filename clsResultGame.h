#pragma once
#include <iostream>
using namespace std;
#include <cstdlib> 



class clsResultGame
{

protected:
	enum enChoice
	{
		ston = 1, paper = 2, seccissior = 3
	};
	enum enNameWinner
	{
		playre = 1, Computer = 2, NoWinner = 3
	};
	

	enChoice _ComputerChoice;
	enChoice _PlyaerChoice;
	int _plyerWinner = 0;
	int _CopmuterWinner = 0;
	int _NoWinner = 0;
	enNameWinner _Winner;
	
	short _ReadRandomNumber(int From, int To) {
		srand(unsigned(time(NULL)));
		int Number = rand() % (To - From + 1) + From;
		return Number;
	}

	enNameWinner ResultWinner()
	{
		
		if (_PlyaerChoice == _ComputerChoice)
		{
			_NoWinner++;
			return enNameWinner::NoWinner;
			
		}
		if (_PlyaerChoice == enChoice::paper && _ComputerChoice == enChoice::seccissior)
		{
			_CopmuterWinner++;
			return enNameWinner::Computer;
		}

		if (_PlyaerChoice == enChoice::ston && _ComputerChoice == enChoice::paper)
		{
			_CopmuterWinner++;
			return enNameWinner::Computer;
		}
		if (_PlyaerChoice == enChoice::seccissior && _ComputerChoice == enChoice::ston)
		{
			_CopmuterWinner++;
			return enNameWinner::Computer;
		}
		_plyerWinner++;
		return enNameWinner::playre;
	}

	string NameChoice(enChoice  A1)
	{
		
		string arr[3] = { "ston" ,"paper","Seccssore" };
		return arr[A1 - 1];
	}

	string NameWinner(enNameWinner Winner)
	{

		string arr[3] = { "player" ,"Copmuter","NoWinner" };
		return arr[Winner - 1];
	}

	void  SystemWinner(enNameWinner Winner)
	{
		if (Winner ==enNameWinner::playre)
		{
			system("color 2F");
			
		}
		if (Winner == enNameWinner::Computer)
		{
			system("color 4F");
			

		}
		if (Winner == enNameWinner::NoWinner)
		{
			system("color 6F");
			
		}
	}


public:

	clsResultGame()
	{

	}
	clsResultGame(int playerChoice )
	{
		_PlyaerChoice = (enChoice) playerChoice;
		_ComputerChoice =(enChoice) _ReadRandomNumber(1, 3);
			
	}

	int PlayerWin()
	{
		return _plyerWinner;
	}

	int ComputerWin()
	{
		return _CopmuterWinner;
	}

	int NoWin()
	{
		return _NoWinner;
	}

static	void  SystemWinner(string Winner)
	{
		if (Winner == "player")
		{
			system("color 2F");

		}
		if (Winner == "Computer")
		{
			system("color 4F");


		}
		if (Winner == "NoWinner")
		{
			system("color 6F");

		}
	}


	void  printResultedRound()
	{
		_Winner = ResultWinner();
		cout << "Player Choice   : " << NameChoice(_PlyaerChoice) << endl;;
		cout << "Computer Choice : " << NameChoice(_ComputerChoice) << endl;;
		cout << "Winner Round    : " << NameWinner(_Winner) << endl ;
		SystemWinner(_Winner);
	}

static	void printFinal(int NumRound,int PlayerWin,int CompWin,int NoWin,string FinalWin)
	{
		//system("cls");
		SystemWinner(FinalWin);
		cout << "\n\t\t _____________________________________________\n";
		cout << "\t\t\t\t Game Over \n";
		cout << "\n\t\t _____________________________________________\n";
		cout << "\t\t\tGame Round  : " << NumRound << endl;
		cout << "\t\t\tPlayer Win  : " << PlayerWin << endl;
		cout << "\t\t\tComputer win: " << CompWin << endl;
		cout << "\t\t\tDraw times  : " << NoWin << endl;
		cout << "\t\t\tFinalWinner : " << FinalWin<<endl;
	}
	
};

