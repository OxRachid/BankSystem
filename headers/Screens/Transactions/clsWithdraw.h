#ifndef CLSWITHDRAW_H
#define CLSWITHDRAW_H

#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"
#include <string>

class clsWithdraw : protected clsScreen {
    private:
        // Print client data
        static void _PrintClientData(clsBankClient client);
        // Read Existing Account Number
        static string _ReadExistAccountNumber();

    public:
        // Deposite
        static void WithdrawScreen();
};

#endif // !CLSWITHDRAW_H
