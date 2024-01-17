#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "Global.h"
using namespace std;

class clsRegisterLogInScreen : protected clsScreen {
private :
	
	// header table of Users
	static void _headerTableRegisterLogIn()
	{
		cout <<"┌──────────────────────────┘└──────────────────────────┐"<< endl;
		cout << "│" << left << setw(20) << "Date/Time" << "│" <<left << setw(14) << "Username"<< "│" <<left << setw(14) << "Password"<< "│" <<left << setw(12) << "Permissions"<< endl;
		cout <<"└──────────────────────────────────────────────────────┘"<< endl;
	}
	
	// print User  list  info at table with format
	static void _PrintRegisterLogInAtTable(clsBankUsers::stLoginRegisterRecord User)
	{
		cout << "│" << left << setw(20) <<User.DateTime<< "│" <<left << setw(14) <<User.UserName<< "│" <<left << setw(14) <<User.PassWord<< "│" <<left << setw(12) <<User.Permission<< endl;
		cout <<"└──────────────────────────────────────────────────────┘"<< endl;
	}


public :
	
	static void ShowRegisterLogInScreen()
	{
		// Check access permission
		if (!clsScreen::CheckAccess(clsBankUsers::enPermissions::pRegisterLogIn))
		{
			return;
		}
		
		// Get Users list from file
		vector<clsBankUsers::stLoginRegisterRecord> VLogIn=clsBankUsers::GetRegisterLogInfromFile();
		// invoke to print header screen 
		string Title="Register LogIn";
		string Subtitle=to_string(VLogIn.size())+" Record(s)";
		clsScreen::headrScreen(Title, Subtitle );
		
		// Print the header table of users
		_headerTableRegisterLogIn();
		// Print the users data
		if ( VLogIn.size()==0 )
		{
			cout<<"                          No Register LogIn Found"<<endl;
			cout <<"└──────────────────────────────────────────────────────┘"<< endl;
		}
		else
		{
			for ( clsBankUsers::stLoginRegisterRecord &U : VLogIn )
			{
				_PrintRegisterLogInAtTable(U);
			}
		}
	}
};
	