#include "../../../headers/Screens/Users/clsFindUser.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Read Existing user
string clsFindUser::_ReadExistUser() {
    string username = clsInputValidate::ReadString(" ^ Enter username : ");
    // check is user exist
    while (!clsUser::isUserExist(username)) {
        cout << Colors::GetYellow() << " No User found..." << Colors::RESET() << endl;
        username = clsInputValidate::ReadString(" ^ Please Enter a Valid username : ");
    }
    return username;
}
// Print User Data
void clsFindUser::_PrintUserData(clsUser user) {
    cout << endl;
    PrintHeaderScreen("*User Data*", "👤", Colors::Blue, false, 36);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " FirstName" << " : " << user.GetFirstName() << endl;
    cout << left << setw(20) << " LastName" << " : " << user.GetLastName() << endl;
    cout << left << setw(20) << " FullName" << " : " << user.GetFullName() << endl;
    cout << left << setw(20) << " Email" << " : " << user.GetEmail() << endl;
    cout << left << setw(20) << " Phone" << " : " << user.GetPhone() << endl;
    cout << left << setw(20) << " Username" << " : " << user.GetUsername() << endl;
    cout << left << setw(20) << " Password" << " : " << user.GetPassword() << endl;
    cout << left << setw(20) << " Permissions" << " : " << user.GetPermission() << endl;
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl;
}

// find user screen
void clsFindUser::FindUserScreen() {
    PrintHeaderScreen("FIND USER SCREEN", "🔍", Colors::Yellow);
    cout << "\n\n";
    // Read existing user
    string username = _ReadExistUser();
    // Search for the user obj and return a full obj
    clsUser user = clsUser::Find(username);
    // ensure the user if is exist and print its data
    if (user.isEmpty()) {
        cout << Colors::GetRed() << "\n [ The user Not Found ]" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetGreen() << "\n [ The user Founded ]" << Colors::RESET() << endl;
        // print user data
        _PrintUserData(user);
    }
    CurrUser = clsUser::Find("Admin");
    _PrintUserData(CurrUser);
}
