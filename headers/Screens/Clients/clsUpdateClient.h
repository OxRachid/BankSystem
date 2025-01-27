#ifndef CLSUPDATECLIENT_H
#define CLSUPDATECLIENT_H
#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"
#include <string>
using namespace std;

class clsUpdateClient : protected clsScreen {
    private:
        // Read Existing Account Number
        static string _ReadExistAccountNumber();
        // Read Update client data
        static void _ReadClientData(clsBankClient &client);
        // Print client data
        static void _PrintClientData(clsBankClient client);

    public:
        // Update client
        static void UpdateClientScreen();
};

#endif // !CLSUPDATECLIENT_H
