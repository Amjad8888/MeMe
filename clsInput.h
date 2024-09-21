#pragma once
#include <iostream>

#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class clsInput
{


public:

	static vector <string> Split(string line, string del = "#//#")
	{
		short pos = 0;
		string word = "";
		vector <string> Str;
		while ((pos = line.find(del)) != line.npos)
		{
			word = line.substr(0, pos);
			if (word != "")
			{
				Str.push_back(word);
				line.erase(0, pos + del.length());
			}
		}
		if (line != "")
		{
			Str.push_back(line);
		}
		return Str;
	}






	static short _ReadNumber(string massage, short From, short To)
	{
		int amount_input;

		cout << "\n\t\t\t" << massage;
		cin >> amount_input;
		while (cin.fail() && amount_input < From || amount_input >To)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\n\t\t\tEnter Number only OR Number In Range  [" << From << "-" << To << "] :";
			cin >> amount_input;
		}
		return amount_input;
	}

	static double _ReadDblNumber(string massage)
	{
		double amount_input;

		cout << "\n\t\t\t " << massage;
		cin >> amount_input;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\n\t\t\tEnter Number only : ";
			cin >> amount_input;
		}
		return amount_input;
	}

	static short _ReadNumber(string massage)
	{
		int amount_input;

		cout << "\n\t\t\t" << massage;
		cin >> amount_input;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\t\t\tEnter Number only : ";
			cin >> amount_input;
		}
		return amount_input;
	}



	static string ReadString(string massage)
	{
		string  S1;
		cout << "\n\t\t\t" << massage;
		cin >> S1;
		return S1;
	}

	static char ReadChar(string massage)
	{
		char A;
		cout << "\n \t\t\t " << massage;
		cin >> A;
		return A;
	}
};


