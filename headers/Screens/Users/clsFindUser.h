#ifndef CLSFINDUSER_H
#define CLSFINDUSER_H

#include "../../Core/clsUser.h"
#include "../clsScreen.h"

class clsFindUser : protected clsScreen {
    private:
        // Read Existing user
        static string _ReadExistUser();
        // Print User Data
        static void _PrintUserData(clsUser user);

    public:
        // find user screen
        static void FindUserScreen();
};

#endif // !CLSFINDUSER_H
