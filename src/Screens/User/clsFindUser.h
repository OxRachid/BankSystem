#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankUsers.h"
using namespace std;

class clsFindUser : protected clsScreen {

private :
	
	// Check if the user is new or already existe
	static void _isUsernameExiste(string &username)
	{
		while ( !clsBankUsers::isUserExiste(username) )
		{
			clsScreen::PrintMessage("This User Does'nt Existe... ");                   
			username=clsEnputValidate::ReadString("Username");
		}
	}
	
	
	// Print user info 
	 static void _PrintUserData(clsBankUsers User)
	{
		cout << "┌──┘" << endl;
		cout << "│" << endl;
		cout<<left<<setw(20)<<"≡ FirstName"<<":  "<<User.GetFirstName()<<endl;
		cout<<left<<setw(20)<<"≡ LastName"<<":  "<<User.GetLastName()<<endl;
		cout<<left<<setw(20)<<"≡ Email"<<":  "<<User.GetEmail()<<endl;
		cout<<left<<setw(20)<<"≡ Phone"<<":  "<<User.GetPhone()<<endl;
		cout<<left<<setw(20)<<"≡ Username"<<":  "<<User.GetUsername()<<endl;
		cout<<left<<setw(20)<<"≡ Password"<<":  "<<User.GetPassword()<<endl;
		cout<<left<<setw(20)<<"≡ Permission"<<":  "<<User.GetPermission()<<endl;
		cout << "│" << endl;
		cout << "└──┐" << endl;
		cout << "    ∞" << endl;
	}
	
	
public :

	static void FindUser()
	{
		// Draw header screen
		clsScreen::headrScreen("Find User Screen", "",true);
		
		// Ask user to Enter the Account Number
		string Username=clsEnputValidate::ReadString("Username");
		// Force user  to Enter an exsisting User
		_isUsernameExiste(Username);
		// Stric Checking and get update mode if the User existe or Empty mode if not 
		clsBankUsers User = clsBankUsers::FindUser(Username);
		// Print the result of searching
		if ( !User.isEmpty() )
		{
			//print the User data
			_PrintUserData(User);
		}
		else
		{		
			clsScreen::PrintMessage("This Account Does'nt exsis... ");
		}
	}	
};