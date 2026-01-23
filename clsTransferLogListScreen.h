#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector>
#include<iomanip>
class clsTransferLogListScreen:protected clsScreen
{

    static void _PrintTransferLogRecord(clsBankClient::stTransferRecord TransferRecord)
    {
        cout << "\t| "
            << setw(20) << left << TransferRecord.DateTime
            << "| " << setw(12) << left << TransferRecord.SourceAccNumber
            << "| " << setw(12) << left << TransferRecord.DestinationAccNumber
            << "| " << setw(10) << left << TransferRecord.TransferAmount
            << "| " << setw(12) << left << TransferRecord.SourceAccBalance
            << "| " << setw(12) << left << TransferRecord.DestinationAccBalance
            << "| " << setw(10) << left << TransferRecord.UserName
            << "|\n";
    }

public:
	static void ShowTransferLogListScreen()
	{
		vector<clsBankClient::stTransferRecord>vTransferLogRecords=clsBankClient::GetTransferLogList();

		_DrawScreenHeader("Transfer Log List Screen.","("+to_string(vTransferLogRecords.size())+") Record(s).");
        cout << "\t-------------------------------------------------------------------------------------------\n";
        cout << "\t| "
            << setw(20) << left << "Date/Time"
            << "| " << setw(12) << left << "s.Account"
            << "| " << setw(12) << left << "d.Account"
            << "| " << setw(10) << left << "Amount"
            << "| " << setw(12) << left << "s.Balance"
            << "| " << setw(12) << left << "d.Balance"
            << "| " << setw(10) << left << "User"
            << "|\n";
        cout << "\t-------------------------------------------------------------------------------------------\n";
        if (vTransferLogRecords.size() == 0)
        {
            cout << "There is NO Transfer Records available." << endl;
        }
        else {
            for (clsBankClient::stTransferRecord& TransferRecord : vTransferLogRecords)
            {
                _PrintTransferLogRecord(TransferRecord);
            }
            cout << "\t-------------------------------------------------------------------------------------------\n";

        }


		
	}
};

