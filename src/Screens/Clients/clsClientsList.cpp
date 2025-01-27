#include "../../../headers/Screens/Clients/clsClientsList.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Core/clsBankClient.h"
#include "../../../headers/Core/clsUser.h"
#include "iostream"
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Print client data in one line
void clsClientsList::_PrintClientDataInOneLine(clsBankClient client) {
    short width = 12;
    cout << Colors::GetBlue() << setfill(' ') << left << setw(width - 4) << client.GetAccountNumber() << left << setw(width + 3) << client.GetFullName() << left << setw(width + 3) << client.GetEmail() << left << setw(width) << client.GetPhone() << left << setw(width - 6) << client.GetPinCode() << left << setw(width - 2) << client.GetAccountBalance() << Colors::RESET() << endl;
}

// Show clients list
void clsClientsList::ClientsList() {
    // check access permissions
    if (!CheckPermissionRights(clsUser::enPermissionAccess::pClientsList)) {
        return;
    }

    PrintHeaderScreen("CLIENTS LIST SCREEN", "🧾", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();

    vector<clsBankClient> vClients = clsBankClient::GetClientsList();
    PrintHeaderScreen("Clients", to_string(vClients.size()), Colors::BoldYellow, false);
    short width = 12;
    cout << Colors::GetBoldYellow() << setfill(' ') << left << setw(width - 5) << "A-Num" << left << setw(width + 3) << " C-Name" << left << setw(width + 3) << " Email" << left << setw(width) << " Phone" << left << setw(width - 6) << " Pin" << left << setw(width - 2) << " A-B" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vClients.empty()) {
        cout << Colors::GetRed() << "               No Clients Found" << Colors::RESET() << endl;
    } else {
        for (clsBankClient &C : vClients) {
            _PrintClientDataInOneLine(C);
        }
    }
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
