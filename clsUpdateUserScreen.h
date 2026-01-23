#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include "clsInputValidate.h"
class clsUpdateUserScreen:protected clsScreen
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

		return Permissions;
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

public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");
		cout << "Enter UserName:";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "There is NO user with this UserName, try another one:";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
		char choice;
		cout << "Are you sure you want to update this User?(y/n)";
		cin >> choice;
		if (tolower(choice) == 'y')
		{
			cout << "\nUpdate User Info" << endl;
			cout << "---------------------------" << endl;
			_ReadUserInfo(User);
			clsUser::enSaveResult SaveResult;
			SaveResult = User.Save();
			switch (SaveResult)
			{
			case clsUser::enSaveResult::svSucceed: {
				cout << "User Updated Successfully :-)" << endl;
				_PrintUser(User);
				break;
			}
			case clsUser::enSaveResult::svFaildEmptyObject: {
				cout << "Error, Empty User" << endl;
			}

			}
		}

	}
};

