#include "../../../headers/Screens/Users/clsAddNewUser.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <string>
using namespace std;

// Read user permissions
short clsAddNewUser::_ReadUserPermissions() {
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

// Read user data
void clsAddNewUser::_ReadUserData(clsUser &user) {
    user.SetFirstName(clsInputValidate::ReadString(" ^ Enter FirstName : "));
    user.SetLastName(clsInputValidate::ReadString(" ^ Enter LastName : "));
    user.SetEmail(clsInputValidate::ReadString(" ^ Enter Email : "));
    user.SetPhone(clsInputValidate::ReadString(" ^ Enter Phone : "));
    user.SetPassword(clsInputValidate::ReadString(" ^ Enter Password : "));
    user.SetPermission(_ReadUserPermissions());
}

// Print User Data
void clsAddNewUser::_PrintUserData(clsUser user) {
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

// Add New User screen
void clsAddNewUser::AddNewUserScreen() {
    PrintHeaderScreen("ADDNEWUSER SCREEN", "+👤", Colors::Cyan);
    cout << "\n\n";
    PrintHeaderScreen("Read User Data", "📝", Colors::Magenta, false, 36);
    string username = clsInputValidate::ReadString(" ^ Enter username : ");
    while (clsUser::isUserExist(username)) {
        cout << Colors::GetYellow() << " [ The User <" << username << "> is already exist ]" << Colors::RESET() << endl;
        username = clsInputValidate::ReadString(" ^ Please Enter another username : ");
    }
    // Get addnewuser Mode
    clsUser user = clsUser::GetAddUserMode(username);
    // Read user data
    _ReadUserData(user);
    // save user data in file
    clsUser::svResult Result = user.save();
    switch (Result) {
        case clsUser::svResult::enSaveSucceed: {
            _PrintUserData(user);
            cout << Colors::GetGreen() << " ⟩ The User Added Succusfully ✓" << Colors::RESET() << endl;
            break;
        }
        case clsUser::svResult::enSaveFailed: {
            cout << Colors::GetMagenta() << " ⟩ Failed, The User object is Empty." << Colors::RESET() << endl;
            break;
        }
        case clsUser::svResult::enFailedUserExist: {
            cout << Colors::GetMagenta() << " ⟩ Failed, The User is already exist." << Colors::RESET() << endl;
            break;
        }
    }
}
