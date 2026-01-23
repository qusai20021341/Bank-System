#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsUpdateClientScreen:protected clsScreen
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
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter First Name:" << endl;
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name:" << endl;
		Client.LastName = clsInputValidate::ReadString();
		cout << "Enter Email:" << endl;
		Client.Email = clsInputValidate::ReadString();
		cout << "Enter Phone:" << endl;
		Client.Phone = clsInputValidate::ReadString();
		cout << "Enter PinCode:" << endl;
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Enter AccountBalance:" << endl;
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

public:
	void static  ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("Update Client Screen");
		cout << "Please enter client account number:\n";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClietnExist(AccountNumber)) {
			cout << "Account number is not fount, chose another one:" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		cout << "Are you sure you want to update this Client Info?(y/n)" << endl;
		char Answer = 'n';
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			cout << "\nUpdate Client Info" << endl;
			cout << "------------------------" << endl;
			_ReadClientInfo(Client);
			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client.Save();
			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svFaildEmptyObject: {
				cout << "Error account was not saved because its empty" << endl;
				break;
			}
			case clsBankClient::enSaveResults::svSucceeded: {
				cout << "Account Updated Successfully :-)" << endl;
				_PrintClient(Client);
			}
			}
		}
		

	}
};

