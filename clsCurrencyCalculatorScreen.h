#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsCurrencyCalculatorScreen:protected clsScreen
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
	static void ShowCurrencyCalculatorScreen()
	{
		string Code1, Code2;
		char Answer = 'n';
		do {
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");
			cout << "\nPlease Enter Currency1 Code:";
			Code1 = clsInputValidate::ReadString();
			clsCurrency CurrencyFrom = clsCurrency::FindByCode(Code1);
			while (CurrencyFrom.IsEmpty())
			{
				cout << "\nCurrency1 NOT Found, Try another Code:";
				Code1 = clsInputValidate::ReadString();
				CurrencyFrom = clsCurrency::FindByCode(Code1);
			}
			cout << "\nPlease Enter Currency2 Code:";
			Code2 = clsInputValidate::ReadString();
			clsCurrency CurrencyTo = clsCurrency::FindByCode(Code2);
			while (CurrencyTo.IsEmpty())
			{
				cout << "\nCurrency1 NOT Found, Try another Code:";
				Code2 = clsInputValidate::ReadString();
				CurrencyFrom = clsCurrency::FindByCode(Code2);
			}
			cout << "\nEnter Amount To Exchange:";
			float ExchangeAmount = clsInputValidate::ReadDblNumber();
			float ConvetToDollar = clsCurrency::ConvertToDollar(CurrencyFrom, ExchangeAmount);
			if (CurrencyTo.CurrencyCode() == "USD")
			{
				cout << "\nConvert From:" << endl;
				_PrintCurrencyCard(CurrencyFrom);
				cout << ExchangeAmount << " " << CurrencyFrom.CurrencyCode() << " = " << ConvetToDollar << " USD" << endl;
			}
			else {
				cout << "\nConvert From:" << endl;
				_PrintCurrencyCard(CurrencyFrom);
				cout << ExchangeAmount << " " << CurrencyFrom.CurrencyCode() << " = " << ConvetToDollar << " USD" << endl;
				cout << "Converting From USD To:" << endl;
				_PrintCurrencyCard(CurrencyTo);
				cout << ExchangeAmount << " " << CurrencyFrom.CurrencyCode() << " = " << clsCurrency::ConvetFromDollar(CurrencyTo, ConvetToDollar) << " " << CurrencyTo.CurrencyCode() << endl;

			}
			cout << "Do you want to perform another calculation?(y/n)" << endl;
			cin >> Answer;

		} while (tolower(Answer)=='y');
		
		

	}
};

