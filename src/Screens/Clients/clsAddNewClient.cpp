#include "../../../headers/Screens/Clients/clsAddNewClient.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Core/clsBankClient.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print client data
void clsAddNewClient::_PrintClientData(clsBankClient client) {
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

// Read client data
void clsAddNewClient::_ReadClientData(clsBankClient &client) {
    client.SetFirstName(clsInputValidate::ReadString(" ^ Enter FirstName : "));
    client.SetLastName(clsInputValidate::ReadString(" ^ Enter LastName : "));
    client.SetEmail(clsInputValidate::ReadString(" ^ Enter Email : "));
    client.SetPhone(clsInputValidate::ReadString(" ^ Enter Phone : "));
    client.SetPinCode(clsInputValidate::ReadString(" ^ Enter PinCode : "));
    client.SetAccountBalance(clsInputValidate::ReadNumber<float>(" ^ Enter AccountBalance : "));
}

// Add new client
void clsAddNewClient::AddNewClientScreen() {
    // check access permissions
    if (!CheckPermissionRights(clsUser::enPermissionAccess::pAddNewClient)) {
        return;
    }

    PrintHeaderScreen("ADDNEWCLIENT SCREEN", "+👤", Colors::Cyan);
    cout << "\n\n";
    string AccountNumber = clsInputValidate::ReadString("\n ^ Enter AccountNumber : ");
    while (clsBankClient::isClientExist(AccountNumber)) {
        cout << Colors::GetYellow() << " ⊕ This Client is already exist..." << Colors::RESET() << endl;
        AccountNumber = clsInputValidate::ReadString(" ^ Enter AccountNumber : ");
    }
    // get add new client obj
    clsBankClient client = clsBankClient::GetAddClientMode(AccountNumber);
    // Read client data
    _ReadClientData(client);
    // save client data in file
    clsBankClient::svResult Result = client.save();
    switch (Result) {
        case clsBankClient::svResult::enSaveSucceed: {
            _PrintClientData(client);
            cout << Colors::GetGreen() << " ⟩ The Client Added Succusfully ✓" << Colors::RESET() << endl;
            break;
        }
        case clsBankClient::svResult::enSaveFailed: {
            cout << Colors::GetMagenta() << " ⟩ Failed, The object is Empty." << Colors::RESET() << endl;
            break;
        }
        case clsBankClient::svResult::enFailedClientExist: {
            cout << Colors::GetMagenta() << " ⟩ Failed, The client is already exist." << Colors::RESET() << endl;
            break;
        }
    }
}
