#ifndef CLSCURRENCYMAINMENU_H
#define CLSCURRENCYMAINMENU_H

#include "../clsScreen.h"
#include <string>

class clsCurrencyMainMenu : protected clsScreen {
    private:
        enum enCurrencyMainMenuOptions {
            eCurrenciesList = 1,
            eFindCurrency = 2,
            eUpdateRate = 3,
            eCurrencyCalcul = 4,
            eMainMenu = 5
        };

        // Perform Currency main menu Options
        static void _PerformCurrencyMainMenuOptions(enCurrencyMainMenuOptions option);
        // Go to CurrencyMainMenuScreen
        static void _GoToCurrencyMainMenu();
        // List Currencies
        static void _CurrenciesListScreen();
        // Find Currency
        static void _FindCurrencyScreen();
        // Update Rate
        static void _UpdateRateScreen();
        // Currency Calculator
        static void _CurrencyCalculScreen();

    public:
        // Currency Main Menu screen
        static void CurrencyMainMenuScreen();
};

#endif // !CLSCURRENCYMAINMENU_H
