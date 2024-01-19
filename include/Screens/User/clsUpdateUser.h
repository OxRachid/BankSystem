#pragma once
#include <iostream>
#include <string>
#include "../../Lib/clsEnputValidate.h"
#include "../clsScreen.h"
#include "../../Core/clsBankUsers.h"
using namespace std;

class clsUpdateUser : protected clsScreen {

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
			clsScreen::PrintMessage("FindClient is Tranactions √");
		}
		
		if ( clsScreen::WarningMessage("Give Access to ManageUsers") )
		{
			Permissions+=clsBankUsers::enPermissions::pManageUsers;
			clsScreen::PrintMessage("ManageUsers is Tranactions √");
		}
		
		if ( clsScreen::WarningMessage("Give Access to RegisterLog") )                                              
		{
			Permissions+=clsBankUsers::enPermissions::pRegisterLogIn;
			clsScreen::PrintMessage("RegisterLog is accessible √");
		}
		return Permissions;
	}
	
	// Read new first name
	static void _ReadNewFirstName(clsBankUsers &User)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update FirstName") )
		{
			string FName; 
			FName=clsEnputValidate::ReadString("New FirsName");
			User.SetFirstName(FName);
			clsScreen::PrintMessage("FirsName Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new last name
	static void _ReadNewLastName(clsBankUsers &User)                                                      
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update LastName") )
		{
			string LName; 
			LName=clsEnputValidate::ReadString("New LastName");
			User.SetLastName(LName);
			clsScreen::PrintMessage("LastName Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new Email
	static void _ReadNewEmail(clsBankUsers &User)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update Email") )
		{
			string Email; 
			Email=clsEnputValidate::ReadString("New Email");
			User.SetEmail(Email);
			clsScreen::PrintMessage("Email Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new Phone
	static void _ReadNewPhone(clsBankUsers &User)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update Phone") )
		{
			string Phone; 
			Phone=clsEnputValidate::ReadString("New Phone");
			User.SetPhone(Phone);
			clsScreen::PrintMessage("Phone Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new Phone
	static void _ReadNewPassword(clsBankUsers &User)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update Password") )
		{
			string Password; 
			Password=clsEnputValidate::ReadString("New Password");
			User.SetPassword(Password);
			clsScreen::PrintMessage("Password Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	// Read new Phone
	static void _ReadNewPermission(clsBankUsers &User)
	{
		// Warning quiestion  befor take the action
		if ( clsString::WarningMessage("Update Permissions") )
		{
			clsScreen::PrintMessage("New Permissions ⊷");
			User.SetPermission(_GetPermission());
			clsScreen::PrintMessage("Permissions Updated successfully √");
		}
		else
		{
			clsScreen::PrintMessage("Skip √");
		}
	}
	
	
	// Read User info manuely
	static void _ReadNewUserInfo(clsBankUsers &User)
	{
		_ReadNewFirstName(User);
		_ReadNewLastName(User);
		_ReadNewEmail(User);
		_ReadNewPhone(User);
		_ReadNewPassword(User);
		_ReadNewPermission(User);
	}
	
public :

	static void UpdateUser ()
	{
		// Print header screen
		clsScreen::headrScreen("Update User","",true);
		
		// Ask for Username
		string Username=clsEnputValidate::ReadString("Username");
		// Check if the user is new or already existe
		_isUsernameExiste(Username);
		// Get the user object 
		clsBankUsers User = clsBankUsers::FindUser(Username);
		// Print the user data befor deleting
		_PrintUserData(User);
		// Update user 
		// Read new User info
		_ReadNewUserInfo(User);
		// Save update and return enum result
		clsBankUsers::eSaveResult svResult=User.Save();
		// Print the result of Saving 
		switch (svResult)
		{
			case clsBankUsers::eSaveResult::e_SaveSucceed :
			{
				// Print new User data
				clsScreen::PrintMessage("Your New Data : ");
				_PrintUserData(User);
				clsScreen::PrintMessage("All Data Updated successfully √");
				break;
			}
			case clsBankUsers::eSaveResult::e_SaveFailed :
			{
				clsScreen::PrintMessage("Update Failed √");
				break;
			}
		}
	}
	
};