#ifndef CLSBANKUSER_H
#define CLSBANKUSER_H

#include "../../Core/clsUser.h"
#include "../../Screens/clsScreen.h"

class clsBankLogin : protected clsScreen {
    private:
        // login
        static bool _Login();

    public:
        // Login screen
        static bool LoginScreen();
};

#endif // !CLSBANKUSER_H
