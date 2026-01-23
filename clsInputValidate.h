#pragma once
#include<iostream>
#include "clsDate.h"
#include "clsUtil.h"
#include "clsPeriod.h"

using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(short num, short From, short To)
	{
		return(num >= From && num <= To);
	}
	static bool IsNumberBetween(int num, int From, int To)
	{
		return(num >= From && num <= To);
	}
	static bool IsNumberBetween(float num, float From, float To)
	{
		return(num >= From && num <= To);
	}
	static bool IsNumberBetween(double num, double From, double To)
	{
		return(num >= From && num <= To);
	}
	static bool IsDateBetweeen(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsDate1AfterDate2(DateFrom, DateTo))
		{
			clsUtil::Swap(DateFrom, DateTo);
		}
		clsPeriod Period(DateFrom, DateTo);

		return clsPeriod::IsDateWithinPeriod(Date, Period);
	}
	static int ReadIntNumber(string ErrorMessage = "Invalid Number, try again.")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;

		}
		return Number;
	}
	static double ReadDblNumber(string ErrorMessage = "Invalid Number, try again.")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;

		}
		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number out of range, try again.")
	{
		int Number = ReadIntNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage << endl;
			Number = ReadIntNumber();

		}
		return Number;
	}
	static float ReadDblNumberBetween(float From, float To, string ErrorMessage = "Number out of range, try again.")
	{
		float Number = ReadIntNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage << endl;
			Number = ReadIntNumber();

		}
		return Number;
	}
	static string ReadString()
	{
		string str;
		getline(cin>>ws, str);
		return str;
	}
	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}


};

