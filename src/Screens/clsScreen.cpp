#include "../../headers/Screens/clsScreen.h"
#include "../../headers/Color/Colors.h"
#include "../../headers/Core/Globals.h"
#include "../../headers/Lib/clsDate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print header screen
void clsScreen::PrintHeaderScreen(string HeaderTitle, string value, Colors::enColors color, bool isMainHeader, short width) {
    cout << Colors::GetColor(color) << setw(width) << setfill('-') << "" << Colors::RESET() << endl;
    cout << Colors::GetColor(color) << setw((width / 2) - 9) << setfill(' ') << " " << left << HeaderTitle << " {" << value << "}" << Colors::RESET() << endl;
    if (isMainHeader) {
        cout << Colors::GetColor(color) << setw((width / 2) - 9) << setfill(' ') << " " << left << "User : " << CurrUser.GetUsername() << Colors::RESET() << endl;
        cout << Colors::GetColor(color) << setw((width / 2) - 9) << setfill(' ') << " " << left << "Date : " << clsDate::GetDateAndTime() << Colors::RESET() << endl;
    }
    cout << Colors::GetColor(color) << setw(width) << setfill('-') << "" << Colors::RESET() << endl;
}

// check permission rights
bool clsScreen::CheckPermissionRights(clsUser::enPermissionAccess FunPermission) {
    if (!CurrUser.CheckAccessPermissions(FunPermission)) {
        cout << Colors::GetRed() << "┌─────────────────────────⚠️──────────────────────────┐" << endl;
        cout << "├ You Don't have Permission to Access this function, ┤" << endl;
        cout << "├ Please Contact Your Admin...                       ┤" << endl;
        cout << "└────────────────────────────────────────────────────┘" << Colors::RESET() << endl;
        return false;
    } else {
        return true;
    }
}
