#include "../../../headers/Screens/Transactions/clsWithdraw.h"
#include "../../../headers/Core/clsBankClient.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Read Existing Account Number
string clsWithdraw::_ReadExistAccountNumber() {
    string AccountNumber = clsInputValidate::ReadString(" ^ Enter AccountNumber : ");
    // check is client exist
    while (!clsBankClient::isClientExist(AccountNumber)) {
        cout << Colors::GetYellow() << " No Client found..." << Colors::RESET() << endl;
        AccountNumber = clsInputValidate::ReadString(" ^ Please Enter a Valid AccountNumber : ");
    }
    return AccountNumber;
}

// Print client data
void clsWithdraw::_PrintClientData(clsBankClient client) {
    cout << endl;
    PrintHeaderScreen("*Client Record*", "👤", Colors::Blue, false, 36);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " FirstName" << " : " << client.GetFirstName() << endl;
    cout << left << setw(20) << " LastName" << " : " << client.GetLastName() << endl;
    cout << left << setw(20) << " FullName" << " : " << client.GetFullName() << endl;
    cout << left << setw(20) << " Email" << " : " << client.GetEmail() << endl;
    cout << left << setw(20) << " Phone" << " : " << client.GetPhone() << endl;
    cout << left << setw(20) << " AccountNumber" << " : " << client.GetAccountNumber() << endl;
    cout << left << setw(20) << " Pincode" << " : " << client.GetPinCode() << endl;
    cout << left << setw(20) << " AccountBalance" << " : " << client.GetAccountBalance() << endl;
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl << endl;
}

// WithdrawScreen
void clsWithdraw::WithdrawScreen() {
    PrintHeaderScreen("WITHDRAW SCREEN", "-💰", Colors::Cyan);
    cout << "\n\n";
    string AccNumber = _ReadExistAccountNumber();
    clsBankClient client = clsBankClient::Find(AccNumber);
    _PrintClientData(client);
    // if AccountBalance of the client is 0 then exit the func
    if (client.GetAccountBalance() == 0) {
        cout << Colors::GetRed() << " [ There are insufficient funds on the Client Account ]" << Colors::RESET() << endl;
        return;
    }

    double Amount = clsInputValidate::ReadPositiveNumber<double>(" ^ Enter Amount : ");
    if (clsInputValidate::AskUser(" \n ⊕ Are you sure You wanna Withdraw " + to_string(Amount))) {
        // Perform Withdraw
        if (client.Withdraw(Amount)) {
            cout << Colors::GetGreen() << " ⟩ Withdraw Succeed ✓ \n ⟩ New Balance is : " << Colors::RESET() << Colors::GetYellow() << client.GetAccountBalance() << Colors::RESET() << endl;
        } else {
            cout << Colors::GetRed() << " \n [ Amount Exeeds the Balance, Your Balance is just {" << client.GetAccountBalance() << "} ]" << Colors::RESET() << endl;
        }
    } else {
        cout << Colors::GetRed() << " ⊗ Withdraw Canceled." << Colors::RESET() << endl;
    }
}
