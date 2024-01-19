#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsUpdateClient : protected clsScreen {
private :
	
	// Read new first name
	static void _ReadNewFirstName(clsBankClient &client)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update FirstName") )
		{
			string FName; 
			FName=clsEnputValidate::ReadString("New FirsName");
			client.SetFirstName(FName);
			clsScreen::PrintMessage("FirsName Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new last name
	static void _ReadNewLastName(clsBankClient &client)                                                      
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update LastName") )
		{
			string LName; 
			LName=clsEnputValidate::ReadString("New LastName");
			client.SetLastName(LName);
			clsScreen::PrintMessage("LastName Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new Email
	static void _ReadNewEmail(clsBankClient &client)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update Email") )
		{
			string Email; 
			Email=clsEnputValidate::ReadString("New Email");
			client.SetEmail(Email);
			clsScreen::PrintMessage("Email Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new Phone
	static void _ReadNewPhone(clsBankClient &client)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update Phone") )
		{
			string Phone; 
			Phone=clsEnputValidate::ReadString("New Phone");
			client.SetPhone(Phone);
			clsScreen::PrintMessage("Phone Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new PinCode
	static void _ReadNewPinCode(clsBankClient &client)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update PinCode") )
		{
			string PinCode; 
			PinCode=clsEnputValidate::ReadString("New Phone");
			client.SetPinCode(PinCode);
			clsScreen::PrintMessage("PinCode Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new Balance
	static void _ReadNewBalance(clsBankClient &client)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update Balance") )
		{
			float Balance; 
			cout<<"    │"<<endl;
			cout<<"    □ Enter New Balance : ";
			Balance=clsEnputValidate::ReadNumber<float>();
			client.SetAccountBalance(Balance);
			clsScreen::PrintMessage("Balance Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read client info manuely
	static void _ReadNewClientInfo(clsBankClient &client)
	{
		_ReadNewFirstName(client);
		_ReadNewLastName(client);
		_ReadNewEmail(client);
		_ReadNewPhone(client);
		_ReadNewPinCode(client);
		_ReadNewBalance(client);
	}
	
	
	// Display client info 
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
		cout << "│" << endl;
		cout << "└──┐" << endl;
		cout << "    ∞" << endl;
	}
	
public :
	
	// Update the client info
	static void ShowUpdateClient()
	{
		// Check access permission
		if (!clsScreen::CheckAccess(clsBankUsers::enPermissions::pUpdateClients))
		{
			return;
		}
		
		
		// Draw header screen
		clsScreen::headrScreen(" Update Screen", "",true);
		
		//Ask user for Account Number
		string AcNumber=clsEnputValidate::ReadString("Account Number");
		// Force user  to Enter an exsisting client
		clsBankClient::isAccountNumberExiste(AcNumber);
		// Find and Return the client object
		clsBankClient client=clsBankClient::Find(AcNumber);
		// Print the client info befor updating
		_Printclient(client);
		// Read new client info
		_ReadNewClientInfo(client);
		// Save new data in file and return enum Result
		clsBankClient::eSaveResult svResult=client.Save();
		// Print the result of Saving 
		switch (svResult)
		{
			case clsBankClient::eSaveResult::e_SaveSucceed :
			{
				// Print new client data
				clsScreen::PrintMessage("Your New Data : ");
				_Printclient(client);
				clsScreen::PrintMessage("All Data Updated successfully √");
				break;
			}
			case clsBankClient::eSaveResult::e_SaveFailed :
			{
				clsScreen::PrintMessage("Update Failed √");
				break;
			}
		}
	}
	
};