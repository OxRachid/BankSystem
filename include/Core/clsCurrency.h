#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsEnputValidate.h"
#include "clsUtil.h"
using namespace std;

// Define the name of file where we will store client data
const string  CurrenciesFile="data/Currencies.txt";

class clsCurrency {

private :
	// Define enum of client mode
	enum eMode { e_EmptyMode=0, e_UpdateMode=1};	
	
	eMode _Mode;
	string _CountryName;
	string _CurrencyCode;
	string _CurrencyName;
	float _CurrencyRate;
	
	// Convert line to currency object
	static clsCurrency _ConvertLineToCurrencyObject(string line)
	{
		vector<string> Vstring=clsString::SplitString(line, "#");
		
		return clsCurrency(eMode::e_UpdateMode, Vstring[0], Vstring[1], Vstring[2], stof(Vstring[3]) );                            
	}
	
	// Convert currency object to line
	static string _ConvertCurrencyObjectLine(clsCurrency Currency)
	{
		string CurrencyLine;
		CurrencyLine+=Currency.GetCountryName()+"#";
		CurrencyLine+=Currency.GetCurrencyCode()+"#";
		CurrencyLine+=Currency.GetCurrencyName()+"#";
		CurrencyLine+=to_string(Currency.GetCurrencyRate());
		return CurrencyLine;
	}
	
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(eMode::e_EmptyMode, "","","",0);
	}
	
	// Get Currency Data from file
	static vector<clsCurrency> _GetCurrenciesDataFromFile()
	{
		vector<clsCurrency> VCurrencies ;
		fstream MyFile;
		MyFile.open(CurrenciesFile, ios::in);
		if ( MyFile.is_open() )
		{
			string line;
			while ( getline(MyFile, line) )
			{
				clsCurrency C=_ConvertLineToCurrencyObject(line);
				VCurrencies.push_back(C);
			}
			MyFile.close();
		}
		
		return VCurrencies;
	}
	
	// Save All Currency data in file
	static void _SaveCurrenyDatainFile(vector<clsCurrency> VCurrencies)
	{
		fstream MyFile;
		MyFile.open(CurrenciesFile, ios::out);
		if ( MyFile.is_open() )
		{
			string line;
			for ( clsCurrency &C : VCurrencies )
			{
				line =_ConvertCurrencyObjectLine(C);
				MyFile<<line<<endl;
			}
			MyFile.close();
		}
		 
	}
	
	// Update currency rate
	void _Update()
	{
		vector<clsCurrency> VCurrencies = _GetCurrenciesDataFromFile();
		for ( clsCurrency &C : VCurrencies )
			{
				if ( C.GetCountryName() == _CountryName )
				{
					C=*this;
					break;
				}
			} 
			
		// Save new data in file
		_SaveCurrenyDatainFile(VCurrencies);
	}
	
public :
		
	// Defaul constructor
	clsCurrency() :_Mode( e_EmptyMode), _CountryName("-"), _CurrencyCode("-"), _CurrencyName("-"), _CurrencyRate(0){}                                             
	
	// Parameterize constructor
	clsCurrency ( eMode Mode, string CountryName, string CurrencyCode, string CurrencyName, float CurrencyRate)
	{
		_Mode = Mode;
		_CountryName = CountryName;
		_CurrencyCode = CurrencyCode;
		_CurrencyName= CurrencyName;
		_CurrencyRate = CurrencyRate;
	}
	
	// Get Country Name
	string GetCountryName()
	{
		return _CountryName;
	}
	
	// Get Country Code
	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}
	
	// Get Country Name
	string GetCurrencyName()
	{
		return _CurrencyName;
	}
	
	// Set Cerrency rate
	void UpdateCurrencyRate( float NewRate)
	{
		_CurrencyRate = NewRate;
		_Update();
	}
	
	// Get Country Rate
	float GetCurrencyRate()
	{
		return _CurrencyRate;
	}
	
	// Is Empty
	bool isEmpty()
	{
		return (_Mode==e_EmptyMode);
	}
	
	// Check if currency exist or not
	static bool isCurrencyExiste(string CurrencyCode)
	{
		clsCurrency C=FindByCode(CurrencyCode);
		return (!C.isEmpty());
	}
	
	// Get data from file
	static vector<clsCurrency> GetCurrenciesList()
	{
		return _GetCurrenciesDataFromFile();
	}
	
	// Find Currency of any country by its name
	static clsCurrency FindByCountry( string CountryName )
	{
		CountryName=clsString::UpperAllString(CountryName);
		
		fstream MyFile;
		MyFile.open(CurrenciesFile, ios::in);
		if ( MyFile.is_open() )
		{
			string line;
			while ( getline(MyFile, line) )
			{
				clsCurrency C=_ConvertLineToCurrencyObject(line);
				if ( clsString::UpperAllString(C.GetCountryName()) == CountryName )
				{
					MyFile.close();
					return C;
				}
			}
			MyFile.close();
		}
		
		return _GetEmptyCurrencyObject();
	}
	
	// Find Currency of any country by its Code
	static clsCurrency FindByCode( string CurrencyCode )
	{
		CurrencyCode=clsString::UpperAllString(CurrencyCode);
		
		fstream MyFile;
		MyFile.open(CurrenciesFile, ios::in);
		if ( MyFile.is_open() )
		{
			string line;
			while ( getline(MyFile, line) )
			{
				clsCurrency C=_ConvertLineToCurrencyObject(line);
				if ( C.GetCurrencyCode() == CurrencyCode )
				{
					MyFile.close();
					return C;
				}
			}
			MyFile.close();
		}
		
		return _GetEmptyCurrencyObject();
	}
	
	// Convert to usd
	 float ConvertToUSD(float Amount)
	{
		return (Amount/GetCurrencyRate());
	}
	
	// Convert to  other  Currency 
	float ConvertToOtherCurrency(float Amount , clsCurrency Currency2)
	{
		// Convert to usd
		float AmountUSD = ConvertToUSD(Amount);
		
		if (Currency2.GetCurrencyCode() == "USD")
		{
			return AmountUSD;
		}
		
		// convert to other currency
		return (AmountUSD*Currency2.GetCurrencyRate());
	}
	
};
