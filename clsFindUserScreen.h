#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsFindUserScreen:protected clsScreen
{
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
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");
		cout << "Enter UserName:";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User NOT found, choose another one:";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		cout << "User Found :-)" << endl;
		_PrintUser(User);
	}

};

