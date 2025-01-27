#ifndef CLSDELETEUSER_H
#define CLSDELETEUSER_H

#include "../../Core/clsUser.h"
#include "../clsScreen.h"

class clsDeleteUser : protected clsScreen {
    private:
        // Read Existing user
        static string _ReadExistUser();
        // Print User Data
        static void _PrintUserData(clsUser user);

    public:
        // Delete user screen
        static void DeleteUserScreen();
};

#endif // CLSDELETEUSER_H
