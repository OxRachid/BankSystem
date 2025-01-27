#include "../headers/Core/Globals.h"
#include "../headers/Screens/Users/clsBankLogin.h"
using namespace std;

int main() {
    while (true) {
        clsBankLogin::LoginScreen();
        if (CurrUser.isEmpty()) {
            break;
        }
    }
    return 0;
}
