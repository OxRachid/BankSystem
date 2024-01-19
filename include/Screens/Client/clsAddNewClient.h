#pragma once
#include <iostream>
#include <string>
#include "../../Lib/clsEnputValidate.h"
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"
using namespace std;

class clsAddNewClient : protected clsScreen {
private :

	// Read new client info 
	 static void  _ReadClientInfo(clsBankClient &client)
	{
		string Input; 
		
		Input=clsEnputValidate::ReadString("FirstName");
		client.SetFirstName(Input);
	
		Input=clsEnputValidate::ReadString("LastName");
		client.SetLastName(Input);
		
		Input=clsEnputValidate::ReadString("Email");
		client.SetEmail(Input);
		
		Input=clsEnputValidate::ReadString("Phone");
		client.SetPhone(Input);
		
		Input=clsEnputValidate::ReadString("PinCode");
		client.SetPinCode(Input);
		
		clsScreen::PrintMessage("Enter  Balance : ", "", false);
		float Balance=clsEnputValidate::ReadNumber<float>();
		client.SetAccountBalance(Balance);
		
	}
	
	// Print client info 
	 static void _Printclient(clsBankClient client)
	{
		cout << "┌──┘" << endl;
		cout << "│" << endl;
		cout<<left<<setw(20)<<"≡ FirstName"<<":  "<<client.GetFirstName()<<endl;
		cout<<left<<setw(20)<<"≡ LastName"<<":  "<<client.GetLastName()<<endl;
		cout<<left<<setw(20)<<"≡ Email"<<":  "<<client.GetEmail()<<endl;
		cout<<left<<setw(20)<<"≡ Phone"<<":  "<<client.GetPhone()<<endl;
		cout<<left<<setw(20)<<"≡ Account N"<<":  "<<client.GetAccountNumber()<<endl;
		cout<<left<<setw(20)<<"≡ PincCode"<<":  "<<client.GetPinCode()<<endl;
		cout<<left<<setw(20)<<"≡ Account Balance"<<":  "<<client.GetAccountBalance()<<endl;
		cout << "└──┐" << endl;
		cout << "    ∞" << endl;
	}
	
	
public :
	
	
	// Add new Client
	static void ShowAddNewClient()
	{
		// Check access permission
		if (!clsScreen::CheckAccess(clsBankUsers::enPermissions::pAddNewClient))
		{
			return;
		}
		
	
		// Draw header screen
		clsScreen::headrScreen("Add New Client", "",true);
		
		// Ask user to Enter the Account Number
		string AcNumber=clsEnputValidate::ReadString("Account Number");
		// Check if the Account Number is Already exsist
		while ( clsBankClient::isClientExiste(AcNumber) )
		{
			clsScreen::PrintMessage("This Account is Already exsis...");
			AcNumber=clsEnputValidate::ReadString("New Account Number");
		}
		// Return New Client Object that initialize with New Account N and its mode
		clsBankClient Newclient=clsBankClient::GetAddNewClientObject(AcNumber);
		// Read All the rest of data of this client
		_ReadClientInfo(Newclient);
		// Sava data to file an return enum Result
		clsBankClient::eSaveResult svResult=Newclient.Save();
		// Print the result of Saving 
		switch (svResult)
		{
			case clsBankClient::eSaveResult::e_SaveSucceed :
			{
				// Print new client data
				clsScreen::PrintMessage("Your  Data : ");
				_Printclient(Newclient);
				clsScreen::PrintMessage("Added successfully √");
				break;
			}
			case clsBankClient::eSaveResult::e_AccountAlreadyExsist :
			{
				clsScreen::PrintMessage("Failed, This Account Number is Already exsist");
				break;
			}
			case clsBankClient::eSaveResult::e_SaveFailed :
			{
				clsScreen::PrintMessage("Adding Failed √");
				break;
			}
		}
	}
	
	
};