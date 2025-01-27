#include "../../../headers/Screens/Currency/clsUpdateRate.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

// print currency record
void clsUpdateRate::_PrintCurrencyRecord(clsCurrency currency) {
    cout << endl;
    PrintHeaderScreen("*Currency Data*", "👤", Colors::Blue, false, 36);
    cout << Colors::GetBlue() << left << setw(16) << setfill(' ') << " Country" << " : " << currency.GetCountry() << endl;
    cout << left << setw(16) << " Currency Code" << " : " << currency.GetCurrencyCode() << endl;
    cout << left << setw(16) << " Currency Name" << " : " << currency.GetCurrencyName() << endl;
    cout << left << setw(16) << " Rate(1$)" << " : " << currency.GetCurrencyRate() << endl;
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl;
}

// read exist currency
string clsUpdateRate::_ReadExistCurrency() {
    string CurrencyCode = clsInputValidate::ReadString("\n * Enter CurrencyCode : ");
    while (!clsCurrency::isCurrencyExist(CurrencyCode)) {
        cout << Colors::GetYellow() << " No Currency found..." << Colors::RESET() << endl;
        CurrencyCode = clsInputValidate::ReadString("\n * Enter a valid CurrencyCode : ");
    }
    return CurrencyCode;
}

// UpdateRate
void clsUpdateRate::UpdateRateScreen() {
    PrintHeaderScreen("UPDATE RATE SCREEN", "⚙️", Colors::Yellow);
    cout << "\n\n";

    string CurrencyCode = _ReadExistCurrency();
    // get currency obj
    clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
    _PrintCurrencyRecord(Currency);

    if (clsInputValidate::AskUser("\n ⊙ Are u sure wanna update Currency Code")) {
        // Read new rate and save it in file
        Currency.UpdateCurrencyRate(clsInputValidate::ReadNumber<double>("\n * Enter New Rate : "));
        // print new update of currency
        _PrintCurrencyRecord(Currency);
        cout << Colors::GetGreen() << " ⟩ Update Rate Succusfully ✓" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetRed() << " [ Failed, Rate Update was canceled ]" << Colors::RESET() << endl;
    }
}
