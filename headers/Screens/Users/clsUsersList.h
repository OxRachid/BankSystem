#ifndef CLSUSERSLIST_H
#define CLSUSERSLIST_H

#include "../../Core/clsUser.h"
#include "../clsScreen.h"
#include <string>

class clsUsersList : protected clsScreen {
    private:
        // print user data
        static void _PrintUserData(clsUser User);

    public:
        // Show UsersList screen
        static void UsersListScreen();
};

#endif // !CLSUSERSLIST_H
