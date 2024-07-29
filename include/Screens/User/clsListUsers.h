#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankUsers.h"
using namespace std;

class clsListUsers : protected clsScreen {

private :

	// header table of Users
	static void _headerTableUsers()
	{
		cout <<"┌──────────────────────────┘└──────────────────────────┐"<< endl;
		cout << "│" << left << setw(10) << "Username" << "│" <<left << setw(12) << "FullName"<< "│" <<left << setw(12) << "Email"<< "│" <<left << setw(8) << "Phone"<< "│" <<left << setw(9) << "Password" << "│" << left << setw(10) << "P-sion" << endl;
		cout <<"└──────────────────────────────────────────────────────┘"<< endl;
	}
	
	// print User  list  info at table with format
	static void _PrintUserInfoAtTable(clsBankUsers user)
	{
		cout << "│" << left << setw(10) <<user.GetUsername() << "│" <<left << setw(12) <<user.GetFullName()<< "│" <<left << setw(12) <<user.GetEmail()<< "│" <<left << setw(8) <<user.GetPhone()<< "│" <<left << setw(9) <<user.GetPassword()<< "│" << left << setw(10) << user.GetPermission()<< endl;
		cout <<"└──────────────────────────────────────────────────────┘"<< endl;
	}

public :
	
	static void ShowListUsers()
	{
		// Get Data from file
		vector<clsBankUsers> Vusers = clsBankUsers::GetUsersList();
		// Print the header screen
		string Title="List Users Screen";
		string Subtitle=to_string(Vusers.size());
		clsScreen::headrScreen(Title, Subtitle);
		
		// Print the header table of users
		_headerTableUsers();
		// Print the users data
		if ( Vusers.size()==0 )
		{
			cout<<"                          No Users Found"<<endl;
			cout <<"└──────────────────────────────────────────────────────┘"<< endl;
		}
		else
		{
			for ( clsBankUsers &U : Vusers )
			{
				_PrintUserInfoAtTable(U);
			}
		}
		
	}
	
};