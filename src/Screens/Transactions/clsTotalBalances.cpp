#include "../../../headers/Screens/Transactions/clsTotalBalances.h"
#include "../../../headers/Core/clsBankClient.h"
#include "../../../headers/Lib/clsUtil.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// print client record Balance
void clsTotalBalances::_PrintClientBalance(clsBankClient client) {
    short width = 18;
    cout << Colors::GetBlue() << setfill(' ') << left << setw(width + 4) << client.GetAccountNumber() << left << setw(width + 4) << client.GetFullName() << left << setw(width) << client.GetAccountBalance() << Colors::RESET() << endl;
}

// total balances
void clsTotalBalances::TotalBalancesScreen() {
    PrintHeaderScreen("TOTALBALANCES SCREEN", "💵", Colors::Cyan);
    cout << "\n\n";
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();
    float TotalBalances = clsBankClient::GetTotalBalances();
    short width = 18;
    PrintHeaderScreen("Clients", to_string(vClients.size()), Colors::BoldYellow, false, 54);
    cout << Colors::GetBoldYellow() << setfill(' ') << left << setw(width + 4) << "Account Number" << left << setw(width + 4) << "Client Name" << left << setw(width) << "Balance" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(54) << setfill('-') << "" << Colors::RESET() << endl;
    if (vClients.empty()) {
        cout << Colors::GetRed() << "                    No Clients Found" << Colors::RESET() << endl;
    } else {
        for (clsBankClient &C : vClients) {
            _PrintClientBalance(C);
        }
    }
    cout << Colors::GetYellow() << setw(54) << setfill('-') << "" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << " Total Balances : " << Colors::RESET() << Colors::GetMagenta() << TotalBalances << Colors::RESET() << endl;
    cout << Colors::GetYellow() << " ( " << clsUtil::NumberToText(TotalBalances) << ")" << Colors::RESET() << endl;
}
