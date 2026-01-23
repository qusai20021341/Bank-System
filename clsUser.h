#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
#include <vector>
#include "clsUtil.h"
#include "Global.h"

using namespace std;
class clsUser:public clsPerson
{
	enum enMode{EmptyMode=1,UpdateMode=2,AddNewMode=3};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", 0, "", "", "", "");
	}
	static string _ConvertUserObjectToLine(clsUser User, string seprator = "#//#")
	{
		string Line =
			User.FirstName + seprator +
			User.LastName + seprator +
			User.Email + seprator +
			User.Phone + seprator +
			User.UserName + seprator +
			clsUtil::Encryption(User.Password)+ seprator +
			to_string(User.Permissions);
		return Line;
	}
	static clsUser _ConvertLineToUserObject(string Line, string seperator = "#//#")
	{
		vector<string>vUserData;
		vUserData = clsString::Split(Line, seperator);
		return clsUser(enMode::UpdateMode, vUserData[4], clsUtil::Decryption(vUserData[5]), stoi(vUserData[6]), vUserData[0], vUserData[1], vUserData[2], vUserData[3]);
	}
	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		string Line;
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
		}
		MyFile.close();

		return vUsers;
	}
	static void _SaveUsersDataToFile(vector<clsUser>vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsUser& U : vUsers)
			{
				if (!U.MarkedForDeleted())
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}

			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector<clsUser>vUsers = _LoadUsersDataFromFile();
		for (clsUser& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}
	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
		}
		MyFile.close();
	}
	string _PreperLogInRecord(string seperator="#//#")
	{
		return clsDate::GetSystemDateTimeString() + seperator + FirstName + seperator + clsUtil::Encryption(Password) + seperator + to_string(Permissions);
	}
	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line,string seprator="#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector<string>LoginRegisterDataLine = clsString::Split(Line, seprator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::Decryption(LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permissions =stoi( LoginRegisterDataLine[3]);
		return LoginRegisterRecord;
	}

	
public:
	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};
	enum enPermissions{pAll=-1,pListClient=1,pAddNewClient=2,pDeleteClient=4,pUpdateClient=8,pFindClient=16,pTransactions=32,pManageUsers=64,pShowLoginRegister=128,pCurrencyExChange=256};
	clsUser(enMode Mode, string UserName, string Password, int Permissions, string FirstName, string LastName, string Email, string Phone) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions=Permissions;

	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	static bool IsUserExist(string UserName)
	{
		clsUser User = Find(UserName);
		return !User.IsEmpty();
	}
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;
	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;
	string FullName()
	{
		return FirstName + " " + LastName;
	}
	static clsUser Find(string UserName)
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName,string Password)
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName &&User.Password==Password)
				{
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	enum enSaveResult{svFaildEmptyObject=1,svSucceed=2,svFaildUserNameExist=3};
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode: {
			return enSaveResult::svFaildEmptyObject;
			break;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceed;
			break;
		}
		case enMode::AddNewMode:
		{
			if (IsUserExist(_UserName))
			{
				return enSaveResult::svFaildUserNameExist;
			}
			else {
				_AddNew();
				return enSaveResult::svSucceed;
			}
			break;
		}
		}
	}
	static clsUser GetAddNewUsertObject(string UserName)
{
    return clsUser(enMode::AddNewMode, UserName, "", 0, "", "", "", "");
}
	bool Delete()
	{
		vector<clsUser>vUsers = _LoadUsersDataFromFile();
		for (clsUser& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}
	static vector<clsUser> GetUsersList()
	{
		vector<clsUser>vUsers = _LoadUsersDataFromFile();
		return vUsers;
	}
	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::pAll)
		{
			return true;
		}
		if ((Permission & this->Permissions) == Permission)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void RegisterLogin()
	{
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << _PreperLogInRecord() << endl;
			MyFile.close();
		}
	}
	static vector<stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector<stLoginRegisterRecord>vLoginRegisterRecord;
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			stLoginRegisterRecord LoginRegisterRecord;
			while (getline(MyFile, Line))
			{
				vLoginRegisterRecord.push_back(_ConvertLoginRegisterLineToRecord(Line));
			}
			MyFile.close();
		}
		return vLoginRegisterRecord;
	}
};

