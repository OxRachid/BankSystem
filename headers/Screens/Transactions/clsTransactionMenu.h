#ifndef CLSTRANSACTIONMENU_H
#define CLSTRANSACTIONMENU_H

#include "../clsScreen.h"
#include <string>
using namespace std;

class clsTransactionMenu : protected clsScreen {
    private:
        enum enTransactionOptions {
            eDeposit = 1,
            eWithdraw = 2,
            eTotalBalances = 3,
            eTransfer = 4,
            eTransferLog = 5,
            eMainMenu = 6
        };
        // Perform transaction options
        static void _PerformTransactionOptions(enTransactionOptions Option);
        // Go To TransactionMenu
        static void _GoToTransactionMenu();
        // Deposit
        static void _DepositScreen();
        // Withdraw
        static void _WithdrawScreen();
        // Total Balances
        static void _TotalBalancesScreen();
        // transfer
        static void _TransferScreen();
        // transfer log
        static void _TransferLogScreen();

    public:
        // transaction menu
        static void TransactionMenu();
};

#endif // !CLSTRANSACTIONMENU_H
