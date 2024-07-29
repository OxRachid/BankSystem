#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsCurrenciesList.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCerrencyCalculator.h"
using namespace std;

class clsCurrencyMainScreen : protected clsScreen {

private :
	
	// Define enum of Main Menu Options
	enum enCurrencyMainMenuOptions { e_CurrenciesList = 1, e_FindCurrency = 2, e_UpdateRate = 3, e_CurrencyCaculator = 4, e_MainMenu = 5};
	
	// Read Main Menu Option
	static short _ReadCurrencyMainMenuOption()
	{
		clsScreen::PrintMessage("What Do You Want ? ","",false);
		return clsEnputValidate::ReadNumberBetween<short>(1,5);
	}
	
	// Show currencies list
	static void _ShowCurrenciesList()
	{
		clsCurrenciesList::CurrenciesList();
	}
	
	// Find currencies 
	static void _FindCurrency()
	{
		clsFindCurrency::FindCurrency();
	}
	
	// Update rate 
	static void _UpdateRate()
	{
		clsUpdateCurrencyRate::UpdateRate();
	}
	
	//  currency calculator
	static void _CurrencyCalcutator()
	{
		clsCerrencyCalculator::CerrencyCalculator();
	}
	
	//  Go back to currency main menu
	static void _GoBackToCurrencyMainMenu()
	{
		cout<<endl;
		cin.get();
		CurrencyMainMenu();
	}
	
	// Perform Main Menu Options using Switch
	static void _PerformingCurrencyMainMenuAction(enCurrencyMainMenuOptions Option)
	{
		switch (Option)
		{
			case enCurrencyMainMenuOptions::e_CurrenciesList :
				{
					_ShowCurrenciesList();
					_GoBackToCurrencyMainMenu();
					break;
				}
			case enCurrencyMainMenuOptions::e_FindCurrency :
				{
					_FindCurrency();
					_GoBackToCurrencyMainMenu();
					break;
				}
			case enCurrencyMainMenuOptions::e_UpdateRate :
				{
					 _UpdateRate();
					_GoBackToCurrencyMainMenu();
					break;
				}
			case enCurrencyMainMenuOptions::e_CurrencyCaculator :
				{
					_CurrencyCalcutator();
					_GoBackToCurrencyMainMenu();
					break;
				}
			case enCurrencyMainMenuOptions::e_MainMenu :
				{
					// Don't write here anything to go back to the main menu screen
					break;
				}
			default:
				break;
		}
	}
	
public :

	static void CurrencyMainMenu()
	{
		// Print the header screen
		clsScreen::headrScreen("Currency Menu 💲");
		
		// Print the Main Menu Screen
		cout << "                [1] Currencies List " << endl;
		cout << "                [2] Find Currency " << endl;
		cout << "                [3] Update Rate  " << endl;
		cout << "                [4] Currency Calculator  " << endl;
		cout << "                [5] Main Menu " << endl<<endl;
		cout << "               └─────────────────┘" << endl;
		cout << "    ┌──────────────────┘" << endl;
		cout << "    │" << endl;
		
		//  Perform the Option whitch is choosing
		_PerformingCurrencyMainMenuAction((enCurrencyMainMenuOptions) _ReadCurrencyMainMenuOption() );
		
	}

};
	