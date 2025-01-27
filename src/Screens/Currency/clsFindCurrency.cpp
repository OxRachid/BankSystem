#include "../../../headers/Screens/Currency/clsFindCurrency.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

// print currency record
void clsFindCurrency::_PrintCurrencyRecord(clsCurrency currency) {
    cout << endl;
    PrintHeaderScreen("*Currency Data*", "👤", Colors::Blue, false, 36);
    cout << Colors::GetBlue() << left << setw(16) << setfill(' ') << " Country" << " : " << currency.GetCountry() << endl;
    cout << left << setw(16) << " Currency Code" << " : " << currency.GetCurrencyCode() << endl;
    cout << left << setw(16) << " Currency Name" << " : " << currency.GetCurrencyName() << endl;
    cout << left << setw(16) << " Rate(1$)" << " : " << currency.GetCurrencyRate() << endl;
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl;
}

// perform find method
clsCurrency clsFindCurrency::_PerformFindMethod(eFindMethod method) {
    // prepare an empty currency obj
    clsCurrency Currency = clsCurrency::FindByCode(" ");

    switch (method) {
        case eFindMethod::eFindByCode: {
            Currency = clsCurrency::FindByCode(clsInputValidate::ReadString("\n * Enter CurrencyCode : "));
            break;
        }
        case eFindMethod::FindByCountry: {
            Currency = clsCurrency::FindByCountry(clsInputValidate::ReadString("\n * Enter Country : "));
            break;
        }
    }
    return Currency;
}

// find currency Screen
void clsFindCurrency::FindCurrencyScreen() {
    PrintHeaderScreen("FIND CURRENCY SCREEN", "🔍", Colors::Yellow);
    cout << "\n\n";

    // Ask user to choose find method
    PrintHeaderScreen("Find Method ", "🔎", Colors::Yellow, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Find By Code" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Find By Country" << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;

    // find currency by the chosen method
    clsCurrency Currency = _PerformFindMethod((eFindMethod)clsInputValidate::Readnumberbetween(1, 2, "\n ^ Enter Find Method : "));

    // Handle the result of searching
    if (Currency.isEmpty()) {
        cout << Colors::GetRed() << "\n [ The Currency Not Found ]" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetGreen() << "\n [ The Currency Founded ]" << Colors::RESET() << endl;
        _PrintCurrencyRecord(Currency);
    }
}
