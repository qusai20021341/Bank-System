#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsPerson.h"
#include<iomanip>
class clsListUsersScreen:protected clsScreen
{
	static void _PrintUserRecord(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;
	}

public:
	static void ShowUsersList()
	{
		vector<clsUser>vUsers = clsUser::GetUsersList();

		_DrawScreenHeader("User List Screen","("+to_string(vUsers.size())+") User.");
		cout << setw(8) << left << "" << "-----------------------------------------------------------------------------------------------" << endl;
		cout << setw(8) << left << "" << "| " << setw(12) << left << "UserName";
		cout << "| " << setw(25) << left << "Full Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions" << endl;
		cout << setw(8) << left << "" << "-----------------------------------------------------------------------------------------------" << endl;
		if (vUsers.size() == 0)
		{
			cout << "\t\t\tNo Users Available in The System." << endl;
		}
		else {
			for (clsUser& U : vUsers) {
				_PrintUserRecord(U);
				cout << endl;
			}
			cout << setw(8) << left << "" << "-----------------------------------------------------------------------------------------------" << endl;

		}

	}
};

