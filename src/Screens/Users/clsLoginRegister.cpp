#include "../../../headers/Screens/Users/clsLoginRegister.h"
#include "../../../headers/Core/clsUser.h"
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// print LoginRegister line
void clsLoginRegister::_PrintLoginRegisterLine(clsUser::stLoginRegister LogReg) {
    short width = 14;
    cout << Colors::GetBoldBlue() << setfill(' ') << left << setw(width) << LogReg.Username << left << setw(width) << LogReg.Password << left << setw(width + 2) << LogReg.Permission << left << setw(width + 4) << LogReg.DateAndTime << Colors::RESET() << endl;
}
// Login Register screen
void clsLoginRegister::LoginRegisterScreen() {
    // check access permissions
    if (!CheckPermissionRights(clsUser::enPermissionAccess::pLoginRegister)) {
        return;
    }

    PrintHeaderScreen("LOGINREGISTER SCREEN", "👤", Colors::Cyan);
    cout << "\n\n";
    vector<clsUser::stLoginRegister> vLogRegisters = clsUser::GetLoginRegisterList();
    PrintHeaderScreen("Login Registers", to_string(vLogRegisters.size()), Colors::BoldYellow, false);
    short width = 14;
    cout << Colors::GetBoldYellow() << setfill(' ') << left << setw(width) << "Username" << left << setw(width) << "Password" << left << setw(width + 2) << "Permissions" << left << setw(width) << "Date & Time" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vLogRegisters.empty()) {
        cout << Colors::GetRed() << "                    No Login Register Found" << Colors::RESET() << endl;
    } else {
        for (clsUser::stLoginRegister &LogReg : vLogRegisters) {
            _PrintLoginRegisterLine(LogReg);
        }
    }
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
