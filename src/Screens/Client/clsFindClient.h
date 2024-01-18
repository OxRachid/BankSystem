#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsFindClient : protected clsScreen {
private :

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
		cout << "│" << endl;
		cout << "└──┐" << endl;
		cout << "    ∞" << endl;
	}
	
public :
	
		// Function to Find Client by AccountNumber
	static void FindClient()
	{
		// Check access permission
		if (!clsScreen::CheckAccess(clsBankUsers::enPermissions::pFindClient))
		{
			return;
		}
		
		
		// Draw header screen
		clsScreen::headrScreen("Find Client", "",true);
		
		// Ask user to Enter the Account Number
		string AcNumber=clsEnputValidate::ReadString("Account Number");
		// Force user  to Enter an exsisting client
		clsBankClient::isAccountNumberExiste(AcNumber);
		// Stric Checking and get update mode if the client existe or Empty mode if not 
		clsBankClient client = clsBankClient::Find(AcNumber);
		// Print the result of searching
		if ( !client.isEmpty() )
		{
			//print the client data
			_Printclient(client);
		}
		else
		{		
			clsScreen::PrintMessage("This Account Does'nt exsis... ");
		}
	}	
	
	
};