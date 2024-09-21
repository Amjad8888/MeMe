#pragma once


#include <iostream>
#include "clsDate.h"
#include "queue"
#include "stack"
#include "clsResultGame.h"
using namespace std;


class clGameStonePaper :protected  clsResultGame
{

private:
	short _Round;

	int _PlayerChoice;
	int _ComWin =0;
	int _PlayWin=0;
	int _NoWin=0;
	string _FinalWinner;
	

static	int ReadNumber(string maassage,int From,int To)
	{
		int ruond;
		cout << maassage;
		cout << " [" << From << "] To [" << To << "]" << endl;
		cin >> ruond;
		while (ruond < From || ruond >To)
		{
			cout << "\n please Enter Number between " << From << " And " << To << endl;
			cin >> ruond;
		}
		
		return ruond;
	}

	string NameFinaleWin(int Pw, int Cw, int No)
	{
		if (Pw > Cw )
		{
			return "Player";
		}
		if (Cw == Pw  )
		{
			return "NoWinner";
		}
		return "Computer";
	}



	void StartGame(int Round )
	{
		system("cls");
		int counter = 0;
		
		while (counter < Round)
		{
			
			counter++;
			cout << "\nRound [" << counter << "] Begin \n";
			cout << " your  Choice ston[1] paper [2] seccissior [3] : ";
			_PlayerChoice = ReadNumber("", 1, 3);
			clsResultGame Round(_PlayerChoice);
			

			cout << "\n------------------------Round Result [" << counter << "]---------------------" << endl;

			Round.printResultedRound();

			_PlayWin += Round.PlayerWin();
			_ComWin += Round.ComputerWin();
			_NoWin += Round.NoWin();

			
		}
		_FinalWinner = NameFinaleWin(_PlayWin, _ComWin, _NoWin);
		
		
	}

public:
	
	clGameStonePaper()
	{
		_Round = ReadNumber("\n\nHow Many Round Choose", 1, 10);
		StartGame(_Round);
		clsResultGame::printFinal(_Round, _PlayWin, _ComWin, _NoWin, _FinalWinner);
	}

	

	

 static void  ShowStartGameScreen()
	{
		system("cls");
		clGameStonePaper();
	
		cout << " press any key to back :";
		system("pause>0");
		
	
	}


};

