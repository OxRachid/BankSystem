#include "../../../headers/Screens/Transactions/clsTransferRegister.h"
#include <iomanip>
using namespace std;

// print TransferRegister line
void clsTransferRegister::_PrintTransferRegisterLine(clsBankClient::stTransferRegister TrReg) {
    short width = 10;
    cout << Colors::GetBoldBlue() << setfill(' ') << left << setw(width) << TrReg.Username << left << setw(width) << TrReg.SourceClient << left << setw(width) << TrReg.DestinationClient << left << setw(width) << TrReg.Amount << left << setw(width) << TrReg.DateAndTime << Colors::RESET() << endl;
}

// Transfer Register screen
void clsTransferRegister::TransferRegisterScreen() {
    PrintHeaderScreen("TRANSFERREGISTER SCREEN", "📝", Colors::Cyan);
    cout << "\n\n";

    vector<clsBankClient::stTransferRegister> vTransferReg = clsBankClient::GetTransferRegisterList();
    short width = 10;
    PrintHeaderScreen("Transfer Register", to_string(vTransferReg.size()), Colors::BoldYellow, false);
    cout << Colors::GetBoldYellow() << setfill(' ') << left << setw(width) << "User" << left << setw(width) << "Source" << left << setw(width) << "Destin" << left << setw(width) << "Amount" << left << setw(width) << "Date & Time" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vTransferReg.empty()) {
        cout << Colors::GetRed() << "              No Transfer Register Found" << Colors::RESET() << endl;
    } else {
        for (clsBankClient::stTransferRegister &T : vTransferReg) {
            _PrintTransferRegisterLine(T);
        }
    }
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
