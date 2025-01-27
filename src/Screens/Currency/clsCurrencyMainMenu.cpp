#include "../../../headers/Screens/Currency/clsCurrencyMainMenu.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/Currency/clsCurrenciesList.h"
#include "../../../headers/Screens/Currency/clsCurrencyCalculator.h"
#include "../../../headers/Screens/Currency/clsFindCurrency.h"
#include "../../../headers/Screens/Currency/clsUpdateRate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Currency Main Menu screen
void clsCurrencyMainMenu::CurrencyMainMenuScreen() {
    system("clear");
    PrintHeaderScreen("CURRENCY MAIN MENU SCREEN", "💱", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Currency Main Menu ", "📋", Colors::Yellow, false);
    const short width = 24;
    /*cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;*/
    cout << setw(width) << setfill(' ') << " " << left << "[1] Show Currencies List" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Find Currency" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Update Rate" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Currency Calculator" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Main Menu" << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    _PerformCurrencyMainMenuOptions((enCurrencyMainMenuOptions)clsInputValidate::Readnumberbetween(1, 5, " \n* Select Option : "));
}

// Perform Currency main menu Options
void clsCurrencyMainMenu::_PerformCurrencyMainMenuOptions(enCurrencyMainMenuOptions option) {
    switch (option) {
        case enCurrencyMainMenuOptions::eCurrenciesList: {
            _CurrenciesListScreen();
            _GoToCurrencyMainMenu();
            break;
        }
        case enCurrencyMainMenuOptions::eFindCurrency: {
            _FindCurrencyScreen();
            _GoToCurrencyMainMenu();
            break;
        }
        case enCurrencyMainMenuOptions::eUpdateRate: {
            _UpdateRateScreen();
            _GoToCurrencyMainMenu();
            break;
        }
        case enCurrencyMainMenuOptions::eCurrencyCalcul: {
            _CurrencyCalculScreen();
            _GoToCurrencyMainMenu();
            break;
        }
        case enCurrencyMainMenuOptions::eMainMenu: {
            break;
        }
    }
}

// Go to CurrencyMainMenuScreen
void clsCurrencyMainMenu::_GoToCurrencyMainMenu() {
    // this trick just to pause termux screen until the user Contenu
    cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
    char Contenue = clsInputValidate::ReadChar();
    Contenue = ' ';
    cout << Contenue << endl;
    // go back to main screen function
    CurrencyMainMenuScreen();
}
// List Currencies
void clsCurrencyMainMenu::_CurrenciesListScreen() {
    system("clear");
    clsCurrenciesList::CurrenciesList();
}
// Find Currency
void clsCurrencyMainMenu::_FindCurrencyScreen() {
    system("clear");
    clsFindCurrency::FindCurrencyScreen();
}
// Update Rate
void clsCurrencyMainMenu::_UpdateRateScreen() {
    system("clear");
    clsUpdateRate::UpdateRateScreen();
}
// Currency Calculator
void clsCurrencyMainMenu::_CurrencyCalculScreen() {
    system("clear");
    clsCurrencyCalculator::CurrencyCalculScreen();
}
