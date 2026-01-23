#pragma once
#include<fstream>
#include <iostream>
#include <string>
#include "clsString.h"
#include <vector>

class clsCurrency
{
	enum enMode{EmptyMode=0,UpdateMode=1};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertCurrencyLineToObject(string Line)
	{
		vector<string>CurrencyLineData = clsString::Split(Line,"#//#");
		return clsCurrency(enMode::UpdateMode, CurrencyLineData[0], CurrencyLineData[1], CurrencyLineData[2], stod(CurrencyLineData[3]));

	}
	 static vector<clsCurrency>_LoadCurrencyDataFromFile()
	{
		vector<clsCurrency>vCurrencies;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vCurrencies.push_back(_ConvertCurrencyLineToObject(Line));
			}
		}
		return vCurrencies;
	}
	static string _ConvertCurrencyObjectToLine(clsCurrency Currency,string seprator="#//#")
	{
		string CurrencyLine = Currency.Country() + seprator + Currency.CurrencyCode() + seprator + Currency.CurrencyName() + seprator + to_string(Currency.Rate);
		return CurrencyLine;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out );
		if (MyFile.is_open())
		{
			for (clsCurrency& C : vCurrencies)
			{
				MyFile << _ConvertCurrencyObjectToLine(C) << endl;
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector<clsCurrency>vCurrencies = _LoadCurrencyDataFromFile();
		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() == _CurrencyCode)
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();

	}
	float GetRate()
	{
		return _Rate;
	}
	__declspec(property(get = GetRate, put = SetRate))float Rate;
	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{
		clsString::UpperCaseAllLetters(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
					
				}
			}
			return clsCurrency(enMode::EmptyMode, "", "", "", 0);
		}
	}
	static clsCurrency FindByCountry(string Country)
	{
		clsString::UpperCaseAllLetters(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);
				string SavedCountry = Currency.Country();
				clsString::UpperCaseAllLetters(SavedCountry);
				if (SavedCountry == Country)
				{
					MyFile.close();
					return Currency;

				}
			}
			return clsCurrency(enMode::EmptyMode, "", "", "", 0);

		}
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}
	static vector<clsCurrency>GetCurrenciesList()
	{
		vector<clsCurrency>vCurreciesList = _LoadCurrencyDataFromFile();
		return vCurreciesList;
	}
	static float ConvertToDollar(clsCurrency CurrencyFrom, float ExchangeAmount)
	{

		return  ExchangeAmount / CurrencyFrom.Rate;
	}
	static float ConvetFromDollar(clsCurrency CurrencyTo, float ExchangeAmount)
	{
		return ExchangeAmount * CurrencyTo.Rate;
	}
	static float _CurrencyCalclulator(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float ExchangeAmount)
	{
		float ToDollar = ConvertToDollar(CurrencyFrom, ExchangeAmount);
		float FromDollar = ConvetFromDollar(CurrencyTo, ToDollar);
		return FromDollar;

	}

};

