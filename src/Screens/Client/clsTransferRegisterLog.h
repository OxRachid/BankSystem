#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsTransferRegisterLog : protected clsScreen {

private :
	
		// header table of Users
	static void _headerTableTransferLog()
	{
		cout <<"┌──────────────────────────┘└──────────────────────────┐"<< endl;
		cout << "│" << left << setw(20) << "Date/Time" << "│" <<left << setw(8) << "F-Client"<< "│" <<left << setw(8) << "T-Client"<< "│" <<left << setw(7) << "Amount"<<  "│" <<left << setw(9) << "F-Balance"<< "│" <<left << setw(9) << "T-Balance"<< "│" <<left << setw(7) << "User"<<endl;
		cout <<"└──────────────────────────────────────────────────────┘"<< endl;
	}
	
	// print User  list  info at table with format
	static void _PrintTransferlogAtTable(clsBankClient::stTransferLog T)
	{
		cout << "│" << left << setw(20) <<T.DateTime<< "│" <<left << setw(8) <<T.FromClient<< "│" <<left << setw(8) <<T.ToClient<< "│" <<left << setw(7) <<T.Amount<<  "│" <<left << setw(9) <<T.FromClientBalance<< "│" <<left << setw(9) <<T.ToClientBalance<< "│" <<left << setw(7) <<T.UserName<<endl;
		cout <<"└──────────────────────────────────────────────────────┘"<< endl;
	}


public :
	
	static void ShowTransferLog()
	{
		
		vector<clsBankClient::stTransferLog> VTransferlog=clsBankClient::GetTransferLogfromFile();
		
		// Draw header screen
		string Title="Transfer Log Screen";
		string Subtitle=to_string(VTransferlog.size());
		clsScreen::headrScreen(Title,Subtitle,true);
		
		// Print the header of table
		_headerTableTransferLog();
		
		// Print each transfer log
		if ( VTransferlog.size()==0 )
		{
			cout<<"                          No Transfer log Found"<<endl;
			cout <<"└──────────────────────────────────────────────────────┘"<< endl;
		}
		else
		{
			for ( clsBankClient::stTransferLog &T : VTransferlog )
			{
				_PrintTransferlogAtTable(T);
			}
		}
		
	}
	
	
};