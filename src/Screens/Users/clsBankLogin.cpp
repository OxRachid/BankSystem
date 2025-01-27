#include "../../../headers/Screens/Users/clsBankLogin.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/clsMainScreen.h"
using namespace std;

// login
bool clsBankLogin::_Login() {
    string username = "", password = "";
    bool isLoginValid = false;
    short LoginAttemps = 3;
    do {
        if (isLoginValid) {
            --LoginAttemps;
            system("clear");
            clsScreen::PrintHeaderScreen("LOGIN SCREEN", "🔑", Colors::Magenta);
            cout << "\n\n";
            cout << Colors::GetRed() << " [ username or password is incorrect ! ]" << endl;
            cout << Colors::GetRed() << " [ You have only " << LoginAttemps << " Attemps to login ]" << endl << endl;
        }
        if (LoginAttemps == 0) {
            cout << Colors::GetRed() << " ⊗ Failed to login ..." << endl;
            return false;
        }
        username = clsInputValidate::ReadString(" Username : ");
        password = clsInputValidate::ReadString(" Password : ");

        CurrUser = clsUser::Find(username, password);
        isLoginValid = CurrUser.isEmpty();
    } while (isLoginValid);
    // save user login info in log file
    CurrUser.RegisterLogIn();
    // if login is valid then we show main menu screen
    clsMainScreen::ShowMainScreen();

    return true;
}

// Login screen
bool clsBankLogin::LoginScreen() {
    system("clear");
    clsScreen::PrintHeaderScreen("LOGIN SCREEN", "🔑", Colors::Magenta);
    cout << "\n\n";
    // Logim
    return _Login();
}
