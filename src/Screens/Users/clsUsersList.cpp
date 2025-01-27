#include "../../../headers/Screens/Users/clsUsersList.h"
#include "../../../headers/Core/clsUser.h"
#include <iomanip>
#include <vector>
using namespace std;

// print user data
void clsUsersList::_PrintUserData(clsUser User) {
    short width = 16;
    cout << Colors::GetBlue() << setfill(' ') << left << setw(width - 2) << User.GetFullName() << left << setw(width - 5) << User.GetUsername() << left << setw(width - 7) << User.GetEmail() << left << setw(width - 7) << User.GetPhone() << left << setw(width + 2) << User.GetPassword() << left << setw(width - 14) << User.GetPermission() << Colors::RESET() << endl;
}

// Show UsersList screen
void clsUsersList::UsersListScreen() {
    PrintHeaderScreen("USERSLIST SCREEN", "👤", Colors::Cyan);
    cout << "\n\n";
    vector<clsUser> vUsers = clsUser::GetUsersList();
    PrintHeaderScreen("Users", to_string(vUsers.size()), Colors::BoldYellow, false);
    short width = 16;
    cout << Colors::GetBoldYellow() << setfill(' ') << left << setw(width - 2) << "FullName" << left << setw(width - 5) << "Username" << left << setw(width - 7) << "Email" << left << setw(width - 7) << "Phone" << left << setw(width + 2) << "Pass" << left << setw(width - 14) << "Perm" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vUsers.empty()) {
        cout << Colors::GetRed() << "                    No Users Found" << Colors::RESET() << endl;
    } else {
        for (clsUser &U : vUsers) {
            _PrintUserData(U);
        }
    }
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
