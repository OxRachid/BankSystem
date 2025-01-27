#ifndef CLSADDNEWUSER_H
#define CLSADDNEWUSER_H

#include "../../Core/clsUser.h"
#include "../clsScreen.h"
#include <string>

class clsAddNewUser : protected clsScreen {
    private:
        // Read user data
        static void _ReadUserData(clsUser &user);
        // Print User Data
        static void _PrintUserData(clsUser user);
        // Read user permissions
        static short _ReadUserPermissions();

    public:
        // Add New User screen
        static void AddNewUserScreen();
};

#endif // !CLSADDNEWUSER_H
