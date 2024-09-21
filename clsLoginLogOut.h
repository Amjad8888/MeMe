#pragma once
#include "clsPerson.h"
#include <iostream>
#include "clsDate.h";
#include <fstream>
#include "clsInput.h"
#include "clsEmployee.h"
#include <stack>

using namespace std;




class clsLoginLogOut :public clsEmployee
{


private:

	
	string _Login;
	string _LogOut;
	

 string _ConvertRecordToLineLog(clsLoginLogOut C,string del ="#//#")
	{
		string line;
		line += C.FirstName + del;
		line += C.LastName + del;
		line += C.EmpNumber() + del;
		line += C.Title + del;
		line += C.LocationWork + del;
		line += C.LogIn  + del;
		line += C.Logout ;
		return line;
	}

static	 clsLoginLogOut _ConverLineToRecordLog(string line)
	{
		vector <string> Vstr = clsInput::Split(line);
		return clsLoginLogOut(eModeLog::LogOut, Vstr[0], Vstr[1], Vstr[2], Vstr[3], Vstr[4], Vstr[5], Vstr[6]);
	}


	bool _SaveLogInToFile(string line)
	{
		fstream MyFile;
		MyFile.open("RejLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << line << endl;
		}
		MyFile.close();
		return true;
	}

	bool __Login()
	{
		string line = _ConvertRecordToLineLog(*this);
		return _SaveLogInToFile(line);
		
	}

	static	vector <clsLoginLogOut> _LoadDataFromLogFile()
	{
		
		vector <clsLoginLogOut> Vec;
		fstream MyFile;
		string line;
		MyFile.open("RejLog.txt",ios::in);
		while (getline(MyFile, line))
		{
			clsLoginLogOut Log = _ConverLineToRecordLog(line);
			Vec.push_back(Log);
			
		}
		return Vec;
	}

	bool _SaveDataLogAfterLogout(vector <clsLoginLogOut> vec)
	{
		fstream MyFile;
		string line;
		
		MyFile.open("RejLog.txt",ios::out);
		if (MyFile.is_open())
		{

			for(clsLoginLogOut &C:vec)
			{

				line = _ConvertRecordToLineLog(C);
				MyFile << line << endl;
				
			}
			
			
		}
		MyFile.close();
		return true;
	}





	bool __LogOut()
	{
		
		vector <clsLoginLogOut> Vec = _LoadDataFromLogFile();
		int counter = 0;
		
		for (clsLoginLogOut& C : Vec)
		{
			if (C.EmpNumber() ==this->EmpNumber())
			{
				if (C.Logout=="NUll" )
				{
					C.Logout = this->Logout;
					break;
				}
				
			}
		}

		return _SaveDataLogAfterLogout(Vec);
	}

public:

	enum eModeLog
	{
		Login = 1, LogOut = 2, clsEmpty = 3
	};
	eModeLog _Mode;
	clsLoginLogOut(eModeLog mode,string FirstName,string LastName,string EmNum,string title,string location,string Login,string Logout):
		clsEmployee(FirstName,LastName,EmNum,title,location)

	{
		_Login = Login;
		_LogOut = Logout;
		_Mode = mode;
	}


	void  setLogin(string login)
	{
		_Login = login;
	}

	string getLogin()
	{
		return _Login;
	}

	__declspec(property(get = getLogin, put = setLogin)) string LogIn;




	void  setLogout(string logout)
	{
		_LogOut = logout;
	}

	string getLogOut()
	{
		return _LogOut;
	}

	__declspec(property(get = getLogOut, put = setLogout)) string Logout;




	static clsLoginLogOut LoginMode(string ENum)
	{
		return	clsLoginLogOut(eModeLog::Login, "", "", ENum, "", "","", "NUll");
	}

	

static	 clsLoginLogOut clsEmptyLog()
	{
		return	clsLoginLogOut(eModeLog::clsEmpty, "", "", "", "", "", "", "");
	}



	 static clsLoginLogOut FindLog(string EmpNum)
	 {
		 fstream MyFile;
		 string line;
		 MyFile.open("RejLog.txt",ios::in);
		 while (getline(MyFile,line))
		 {
			 clsLoginLogOut Log = _ConverLineToRecordLog(line);
			 if (Log.EmpNumber() ==EmpNum)
			 {
				 return Log;
			 }
		 }
		 return clsEmptyLog();
	}


	 bool IsEmpty()
	 {
		 return _Mode == eModeLog::clsEmpty;
	 }

	 static bool IsExistLog(string NEmp)
	 {
		 clsLoginLogOut L = FindLog(NEmp);
		 return (!L.IsEmpty());
	 }

	enum ensaveL
	{
		SaveLogin =1, SaveLogout = 2,FailSave =3 
	};

	ensaveL Save()
	{
		switch (_Mode)
		{
		case clsLoginLogOut::Login:
			__Login();
			_Mode = eModeLog::LogOut;
			*this = clsEmptyLog();
			return SaveLogin;
			break;
		case clsLoginLogOut::LogOut:
			__LogOut();
			return SaveLogout;
			break;
		case clsLoginLogOut::clsEmpty:
			return FailSave;
			break;
		default:
			break;
		}
	}





	static stack <clsLoginLogOut> LoadDataFromLoFile()
	{
		stack <clsLoginLogOut> St;
		vector <clsLoginLogOut> Vec = _LoadDataFromLogFile();
		for (clsLoginLogOut& C : Vec)
		{
			St.push(C);
		}
		return St;
	}

};

