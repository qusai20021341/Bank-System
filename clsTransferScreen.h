#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen:protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:" << endl;
		cout << "-------------------------------" << endl;
		cout <<"Full Name:"<< Client.FirstName + " " + Client.LastName << endl;
		cout << "Acc. Number:" << Client.AccountNumber() << endl;
		cout << "Balance:" << Client.AccountBalance << endl;
		cout << "-------------------------------\n" << endl;

	}
	static double _ReadAmount(clsBankClient ClientFrom)
	{
		cout << "Enter Transfer Amount:";
		double TransferAmount = clsInputValidate::ReadDblNumber();
		while (TransferAmount > ClientFrom.AccountBalance)
		{
			cout << "Amount Exceeds the Available Balance, Enter another Amount:";
			TransferAmount = clsInputValidate::ReadDblNumber();
		}
		return TransferAmount;
	}
public:
	static void ShowTrasferScreen()
	{
		_DrawScreenHeader("Transfer Screen");
		string AccountNumber;
		cout << "\n\nPlease Enter Account Number to Transfer From:";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClietnExist(AccountNumber))
		{
			cout << "\nClinet NOT Found, Try another Account Number:";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient ClientFrom = clsBankClient::Find(AccountNumber);
		_PrintClient(ClientFrom);
		cout << "Please Enter Account Number to Transfer To:";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClietnExist(AccountNumber))
		{
			cout << "\nClinet NOT Found, Try another Account Number:";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient ClientTo = clsBankClient::Find(AccountNumber);
		_PrintClient(ClientTo);
		double TransferAmount = _ReadAmount(ClientFrom);
		cout << "Are you sure you want to perform this operation?(y/n)";
		char Answer;
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			if (ClientFrom.Transfer(TransferAmount, ClientTo))
			{
				cout << "\nTransfer done Successfully.\n" << endl;
				_PrintClient(ClientFrom);
				cout << "\n\n";
				_PrintClient(ClientTo);
			}
			else {
				cout << "Transfer Faild!!" << endl;
			}
			
		}


		



	}
};

