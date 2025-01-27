#include "../../headers/Core/clsCurrency.h"
#include "../../headers/Lib/clsString.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// define currencies file
string CurrencyFile = "data/Currencies.txt";

// constructor
clsCurrency::clsCurrency(enMode mode, string country, string code, string name, float rate)
    : _Mode(mode),
      _Country(country),
      _CurrencyCode(code),
      _CurrencyName(name),
      _CurrencyRate(rate) {}

// update currency rate
void clsCurrency::UpdateCurrencyRate(float NewRate) {
    _CurrencyRate = NewRate;
    // update currencyobj
    _Update();
}
// getter
string clsCurrency::GetCountry() {
    return _Country;
}
string clsCurrency::GetCurrencyCode() {
    return _CurrencyCode;
}
string clsCurrency::GetCurrencyName() {
    return _CurrencyName;
}
float clsCurrency::GetCurrencyRate() {
    return _CurrencyRate;
}

// is obj empty
bool clsCurrency::isEmpty() {
    return (_Mode == enMode::eEmptyMode);
}

// is currency exist
bool clsCurrency::isCurrencyExist(string CurrenyCode) {
    clsCurrency Currency = FindByCode(CurrenyCode);
    return (!Currency.isEmpty());
}

// get empty mode currency obj
clsCurrency clsCurrency::_GetEmptyModeCurrencyObj() {
    return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
}

// Convert Curreny obj to line
string clsCurrency::_ConvertCurrencyObjToLine(clsCurrency Currency, string seperator) {
    string strCurrency = "";
    strCurrency += Currency._Country + seperator;
    strCurrency += Currency._CurrencyCode + seperator;
    strCurrency += Currency._CurrencyName + seperator;
    strCurrency += to_string(Currency._CurrencyRate);
    return strCurrency;
}
// Convert Line to Curreny obj
clsCurrency clsCurrency::_ConvertLineToCurrencyObj(string line, string seperator) {
    vector<string> vStr = clsString::Split(line, seperator);
    return clsCurrency(enMode::eUpdateMode, vStr[0], vStr[1], vStr[2], stof(vStr[3]));
}
// get currenciees list from file
vector<clsCurrency> clsCurrency::GetCurrenciesList() {
    vector<clsCurrency> vCurrencies;
    fstream MyFile;
    MyFile.open(CurrencyFile, ios::in);
    if (MyFile.is_open()) {
        string line = "";
        while (getline(MyFile, line)) {
            clsCurrency currency = _ConvertLineToCurrencyObj(line);
            vCurrencies.push_back(currency);
        }
        MyFile.close();
    }
    return vCurrencies;
}
// save vector of currencies list in file
void clsCurrency::SaveCurrenciesListInFile(vector<clsCurrency> vCurrencies) {
    fstream MyFile;
    MyFile.open(CurrencyFile, ios::out);
    if (MyFile.is_open()) {
        string line = "";
        for (clsCurrency &C : vCurrencies) {
            line = _ConvertCurrencyObjToLine(C);
            MyFile << line << endl;
        }
        MyFile.close();
    }
}

// Update
void clsCurrency::_Update() {
    vector<clsCurrency> vCurrencies = GetCurrenciesList();
    for (clsCurrency &C : vCurrencies) {
        if (C._Country == _Country) {
            C = *this;
            break;
        }
    }
    // save vector in file
    SaveCurrenciesListInFile(vCurrencies);
}

// Find currency by code
clsCurrency clsCurrency::FindByCode(string Code) {
    // Upper all currencycode string
    Code = clsString::UpperAllString(Code);

    fstream MyFile;
    MyFile.open(CurrencyFile, ios::in);
    if (MyFile.is_open()) {
        string line = "";
        while (getline(MyFile, line)) {
            clsCurrency currency = _ConvertLineToCurrencyObj(line);
            if (currency._CurrencyCode == Code) {
                MyFile.close();
                return currency;
            }
        }
        MyFile.close();
    }
    return _GetEmptyModeCurrencyObj();
}

// Find currency by country
clsCurrency clsCurrency::FindByCountry(string Country) {
    // Upper all country string
    Country = clsString::UpperAllString(Country);

    fstream MyFile;
    MyFile.open(CurrencyFile, ios::in);
    if (MyFile.is_open()) {
        string line = "";
        while (getline(MyFile, line)) {
            clsCurrency currency = _ConvertLineToCurrencyObj(line);
            if (clsString::UpperAllString(currency._Country) == Country) {
                MyFile.close();
                return currency;
            }
        }
        MyFile.close();
    }
    return _GetEmptyModeCurrencyObj();
}

// convert to usd
float clsCurrency::ConvertToUSD(float Amount) {
    return (Amount / _CurrencyRate);
}
// Convert to other currency
float clsCurrency::ConvertToOtherCurrency(float Amount, clsCurrency Currency2) {
    float AmountInUSD = ConvertToUSD(Amount);
    if (Currency2._CurrencyCode == "USD") {
        return AmountInUSD;
    }
    return (AmountInUSD * Currency2.GetCurrencyRate());
}
