#ifndef CLSUPDATERATE_H
#define CLSUPDATERATE_H

#include "../../Core/clsCurrency.h"
#include "../clsScreen.h"
#include <string>

class clsUpdateRate : protected clsScreen {
    private:
        // print currency record
        static void _PrintCurrencyRecord(clsCurrency Currency);
        // read exist currency
        static string _ReadExistCurrency();

    public:
        // UpdateRate
        static void UpdateRateScreen();
};

#endif // !CLSUPDATERATE_H
