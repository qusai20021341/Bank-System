#pragma once
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogListScreen.h"

class clsTransactionsScreen:protected clsScreen
{
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2, eShowTotalBalance, eTransfer=4,eShowTransferLog=5,eShowMainMenue = 6
	};
	static short _ReadTranscationsMenueOption()
	{
		cout << setw(37) << left <<"" << "choose what do you want to do [1/6]" << endl;
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return choice;
	}
	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferLogScreen()
	{
		clsTransferLogListScreen::ShowTransferLogListScreen();
	}
	static void _ShowTrasferScreen()
	{
		clsTransferScreen::ShowTrasferScreen();
	}
	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		case enTransactionsMenueOptions::eDeposit: {
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsScreen();
		}break;
		case enTransactionsMenueOptions::eWithdraw: {
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsScreen();
		}break;
		case enTransactionsMenueOptions::eShowTotalBalance: {
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsScreen();

		}break;
		case enTransactionsMenueOptions::eTransfer: {
			system("cls");
			_ShowTrasferScreen();
			_GoBackToTransactionsScreen();
		}break;
		case enTransactionsMenueOptions::eShowTransferLog: {
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsScreen();
		}break;
		case enTransactionsMenueOptions::eShowMainMenue: {
			//handled by main screen
		}break;
		}
	}
	static void _GoBackToTransactionsScreen()
	{
		cout << "Press any key to goback to Transactions Menue" << endl;
		system("pause");
		ShowTransactionsMenue();
	}
public:






	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("Transactions Screen");
		cout << setw(37) << left << "" << "=======================================================" << endl;
		cout << setw(37) << left << "" << "                  transaction Menue                      " << endl;
		cout << setw(37) << left << "" << "=======================================================" << endl;
		cout << setw(37) << left << "" << "\t[1]Deposit.\n";
		cout << setw(37) << left << "" << "\t[2]Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3]Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4]Transfer.\n";
		cout << setw(37) << left << "" << "\t[5]Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6]Main Menue.\n";
		cout << setw(37) << left << "" << "=======================================================" << endl;
		_PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTranscationsMenueOption());
	}
};

