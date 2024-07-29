#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankUsers.h"
using namespace std;

class clsDeleteUser : protected clsScreen {
	
private :

	// Check if the user existe or not
	static void _isUsernameExiste(string &username)
	{
		while ( !clsBankUsers::isUserExiste(username) )
		{
			clsScreen::PrintMessage("This User Does'nt  Existe... ");                   
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

	static void DeleteUser()
	{
		// Print the header screen
		clsScreen::headrScreen("Delete User","",true);
		
		// Ask for username
		string Username=clsEnputValidate::ReadString("Username");
		// Check if the user existe or not
		_isUsernameExiste(Username);
		// Get the user object 
		clsBankUsers User = clsBankUsers::FindUser(Username);
		// Print the user data befor deleting
		_PrintUserData(User);
		// Ask befor delete
		if ( clsScreen::WarningMessage("Delete") )
		{
			if ( User.Delete())
			{
				clsScreen::PrintMessage("Deleted Successfuly √");
				_PrintUserData(User);
			}
			else
			{
				clsScreen::PrintMessage("Failed Delete, You Can't Delete the Admin");
			}
		}
		else
		{
			clsScreen::PrintMessage("Delete is canceled √");
		}
		
	}
	
};