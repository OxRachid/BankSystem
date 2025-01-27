#include "../../../headers/Screens/Transactions/clsTransfer.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Core/clsBankClient.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsDate.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print client data
void clsTransfer::_PrintClientData(clsBankClient client) {
    cout << endl;
    PrintHeaderScreen("*Client Record*", "👤", Colors::Blue, false, 36);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " FullName" << " : " << client.GetFullName() << endl;
    cout << left << setw(20) << " AccountNumber" << " : " << client.GetAccountNumber() << endl;
    cout << left << setw(20) << " Pincode" << " : " << client.GetPinCode() << endl;
    cout << left << setw(20) << " AccountBalance" << " : " << client.GetAccountBalance() << endl;
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl << endl;
}
// Read Existing Account Number
string clsTransfer::_ReadAccountNumber(string FromOrTo) {
    string AccountNumber = clsInputValidate::ReadString(" ^ Transfer Amount " + FromOrTo + " : ");
    // check is client exist
    while (!clsBankClient::isClientExist(AccountNumber)) {
        cout << Colors::GetYellow() << " No Client found..." << Colors::RESET() << endl;
        AccountNumber = clsInputValidate::ReadString(" ^ Please Enter a Valid AccountNumber : ");
    }
    return AccountNumber;
}

// check amount if is valid
double clsTransfer::_ReadAmount(clsBankClient SourceClient) {
    double Amount = clsInputValidate::ReadPositiveNumber<double>(" ⊙ Amount : ");
    while (Amount > SourceClient.GetAccountBalance()) {
        cout << Colors::GetRed() << " [ invalid Amount, You can only Transfer Up to " << SourceClient.GetAccountBalance() << " ]" << Colors::RESET() << endl;
        Amount = clsInputValidate::ReadPositiveNumber<double>(" ⊙ Enter a valid Amount : ");
    }
    return Amount;
}

// transfer screen
void clsTransfer::TransferScreen() {

    PrintHeaderScreen("TRANSFER SCREEN", "💸", Colors::Cyan);
    cout << "\n\n";

    // Search and get client record
    clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("From"));
    // Print  source client Record
    _PrintClientData(SourceClient);

    // if AccountBalance of the source is 0 then exit the func
    if (SourceClient.GetAccountBalance() == 0) {
        cout << Colors::GetRed() << " [ There are insufficient funds on the Sender Client ]" << Colors::RESET() << endl;
        return;
    }

    clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
    // Print client Record
    _PrintClientData(DestinationClient);

    // Read and check Amount
    double Amount = _ReadAmount(SourceClient);

    if (clsInputValidate::AskUser("\n ⊖ Are u sure wanna Transfer " + to_string(Amount))) {
        // Withdraw Amount from the sender
        if (SourceClient.Transfer(DestinationClient, Amount)) {
            cout << Colors::GetGreen() << "\n ⟩ Transfer Done Succusfully ✓ " << Colors::RESET() << endl;
            // Print the SourceClient update record
            _PrintClientData(SourceClient);
            // print the DestinationClient update record
            _PrintClientData(DestinationClient);
            // Transfer Register
            clsBankClient::TransferRegister(CurrUser, SourceClient.GetAccountNumber(), DestinationClient.GetAccountNumber(), Amount, clsDate::GetDateAndTime());
        } else {
            cout << Colors::GetRed() << " [ Transfer Failed ]" << Colors::RESET() << endl;
        }
    } else {
        cout << Colors::GetRed() << " [ Transfer Canceled ]" << Colors::RESET() << endl;
    }
}
