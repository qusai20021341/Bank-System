#pragma once
#include<iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include <vector>
#include <fstream>
#include "Global.h"
#include "clsDate.h"
#include "clsString.h"


using namespace std;
class clsBankClient:public clsPerson
{
	enum enMode{EmptyMode=1,UpdateMode=2,AddNewMode=3};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete=false;


	static clsBankClient _ConvertLineToClientObject(string Line,string seperator="#//#")
	{
		vector<string>vClientData;
		vClientData = clsString::Split(Line, seperator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	static string _ConvertClientObjectToLine(clsBankClient Client,string seprator="#//#")
	{
		string Line = Client.FirstName + seprator + Client.LastName + seprator + Client.Email + seprator + Client.Phone + seprator + Client.AccountNumber() + seprator + Client.PinCode + seprator + to_string(Client.AccountBalance);
		return Line;
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static void _SaveClientsDataToFile(vector<clsBankClient>vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				if (!C.MarkedForDeleted())
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
				
			}
			MyFile.close();
		}
	}
	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		string Line;
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}
		}
		MyFile.close();
		
		return vClients;
	}
	void _Update()
	{
		vector<clsBankClient> _vClients=_LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
			}
		}
		
		_SaveClientsDataToFile(_vClients);
	
	}
	void _AddNew() 
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
		}
		MyFile.close();
	}
	string _PreperTransferRecord(clsBankClient DestinationClient,double Amount,string seprator="#//#")
	{
		return clsDate::GetSystemDateTimeString() + seprator + _AccountNumber + seprator + DestinationClient.AccountNumber() + seprator + to_string(Amount) + seprator + to_string(_AccountBalance) + seprator + to_string(DestinationClient.AccountBalance) + seprator + CurrentUser.UserName;
	}
	void _RegisterTransferLog(clsBankClient DestinationClient, double Amount)
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << _PreperTransferRecord(DestinationClient, Amount) << endl;
			MyFile.close();
		}
	}
	struct stTransferRecord;
	static stTransferRecord _ConverTransferLogLineToRecord(string Line)
	{
		stTransferRecord TransferRecord;
		vector<string>vTransferData = clsString::Split(Line, "#//#");
		TransferRecord.DateTime = vTransferData[0];
		TransferRecord.SourceAccNumber = vTransferData[1];
		TransferRecord.DestinationAccNumber = vTransferData[2];
		TransferRecord.TransferAmount = stod(vTransferData[3]);
		TransferRecord.SourceAccBalance = stod(vTransferData[4]);
		TransferRecord.DestinationAccBalance = stod(vTransferData[5]);
		TransferRecord.UserName = vTransferData[6];
		
		return TransferRecord;
	}


public:
	struct stTransferRecord
	{
		string DateTime;
		string SourceAccNumber;
		string DestinationAccNumber;
		double TransferAmount;
		double SourceAccBalance;
		double DestinationAccBalance;
		string UserName;
	};
	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone,  string AccountNumber, string PinCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	string AccountNumber()
	{
		return _AccountNumber;
	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode==PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	enum enSaveResults{svFaildEmptyObject=1,svSucceeded=2,svFaildAccountNumberExists=3};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode: {
			return enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode: {

			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::AddNewMode: {
			if (clsBankClient::IsClietnExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else {
				_AddNew();
				return enSaveResults::svSucceeded;

			}
			break;
		}
		}
	}
	static bool IsClietnExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(AddNewMode, "", "", "", "", AccountNumber, "", 0);

	}
	bool Delete()
	{
		vector<clsBankClient>vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}
	static vector<clsBankClient> GetClientsList()
	{
		vector<clsBankClient>vClients = _LoadClientsDataFromFile();
		return vClients;
	}
	static double GetTotalBalances()
	{
		vector<clsBankClient>vClients = _LoadClientsDataFromFile();
		double TotalBalance = 0;
		for (clsBankClient& C : vClients)
		{
			TotalBalance += C.AccountBalance;
		}
		return TotalBalance;
	}
	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
		
	}
	bool Transfer(double Amount, clsBankClient& DestinationClient)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else {
			Withdraw(Amount);
			DestinationClient.Deposit(Amount);
			_RegisterTransferLog(DestinationClient, Amount);
			return true;
		}
	}
	static vector<stTransferRecord> GetTransferLogList()
	{
		vector<stTransferRecord> vTransferRecords;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line="";
			while (getline(MyFile, Line))
			{
				vTransferRecords.push_back(_ConverTransferLogLineToRecord(Line));
			}
			MyFile.close();
		}
		return vTransferRecords;
	}

};

