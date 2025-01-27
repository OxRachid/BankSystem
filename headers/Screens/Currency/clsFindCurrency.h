#ifndef CLSFINDCURRENCY_H
#define CLSFINDCURRENCY_H

#include "../../Core/clsCurrency.h"
#include "../clsScreen.h"
#include <string>

class clsFindCurrency : protected clsScreen {
    private:
        // enum for find method
        enum eFindMethod {
            eFindByCode = 1,
            FindByCountry = 2
        };
        // print currency record
        static void _PrintCurrencyRecord(clsCurrency currency);
        // perform find method
        static clsCurrency _PerformFindMethod(eFindMethod method);

    public:
        // find currency Screen
        static void FindCurrencyScreen();
};

#endif // !CLSFINDCURRENCY_H
