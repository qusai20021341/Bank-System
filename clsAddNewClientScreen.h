#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsAddNewClientScreen:protected clsScreen
{
	static 	void _PrintClient(clsBankClient Client)
	{
		cout << "--------Client Card------------" << endl;
		cout << "First Name : " << Client.GetFirstName() << endl;
		cout << "Last Name  : " << Client. GetLastName() << endl;
		cout << "Email      : " << Client. GetEmail() << endl;
		cout << "Phone      :" << Client.GetPhone() << endl;
		cout << "Acc. Number: " << Client. AccountNumber() << endl;
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
	
	static void ShowNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("Add New Client Screen.");

		string AccountNumber = "";
		cout << "\nPlease Enter Account Number:" << endl;
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClietnExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, Choese another one:" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svFaildEmptyObject: {
			cout << "Error account was not saved because its empty" << endl;
			break;
		}
		case clsBankClient::enSaveResults::svSucceeded: {
			cout << "Account Added Successflly :-)" << endl;
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists: {
			cout << "Error Account Number is already exist !!" << endl;
			break;

		}

		}


	}

};

