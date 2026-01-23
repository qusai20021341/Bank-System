#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen:protected clsScreen
{
	enum _enCurrencyExchangeOptions{pListCurrencies=1,pFindCurrency=2,pUpdateRate=3,pCurrencyCalculator=4,pMainMenue=5};
	static void _GoBackToCurrencyExchangeMenueScreen()
	{
		cout << "Press any key to goback to Transactions Menue" << endl;
		system("pause");
		ShowCurrencyExchangeMenue();
	}
	static short ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "choose what do you want to do [1-5]" << endl;
		short choice = clsInputValidate::ReadIntNumberBetween(1, 5);
		return choice;
	}
	static void _ShowListCurrenciesScreen()
	{
		clsListCurrenciesScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurrencyScrren()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _PerformCurrencyExchangeMenueObject(_enCurrencyExchangeOptions MenueOption)
	{
		switch (MenueOption)
		{
		case _enCurrencyExchangeOptions::pListCurrencies: {
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenueScreen();
			break;
		}
		case _enCurrencyExchangeOptions::pFindCurrency: {
			system("cls");
			_ShowFindCurrencyScrren();
			_GoBackToCurrencyExchangeMenueScreen();
			break;
		}
		case _enCurrencyExchangeOptions::pUpdateRate: {
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenueScreen();
			break;
		}
		case _enCurrencyExchangeOptions::pCurrencyCalculator: {
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenueScreen();
			break;
		}
		case _enCurrencyExchangeOptions::pMainMenue: {
			
			//Go back to main menue
		}




		}

	}

public:
	static void ShowCurrencyExchangeMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExChange))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("Currency Exchange Main Screen");
		cout << setw(37) << left << "" << "=======================================================" << endl;
		cout << setw(37) << left << "" << "                Currency Exchange Menue                      " << endl;
		cout << setw(37) << left << "" << "=======================================================" << endl;
		cout << setw(37) << left << "" << "\t[1]List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2]Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3]Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4]Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5]Mian Menue.\n";
		cout << setw(37) << left << "" << "=======================================================" << endl;
		_PerformCurrencyExchangeMenueObject((_enCurrencyExchangeOptions)ReadCurrencyExchangeMenueOption());

	}
};

