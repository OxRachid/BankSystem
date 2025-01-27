#ifndef CLSADDNEWCLIENT_H
#define CLSADDNEWCLIENT_H

#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"
using namespace std;

class clsAddNewClient : protected clsScreen {
        // Read client data
        static void _ReadClientData(clsBankClient &client);
        // Print client data
        static void _PrintClientData(clsBankClient client);

    public:
        // Add new client
        static void AddNewClientScreen();
};

#endif // !CLSADDNEWCLIENT_H
