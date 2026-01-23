#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsTotalBalancesScreen:protected clsScreen
{
	static void PrintClientRecordBalanceLine(clsBankClient C)
	{
		cout << "|" << left << setw(15) << C.AccountNumber();
		cout << "|" << left << setw(40) << C.FirstName + " " + C.LastName;
		cout << "|" << left << setw(12) << C.AccountBalance << endl;
	}

public:
	static void ShowTotalBalances()
	{
			vector<clsBankClient>vClients = clsBankClient::GetClientsList();
			_DrawScreenHeader("Balances List Screen","(" + to_string(vClients.size() )+ ") Clients");
		
			
			cout << "-----------------------------------------------------------------------------------------------\n";
			cout << "|" << left << setw(15) << "Account Number";
			cout << "|" << left << setw(40) << "Client Name";
			cout << "|" << left << setw(12) << "Balance" << endl;;
			cout << "-----------------------------------------------------------------------------------------------\n";
			double TotalBalances = clsBankClient::GetTotalBalances();
			if (vClients.size())
			{
				for (clsBankClient& C : vClients)
				{
					PrintClientRecordBalanceLine(C);
				}
				cout << "-----------------------------------------------------------------------------------------------\n";
				cout << "Total Balances: " << TotalBalances << endl;
				cout << "(" << clsUtil::NumberToText(TotalBalances) << ")" << endl;;

			}
			else {
				cout << "No Client avilable in the system!" << endl;
			}
		

	}
};

