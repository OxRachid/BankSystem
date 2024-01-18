#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankUsers.h"
using namespace std;

class clsAddNewUser : protected clsScreen {
	
private :

	// Check if the user is new or already existe
	static void _isUsernameExiste(string &username)
	{
		while ( clsBankUsers::isUserExiste(username) )
		{
			clsScreen::PrintMessage("This User is Already Existe, Try another one : ");                   
			username=clsEnputValidate::ReadString("Username");
		}
	}
	
	// Get Permission
	static short _GetPermission()
	{
		clsScreen::PrintMessage("──Permissions ⊷");
		
		// Ask if Can give Access to all functions
		if ( clsScreen::WarningMessage("Give All Access") )
		{
			clsScreen::PrintMessage("All Functions are accessible √");
			return -1;
		}
		
		short Permissions=0;
		
		if ( clsScreen::WarningMessage("Give Access to Showclientlist") )
		{
			Permissions+=clsBankUsers::enPermissions::pListClients;
			clsScreen::PrintMessage("Showclientlist is accessible √");
		}
		
		if ( clsScreen::WarningMessage("Give Access to AddNewClient") )
		{
			Permissions+=clsBankUsers::enPermissions::pAddNewClient;
			clsScreen::PrintMessage("AddNewClient is accessible √");
		}
		
		if ( clsScreen::WarningMessage("Give Access to DeleteClient") )
		{
			Permissions+=clsBankUsers::enPermissions::pDeleteClient;
			clsScreen::PrintMessage("DeleteClient is accessible √");
		}
		
		if ( clsScreen::WarningMessage("Give Access to UpdateClients") )
		{
			Permissions+=clsBankUsers::enPermissions::pUpdateClients;
			clsScreen::PrintMessage("UpdateClients is accessible √");
		}
		
		if ( clsScreen::WarningMessage("Give Access to FindClient") )
		{
			Permissions+=clsBankUsers::enPermissions::pFindClient;
			clsScreen::PrintMessage("FindClient is accessible √");
		}
		
		if ( clsScreen::WarningMessage("Give Access to Tranactions") )
		{
			Permissions+=clsBankUsers::enPermissions::pTranactions;
			clsScreen::PrintMessage("FindClient is accessible √");
		}
		
		if ( clsScreen::WarningMessage("Give Access to ManageUsers") )
		{
			Permissions+=clsBankUsers::enPermissions::pManageUsers;
			clsScreen::PrintMessage("ManageUsers is accessible √");
		}
		
		if ( clsScreen::WarningMessage("Give Access to RegisterLog") )                                              
		{
			Permissions+=clsBankUsers::enPermissions::pRegisterLogIn;
			clsScreen::PrintMessage("RegisterLog is accessible √");
		}
		
		return Permissions;
	}
	
	// Read data of new user
	static void _ReadNewUserData(clsBankUsers &User)
	{
		string data="";
		
		// Read Firstname
		data=clsEnputValidate::ReadString("Firstname");
		User.SetFirstName(data);
		
		// Read Lastname
		data=clsEnputValidate::ReadString("Lastname");
		User.SetLastName(data);
		
		// Read Email
		data=clsEnputValidate::ReadString("Email");
		User.SetEmail(data);
		
		// Read Phone
		data=clsEnputValidate::ReadString("Phone");
		User.SetPhone(data);
		
		// Read Password
		data=clsEnputValidate::ReadString("Password");
		User.SetPassword(data);
		
		// Read Permission
		User.SetPermission(_GetPermission());
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

	static void AddNewUser()
	{
		// Print header screen
		clsScreen::headrScreen("Add New User","",true);
		
		// Ask for Username
		string Username=clsEnputValidate::ReadString("Username");
		// Check if the user is new or already existe
		_isUsernameExiste(Username);
		// Get  new user object fill with username and mode
		clsBankUsers User = clsBankUsers::GetAddNewUserObject(Username);
		// Read Data from new user
		_ReadNewUserData(User);
		// Save new user data and return enum result
		clsBankUsers::eSaveResult svResult=User.Save();
		// Print result of saving
		switch(svResult)
		{
			case clsBankUsers::eSaveResult::e_SaveSucceed :
			{
				// Print new user data
				clsScreen::PrintMessage("Your  Data : ");
				_PrintUserData(User);
				clsScreen::PrintMessage("Added successfully √");
				break;
			}
			case clsBankUsers::eSaveResult::e_UserAlreadyExsist :
			{
				clsScreen::PrintMessage("Failed, This User is Already exsist");
				break;
			}
			case clsBankUsers::eSaveResult::e_SaveFailed :
			{
				clsScreen::PrintMessage("Adding Failed √");
				break;
			}
		}
	}
	
};