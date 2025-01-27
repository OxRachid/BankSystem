#ifndef CLSUPDATEUSER_H
#define CLSUPDATEUSER_H

#include "../../Core/clsUser.h"
#include "../clsScreen.h"

class clsUpdateUser : protected clsScreen {
    private:
        // Read Existing user
        static string _ReadExistUser();
        // Print User Data
        static void _PrintUserData(clsUser user);
        // update user data
        static void _ReadNewUserData(clsUser &user);
        // Read user permissions
        static short _ReadUserPermissions();

    public:
        // Update user screen
        static void UpdateUserScreen();
};

#endif // !CLSUPDATEUSER_H
