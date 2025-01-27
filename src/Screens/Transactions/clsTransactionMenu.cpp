#include "../../../headers/Screens/Transactions/clsTransactionMenu.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/Transactions/clsDeposite.h"
#include "../../../headers/Screens/Transactions/clsTotalBalances.h"
#include "../../../headers/Screens/Transactions/clsTransfer.h"
#include "../../../headers/Screens/Transactions/clsTransferRegister.h"
#include "../../../headers/Screens/Transactions/clsWithdraw.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
// transaction menu
void clsTransactionMenu::TransactionMenu() {
    // check access permissions
    if (!CheckPermissionRights(clsUser::enPermissionAccess::pTransaction)) {
        return;
    }

    system("clear");
    PrintHeaderScreen("TRANSACTIONS SCREEN", "💲", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Transactions Menu ", "📋", Colors::Yellow, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Deposite" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Withdraw" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Total Balances" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Transfer" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Transfer Log" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Main Menu" << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    _PerformTransactionOptions((enTransactionOptions)clsInputValidate::Readnumberbetween(1, 6, " \n* Select Option : "));
}

// Perform transaction options
void clsTransactionMenu::_PerformTransactionOptions(enTransactionOptions Option) {
    switch (Option) {
        case enTransactionOptions::eDeposit: {
            _DepositScreen();
            _GoToTransactionMenu();
            break;
        }
        case enTransactionOptions::eWithdraw: {
            _WithdrawScreen();
            _GoToTransactionMenu();
            break;
        }
        case enTransactionOptions::eTotalBalances: {
            _TotalBalancesScreen();
            _GoToTransactionMenu();
            break;
        }
        case enTransactionOptions::eTransfer: {
            _TransferScreen();
            _GoToTransactionMenu();
            break;
        }
        case enTransactionOptions::eTransferLog: {
            _TransferLogScreen();
            _GoToTransactionMenu();
            break;
        }

        case enTransactionOptions::eMainMenu: {
            break;
        }
        default:
            break;
    }
}

// Go To TransactionMenu
void clsTransactionMenu::_GoToTransactionMenu() {
    // this trick just to pause termux screen until the user Contenu
    cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
    char Contenue = clsInputValidate::ReadChar();
    Contenue = ' ';
    cout << Contenue << endl;
    // go back to main screen function
    TransactionMenu();
}
// Deposit
void clsTransactionMenu::_DepositScreen() {
    system("clear");
    clsDeposite::DepositeScreen();
}
// Withdraw
void clsTransactionMenu::_WithdrawScreen() {
    system("clear");
    clsWithdraw::WithdrawScreen();
}
// Total Balances
void clsTransactionMenu::_TotalBalancesScreen() {
    system("clear");
    clsTotalBalances::TotalBalancesScreen();
}

// transfer
void clsTransactionMenu::_TransferScreen() {
    system("clear");
    clsTransfer::TransferScreen();
}

// transfer log
void clsTransactionMenu::_TransferLogScreen() {
    system("clear");
    clsTransferRegister::TransferRegisterScreen();
}
