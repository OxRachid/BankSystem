#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsDrposit.h"
#include "clsWithdraw.h"
#include "clsPrintTotalBalances.h"
#include "clsTransfer.h"
#include "clsTransferRegisterLog.h"
using namespace std;

class clsTransactionMenuScreen : protected clsScreen {
private :
	
	// Define enum of transaction menu options
	enum enTransactionOptions { e_Deposit = 1, e_Withdraw = 2, e_PrintTotalBalances = 3, e_Transfer=4,e_TransferLog=5, e_MainMenu =6 };
	
	// Read Main Menu Option
	static short _ReadMainMenuOption()
	{
		clsScreen::PrintMessage("What Do You Want ? ","",false);
		return clsEnputValidate::ReadNumberBetween<short>(1,6);
	}
	
	// Go back to Main Menu screen
	static void _GoBackToTransactionMenu()
	{
		cout<<endl;
		system("pause");
		TransactionMenu();
	}
	
	// Deposit screen
	static void _Deposit()
	{
		clsDrposit::DepositScreen();
	}
	
	// Withdraw screen
	static void _Withdraw()
	{
		clsWithdraw::WithdrawScreen();
	}
	
	// Print Total Balances screen
	static void _PrintTotalBalances()
	{
		clsPrintTotalBalances::PrintTotalBalances();
	}
	
	// Transfer
	static void _Transfer()
	{
		clsTransfer::Transfer();
	}
	
	// Transfer log
	static void _TransferLog()
	{
		clsTransferRegisterLog::ShowTransferLog();
	}
	
	// perform Transaction actions 
	static void _PerformingTransactionAction(enTransactionOptions option)
	{
		switch (option)
		{
			case enTransactionOptions::e_Deposit:
				{
					_Deposit();
					_GoBackToTransactionMenu();
					break;
				}
			case enTransactionOptions::e_Withdraw:
				{
					_Withdraw();
					_GoBackToTransactionMenu();
					break;
				}
			case enTransactionOptions::e_PrintTotalBalances:
				{
					_PrintTotalBalances();
					_GoBackToTransactionMenu();
					break;
				}
			case enTransactionOptions::e_Transfer:
				{
					_Transfer();
					_GoBackToTransactionMenu();
					break;
				}
			case enTransactionOptions::e_TransferLog:
				{
					_TransferLog();
					_GoBackToTransactionMenu();
					break;
				}
			case enTransactionOptions::e_MainMenu:
				{
					// We don't need to write anything to break the switch and go back to the main menu
					break;
				}
		}
	}
	
public :
	
	// Transaction Menu
	static void TransactionMenu()
	{
		// Check access permission
		if (!clsScreen::CheckAccess(clsBankUsers::enPermissions::pTranactions))
		{
			system("pause");
			return;
		}
		
	
		// Draw header screen
		clsScreen::headrScreen("Transaction Menu");
		
		// Show transaction menu
		cout << "                 [1] Deposit " << endl;
		cout << "                 [2] Withdraw " << endl;
		cout << "                 [3] Total Balances  " << endl;
		cout << "                 [4] Transfer " << endl;
		cout << "                 [5] Transfer log  " << endl;
		cout << "                 [6] Main Menu  " << endl;
		cout << "               └─────────────────┘" << endl;
		cout << "    ┌──────────────────┘" << endl;
		cout << "    │" << endl;
	
		//  Perform the Option whitch is choosing
		_PerformingTransactionAction((enTransactionOptions) _ReadMainMenuOption() );
	}
	
	
};