#ifndef CLSSCREEN_H
#define CLSSCREEN_H
#include "../Color/Colors.h"
#include "../Core/clsUser.h"
#include <string>
using namespace std;

class clsScreen {
    protected:
        // Print header screen
        static void PrintHeaderScreen(string HeaderTitle = "", string value = "", Colors::enColors color = Colors::White, bool isMainHeader = true, short width = 66);
        // check permission rights
        static bool CheckPermissionRights(clsUser::enPermissionAccess FunPermission);
};

#endif // !CLSSCREEN_H
