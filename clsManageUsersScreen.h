#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersScreen:protected clsScreen
{
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eGoBackToMainMenue = 6
	};
	static short ReadManageUSersMenuseOption()
	{
		cout << setw(37) << left << "" << "choose what do you want [1 to 6]" << endl;
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return choice;
	}
	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "Press any key to goback to manage users menue" << endl;
		system("pause");
		ShowManageUsersMenue();
	}

	static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersOption)
	{
		switch (ManageUsersOption)
		{
			case enManageUsersMenueOptions::eListUsers:
			{
				system("cls");
				_ShowListUsersScreen();
				_GoBackToManageUsersMenue();

			}break;
			case enManageUsersMenueOptions::eAddNewUser:
			{
				system("cls");
				_ShowAddNewUserScreen();
				_GoBackToManageUsersMenue();
			}break;
			case enManageUsersMenueOptions::eDeleteUser:
			{

				system("cls");
				_ShowDeleteUserScreen();
				_GoBackToManageUsersMenue();
			}break;
			case enManageUsersMenueOptions::eUpdateUser:
			{
				system("cls");
				_ShowUpdateUserScreen();
				_GoBackToManageUsersMenue();
			}
			case enManageUsersMenueOptions::eFindUser: {
				system("cls");
				_ShowFindUserScreen();
				_GoBackToManageUsersMenue();
			}break;
			case enManageUsersMenueOptions::eGoBackToMainMenue: {
				//handled by main menue
			}
		}

	}


public:
	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("Mangae Users Screen");
		cout << setw(37) << left << "" << "=======================================================" << endl;
		cout << setw(37) << left << "" << "                  Manage Users Menue                      " << endl;
		cout << setw(37) << left << "" << "=======================================================" << endl;
		cout << setw(37) << left << "" << "\t[1]List Users.\n";
		cout << setw(37) << left << "" << "\t[2]Add New User.\n";
		cout << setw(37) << left << "" << "\t[3]Delete User.\n";
		cout << setw(37) << left << "" << "\t[4]Update User.\n";
		cout << setw(37) << left << "" << "\t[5]Find User.\n";
		cout << setw(37) << left << "" << "\t[6]Main Menue.\n";
		cout << setw(37) << left << "" << "=======================================================" << endl;
		_PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUSersMenuseOption());
	}
};

