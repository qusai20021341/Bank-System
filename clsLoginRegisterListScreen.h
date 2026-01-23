#pragma once
#include<iomanip>
#include<vector>
#include<fstream>
#include "clsScreen.h"
#include "clsString.h"
class clsLoginRegisterListScreen:protected clsScreen
{
    
    static void _PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord LoignRegisterRecord )
    {
        cout << "\t| "
            << setw(25) << left << LoignRegisterRecord.DateTime
            << "| " << setw(15) << left << LoignRegisterRecord.UserName
            << "| " << setw(12) << left << LoignRegisterRecord.Password
            << "| " << setw(12) << left << LoignRegisterRecord.Permissions
            << "|\n";
   

    }
public:
	static void ShowLoginRegisterList()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
        {
            return;
        }
        vector<clsUser::stLoginRegisterRecord>vLoginRegisterRecords = clsUser::GetLoginRegisterList();

		_DrawScreenHeader("Login Register List Screen","("+to_string(vLoginRegisterRecords.size())+") Record(s).");
        cout << "\t--------------------------------------------------------------------\n";
        cout << "\t| "
            << setw(25) << left << "Date/Time"
            << "| " << setw(15) << left << "UserName"
            << "| " << setw(12) << left << "Password"
            << "| " << setw(12) << left << "Permissions"
            << "|\n";
        cout << "\t--------------------------------------------------------------------\n";
        if (vLoginRegisterRecords.size() == 0)
        {
            cout << "No Login Data Available" << endl;
        }
        else
        {
            for (clsUser::stLoginRegisterRecord& Line : vLoginRegisterRecords)
            {
                _PrintLoginRegisterRecord(Line);
            }
            cout << "\t--------------------------------------------------------------------\n";

        }
        

	}
};

