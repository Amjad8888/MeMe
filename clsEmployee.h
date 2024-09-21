#pragma once
#include "clsPerson.h"
#include <iostream>
#include "clsDate.h";
#include <fstream>
#include "clsInput.h"
using namespace std;


class clsEmployee :public clsPerson
{


private:

	enum eMode
	{
		eAddNewMode = 1, eUpdateMode = 2, eEmptyMode =3
	};

	string _EmployeeNumber;
	string _EmployeeTitle;
	string _LocationWork;
	short  _YearBeginEmp;
	short  _YearService;
	float  _Salary;
	eMode _Mode;
	bool MarkEmp = false;




	static clsEmployee _ConverLineToRecord(string line)
	{
		vector <string> Vstr = clsInput::Split(line);
		return clsEmployee(eMode::eUpdateMode, Vstr[0], Vstr[1], Vstr[2],Vstr[3],Vstr[4], Vstr[5], Vstr[6], stof(Vstr[7]), stoi(Vstr[8]),
			stoi(Vstr[9]), Vstr[10], Vstr[11], stoi(Vstr[12]), Vstr[13], Vstr[14], stoi(Vstr[15]), stoi(Vstr[16]), stoi(Vstr[17]), Vstr[18]);
	}
	
	  
	 
	 static string _ConvertRecordToLine(clsEmployee EP, string del = "#//#")
	 {
		 string line;
		 line += EP.FirstName + del;
		 line += EP.LastName + del;
		 line += EP.EmpNumber() + del;
		 line += EP.Phone + del;
		 line += EP.Email + del;
		 line += EP.Title + del;
		 line += EP.LocationWork + del;
		 line += to_string( EP.Salary) + del;
		 line += to_string(EP.YearService) + del;
		 line += to_string( EP.Age) + del;
		 line += EP.Gender + del;
		 line += EP.Case + del;
		 line += to_string(EP.NumberKids) + del;
		 line += EP.Address.Province + del;
		 line += EP.Address.City + del;
		 line += to_string (EP.Address.LocalityNumber )+ del;
		 line += to_string(EP.Address.AlleyNumber) + del;
		 line += to_string(EP.Address.HouseNumber) + del;
		 line += EP.Address.PointGuide;
		 return line;
	 }

	 static void _SaveRecordToFile(string line)
	 {
		 fstream MyFile;
		 MyFile.open("Employee.txt", ios::out | ios::app);
		 if (MyFile.is_open())
		 {
			 MyFile << line << endl;
		 }
		 MyFile.close();

	 }

	 static vector <clsEmployee> _LoadDataFromFile()
	 {
		 fstream MyFile;
		 string line;
		 vector <clsEmployee> Vec;
		 MyFile.open("Employee.txt", ios::in);
		 if (MyFile.is_open())
		 {
			 while (getline(MyFile,line))
			 {
				 clsEmployee Emp = _ConverLineToRecord(line);
				 Vec.push_back(Emp);
			 }
		 }
		 MyFile.close();
		 return Vec;
	 }


	 void _SaveAfterUpdate(vector <clsEmployee> Vec)
	 {
		 fstream MyFile;
		 string line;
		 MyFile.open("Employee.txt", ios::out);
		 if (MyFile.is_open())
		 {

			 for (clsEmployee& C : Vec)
			 {
				 line = _ConvertRecordToLine(C);
				 MyFile << line << endl;
			 }
			 MyFile.close();
		 }
	 }


	 void _AddNew()
	 {
		 string line = _ConvertRecordToLine(*this);
		 _SaveRecordToFile(line);
	 }

	 void _Update()
	 {
		 vector <clsEmployee> Vec = _LoadDataFromFile();

		 for (clsEmployee& C : Vec)
		 {
			 if (C.EmpNumber() == this->EmpNumber())
			 {
				 C = *this;
				 break;
			 }
		 }
		 _SaveAfterUpdate(Vec);
	 }

	 bool _SaveDataAfterMarK(vector <clsEmployee> Vec)
	 {
		 fstream MyFile;
		 string line;
		 MyFile.open("Employee.txt", ios::out);
		 if (MyFile.is_open())
		 {

			 for (clsEmployee& C : Vec)
			 {
				 if (C.MarkEmp == false)
				 {
					 line = _ConvertRecordToLine(C);
					 MyFile << line << endl;
				 }
				 
			 }

			 MyFile.close();
			 return true;
		 }
	 }


