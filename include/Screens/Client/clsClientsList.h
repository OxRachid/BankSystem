#pragma once
#include <iostream>
#include <string>
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"
#include "../../Core/Global.h"
using namespace std;

class clsClientsList : protected clsScreen {
private :
	
	// header table of client
	static void _headerTableClients()
	{
		cout <<"┌──────────────────────────┘└──────────────────────────┐"<< endl;
		cout << "│" << left << setw(10) << "FirstName" << "│" <<left << setw(9) << "LastName"<< "│" <<left << setw(11) << "Email"<< "│" <<left << setw(8) << "Phone"<< "│" <<left << setw(6) << "AC Nm" << "│" << left << setw(6) << "P-Cod" << "│" << left << setw(10) << "Balance"<< endl;
		cout <<"└──────────────────────────────────────────────────────┘"<< endl;
	}
	
	// print client info at table with format
	static void _PrintClientInfoAtTable(clsBankClient client)
	{
		cout << "│" << left << setw(10) <<client.GetFirstName() << "│" <<left << setw(9) <<client.GetLastName()<< "│" <<left << setw(11) <<client.GetEmail()<< "│" <<left << setw(8) <<client.GetPhone()<< "│" <<left << setw(6) <<client.GetAccountNumber()<< "│" << left << setw(6) << client.GetPinCode()<< "│" << left << setw(10) <<client.GetAccountBalance()<< endl;
		cout <<"└──────────────────────────────────────────────────────┘"<< endl;
	}
	
	
public :
	
	// Show Clients list
	static void ShowClientsList()
	{
		// Check access permission
		if (!clsScreen::CheckAccess(clsBankUsers::enPermissions::pListClients))
		{
			return;
		}
		
		// Get clients list from file
		vector<clsBankClient> Vclients=clsBankClient::GetClientsList();
		// invoke to print header screen 
		string Title="Clients list";
		string Subtitle=to_string(Vclients.size());
		clsScreen::headrScreen(Title, Subtitle );
		// invoke to print header of table
		_headerTableClients();
		// Print clients list
		if ( Vclients.size()==0 )
		{
			cout<<"                          No Clients Found"<<endl;
			cout <<"└──────────────────────────────────────────────────────┘"<< endl;
		}
		else
		{
			for ( clsBankClient &C : Vclients )
			{
				_PrintClientInfoAtTable(C);
			}
		}
	}
	
};
