#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "../Lib/clsString.h"
#include "../Lib/clsEnputValidate.h"
#include "../Lib/clsUtil.h"
#include "clsBankUsers.h"
using namespace std;

// Define the name of file where we will store client data
const string ClientFile="ClientFile.txt";
// Define the name of file where we will store transfer register data
const string TransferRegisterFile="TransferRegisterFile.txt";

class clsBankClient : public clsPerson {
private :
	
	// Define enum of client mode
	enum eMode { e_EmptyMode=0, e_UpdateMode=1, e_AddNewClient=2};	
	
	eMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkDeletion=false;

	
	// Get New Client Object with its Mode and its Account N
	static clsBankClient _GetAddNewClientObject(string AcNumber)
	{
		return clsBankClient ( e_AddNewClient, "", "", "", "", AcNumber, "", 0);
	}
	
	// Convert String Line to Client Object
	static clsBankClient _ConvertLineToClientObject(string line)
	{
		vector<string> Vstring=clsString::SplitString(line, "#");
		return clsBankClient(eMode::e_UpdateMode, Vstring[0], Vstring[1], Vstring[2], Vstring[3], Vstring[4], Vstring[5], stof(Vstring[6]));
	}
	
	// Return Empty Client Object
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient( eMode::e_EmptyMode, "","","","","","",0);
	}
	
	
	// Convert object to line string
	static string _ConvertObjectToLine(clsBankClient client)
	{
		string Sclient;
		Sclient+=client.GetFirstName();
		Sclient+="#";
		Sclient+=client.GetLastName();
		Sclient+="#";
		Sclient+=client.GetEmail();
		Sclient+="#";
		Sclient+=client.GetPhone();
		Sclient+="#";
		Sclient+=client.GetAccountNumber();
		Sclient+="#";
		Sclient+=client.GetPinCode();
		Sclient+="#";
		Sclient+=to_string(client.GetAccountBalance());
		return Sclient;
	}
	
	// Save Data to File
	static void _SaveDateToFile(vector<clsBankClient> _Vclients)
	{
		fstream MyFile;
		MyFile.open(ClientFile, ios::out);
		if( MyFile.is_open() )
		{
			string Line;
			for ( clsBankClient &C : _Vclients )
			{
				if ( C._MarkDeletion==false)
				{
					Line=_ConvertObjectToLine(C);
					MyFile<<Line<<endl;
				}
			}
			MyFile.close();
		}
	}
	

	// Get Data From File
	static vector<clsBankClient> _GetDataFromFile()
	{
		vector<clsBankClient> _Vclients;
		fstream MyFile;
		MyFile.open(ClientFile, ios::in); 
		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline(MyFile, Line) )
			{
				clsBankClient client=_ConvertLineToClientObject(Line);
				_Vclients.push_back(client);
			}
			MyFile.close();
		}
		return _Vclients;
	}
	
	// Update client info
	 void _Update()
	{
		vector<clsBankClient> _Vclients = _GetDataFromFile();
		for ( clsBankClient &C : _Vclients )
		{
			if ( C._AccountNumber== GetAccountNumber() )
			{
				C=*this;
				break;
			}
		}
		_SaveDateToFile(_Vclients);
	}
	
	// Add New Client
	void _AddNewClient()
	{
		string Line = _ConvertObjectToLine(*this);
		fstream MyFile;
		MyFile.open(ClientFile, ios::out | ios::app);
		if ( MyFile.is_open() )
		{
			MyFile<<Line<<endl;
			MyFile.close();
		}
	}
	
	
	// Get Toral Balances
	static double _GetTotalBalances()
	{
		double TotalBalance=0;
		// Get Client Object Data from File and store it in Vector
		vector<clsBankClient> _Vclients = _GetDataFromFile();
		// Get total balances
		for ( clsBankClient &C : _Vclients )
		{
			TotalBalance+=C._AccountBalance;
		}
		return TotalBalance;
	}
	
	// Convert transfer register to line string
	string _ConvertTransferRegistertoLine(double Amount, clsBankClient ToClient,  string UserName)
	{
		string TransferRegister;
		TransferRegister+=clsDate::GetSystemDateAndTimeinString()+"#";
		TransferRegister+=GetAccountNumber()+"#";
		TransferRegister+=ToClient.GetAccountNumber()+"#";
		TransferRegister+=to_string(Amount)+"#";
		TransferRegister+=to_string(GetAccountBalance())+"#";
		TransferRegister+=to_string(ToClient.GetAccountBalance())+"#";
		TransferRegister+=UserName;
		return TransferRegister;
	}
	
		
	// Save transfer register log in file
	void _TransferRegister(double Amount, clsBankClient ToClient, string UserName)
	{
		string line = _ConvertTransferRegistertoLine(Amount , ToClient, UserName);
		fstream MyFile;
		MyFile.open(TransferRegisterFile, ios::app);
		if ( MyFile.is_open() )
		{
			MyFile<<line<<endl;
			MyFile.close();
		}
	}
	
