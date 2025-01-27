#ifndef CLSDEPOSITE_H
#define CLSDEPOSITE_H

#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"
#include <string>

class clsDeposite : protected clsScreen {
    private:
        // Print client data
        static void _PrintClientData(clsBankClient client);
        // Read Existing Account Number
        static string _ReadExistAccountNumber();

    public:
        // Deposite
        static void DepositeScreen();
};

#endif // !CLSDEPOSITE_H
