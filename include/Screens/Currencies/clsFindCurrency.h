#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../../Lib/clsEnputValidate.h"
#include "../clsScreen.h"
#include "../../Core/clsCurrency.h"
using namespace std;

class clsFindCurrency : protected clsScreen {

private :
	
	// Define enum of type of search
	enum enFindBy {e_FindByCode=1, e_FindByCountry=2};
	
	// Read Type of search
	static short _ReadTypeOfSearch()
	{
		clsScreen::PrintMessage("Find By : [1] By Code  |  [2] By Country ? ","",false);
		short Option=clsEnputValidate::ReadNumberBetween<short>(1,2);
		return Option;
	}
	
	// Perform find currency option
	static  clsCurrency _PerfomFindcurrencyType( enFindBy Option)
	{
		switch (Option)
		{
			case enFindBy::e_FindByCode :
			{
				string CurrencyCode=clsEnputValidate::ReadString("Currency Code");
				clsCurrency Currency=clsCurrency::FindByCode(CurrencyCode);
				return Currency;
				break;
			}
			case enFindBy::e_FindByCountry :
			{
				string Country=clsEnputValidate::ReadString("Country Name");
				clsCurrency Currency=clsCurrency::FindByCountry(Country);
				return Currency;
				break;
			}
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

	static void FindCurrency()
	{
		
		// Print the header
		string Title ="Find Currency 🔎";
		clsScreen::headrScreen(Title,"",true);
		
		// Ask the user for what type of search and perform the action and return currency object
		clsCurrency Currency = _PerfomFindcurrencyType((enFindBy) _ReadTypeOfSearch());
		
		// Check object and print the result
		if ( !Currency.isEmpty() )
		{
			clsScreen::PrintMessage("Currency Found √");
			_PrintCurrency(Currency);
		}
		else
		{
			clsScreen::PrintMessage("Currency Not Found √");
		}
		
	}


};