#ifndef CLSMANAGEUSERSMENU_H
#define CLSMANAGEUSERSMENU_H

#include "../clsScreen.h"
#include <string>
using namespace std;

class clsManageUsersMenu : protected clsScreen {
    private:
        enum enManageUsersOptions {
            eUsersList = 1,
            eAddNewUser = 2,
            eDeleteUser = 3,
            eUpdateUser = 4,
            eFindUser = 5,
            eShowMainMenu = 6
        };

        // Perform ManageUsersMenu Options
        static void _PerformManageUsersOptions(enManageUsersOptions eOption);
        // Go to ManageUsersMenu screen
        static void _GoToManageUsersMenu();
        // Users list screen
        static void _UsersListScreen();
        // add new user screen
        static void _AddNewUserScreen();
        // delete user screen
        static void _DeleteUserScreen();
        // update user screen
        static void _UpdateUserScreen();
        // Find user screen
        static void _FindUserScreen();

    public:
        // Manage uers menu
        static void ManageUsersMenu();
};

#endif // !CLSMANAGEUSERSMENU_H