	 bool _MarkEmployeeToDelet(vector <clsEmployee> &Vec)
	 {
		 for (clsEmployee& C : Vec)
		 {
			 if (C.EmpNumber() == this->EmpNumber())
			 {
				 C.MarkEmp = true;
				 return true;
			 }
		 }
	 }




public:


	//// person Info
	clsEmployee(eMode mode ,string FirsName, string LastName, string EmployeeNum,string phone,string email,string Title,string locationWork,float salary,
		 int yearService,int Age, string Gender, string Case, int NumberKids,
		string province,string city,short localitynumber,short AlleyNumber,short HouseNumber,string PointGuide ):
	clsPerson( FirsName,LastName,phone,email,Age,Gender,Case,NumberKids,province,city,localitynumber,AlleyNumber,HouseNumber,PointGuide)
	{
		_Mode = mode;
		_EmployeeNumber = EmployeeNum;
		_EmployeeTitle = Title;
		_LocationWork = locationWork;
		_YearService = yearService;
		_Salary = salary;
	
	}
	

	clsEmployee(string FirstName,string lastName,string EmpNum,string title,string location):clsPerson(FirstName,lastName)
	{
		_EmployeeNumber = EmpNum;
		_EmployeeTitle = title;
		_LocationWork = location;
	}


	string EmpNumber()
	{
		return _EmployeeNumber;
	}

	void setTitle(string title)
	{
		_EmployeeTitle = title;
	}

	string getTitle()
	{
		return _EmployeeTitle;
	}
	__declspec(property(get = getTitle, put = setTitle)) string Title;


	void setLocationWork(string locationWork)
	{
		_LocationWork = locationWork;
	}

	string geLocationWork()
	{
		return _LocationWork;
	}
	__declspec(property(get = geLocationWork, put = setLocationWork)) string LocationWork;




	void setSalary(float salary)
	{
		_Salary = salary;
	}

	float getSalary()
	{
		return _Salary;
	}

	__declspec(property(get = getSalary, put = setSalary)) float Salary;

	void setYearService(int YearS)
	{
	   _YearService = YearS;
	}

	short getYearService()
	{
		return _YearService;
	}

	__declspec(property(get = getYearService, put = setYearService)) short YearService;

	void setYearBegin(int YearB)
	{
		_YearBeginEmp = YearB;
	}

	short getYearBegin()
	{
		return _YearBeginEmp;
	}

	__declspec(property(get = getYearBegin, put = setYearBegin)) short YearBegin;
	

	static clsEmployee AddModeEmployee(string EmpNum)
	{
		return clsEmployee(eMode::eAddNewMode,"", "", EmpNum, "", "", "", "", 0, 0, 0, "", "", 0, "", "", 0, 0, 0, "");
	}

   static	clsEmployee clsEmpty()
	{
		return clsEmployee(eMode::eEmptyMode, "", "", "","", "", "", "", 0, 0, 0, "", "", 0, "", "", 0, 0, 0, "");
	}

   bool IsEmpty()
  {
	return _Mode == eMode::eEmptyMode;
  }

   static clsEmployee Find(string ENum)
	{
		string line;
		fstream MyFile;
		MyFile.open("Employee.txt", ios::in);
		while (getline(MyFile,line))
		{
			clsEmployee Employee = _ConverLineToRecord(line);
			if (Employee.EmpNumber() == ENum)
			{
				return Employee;
			}
		}
		return clsEmpty();
	}



     static bool IsExist(string ENumb)
   {
	clsEmployee Emp = Find(ENumb);
	return (!Emp.IsEmpty());
   }










	enum  ensave
	{
		enSaveSeccessflly = 1, enFailSave, enEmpty =3
	};

	
	ensave Save()
	{
		switch (_Mode)
		{
		case clsEmployee::eAddNewMode:
			_AddNew();
			_Mode = eUpdateMode;
			*this = clsEmpty();
			return enSaveSeccessflly;
			break;
		case clsEmployee::eUpdateMode:
			_Update();
			return enSaveSeccessflly;
			break;
		case clsEmployee::eEmptyMode:
			return enEmpty;
			break;
		default:
			break;
		}
	}

	static vector <clsEmployee> LoadDataFromFile()
	{
		return _LoadDataFromFile();
	}

	bool Delete()
	{
		vector <clsEmployee> Vec = LoadDataFromFile();
		       _MarkEmployeeToDelet(Vec);
		return  _SaveDataAfterMarK(Vec);

	}





};

