#ifndef CLSCURRENCYCALCULATOR_H
#define CLSCURRENCYCALCULATOR_H

#include "../../Core/clsCurrency.h"
#include "../clsScreen.h"
#include <string>

class clsCurrencyCalculator : protected clsScreen {
    private:
        // print currency record
        static void _PrintCurrencyRecord(clsCurrency Currency);
        // read exist currency
        static string _ReadExistCurrency(string prompt);
        // perform currency Calculator
        static void _PerformCurrencyCalculator();

    public:
        // Currency Calculator
        static void CurrencyCalculScreen();
};

#endif // !CLSCURRENCYCALCULATOR_H
