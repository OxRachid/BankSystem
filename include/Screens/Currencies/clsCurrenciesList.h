#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../../Lib/clsEnputValidate.h"
#include "../clsScreen.h"
#include "../../Core/clsCurrency.h"
using namespace std;

class clsCurrenciesList : protected clsScreen {

private :
	
	// header table of client
	static void _headerTableCurrencies()
	{
		cout <<"┌──────────────────────────┘└──────────────────────────────┐"<< endl;
		cout << "│" << left << setw(26) << "Country" << "│" <<left << setw(7) << "C-Code"<< "│" <<left << setw(26) << "Currency Name"<< "│" <<left << setw(5) << "Rate"<<endl;
		cout <<"└──────────────────────────────────────────────────────────┘"<< endl;
	}
	
	// print client info at table with format
	static void _PrintCurrenciesInfoAtTable(clsCurrency C)
	{
		cout << "│" << left << setw(26) <<C.GetCountryName()<< "│" <<left << setw(7) <<C.GetCurrencyCode()<< "│" <<left << setw(26) <<C.GetCurrencyName()<< "│" <<left << setw(5) <<C.GetCurrencyRate()<<endl;
		cout <<"└──────────────────────────────────────────────────────────┘"<< endl;
	}
	

public :

	static void CurrenciesList()
	{
		// Get data from file
		vector<clsCurrency> VCurrencies=clsCurrency::GetCurrenciesList();
		
		// Print the header
		string Title ="Currencies List 📄";
		string Subtitle =to_string(VCurrencies.size())+" Currency";
		clsScreen::headrScreen(Title,Subtitle);
		
		// Print the header of table
		_headerTableCurrencies();
		// Print data
		if ( VCurrencies.size()==0 )
		{
			cout<<"                          No Currency Found"<<endl;
			cout <<"└──────────────────────────────────────────────────────────┘"<< endl;
		}
		else
		{
			for ( clsCurrency &C : VCurrencies  )
			{
				_PrintCurrenciesInfoAtTable(C);
			}
		}
	}

};
	