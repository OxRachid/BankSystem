#include "../../../headers/Screens/Clients/clsFindClient.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Core/clsBankClient.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print client data
void clsFindClient::_PrintClientData(clsBankClient client) {
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
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl;
}

// Read Existing Account Number
string clsFindClient::_ReadExistAccountNumber() {
    string AccountNumber = clsInputValidate::ReadString(" ^ Enter AccountNumber : ");
    // check is client exist
    while (!clsBankClient::isClientExist(AccountNumber)) {
        cout << Colors::GetYellow() << " No Client found..." << Colors::RESET() << endl;
        AccountNumber = clsInputValidate::ReadString(" ^ Please Enter a Valid AccountNumber : ");
    }
    return AccountNumber;
}

// find Find Client
void clsFindClient::FindClient() {
    // check access permissions
    if (!CheckPermissionRights(clsUser::enPermissionAccess::pFindClient)) {
        return;
    }

    PrintHeaderScreen("FIND CLIENT SCREEN", "🔍", Colors::Cyan);
    cout << "\n\n";
    // Read exist accountnumber
    string AccountNumber = _ReadExistAccountNumber();
    // Get client obj
    clsBankClient client = clsBankClient::Find(AccountNumber);
    if (client.isEmpty()) {
        cout << Colors::GetRed() << "\n [ The Client Not Found ]" << endl;
    } else {
        cout << Colors::GetGreen() << "\n [ The Client Founded ]" << endl;
        // print client obj
        _PrintClientData(client);
    }
}
