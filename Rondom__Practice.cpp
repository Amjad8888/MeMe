//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud
#include <cstdlib> 
#include <iostream>

#include "clsGameStonPaper.h"
#include "clsMainEmpMenuScreen.h"
#include "clsShowCalculaterScreen.h"
using namespace std;









int main()
{
	srand(unsigned(time(NULL)));
	
//	project Calculator ****** 
	// clsShowCalculaterScreen C;
 //	C.ShowCalculator();


	//  project Game Stone Paper *****
	// clGameStonePaper::ShowStartGameScreen();
	
	// project Employee System *****

	// clsMainEmployeeScreen::ShowMainMenueScreen();
	
	int Sum = 0;
	int N =10;
	int N2 = 0;
	string S1 = "1234";
	int  R = 0;
	Sum = stoi(S1);

	 

	while (Sum>10)
	{
		R = Sum % 10;
		N2 += R;
		N2 = N * N2;
		Sum /= 10;
	}
	N2 += Sum;
	cout << N2 << endl;
}






