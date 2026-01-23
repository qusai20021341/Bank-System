#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"

class clsClientListScreen:protected clsScreen
{
	static void _PrintClientRecordLine(clsBankClient C)
	{

		cout << "|" << left << setw(15) << C.AccountNumber();
		cout << "|" << left << setw(20) << C.FirstName + " " + C.LastName;
		cout << "|" << left << setw(12) << C.Phone;
		cout << "|" << left << setw(20) << C.Email;
		cout << "|" << left << setw(10) << C.PinCode;
		cout << "|" << left << setw(12) << C.AccountBalance << endl;

	}

public:

	static void ShowClientsList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClient))
		{
			return;
		}
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		_DrawScreenHeader("Clinets List Screen","("+ to_string(vClients.size())+")" + " Client(s)");
		cout << "-----------------------------------------------------------------------------------------------\n";
		cout << "|" << left << setw(15) << "Account Number";
		cout << "|" << left << setw(20) << "Client Name";
		cout << "|" << left << setw(12) << "Phone";
		cout << "|" << left << setw(20) << "Email";
		cout << "|" << left << setw(10) << "PinCode";
		cout << "|" << left << setw(12) << "Balance" << endl;;
		cout << "-----------------------------------------------------------------------------------------------\n";
		if (vClients.size() != 0)
		{
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordLine(C);
			}
			cout << "-----------------------------------------------------------------------------------------------\n";

		}
		else {
			cout << "No Clients available in the system!" << endl;
		}


	}
};

