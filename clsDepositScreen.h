#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsDepositScreen:clsScreen
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
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClietnExist(AccountNumber))
		{
			cout << "\nClient With Account Number [" << AccountNumber << "] is NOT exist,try again:\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		double DepositAmount = 0;
		cout << "Enter Deposit Amount:";
		DepositAmount = clsInputValidate::ReadDblNumber();
		cout << "Are you sure you want to perform this transaction?(y/n)";
		char Answer;
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Client.Deposit(DepositAmount);
			cout << "Amount Deposited Successfully." << endl;
			cout << "New Balance is:" << Client.AccountBalance << endl;
		}
		else {
			cout << "Operation was cnaseled" << endl;
		}
		


	}
};

