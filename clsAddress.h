#pragma once

#include <iostream>
using namespace std;


class clsAddress
{


private:
	string _Province;
	string _City;
	short _LocalityNumber;
	short _AlleyNumber;
	short _HouseNumber;
	string _PointGuide;



public:

	clsAddress(string province,string city,short localityNumber,short AllyNumber,short HouseNumber,string pointGuide)
	{
		_Province = province;
		_City = city;
		_LocalityNumber = localityNumber;
		_AlleyNumber = AllyNumber;
		_HouseNumber = HouseNumber;
		_PointGuide = pointGuide;
	}

	void setProvince(string prov)
	{
		_Province = prov;
	}

	string getProvince()
	{
		return _Province;
	}

	__declspec(property(get = getProvince, put = setProvince)) string Province;


	void setCity(string city)
	{
		_City = city;
	}

	string getCity()
	{
		return _City;
	}

	__declspec(property(get = getCity, put = setCity)) string City;


	void setLocalNumber(int LoCNum)
	{
		_LocalityNumber = LoCNum;
	}

	short getLocalNumber()
	{
		return _LocalityNumber;
	}

	__declspec(property(get = getLocalNumber, put = setLocalNumber)) short LocalityNumber;



	void setAlleyNumber(int AlleyN)
	{
		_AlleyNumber = AlleyN;
	}

	int getAlleyNumber()
	{
		return _AlleyNumber;
	}

	__declspec(property(get = getAlleyNumber, put = setAlleyNumber)) int AlleyNumber;
	


	void setHouseNumber(int HousN)
	{
		_HouseNumber = HousN;
	}

	int getHouseNumber()
	{
		return _HouseNumber;
	}

	__declspec(property(get = getHouseNumber, put = setHouseNumber)) int HouseNumber;



	void setGuidePoint(string Gpoint)
	{
		_PointGuide = Gpoint;
	}

	string getGuidePoint()
	{
		return _PointGuide;
	}

	__declspec(property(get = getGuidePoint, put = setGuidePoint)) string PointGuide;



	

};

