#include "../../../headers/Screens/Clients/clsUpdateClient.h"
#include "../../../headers/Core/Globals.h"
#include "../../../headers/Core/clsBankClient.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Read Existing Account Number
string clsUpdateClient::_ReadExistAccountNumber() {
    string AccountNumber = clsInputValidate::ReadString(" ^ Enter AccountNumber : ");
    // check is client exist
    while (!clsBankClient::isClientExist(AccountNumber)) {
        cout << Colors::GetYellow() << " No Client found..." << Colors::RESET() << endl;
        AccountNumber = clsInputValidate::ReadString(" ^ Please Enter a Valid AccountNumber : ");
    }
    return AccountNumber;
}

// Print client data
void clsUpdateClient::_PrintClientData(clsBankClient client) {
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

// Read update client data
void clsUpdateClient::_ReadClientData(clsBankClient &client) {
    PrintHeaderScreen("Update Client Data", "⇌", Colors::Magenta, false, 36);
    client.SetFirstName(clsInputValidate::ReadString(" ^ Enter New FirstName : "));
    client.SetLastName(clsInputValidate::ReadString(" ^ Enter New LastName : "));
    client.SetEmail(clsInputValidate::ReadString(" ^ Enter New Email : "));
    client.SetPhone(clsInputValidate::ReadString(" ^ Enter New Phone : "));
    client.SetPinCode(clsInputValidate::ReadString(" ^ Enter New PinCode : "));
    client.SetAccountBalance(clsInputValidate::ReadNumber<float>(" ^ Enter New AccountBalance : "));
}

// Update client
void clsUpdateClient::UpdateClientScreen() {
    // check access permissions
    if (!CheckPermissionRights(clsUser::enPermissionAccess::pUpdateClient)) {
        return;
    }

    PrintHeaderScreen("UPDATE CLIENT SCREEN", "⚙️", Colors::Cyan);
    cout << "\n\n";
    // Read exist accountnumber
    string AccountNumber = _ReadExistAccountNumber();
    // Get client obj
    clsBankClient client = clsBankClient::Find(AccountNumber);
    // print client obj
    _PrintClientData(client);
    if (clsInputValidate::AskUser("\n ^ Are u sure wanna Update <" + AccountNumber + ">")) {
        _ReadClientData(client);
        clsBankClient::svResult Result = client.save();
        switch (Result) {
            case clsBankClient::svResult::enSaveSucceed: {
                _PrintClientData(client);
                cout << Colors::GetGreen() << " ⟩ Updated Succusfully ✓" << Colors::RESET() << endl;
                break;
            }
            case clsBankClient::svResult::enSaveFailed: {
                cout << Colors::GetMagenta() << " ⟩ Failed, The object is Empty" << Colors::RESET() << endl;
                break;
            }
            case clsBankClient::svResult::enFailedClientExist: {
                cout << Colors::GetMagenta() << " ⟩ Failed, The client is already exist." << Colors::RESET() << endl;
                break;
            }
        }
    } else {
        cout << Colors::GetMagenta() << " ⟩ Update Canceled ✓" << Colors::RESET() << endl;
    }
}
