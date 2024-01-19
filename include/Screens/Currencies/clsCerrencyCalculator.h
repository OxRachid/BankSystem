#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../../Lib/clsEnputValidate.h"
#include "../clsScreen.h"
#include "../../Core/clsCurrency.h"
using namespace std;

class clsCerrencyCalculator : protected clsScreen {

private :

	// Read amount
	static float _ReadAmount()
	{
		return clsEnputValidate::ReadNumber<float>("Enter the Amount : ");
	}
	
	// Read and check and get currency object
	static clsCurrency _GetCurrency(string message)
	{
			// Ask for cerrency code
			string CurrencyCode=clsEnputValidate::ReadString(message);
			// Check if the currency existe or not
			while ( !clsCurrency::isCurrencyExiste(CurrencyCode) )
			{
				clsScreen::PrintMessage("This Currency Code does'nt existe");
				CurrencyCode = clsEnputValidate::ReadString(message);
			}
			
			// Get full object
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
				
			return Currency;
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
	
	
	// Perform converting process
	static void  _PrintCalculatorResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		// Convert currency(1) to usd
		float AmountUSD = CurrencyFrom.ConvertToUSD(Amount);
		// Print currency(1) data
		_PrintCurrency(CurrencyFrom);
		
		// Print the result of converting to USD
		string ConvertResult="⊷ "+to_string(Amount)+" "+CurrencyFrom.GetCurrencyCode()+" = "+to_string(AmountUSD)+" USD";                                          
		clsScreen::PrintMessage(ConvertResult);
	
		// check if currency(2) == usd to break function and return usd result
		if (CurrencyTo.GetCurrencyCode() == "USD")
		{
			return;
		}
		
		// Convert from currency(1) to currency(2)
		float AmountinCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		
		// Print currency(2) data
		_PrintCurrency(CurrencyTo);
		
		// Print the result of converting to currency(2)
		ConvertResult="⊷ "+to_string(Amount)+" "+CurrencyFrom.GetCurrencyCode()+" = "+to_string(AmountinCurrency2)+" "+CurrencyTo.GetCurrencyCode();                                          
		clsScreen::PrintMessage(ConvertResult);
	
	}
			
public :

		static void CerrencyCalculator()
		{
			char Contenue='Y';
			while ( toupper(Contenue) == 'Y' )
			{
				// Print the header
				string Title ="C- Calculator 💱";
				clsScreen::headrScreen(Title,"",true);
			
			
				// Get  CurrencyFrom object
				clsCurrency CurrencyFrom = _GetCurrency("Currency(1) Code");
				// Get  CurrencyTo object
				clsCurrency CurrencyTo = _GetCurrency("Currency(2) Code");
				
				//  Ask for amount
				float Amount=_ReadAmount();
				
				// Perform and Print converting process
				_PrintCalculatorResult(Amount, CurrencyFrom, CurrencyTo);
			
				// Ask for making another calculation
				clsScreen::PrintMessage("Do you wanna make another calculation ? y/n ≫  ","",false);
				Contenue = clsEnputValidate::ReadChar();
			}
			
		}

};
	