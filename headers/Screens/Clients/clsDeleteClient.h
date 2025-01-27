#ifndef CLSDELETECLIENT_H
#define CLSDELETECLIENT_H

#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"
#include <string>
using namespace std;

class clsDeleteClient : protected clsScreen {
    private:
        // Read Existing Account Number
        static string _ReadExistAccountNumber();
        // Print client data
        static void _PrintClientData(clsBankClient client);

    public:
        // Delete client
        static void DeleteClientScreen();
};

#endif // !CLSDELETECLIENT_H
