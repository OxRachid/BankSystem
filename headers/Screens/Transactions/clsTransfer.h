#ifndef CLSTRANSFER_H
#define CLSTRANSFER_H

#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"
#include <string>

class clsTransfer : protected clsScreen {
    private:
        // Print client data
        static void _PrintClientData(clsBankClient client);
        // Read Existing Account Number
        static string _ReadAccountNumber(string FromOrTo);
        // check amount if is valid
        static double _ReadAmount(clsBankClient SourceClient);

    public:
        // transfer screen
        static void TransferScreen();
};

#endif // !CLSTRANSFER_H
