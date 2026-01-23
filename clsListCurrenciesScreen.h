#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include<vector>
class clsListCurrenciesScreen:clsScreen
{

	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << setw(12) << left << ""
			<< "|" << left << setw(25) << Currency.Country()
			<< "|" << left << setw(10) << Currency.CurrencyCode()
			<< "|" << left << setw(30) << Currency.CurrencyName()
			<< "|" << left << setw(10) << Currency.Rate << "|\n";
	}


public:
	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency>vCurrencies = clsCurrency::GetCurrenciesList();
		_DrawScreenHeader("Currencies List Screen.", "(" + to_string(vCurrencies.size()) + ") Currency.");
		cout << setw(12) << left << ""
			<< "-----------------------------------------------------------------------------------------------\n";
		cout << setw(12) << left << ""
			<< "|" << left << setw(25) << "Country"
			<< "|" << left << setw(10) << "Code"
			<< "|" << left << setw(30) << "Name"
			<< "|" << left << setw(10) << "Rate" << "|\n";
		cout << setw(12) << left << ""
			<< "-----------------------------------------------------------------------------------------------\n";
		if (vCurrencies.size() == 0)
		{
			cout << "No Currencies available" << endl;
		}
		else {
			for (clsCurrency& C : vCurrencies)
			{
				_PrintCurrencyRecord(C);
			}
			cout << setw(12) << left << ""
				<< "-----------------------------------------------------------------------------------------------\n";
		}
	




	}
};

