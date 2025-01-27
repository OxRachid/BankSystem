#include "../../../headers/Screens/Currency/clsCurrenciesList.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// print Currencies list line
void clsCurrenciesList::_PrintCurrencyLine(clsCurrency currency) {
    short width = 18;
    cout << Colors::GetBoldBlue() << setfill(' ') << left << setw(width + 9) << currency.GetCountry() << left << setw(width - 12) << currency.GetCurrencyCode() << left << setw(width + 6) << currency.GetCurrencyName() << left << setw(width - 13) << currency.GetCurrencyRate() << Colors::RESET() << endl;
}

// Currencies List
void clsCurrenciesList::CurrenciesList() {
    PrintHeaderScreen("CURRENCIES LIST SCREEN", "💵", Colors::Cyan);
    cout << "\n\n";

    vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

    short width = 18;
    PrintHeaderScreen("Currencies", to_string(vCurrencies.size()), Colors::BoldYellow, false);
    cout << Colors::GetBoldYellow() << setfill(' ') << left << setw(width + 9) << "Country" << left << setw(width - 12) << "Code" << left << setw(width + 6) << "Name" << left << setw(width - 13) << "Rate" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vCurrencies.empty()) {
        cout << Colors::GetRed() << "                    No Currencies Found" << Colors::RESET() << endl;
    } else {
        for (clsCurrency &C : vCurrencies) {
            _PrintCurrencyLine(C);
        }
    }
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
