#pragma once
#include <iostream>
#include <string>
#include "../../Lib/clsEnputValidate.h"
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"
using namespace std;

class clsPrintTotalBalances : protected clsScreen {
	
private :

	// header table of balance
	static void _headerTableClientsBalance()
	{
		cout<<"┌─────────────────────┘└──────────────────────┐"<< endl;
		cout << "│" << left << setw(15) << "Account N∘" << "│" << left << setw(15) << "Name" <<"│" << left << setw(15) << "Balance" << endl;
		cout <<"└─────────────────────────────────────────────┘"<< endl;
	}
	
	
	// print client balance info at table with format
	static void _PrintClientBalanceAtTable(clsBankClient client)
	{
		cout << " " << left << setw(15) << client.GetAccountNumber()<< "│" << left << setw(15) <<client.GetFullName()<< "│" << left << setw(15) << client.GetAccountBalance()<< endl;
		cout <<" ─────────────────────────────────────────────"<< endl;
	}
	

public :
	
	static void PrintTotalBalances()
	{
		// Get clients list from file
		vector<clsBankClient> Vclients=clsBankClient::GetClientsList();
		// invoke to print header screen 
		string Title="Clients list";
		string Subtitle=to_string(Vclients.size());
		clsScreen::headrScreen(Title, Subtitle );
		// invoke to print header of table
		_headerTableClientsBalance();
		// Print clients balances  list
		if ( Vclients.size()==0 )
		{
			cout<<"                          No Clients Found"<<endl;
			cout <<"└──────────────────────────────────────────────────────┘"<< endl;
		}
		else
		{
			for ( clsBankClient &C : Vclients )
			{
				_PrintClientBalanceAtTable(C);
			}
		}
		
		
	}
	
	
};