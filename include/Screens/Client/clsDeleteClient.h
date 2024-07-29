#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsString.h"
using namespace std;

class clsDeleteClient : protected clsScreen {
private :
	
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
	
	// Delete 
	 static void ShowDeleteClient()
	{
		// Check access permission
		if (!clsScreen::CheckAccess(clsBankUsers::enPermissions::pDeleteClient))
		{
			return;
		}
		
		
		// Draw header screen
		clsScreen::headrScreen("Delete Screen", "",true);
		
		// Ask user to Enter Account number of client to delete
		string AcNumber=clsEnputValidate::ReadString("Account Number");
		// check if the client existe or not 
		clsBankClient::isAccountNumberExiste(AcNumber);
		// Find and Return the Client Object  that we are looking for
		clsBankClient client = clsBankClient::Find(AcNumber);
		// Print the client info befor deleting
		_Printclient(client);
		// Delete the client  and Print the result of deletion
		if ( clsString::WarningMessage("Delete") )
			{
				if (client.Delete() )
				{
					// Print the client info After deleting
					_Printclient(client);
					clsScreen::PrintMessage("Deleted successfully √");
				}
				else
				{
					clsScreen::PrintMessage("Delete Failed  √");
				}
			}
		else
			{
				clsScreen::PrintMessage("Delete Canceled  √");
			}
		
	}
	
	
	
};