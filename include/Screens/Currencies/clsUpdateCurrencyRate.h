#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../../Lib/clsEnputValidate.h"
#include "../clsScreen.h"
#include "../../Core/clsCurrency.h"
using namespace std;

class clsUpdateCurrencyRate: protected clsScreen {

private :
	
	// Read New Rate
	static float _ReadNewRate()
	{
		return clsEnputValidate::ReadNumber<float>("Enter New Rate : ");
	}
	
	// check is currency code existe or not
	static void _isCurrencyCodeExiste(string &C_Code)
	{
		while ( !clsCurrency::isCurrencyExiste(C_Code) )
		{
			clsScreen::PrintMessage("This Currency Code does'nt existe");
			C_Code = clsEnputValidate::ReadString("Currency Code");
		}
	}
	
	// Display currency  info 
	 static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "┌──┘" << endl;
		cout << "│" << endl;
		cout<<left<<setw(20)<<"≡ Country Name"<<":  "<<Currency.GetCountryName()<<endl;
		cout<<left<<setw(20)<<"≡ Currency Code"<<":  "<<Currency.GetCurrencyCode()<<endl;
		cout<<left<<setw(20)<<"≡ Currency Name"<<":  "<<Currency.GetCurrencyName()<<endl;
		cout<<left<<setw(20)<<"≡ Rate"<<":  "<<Currency.GetCurrencyRate()<<endl;
		cout << "│" << endl;
		cout << "└──┐" << endl;
		cout << "    ∞" << endl;
	}
	
public :

	static void UpdateRate()
	{
		
		// Print the header
		string Title ="Update Rate ♻️";
		clsScreen::headrScreen(Title,"",true);
		
		// Ask for currency code
		string CurrencyCode=clsEnputValidate::ReadString("Currency Code");
		// check if the currency existe
		_isCurrencyCodeExiste(CurrencyCode);
		// Get The currency object
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);                   
		// Print currency info
		_PrintCurrency(Currency);
		// Update Rate
		if ( clsScreen::WarningMessage("Update Rate to this Currency") )
		{
			// Update to new rate
			Currency.UpdateCurrencyRate(_ReadNewRate());
			// Print the new date of this currency
			clsScreen::PrintMessage("Updated Succesfuly √");
			_PrintCurrency(Currency);
		}
		else
		{
			clsScreen::PrintMessage("Update is cenceled");
		}
	}

};