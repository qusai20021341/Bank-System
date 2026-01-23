#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h";
#include "Global.h"
#include "clsDate.h"
#include<fstream>
#include "clsString.h"
#include "clsDate.h"
class clsLoginScreen:protected clsScreen
{
	
	
	static bool _Login()
	{
		string UserName, Password;
		bool LoginFaild = false;
		short FaildLoginCount = 0;

		do {
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvalid Username/Password." << endl;
				cout << "You have " << (3-FaildLoginCount) << " trails to login" << endl;

				if (FaildLoginCount == 3)
				{
					cout << "\nYou'r Locked after 3 faild trails." << endl;
					return false;
				}
				
					
			}
			cout << "\nEnter UserName:" << endl;
			UserName = clsInputValidate::ReadString();
			cout << "Enter Password:" << endl;
			Password = clsInputValidate::ReadString();
			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();

	}
};

