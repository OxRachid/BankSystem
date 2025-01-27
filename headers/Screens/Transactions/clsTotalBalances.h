#ifndef CLSTOTALBALANCES_H
#define CLSTOTALBALANCES_H

#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"
#include <string>

class clsTotalBalances : protected clsScreen {
    private:
        // print client record Balance
        static void _PrintClientBalance(clsBankClient client);

    public:
        // total balances
        static void TotalBalancesScreen();
};

#endif // !CLSTOTALBALANCES_H
