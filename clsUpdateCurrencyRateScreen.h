#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsUpdateCurrencyRateScreen:protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card:" << endl;
		cout << "-------------------------------" << endl;
		cout << "Country  :" << Currency.Country() << endl;
		cout << "Code     :" << Currency.CurrencyCode() << endl;
		cout << "Name     :" << Currency.CurrencyName() << endl;
		cout << "Rate(1$) :" << Currency.Rate << endl;
		cout << "-------------------------------" << endl;
	}
public:
	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("Update Currency Screen");
		cout << "Please Enter Currency Code:";
		string Code = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(Code);
		while (Currency.IsEmpty())
		{
			cout << "Currency NOT Found, Try again:";
			string Code = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCode(Code);
		}
		_PrintCurrencyCard(Currency);
		cout << "Are you sure you want to Update the rate of this currency?(y/n)";
		char Answer;
		cin >> Answer;
		if (tolower(Answer))
		{
			cout << "\nUpdate Currency Rate:" << endl;
			cout << "-------------------------------" << endl;
			cout << "Enter New Rate:";
			float NewRate = clsInputValidate::ReadDblNumber();
			Currency.UpdateRate(NewRate);
			cout << "Currence Rate Updated Successfully :-)" << endl;
			_PrintCurrencyCard(Currency);

		}


	}
};

