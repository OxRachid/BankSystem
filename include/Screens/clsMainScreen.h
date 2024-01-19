#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../Lib/clsEnputValidate.h"
#include "clsScreen.h"
#include "Client/clsAddNewClient.h"
#include "Client/clsDeleteClient.h"
#include "Client/clsUpdateClient.h"
#include "Client/clsClientsList.h"
#include "Client/clsFindClient.h"
#include "Client/clsTransactionMenuScreen.h"
#include "User/clsManageUsers.h"
#include "User/clsRegisterLogInScreen.h"
#include "Currencies/clsCurrencyMainScreen.h"
#include "../Core/Global.h"
using namespace std;


class clsMainScreen : protected clsScreen {

private :
	
	// Define enum of Main Menu Options
	enum enMainMenuOptions { e_ShowClientList = 1, e_AddNewClient = 2, e_DeleteClient = 3, e_UpdateClientinfo = 4, e_FindClient = 5, e_Transaction = 6, e_ManageUser= 7, e_RegisterLogIn=8, e_CurrencyExchang=9, e_LogOut = 10};
	
	// Read Main Menu Option
	static short _ReadMainMenuOption()
	{
		clsScreen::PrintMessage("📌 You are in the main menu");
		clsScreen::PrintMessage("what would you like? ","",false);
		return clsEnputValidate::ReadNumberBetween<short>(1,10);
	}
	
	// Go back to Main Menu screen
	static void _GoBackToMainMenu()
	{
		cout<<endl;
		system("pause");
		ShowMainMenu();
	}
	
	// Show Client list
	static void _ShowClientList()
	{
		clsClientsList::ShowClientsList();
	}
	
	// Add New Client
	static void _AddNewClient()
	{
		clsAddNewClient::ShowAddNewClient();
	}
	
	// Delete Client
	static void _DeleteClient()
	{
		clsDeleteClient::ShowDeleteClient();
	}

	// Update Client
	static void _UpdateClientinfo()
	{
		clsUpdateClient::ShowUpdateClient();
	}
	
	// Find Client
	static void _FindClient()
	{
		clsFindClient::FindClient();
	}
	
	// Transaction Menu
	static void _TransactionMenu()
	{
		clsTransactionMenuScreen::TransactionMenu();
	}
	
	// Manage User Menu
	static void _ManageUserMenu()
	{
		clsManageUsers::ManageUserMenu();
	}
	
	// Register Log In screen
	static void _RegisterLogIn()
	{
		clsRegisterLogInScreen::ShowRegisterLogInScreen();
	}
	
	// Currency Exchange
	static void _CurrencyExchange()
	{
		clsCurrencyMainScreen::CurrencyMainMenu();
	}
	
	// Log Out
	static void _LogOut()
	{
		// Make CurrentUser empty object
		CurrentUser=clsBankUsers::FindUser("","");
		// and then we don't need to write anything else to go back again to login fuction derictly
	}
	
	// Perform Main Menu Options using Switch
	static void _PerformingMainMenuAction(enMainMenuOptions Option)
	{
		switch (Option)
		{
			case enMainMenuOptions::e_ShowClientList:
				{
					_ShowClientList();
					_GoBackToMainMenu();
					break;
				}
			case enMainMenuOptions::e_AddNewClient:
				{
					_AddNewClient();
					_GoBackToMainMenu();
					break;
				}
			case enMainMenuOptions::e_DeleteClient:
				{
					 _DeleteClient();
					_GoBackToMainMenu();
					break;
				}
			case enMainMenuOptions::e_UpdateClientinfo:
				{
					_UpdateClientinfo();
					_GoBackToMainMenu();
					break;
				}
			case enMainMenuOptions::e_FindClient:
				{
					_FindClient();
					_GoBackToMainMenu();
					break;
				}
			case enMainMenuOptions::e_Transaction:
				{
					_TransactionMenu();
					ShowMainMenu();
					break;
				}
			case enMainMenuOptions::e_ManageUser:
				{
					_ManageUserMenu();
					ShowMainMenu();
					break;
				}
			case enMainMenuOptions::e_RegisterLogIn:
				{
					_RegisterLogIn();
					_GoBackToMainMenu();
					break;
				}
			case enMainMenuOptions::e_CurrencyExchang :
				{
					_CurrencyExchange();
					ShowMainMenu();
					break;
				}
			case enMainMenuOptions::e_LogOut:
				{
					_LogOut();
					break;
				}
			default:
				break;
		}
	}
	
public :
	
	// Main Menu Screen
	static void ShowMainMenu()
	{
		// Print the header screen
		clsScreen::headrScreen("Main Menu Screen");
		
		// Print the Main Menu Screen
		cout << "                [1] Show Client List " << endl;
		cout << "                [2] Add New Client " << endl;
		cout << "                [3] Delete Client  " << endl;
		cout << "                [4] Update Client  " << endl;
		cout << "                [5] Find Client " << endl;
		cout << "                [6] Transaction " << endl;
		cout << "                [7] Manage user" << endl;
		cout << "                [8] Register LogIn" << endl;
		cout << "                [9] Currency Exchang" << endl;
		cout << "                [10] Log out" << endl << endl;
		cout << "               └─────────────────┘" << endl;
		cout << "    ┌──────────────────┘" << endl;
		cout << "    │" << endl;
		
		//  Perform the Option whitch is choosing
		_PerformingMainMenuAction((enMainMenuOptions) _ReadMainMenuOption() );
	}
	
	
};
