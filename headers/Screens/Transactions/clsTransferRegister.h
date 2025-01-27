#ifndef CLSTRANSFERREGISTER_H
#define CLSTRANSFERREGISTER_H

#include "../../Core/clsBankClient.h"
#include "../clsScreen.h"

class clsTransferRegister : protected clsScreen {
        // print TransferRegister line
        static void _PrintTransferRegisterLine(clsBankClient::stTransferRegister TrReg);

    public:
        // Transfer Register screen
        static void TransferRegisterScreen();
};

#endif // !CLSTRANSFERREGISTER_H
