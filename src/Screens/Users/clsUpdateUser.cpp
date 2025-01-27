#include "../../../headers/Screens/Users/clsUpdateUser.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Read Existing user
string clsUpdateUser::_ReadExistUser() {
    string username = clsInputValidate::ReadString(" ^ Enter username : ");
    // check is user exist
    while (!clsUser::isUserExist(username)) {
        cout << Colors::GetYellow() << " No User found..." << Colors::RESET() << endl;
        username = clsInputValidate::ReadString(" ^ Please Enter a Valid username : ");
    }
    return username;
}
// Print User Data
void clsUpdateUser::_PrintUserData(clsUser user) {
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

// Read user permissions
short clsUpdateUser::_ReadUserPermissions() {
    PrintHeaderScreen("Read Permissions", "🔐", Colors::Yellow, false, 36);
    if (clsInputValidate::AskUser(" ^ Give Access to All Functions")) {
        return -1;
    }

    cout << Colors::GetBlue() << " □ Give Access to : " << Colors::RESET() << endl;
    short permissions = 0;
    if (clsInputValidate::AskUser(" ⊷ (ClientsList) ")) {
        permissions += clsUser::enPermissionAccess::pClientsList;
    }
    if (clsInputValidate::AskUser(" ⊷ (AddNewClient) ")) {
        permissions += clsUser::enPermissionAccess::pAddNewClient;
    }
    if (clsInputValidate::AskUser(" ⊷ (DeleteClient) ")) {
        permissions += clsUser::enPermissionAccess::pDeleteClient;
    }
    if (clsInputValidate::AskUser(" ⊷ (UpdateClient) ")) {
        permissions += clsUser::enPermissionAccess::pUpdateClient;
    }
    if (clsInputValidate::AskUser(" ⊷ (FindClient) ")) {
        permissions += clsUser::enPermissionAccess::pFindClient;
    }
    if (clsInputValidate::AskUser(" ⊷ (Transactions) ")) {
        permissions += clsUser::enPermissionAccess::pTransaction;
    }
    if (clsInputValidate::AskUser(" ⊷ (Manage Users) ")) {
        permissions += clsUser::enPermissionAccess::pManageUsers;
    }
    if (clsInputValidate::AskUser(" ⊷ (Login Register) ")) {
        permissions += clsUser::enPermissionAccess::pLoginRegister;
    }

    return permissions;
}

// update user data
void clsUpdateUser::_ReadNewUserData(clsUser &user) {
    PrintHeaderScreen("Update User Data", "📝", Colors::Magenta, false, 36);
    user.SetFirstName(clsInputValidate::ReadString(" ^ Enter FirstName : "));
    user.SetLastName(clsInputValidate::ReadString(" ^ Enter LastName : "));
    user.SetEmail(clsInputValidate::ReadString(" ^ Enter Email : "));
    user.SetPhone(clsInputValidate::ReadString(" ^ Enter Phone : "));
    user.SetPassword(clsInputValidate::ReadString(" ^ Enter Password : "));
    user.SetPermission(_ReadUserPermissions());
}

// Update user screen
void clsUpdateUser::UpdateUserScreen() {
    PrintHeaderScreen("UPDATE USER SCREEN", "⚙️", Colors::Cyan);
    cout << "\n\n";
    // Read Existing user
    string username = _ReadExistUser();
    // Search and Get user obj
    clsUser user = clsUser::Find(username);
    // Print user data
    _PrintUserData(user);
    if (clsInputValidate::AskUser("\n ^ Are u sure wanna Update <" + username + ">")) {
        // update user data
        _ReadNewUserData(user);
        // save the update user
        clsUser::svResult Result = user.save();
        switch (Result) {
            case clsUser::svResult::enSaveSucceed: {
                _PrintUserData(user);
                cout << Colors::GetGreen() << " ⟩ Updated Succusfully ✓" << Colors::RESET() << endl;
                break;
            }
            case clsUser::svResult::enSaveFailed: {
                cout << Colors::GetRed() << " [ Failed, The object is Empty ]" << Colors::RESET() << endl;
                break;
            }
            case clsUser::svResult::enFailedUserExist: {
                cout << Colors::GetRed() << " [ Failed, The user is already exist ]" << Colors::RESET() << endl;
                break;
            }
        }

    } else {
        cout << Colors::GetMagenta() << " ⟩ Update Canceled ✓" << Colors::RESET() << endl;
    }
}
