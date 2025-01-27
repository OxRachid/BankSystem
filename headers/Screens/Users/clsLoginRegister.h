#ifndef CLSLOGINREGISTER_H
#define CLSLOGINREGISTER_H

#include "../../Core/clsUser.h"
#include "../clsScreen.h"
#include <string>

class clsLoginRegister : protected clsScreen {
    private:
        // print LoginRegister line
        static void _PrintLoginRegisterLine(clsUser::stLoginRegister LogReg);

    public:
        // Login Register screen
        static void LoginRegisterScreen();
};

#endif // !CLSLOGINREGISTER_H
