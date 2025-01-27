#include "../../../headers/Screens/Currency/clsCurrencyCalculator.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

// print currency record
void clsCurrencyCalculator::_PrintCurrencyRecord(clsCurrency currency) {
    cout << endl;
    PrintHeaderScreen("*Currency Data*", "👤", Colors::Blue, false, 36);
    cout << Colors::GetBlue() << left << setw(16) << setfill(' ') << " Country" << " : " << currency.GetCountry() << endl;
    cout << left << setw(16) << " Currency Code" << " : " << currency.GetCurrencyCode() << endl;
    cout << left << setw(16) << " Currency Name" << " : " << currency.GetCurrencyName() << endl;
    cout << left << setw(16) << " Rate(1$)" << " : " << currency.GetCurrencyRate() << endl;
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl;
}

// read exist currency
string clsCurrencyCalculator::_ReadExistCurrency(string prompt) {
    string CurrencyCode = clsInputValidate::ReadString(prompt);
    while (!clsCurrency::isCurrencyExist(CurrencyCode)) {
        cout << Colors::GetYellow() << " No Currency found..." << Colors::RESET() << endl;
        CurrencyCode = clsInputValidate::ReadString(prompt);
    }
    return CurrencyCode;
}

// perform currency Calculator
void clsCurrencyCalculator::_PerformCurrencyCalculator() {
    // Ask user for currency 1
    clsCurrency Currency1 = clsCurrency::FindByCode(_ReadExistCurrency("\n ^ Enter Currecy(1) Code : "));
    // Ask user for currency 2
    clsCurrency Currency2 = clsCurrency::FindByCode(_ReadExistCurrency("\n ^ Enter Currecy(2) Code : "));

    // Ask user for the Amount
    float Amount = clsInputValidate::ReadNumber<float>("\n * Enter Amount : ");
    float AmountInUSD = Currency1.ConvertToUSD(Amount);

    // Print Currency1 record
    _PrintCurrencyRecord(Currency1);
    cout << Colors::GetGreen() << Amount << " " << Currency1.GetCurrencyCode() << " = " << AmountInUSD << " USD" << Colors::RESET() << endl;
    if (Currency2.GetCurrencyCode() == "USD") {
        return;
    }
    // Convert from Currency1 To Currency2
    float ConvertToCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
    // Print Currency2 record
    _PrintCurrencyRecord(Currency2);
    // Print the result
    cout << Colors::GetGreen() << Amount << " " << Currency1.GetCurrencyCode() << " = " << ConvertToCurrency2 << " " << Currency2.GetCurrencyCode() << Colors::RESET() << endl;
}

// Currency Calculator
void clsCurrencyCalculator::CurrencyCalculScreen() {
    bool CalculMore = true;
    do {
        system("clear");
        PrintHeaderScreen("CURRENCYCALCULATOR SCREEN", "💱", Colors::Yellow);
        cout << "\n\n";
        // perform currency Calculator
        _PerformCurrencyCalculator();
        CalculMore = clsInputValidate::AskUser("\n ⊕ Perform Another Calcualation");
    } while (CalculMore);
}
