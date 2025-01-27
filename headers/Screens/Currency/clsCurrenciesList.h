#ifndef CLSCURRENCIESLIST_H
#define CLSCURRENCIESLIST_H

#include "../../Core/clsCurrency.h"
#include "../clsScreen.h"
#include <string>
#include <type_traits>

class clsCurrenciesList : protected clsScreen {
    private:
        // print Currencies list line
        static void _PrintCurrencyLine(clsCurrency currency);

    public:
        // Currencies List
        static void CurrenciesList();
};

#endif // !CLSCURRENCIESLIST_H
