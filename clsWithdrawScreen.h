#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsWithdrawScreen:protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "--------Client Card------------" << endl;
		cout << "First Name : " << Client.GetFirstName() << endl;
		cout << "Last Name  : " << Client.GetLastName() << endl;
		cout << "Email      : " << Client.GetEmail() << endl;
		cout << "Phone      :" << Client.GetPhone() << endl;
		cout << "Acc. Number: " << Client.AccountNumber() << endl;
		cout << "Passwor    : " << Client.PinCode << endl;
		cout << "Balance    : " << Client.AccountBalance << endl;
		cout << "-------------------------------" << endl;


	}
	static string _ReadAccountNumber()
	{
		cout << "Enter Account Number:" << endl;
		return clsInputValidate::ReadString();
	}
public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClietnExist(AccountNumber))
		{
			cout << "\nClient With Account Number [" << AccountNumber << "] is NOT exist,try again:\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		double WithdrawAmount = 0;
		cout << "Enter Withdraw Amount:";
		WithdrawAmount = clsInputValidate::ReadDblNumber();
		cout << "Are you sure you want to perform this transaction?(y/n)";
		char Answer;
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			
			if (Client.Withdraw(WithdrawAmount)) {
				cout << "Amount Withdrawed Successfully." << endl;
				cout << "New Balance is:" << Client.AccountBalance << endl;
			}
			else {
				cout << "\nCan't withdraw, Insuffecient Balance!" << endl;
				cout << "Amount to withdraw is:" << WithdrawAmount << endl;
				cout << "Your Balance is:" << Client.AccountBalance << endl;
			}
			
		}
		else {
			cout << "Operation was cnaseled" << endl;
		}

	}
};

