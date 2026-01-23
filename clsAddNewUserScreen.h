#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include "clsInputValidate.h"

class clsAddNewUserScreen:protected clsScreen
{
	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';
		cout << "Do you want to give full access?(y,n)" << endl;
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			return -1;
		}
		cout << "Do you want to give access to:" << endl;
		cout << "\nShow Client List?(y/n)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pListClient;
		}
		cout << "\nAdd New Client?(y/n)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\nDelete Client?(y/n)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}
		cout << "\nUpdate Client?(y/n)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}
		cout << "\nFind Client?(y/n)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}
		cout << "\nTransactions?(y/n)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}
		cout << "\nManage Users?(y/n)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}
		cout << "\nShow Login Register?(y/n)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pShowLoginRegister;
		}
		cout << "\nCurrencies Exchange ?(y/n)";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pCurrencyExChange;
		}

		return Permissions;
	}
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Enter First Name:";
		User.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name:";
		User.LastName = clsInputValidate::ReadString();
		cout << "Enter Email:";
		User.Email = clsInputValidate::ReadString();
		cout << "Enter Phone:";
		User.Phone = clsInputValidate::ReadString();
		cout << "Enter Password:";
		User.Password = clsInputValidate::ReadString();
		cout << "Enter Permissions:";
		User.Permissions = _ReadPermissionsToSet();

	}
	static void _PrintUser(clsUser User)
	{
		cout << "---------------User Card------------------" << endl;
		cout << "First Name  :" << User.FirstName << endl;
		cout << "Last Name   :" << User.LastName << endl;
		cout << "Full Name   :" << User.FullName() << endl;
		cout << "Email       :" << User.Email << endl;
		cout << "Phone       :" << User.Phone << endl;
		cout << "UserName    :" << User.UserName << endl;
		cout << "Password    :" << User.Password << endl;
		cout << "Permissions :" << User.Permissions << endl;
		cout << "------------------------------------------" << endl;

	}

public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add New User Screen");
		cout << "Enter UserName:";
		string UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "This UserName is already used, choose another one:";
			UserName = clsInputValidate::ReadString();
		}
		clsUser NewUser = clsUser::GetAddNewUsertObject(UserName);
		_ReadUserInfo(NewUser);
		clsUser::enSaveResult SaveResult;
		SaveResult = NewUser.Save();
		switch (SaveResult)
		{
		case clsUser::enSaveResult::svSucceed:
		{
			cout << "User Saved Successfully :-)" << endl;
			_PrintUser(NewUser);
			break;
		}
		case clsUser::enSaveResult::svFaildEmptyObject:
		{
			cout << "Error, User was not saved because it's Empty." << endl;
			break;
		}
		case clsUser::enSaveResult::svFaildUserNameExist:
		{
			cout<<"Error, User was not saved becase UserName is Used" << endl;
			break;
		}
		}

	}
};

