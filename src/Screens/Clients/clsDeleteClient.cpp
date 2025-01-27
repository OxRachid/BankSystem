#include "../../../headers/Screens/Clients/clsDeleteClient.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Core/clsBankClient.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Read Existing Account Number
string clsDeleteClient::_ReadExistAccountNumber() {
    string AccountNumber = clsInputValidate::ReadString(" ^ Enter AccountNumber :");
    // check is client exist
    while (!clsBankClient::isClientExist(AccountNumber)) {
        cout << Colors::GetYellow() << " No Client found..." << Colors::RESET() << endl;
        AccountNumber = clsInputValidate::ReadString(" ^ Please Enter a Valid AccountNumber : ");
    }
    return AccountNumber;
}

// Print client data
void clsDeleteClient::_PrintClientData(clsBankClient client) {
    PrintHeaderScreen("*Client Record*", "👤", Colors::Blue, false, 36);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " FirstName" << " : " << client.GetFirstName() << endl;
    cout << left << setw(20) << " LastName" << " : " << client.GetLastName() << endl;
    cout << left << setw(20) << " FullName" << " : " << client.GetFullName() << endl;
    cout << left << setw(20) << " Email" << " : " << client.GetEmail() << endl;
    cout << left << setw(20) << " Phone" << " : " << client.GetPhone() << endl;
    cout << left << setw(20) << " AccountNumber" << " : " << client.GetAccountNumber() << endl;
    cout << left << setw(20) << " Pincode" << " : " << client.GetPinCode() << endl;
    cout << left << setw(20) << " AccountBalance" << " : " << client.GetAccountBalance() << endl;
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl;
}

// Delete client
void clsDeleteClient::DeleteClientScreen() {
    // check access permissions
    if (!CheckPermissionRights(clsUser::enPermissionAccess::pDeleteClient)) {
        return;
    }

    PrintHeaderScreen("DELETE SCREEN", "-👤", Colors::Red);
    cout << "\n\n";
    // Read exist accountnumber
    string AccountNumber = _ReadExistAccountNumber();
    // get client data
    clsBankClient client = clsBankClient::Find(AccountNumber);
    // print client record
    _PrintClientData(client);
    // perform Delete
    if (clsInputValidate::AskUser("Delete this Client? ")) {
        clsBankClient::Delete(client);
        _PrintClientData(client);
        cout << Colors::GetGreen() << " ⟩ The Client Deleted Succusfully ✓" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetMagenta() << " ⟩ Delete Canceled ✓" << Colors::RESET() << endl;
    }
}
