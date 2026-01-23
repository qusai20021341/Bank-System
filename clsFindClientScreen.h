#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsFindClientScreen:protected clsScreen
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
public:
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("Find Client Screen");
		string AccountNumber = "";
		cout << "Please enter Account number" << endl;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClietnExist(AccountNumber))
		{
			cout << "Account Number is not found, choose another one:";
			AccountNumber = clsInputValidate::ReadString();
		}
		
			clsBankClient Client = clsBankClient::Find(AccountNumber);
			if (!Client.IsEmpty())
			{
				cout << "Client Found :-)" << endl;
				_PrintClient(Client);
			}
			else {
				cout << "Client Was Not Found" << endl;
			}
			
		

	}
};

