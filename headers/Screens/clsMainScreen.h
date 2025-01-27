#ifndef CLSMAINSCREEN_H
#define CLSMAINSCREEN_H
#include "clsScreen.h"
#include <string>
using namespace std;

class clsMainScreen : protected clsScreen {
    private:
        enum enMainSceenOptions {
            eClientsList = 1,
            eAddNewClient = 2,
            eDeleteClient = 3,
            eUpdateClient = 4,
            eFindClient = 5,
            eTransaction = 6,
            eManageUsers = 7,
            eLoginRegister = 8,
            eCurrencyExchange = 9,
            eLogout = 10
        };

        // Perform main screen options
        static void _PerformMainScreenOptions(enMainSceenOptions options);
        // Go To main screen
        static void _GoToMainScreen();
        // Show clients list
        static void _ShowClientsList();
        // Add new client
        static void _ShowAddNewClient();
        // Delete Client
        static void _ShowDeleteClient();
        // Update Client
        static void _ShowUpdateClient();
        // find client
        static void _ShowFindClient();
        // Transaction
        static void _ShowTransactionsMenu();
        // manage users
        static void _ShowManageUsersMenu();
        // Login Register
        static void _ShowLoginRegister();
        // CurrencyExchange
        static void _CurrencyExchange();

    public:
        // Print main screen
        static void ShowMainScreen();
};

#endif // !CLSMAINSCREEN_H
