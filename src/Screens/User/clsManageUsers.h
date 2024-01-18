#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsListUsers.h"
#include "clsAddNewUser.h"
#include "clsDeleteUser.h"
#include "clsUpdateUser.h"
#include "clsFindUser.h"
using namespace std;

class clsManageUsers : protected clsScreen {

private :
	
	// Define enum of manage user menu options
	enum enManageUserOptions { e_ListUser=1, e_AddNewUser=2, e_DeleteUser=3, e_UpdateUser=4, e_FindUser=5, e_MainMenu=6};
	
	// Read manage user menu option
	static short _ReadMainMenuOption()
	{
		clsScreen::PrintMessage("What Do You Want ? ","",false);
		return clsEnputValidate::ReadNumberBetween<short>(1,6);
	}
	
	// Go back to  manage user menu 
	static void _GoBackToManageUserMenu()
	{
		cout<<endl;
		system("pause");
		ManageUserMenu();
	}

	// Show users list
	static void _ListUsers()
	{
		clsListUsers::ShowListUsers();
	}
	
	// Add new user
	static void _AddNewUser()
	{
		clsAddNewUser::AddNewUser();
	}
	
	// Delete User
	static void _DeleteUser()
	{
		clsDeleteUser::DeleteUser();
	}
	
	// Update User
	static void _UpdateUser()
	{
		clsUpdateUser::UpdateUser();
	}
	
	// Find User
	static void _FindUser()
	{
		clsFindUser::FindUser();
	}
	
	// Perform Manage user actions
	static void PerformingManageUser(enManageUserOptions Action)
	{
		switch(Action)
		{
			case enManageUserOptions::e_ListUser :
			{
				_ListUsers();
				_GoBackToManageUserMenu();
				break;
			}
			case enManageUserOptions::e_AddNewUser :
			{
				_AddNewUser();
				_GoBackToManageUserMenu();
				break;
			}
			case enManageUserOptions::e_DeleteUser :
			{
				_DeleteUser();
				_GoBackToManageUserMenu();
				break;
			}
			case enManageUserOptions::e_UpdateUser :
			{
				_UpdateUser();
				_GoBackToManageUserMenu();
				break;
			}
			case enManageUserOptions::e_FindUser :
			{
				_FindUser();
				_GoBackToManageUserMenu();
				break;
			}
			case enManageUserOptions::e_MainMenu :
			{
				// We don't write anything to let it go back to main menu
				break;
			}
		}
	}
	
public :

	// manage user Menu
	static void ManageUserMenu()
	{
		// Check access permission
		if (!clsScreen::CheckAccess(clsBankUsers::enPermissions::pManageUsers))
		{
			system("pause");
			return;
		}
		
	
		clsScreen::headrScreen("Manage User");
		cout << "                 [1] List Users " << endl;
		cout << "                 [2] Add New User " << endl;
		cout << "                 [3] Delete User  " << endl;
		cout << "                 [4] Update User  " << endl;
		cout << "                 [5] Find User  " << endl;
		cout << "                 [6] Main Menu  " << endl;
		cout << "               └─────────────────┘" << endl;
		cout << "    ┌──────────────────┘" << endl;
		// Perform Options
		PerformingManageUser( (enManageUserOptions) _ReadMainMenuOption());
	}
	
	
};