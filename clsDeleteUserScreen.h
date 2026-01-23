#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include "clsInputValidate.h"
class clsDeleteUserScreen:protected clsScreen
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
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");
		cout << "Enter UserName:";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "There is NO user with this UserName, try another one:";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
		char choice = 'n';
		cout << "Are you sure you want to Delete this User?(y/n)" << endl;
		cin >> choice;
		if (tolower(choice) == 'y')
		{
			if (User.Delete())
			{
				cout << "User Deleted Successfully." << endl;
				_PrintUser(User);
			}
			else {
				cout << "Error,User was not delelted" << endl;
			}
		}
	}

};

