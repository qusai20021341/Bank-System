#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsFindCurrencyScreen:protected clsScreen
{
	enum enFindFindCurrencyOptions{eFindByCode=1,eFindByCountry=2};
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "Currency Card:" << endl;
		cout << "-------------------------------" << endl;
		cout << "Country  :" << Currency.Country() << endl;
		cout << "Code     :" << Currency.CurrencyCode() << endl;
		cout << "Name     :" << Currency.CurrencyName() << endl;
		cout << "Rate(1$) :" << Currency.Rate << endl;
		cout << "-------------------------------" << endl;
	}
	static short _ReadFindOption()
	{
		cout << "Find By:[1]Code  [2]Country" << endl;
		short choice = clsInputValidate::ReadIntNumberBetween(1, 2);
		return choice;
	}
	static void _PerformFindCurrency(enFindFindCurrencyOptions FindOption)
	{
		switch (FindOption)
		{
		case enFindFindCurrencyOptions::eFindByCode: {
			cout << "Please Enter Currency Code:";
			string Code = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(Code);
			if (Currency.IsEmpty())
			{
				cout << "Currency NOT Found !" << endl;
			}
			else {
				cout << "Currency Found :-)" << endl;
				_PrintCurrencyCard(Currency);

			}
			break;
		}
		case enFindFindCurrencyOptions::eFindByCountry: {
			cout << "Please Enter Currency Name:";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			if (Currency.IsEmpty())
			{
				cout << "Currency NOT Found !" << endl;
			}
			else {
				cout << "Currency Found :-)" << endl;
				_PrintCurrencyCard(Currency);

			}
			break;
		}
		}
	}
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");
		_PerformFindCurrency((enFindFindCurrencyOptions)_ReadFindOption());
	}
};

