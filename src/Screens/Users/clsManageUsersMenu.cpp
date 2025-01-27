#include "../../../headers/Screens/Users/clsManageUsersMenu.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/Users/clsAddNewUser.h"
#include "../../../headers/Screens/Users/clsDeleteUser.h"
#include "../../../headers/Screens/Users/clsFindUser.h"
#include "../../../headers/Screens/Users/clsUpdateUser.h"
#include "../../../headers/Screens/Users/clsUsersList.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Manage uers menu
void clsManageUsersMenu::ManageUsersMenu() {
    // check access permissions
    if (!CheckPermissionRights(clsUser::enPermissionAccess::pManageUsers)) {
        return;
    }

    system("clear");
    PrintHeaderScreen("MANAGE USERS NENU ", "👥", Colors::Blue);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Manage Users ", "📋", Colors::Yellow, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Users List" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Add New User" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Delete User" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Update User" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Find User" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Main Menu" << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    enManageUsersOptions eOption = (enManageUsersOptions)clsInputValidate::Readnumberbetween<short>(1, 6, "\n * Select Option : ");
    _PerformManageUsersOptions(eOption);
}

// Perform ManageUsersOptions
void clsManageUsersMenu::_PerformManageUsersOptions(enManageUsersOptions option) {
    switch (option) {
        case enManageUsersOptions::eUsersList: {
            system("clear");
            _UsersListScreen();
            _GoToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eAddNewUser: {
            system("clear");
            _AddNewUserScreen();
            _GoToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eDeleteUser: {
            system("clear");
            _DeleteUserScreen();
            _GoToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eUpdateUser: {
            system("clear");
            _UpdateUserScreen();
            _GoToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eFindUser: {
            system("clear");
            _FindUserScreen();
            _GoToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eShowMainMenu: {
            // nothing to write here to make it exit to main menu dericlty
            break;
        }
        default:
            break;
    }
}

// Go to ManageUsersMenu screen
void clsManageUsersMenu::_GoToManageUsersMenu() {
    // this trick just to pause termux screen until the user Contenu
    cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
    char Contenue = clsInputValidate::ReadChar();
    Contenue = ' ';
    cout << Contenue << endl;
    // go back to main screen function
    ManageUsersMenu();
}
// Users list screen
void clsManageUsersMenu::_UsersListScreen() {
    system("clear");
    clsUsersList::UsersListScreen();
}
// add new user screen
void clsManageUsersMenu::_AddNewUserScreen() {
    system("clear");
    clsAddNewUser::AddNewUserScreen();
}
// delete user screen
void clsManageUsersMenu::_DeleteUserScreen() {
    system("clear");
    clsDeleteUser::DeleteUserScreen();
}
// update user screen
void clsManageUsersMenu::_UpdateUserScreen() {
    system("clear");
    clsUpdateUser::UpdateUserScreen();
}
// Find user screen
void clsManageUsersMenu::_FindUserScreen() {
    system("clear");
    clsFindUser::FindUserScreen();
}
