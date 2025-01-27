#include "../../headers/Screens/clsMainScreen.h"
#include "../../headers/Color/Colors.h"
#include "../../headers/Lib/clsInputValidate.h"
#include "../../headers/Screens/Clients/clsAddNewClient.h"
#include "../../headers/Screens/Clients/clsClientsList.h"
#include "../../headers/Screens/Clients/clsDeleteClient.h"
#include "../../headers/Screens/Clients/clsFindClient.h"
#include "../../headers/Screens/Clients/clsUpdateClient.h"
#include "../../headers/Screens/Currency/clsCurrencyMainMenu.h"
#include "../../headers/Screens/Transactions/clsTransactionMenu.h"
#include "../../headers/Screens/Users/clsLoginRegister.h"
#include "../../headers/Screens/Users/clsManageUsersMenu.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print main screen
void clsMainScreen::ShowMainScreen() {
    system("clear");
    PrintHeaderScreen("MAIN SCREEN", "📂", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Main Menue ", "📋", Colors::Yellow, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Show Clients List" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Add New Client" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Delete Client" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Update Client" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Find Client" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Transactions" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[7] Manage Users" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[8] Login Register" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[9] Currency Exchange" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[10] Log out" << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    _PerformMainScreenOptions((enMainSceenOptions)clsInputValidate::Readnumberbetween(1, 10, " \n* Select Option : "));
}

// Perform main screen options
void clsMainScreen::_PerformMainScreenOptions(enMainSceenOptions options) {
    switch (options) {
        case enMainSceenOptions::eClientsList: {
            _ShowClientsList();
            _GoToMainScreen();
            break;
        }
        case enMainSceenOptions::eAddNewClient: {
            _ShowAddNewClient();
            _GoToMainScreen();
            break;
        }
        case enMainSceenOptions::eDeleteClient: {
            _ShowDeleteClient();
            _GoToMainScreen();
            break;
        }
        case enMainSceenOptions::eUpdateClient: {
            _ShowUpdateClient();
            _GoToMainScreen();
            break;
        }
        case enMainSceenOptions::eFindClient: {
            _ShowFindClient();
            _GoToMainScreen();
            break;
        }
        case enMainSceenOptions::eTransaction: {
            _ShowTransactionsMenu();
            _GoToMainScreen();
            break;
        }
        case enMainSceenOptions::eManageUsers: {
            _ShowManageUsersMenu();
            _GoToMainScreen();
            break;
        }
        case enMainSceenOptions::eLoginRegister: {
            _ShowLoginRegister();
            _GoToMainScreen();
            break;
        }
        case enMainSceenOptions::eCurrencyExchange: {
            _CurrencyExchange();
            _GoToMainScreen();
            break;
        }
        case enMainSceenOptions::eLogout: {
            break;
        }
    }
}

// Go To main screen
void clsMainScreen::_GoToMainScreen() {
    // this trick just to pause termux screen until the user Contenu
    cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
    char Contenue = clsInputValidate::ReadChar();
    Contenue = ' ';
    cout << Contenue << endl;
    // go back to main screen function
    ShowMainScreen();
}
// Show clients list
void clsMainScreen::_ShowClientsList() {
    system("clear");
    clsClientsList::ClientsList();
}
// Add new client
void clsMainScreen::_ShowAddNewClient() {
    system("clear");
    clsAddNewClient::AddNewClientScreen();
}
// Delete Client
void clsMainScreen::_ShowDeleteClient() {
    system("clear");
    clsDeleteClient::DeleteClientScreen();
}
// Update Client
void clsMainScreen::_ShowUpdateClient() {
    system("clear");
    clsUpdateClient::UpdateClientScreen();
}
// find client
void clsMainScreen::_ShowFindClient() {
    system("clear");
    clsFindClient::FindClient();
}
// Transactions menu
void clsMainScreen::_ShowTransactionsMenu() {
    system("clear");
    clsTransactionMenu::TransactionMenu();
}
// manage users menu
void clsMainScreen::_ShowManageUsersMenu() {
    system("clear");
    clsManageUsersMenu::ManageUsersMenu();
}

// Login Register
void clsMainScreen::_ShowLoginRegister() {
    system("clear");
    clsLoginRegister::LoginRegisterScreen();
}

// CurrencyExchange
void clsMainScreen::_CurrencyExchange() {
    system("clear");
    clsCurrencyMainMenu::CurrencyMainMenuScreen();
}
