#pragma once
#include<iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		clsDate CurrentDate;
		cout << setw(37) << left << "" << "---------------------------------------------------" << endl;
		cout << setw(37) << left << "" << "\t     " << Title << "                   " << endl;
		cout << setw(37) << left << "" << "\t     "<<SubTitle<<"                   " << endl;
		cout << setw(37) << left << "" << "---------------------------------------------------" << endl;
		cout << setw(37) << left << "" << "User:" << CurrentUser.FullName() << endl;
		cout << setw(37) << left << "" << "Date:" <<CurrentDate.GetStringDate() << endl;
		


	}
	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << setw(37) << left << "" << "---------------------------------------------------" << endl;
			cout << setw(37) << left << "" << "\t     " << "Access Denied! Contact Your Admin" << "                   " << endl;
			cout << setw(37) << left << "" << "---------------------------------------------------" << endl;
			return false;
		}
		else {
			return true;
		}
	}
};