public :
	
	// Default constructor
	clsBankClient(){}
	
	// Constructor  parameterize for signing member varaibles
	clsBankClient(eMode Mode, string Firstname, string Lastname, string Email, string Phone, string AccountNumber, string PinCode, float Balance): clsPerson( Firstname, Lastname, Email, Phone)                                 
	{
		_Mode=Mode;
		_AccountNumber=AccountNumber;
		_PinCode=PinCode;
		_AccountBalance=Balance;
	}                                                                                                         
	
	struct stTransferLog{
		string DateTime;
		string FromClient;
		string ToClient;
		double Amount;
		double FromClientBalance;
		double ToClientBalance;
		string UserName;
	};
	
	// Convert line to transfer log struct
	static stTransferLog  ConvertLinetostTransferLog(string line)
	{
		vector<string> Vstring=clsString::SplitString(line,"#");
		stTransferLog TrLog;
		TrLog.DateTime=Vstring[0];
		TrLog.FromClient=Vstring[1];
		TrLog.ToClient=Vstring[2];
		TrLog.Amount=stod(Vstring[3]);
		TrLog.FromClientBalance=stod(Vstring[4]);
		TrLog.ToClientBalance=stod(Vstring[5]);
		TrLog.UserName=Vstring[6];
		return TrLog;
	}
	
	// Get transfer log from file
	static vector<stTransferLog> GetTransferLogfromFile()
	{
		vector<stTransferLog> Vtransferlog;
		string line;
		fstream MyFile;
		MyFile.open(TransferRegisterFile, ios::in);
		if (MyFile.is_open())
		{
			while(getline(MyFile,line))
			{
				stTransferLog X=ConvertLinetostTransferLog(line);
				Vtransferlog.push_back(X);
			}
			MyFile.close();
		}
		return Vtransferlog;
	}
	
	// Get AccountNumber
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	
	// Set PinCode
	void SetPinCode( string PinCode)
	{
		_PinCode=PinCode;
	}
	// Get PinCode
	string GetPinCode()
	{
		return _PinCode;
	}
	
	// Set AccountBalance
	void SetAccountBalance( float Balance )
	{
		_AccountBalance=Balance;
	}
	// Get AccountBalance
	float GetAccountBalance()
	{
		return _AccountBalance;
	}


	// Get Client list
	static vector<clsBankClient>  GetClientsList()
	{
		return _GetDataFromFile();
	}
	
	// Get new client object initialize with ac number and mode
	static clsBankClient GetAddNewClientObject(string AcNumber)
	{
		return _GetAddNewClientObject(AcNumber);
	}
	
	// Convert String Line to Client Object
	static clsBankClient ConvertLineToClientObject(string line)
	{
		return _ConvertLineToClientObject(line);
	}
	
	
	// Force the user to Enter an existing client
	static void isAccountNumberExiste(string &AcNumber)
	{
		while ( !isClientExiste(AcNumber) )
		{
			cout << "    │" << endl;
			cout << "    ⊗ This Account Does't exsis... "<<endl;
			AcNumber=clsEnputValidate::ReadString("Account Number");
		}
	}
	
	
	
	// add Money to client balance
	void MakeDeposit(double Amount)
	{
		// deposit Amount
		_AccountBalance+=Amount;
		// Save new data in the file
		Save();
	}
	
	// Subtruct Money from client balance
	bool MakeWithdraw(double Amount)
	{
		if ( Amount > _AccountBalance || Amount <= 0 )
		{
			return false;
		}
		else {
			// Withdraw Amount
			_AccountBalance-=Amount;
			// Save new data in the file
			Save();
		}
		return true;
	}
	
	// Check if Amount to withdraw is valid
	void isAmountCanBeWithdraw(double &Amount)
	{
		while ( Amount > _AccountBalance || Amount <= 0)
		{
			cout<< "    │" << endl;
			cout << "    ⊗ This Amount ["<<Amount<<"] is invalid, Enter another one :  ";
			Amount=clsEnputValidate::ReadNumber<double>();
		}
	}
	
	// Delete client
	bool Delete()
	{
		// Get Client Object Data from File and store it in Vector
		vector<clsBankClient> Vclients = _GetDataFromFile();
		// Put true Mark delete  in the exact client 
		for ( clsBankClient &C : Vclients )
		{
			if ( C._AccountNumber==GetAccountNumber() )
			{
				C._MarkDeletion=true;
			}
		}
		// Save new data in the file
		_SaveDateToFile(Vclients);
		// Make the current client object Empty 
		*this=_GetEmptyClientObject();
		return true;
	}
	
	// Define enum of Save Result
	enum eSaveResult { e_SaveFailed=0, e_SaveSucceed=1, e_AccountAlreadyExsist=2};
	// Save data and return enum result
	eSaveResult Save()
	{
		switch (_Mode)
		{
				case eMode::e_EmptyMode :
				{
					return e_SaveFailed;
					break;
				}
				case eMode::e_UpdateMode :
				{
					_Update();
					return e_SaveSucceed;
					break;
				}		
				case eMode::e_AddNewClient :
				{
					if ( isClientExiste(GetAccountNumber()) )
					{
						return e_AccountAlreadyExsist;
					}
					else
					{
						_AddNewClient();
						_Mode=e_UpdateMode;
						return e_SaveSucceed;
					}
				}
		}
	}
	
	// Check if the client object is Empty 
	bool isEmpty()
	{
		return ( _Mode==eMode::e_EmptyMode);
	}
	
	// Check if the client object exist 
	static bool isClientExiste(string AccountNumber)
	{
		clsBankClient client=clsBankClient::Find(AccountNumber);
		return ( !client.isEmpty() );
	}
	
	// Function to Find Client by AccountNumber
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open(ClientFile, ios::in); // read mode
		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline(MyFile, Line) )
			{
				clsBankClient client=_ConvertLineToClientObject(Line);
				if ( client._AccountNumber==AccountNumber)
				{
					MyFile.close();
					return client;
				}
			}
			
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	
	// Function to Find Client by AccountNumber && PinCode
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open(ClientFile, ios::in); // read mode
		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline(MyFile, Line) )
			{
				clsBankClient client=_ConvertLineToClientObject(Line);
				if ( client._AccountNumber==AccountNumber && client._PinCode==PinCode)
				{
					MyFile.close();
					return client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	
	
	
	// Transfer function
	bool Transfer(double Amount, clsBankClient &ToClient, string UserName)
	{
		if ( Amount > GetAccountBalance() || Amount <= 0 )
			return false;
		
		MakeWithdraw(Amount);
		ToClient.MakeDeposit(Amount);
		// Save transfer register log in file
		_TransferRegister(Amount, ToClient, UserName);
		return true;
	}
	
};
