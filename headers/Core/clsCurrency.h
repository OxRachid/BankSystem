#ifndef CLSCURRENCY_H
#define CLSCURRENCY_H

#include <chrono>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsCurrency {
    private:
        enum enMode {
            eEmptyMode = 1,
            eUpdateMode = 2
        };
        enMode _Mode;
        string _Country = "";
        string _CurrencyCode = "";
        string _CurrencyName = "";
        float _CurrencyRate = 0;

        // get empty mode currency obj
        static clsCurrency _GetEmptyModeCurrencyObj();
        // Convert Curreny obj to line
        static string _ConvertCurrencyObjToLine(clsCurrency Currency, string seperator = "#-#");
        // Convert Line to Curreny obj
        static clsCurrency _ConvertLineToCurrencyObj(string line, string seperator = "#-#");
        // Update
        void _Update();

    public:
        // constructor
        clsCurrency(enMode mode, string country, string code, string name, float rate);
        // setter
        void UpdateCurrencyRate(float NewRate);
        // getter
        string GetCountry();
        string GetCurrencyCode();
        string GetCurrencyName();
        float GetCurrencyRate();
        // is obj empty
        bool isEmpty();
        // is currency exist
        static bool isCurrencyExist(string CurrenyCode);
        // Find currency by code
        static clsCurrency FindByCode(string Code);
        // Find currency by country
        static clsCurrency FindByCountry(string Country);
        // get currenciees list from file
        static vector<clsCurrency> GetCurrenciesList();
        // save vector of currencies list in file
        static void SaveCurrenciesListInFile(vector<clsCurrency> vCurrencies);
        // convert to usd
        float ConvertToUSD(float Amount);
        // Convert to other currency
        float ConvertToOtherCurrency(float Amount, clsCurrency Currency2);
};

#endif // !CLSCURRENCY_H
