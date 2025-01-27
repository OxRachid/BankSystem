#include "../../../headers/Screens/Users/clsDeleteUser.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <string>
using namespace std;

// Read Existing user
string clsDeleteUser::_ReadExistUser() {
    string username = clsInputValidate::ReadString(" ^ Enter username : ");
    // check is user exist
    while (!clsUser::isUserExist(username)) {
        cout << Colors::GetYellow() << " No User found..." << Colors::RESET() << endl;
        username = clsInputValidate::ReadString(" ^ Please Enter a Valid username : ");
    }
    return username;
}
// Print User Data
void clsDeleteUser::_PrintUserData(clsUser user) {
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

// Delete user screen
void clsDeleteUser::DeleteUserScreen() {
    PrintHeaderScreen("DELETE USER SCREEN", "-👤", Colors::Red);
    cout << "\n\n";
    // Read existing user
    string username = _ReadExistUser();
    // Search for the user obj and return a full obj
    clsUser user = clsUser::Find(username);
    // print user data in screen
    _PrintUserData(user);
    // Ask user to take action
    if (clsInputValidate::AskUser("\n ^ Are u sure wanna delete <" + username + ">")) {
        clsUser::Delete(user);
        _PrintUserData(user);
        cout << Colors::GetGreen() << " ⟩ The User Deleted Succusfully ✓" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetMagenta() << " ⟩ Delete Canceled ✓" << Colors::RESET() << endl;
    }
}
