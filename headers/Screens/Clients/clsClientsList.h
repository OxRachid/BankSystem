#ifndef CLSCLIENTSLIST_H
#define CLSCLIENTSLIST_H

#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"
#include <string>

using namespace std;

class clsClientsList : protected clsScreen {
    private:
        // Print client data in one line
        static void _PrintClientDataInOneLine(clsBankClient client);

    public:
        // Show clients list
        static void ClientsList();
};

#endif // !CLSCLIENTSLIST_H
