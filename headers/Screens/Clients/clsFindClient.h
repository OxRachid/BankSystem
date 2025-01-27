#ifndef CLSFINDCLIENT_H
#define CLSFINDCLIENT_H

#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"
#include <string>
using namespace std;

class clsFindClient : protected clsScreen {
    private:
        // Read Existing Account Number
        static string _ReadExistAccountNumber();
        // Print client data
        static void _PrintClientData(clsBankClient client);

    public:
        // find Find Client
        static void FindClient();
};

#endif // !CLSFINDCLIENT_H
