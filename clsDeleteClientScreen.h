#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDeleteClientScreen:protected clsScreen
{
	static 	void _PrintClient(clsBankClient Client)
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

public:
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("Delete Client Screen");
		string AccountNumber;
		cout << "Please Enter Account Number:" << endl;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClietnExist(AccountNumber))
		{
			cout << "Account number is not found, please choose another one." << endl;
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		cout << "Are you sure you want to delete this Clinet?(y/n)" << endl;
		char Answer = 'n';
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			if (Client.Delete())
			{
				cout << "Clinet Deleted Successfully." << endl;
				_PrintClient(Client);
			}
			else {
				cout << "Error,Client was not delelted" << endl;
			}
		}
	}
};

