#pragma once
#include "clsAddress.h"


#include <iostream>
using namespace std;



class clsPerson 
{

private:
	
	string _FirstName;
	string _LastName;
	short _Age;
	string _Phone;
	string _Email;
	string _Gender;
	string _Case;
	short _NumberKids;
	short _YearBorn;



public:
	
	clsAddress Address = clsAddress("","",0,0,0,"");
	clsPerson(string firstNam,string lastName,string Phone ,string Email ,short age,string gender,string Case,short numberKids
	,string province,string city,short localityNumber,short AlleyNumber,short houseNumber,string pointGide)
		
	{
		Address = clsAddress(province, city, localityNumber, AlleyNumber, houseNumber, pointGide);

		_FirstName = firstNam;
		_LastName = lastName;
		_Age   = age;
		_Phone = Phone;
		_Email = Email;
		_Gender = gender;
		_Case  = Case;
		_NumberKids = numberKids;
		
	
	}

	clsPerson(string FirstName,string LastName)
	{
		_FirstName = FirstName;
		_LastName = LastName;
	}
	

	void setFirstName(string firstname)
	{
		_FirstName = firstname;
	}

	string getFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;



	void setLastName(string lastname)
	{
		_LastName = lastname;
	}

	string getLastName()
	{
		return _LastName;
	}

	__declspec(property(get = getLastName, put = setLastName)) string LastName;


	string FullName()
	{
		return FirstName + " " + LastName;
	}


	void setPhone(string phone)
	{
		_Phone = phone;
	}

	string getPhone()
	{
		return _Phone;
	}

	__declspec(property(get = getPhone, put = setPhone)) string Phone;

	void setEmail(string email)
	{
		_Email = email;
	}

	string getEmail()
	{
		return _Email;
	}

	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setAge(int age)
	{
		_Age = age;
	}

	short getAge()
	{
		return _Age;
	}

	__declspec(property(get = getAge, put = setAge)) short Age;


	



	void setGender(string gender)
	{
		_Gender = gender;
	}

	string getGender()
	{
		return _Gender;
	}

	__declspec(property(get = getGender, put = setGender)) string Gender;


	void setCase(string Case)
	{
		_Case = Case;
	}

	string getCase()
	{
		return _Case;
	}

	__declspec(property(get = getCase, put = setCase)) string Case;
	

	void setNumberKids(int Nkid)
	{
		_NumberKids = Nkid;
	}

	int getNumberKids()
	{
		return _NumberKids;
	}

	__declspec(property(get = getNumberKids, put = setNumberKids)) int NumberKids;



	void setYearBorn(int YearB)
	{
		 _YearBorn= YearB;
	}

	short getYearBorn()
	{
		return _YearBorn;
	}

	__declspec(property(get = getYearBorn, put = setYearBorn)) short YearBorn;


};

