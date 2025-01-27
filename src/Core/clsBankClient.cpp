#include "../../headers/Core/clsBankClient.h"
#include "../../headers/Lib/clsDate.h"
#include "../../headers/Lib/clsString.h"
#include <fstream>
#include <ios>
#include <numeric>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

// declare clients file
string ClientsFile = "data/Clients.txt";
// define TransferRegister file
string TransferRegFile = "data/TransferRegister.txt";

// constructor parameter
clsBankClient::clsBankClient(enMode mode, string firstname, string lastname, string email, string phone, string accountnumber, string pincode, float accountbalance)
    : clsPerson(firstname, lastname, email, phone) {
    _Mode = mode;
    _AccountNumber = accountnumber;
    _PinCode = pincode;
    _AccountBalance = accountbalance;
}

// Setter
void clsBankClient::SetPinCode(string pincode) {
    _PinCode = pincode;
}
void clsBankClient::SetAccountBalance(float accountbalance) {
    _AccountBalance = accountbalance;
}
// Getter
string clsBankClient::GetAccountNumber() {
    return _AccountNumber;
}
string clsBankClient::GetPinCode() {
    return _PinCode;
}
float clsBankClient::GetAccountBalance() {
    return _AccountBalance;
}
// check obj if is Empty
bool clsBankClient::isEmpty() {
    return (_Mode == EmptyMode);
}

// Convert line to client obj
clsBankClient clsBankClient::_CovertLineToClientObj(string line, string seperator) {
    vector<string> vClient = clsString::Split(line, seperator);
    return clsBankClient(UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));
}

// convert line to transfer register obj
clsBankClient::stTransferRegister clsBankClient::ConvertLineToTransferRegisterObj(string line) {
    vector<string> vStr = clsString::Split(line, "#-#");
    return stTransferRegister(vStr[0], vStr[1], vStr[2], stod(vStr[3]), vStr[4]);
};

// Convert client obj to line
string clsBankClient::_ConvertClientObjToLine(clsBankClient client, string seperator) {
    string line = "";
    line += client.GetFirstName() + seperator;
    line += client.GetLastName() + seperator;
    line += client.GetEmail() + seperator;
    line += client.GetPhone() + seperator;
    line += client.GetAccountNumber() + seperator;
    line += client.GetPinCode() + seperator;
    line += to_string(client.GetAccountBalance());
    return line;
}

// prepare transfer register line
string clsBankClient::_PrepareTransferRegister(clsUser User, string SourceClient, string DestinationClient, double Amount, string DateAndTime) {
    string TransferRegLine = "";
    TransferRegLine += User.GetUsername() + "#-#";
    TransferRegLine += SourceClient + "#-#";
    TransferRegLine += DestinationClient + "#-#";
    TransferRegLine += to_string(Amount) + "#-#";
    TransferRegLine += DateAndTime;
    return TransferRegLine;
}

// Get Empty client obj
clsBankClient clsBankClient::_GetEmptyClientObj() {
    return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
}

// get add new client obj
clsBankClient clsBankClient::_GetAddClientMode(string AccountNumber) {
    return clsBankClient(enMode::AddClientMode, "", "", "", "", AccountNumber, "", 0);
}

// Get addNewClient Mode
clsBankClient clsBankClient::GetAddClientMode(string AccountNumber) {
    return _GetAddClientMode(AccountNumber);
}

// is client exist
bool clsBankClient::isClientExist(string AccountNumber) {
    clsBankClient client = Find(AccountNumber);
    return !client.isEmpty();
}

// find client By Account Number (static)
clsBankClient clsBankClient::Find(string AccoutNumber) {
    fstream MyFile;
    MyFile.open(ClientsFile, ios::in);
    if (MyFile.is_open()) {
        string Line = "";
        while (getline(MyFile, Line)) {
            clsBankClient client = _CovertLineToClientObj(Line);
            if (client.GetAccountNumber() == AccoutNumber) {
                MyFile.close();
                return client;
            }
        }
        MyFile.close();
    }
    // if client not found then return impty client obj
    return _GetEmptyClientObj();
}
// find client By Account Number && PinCode (static)
clsBankClient clsBankClient::Find(string AccoutNumber, string PinCode) {
    fstream MyFile;
    MyFile.open(ClientsFile, ios::in);
    if (MyFile.is_open()) {
        string Line = "";
        while (getline(MyFile, Line)) {
            clsBankClient client = _CovertLineToClientObj(Line, "#-#");
            if (client.GetAccountNumber() == AccoutNumber && client.GetPinCode() == PinCode) {
                MyFile.close();
                return client;
            }
        }
        MyFile.close();
    }
    // if client not found then return impty client obj
    return _GetEmptyClientObj();
}

// load client date from file to vector
vector<clsBankClient> clsBankClient::_LoadClientsFromFile() {
    vector<clsBankClient> vClients;
    fstream MyFile;
    MyFile.open(ClientsFile, ios::in);
    if (MyFile.is_open()) {
        string line = "";
        while (getline(MyFile, line)) {
            clsBankClient client = _CovertLineToClientObj(line, "#-#");
            vClients.push_back(client);
        }
        MyFile.close();
    }
    return vClients;
}

// save vector in file
void clsBankClient::_SaveClientDataToFile(vector<clsBankClient> vClients) {
    fstream MyFile;
    MyFile.open(ClientsFile, ios::out);
    if (MyFile.is_open()) {
        string line = "";
        for (clsBankClient &C : vClients) {
            if (C._MarkDelete == false) {
                line = _ConvertClientObjToLine(C);
                MyFile << line << endl;
            }
        }
        MyFile.close();
    }
}

// Add client to file
void clsBankClient::_AddClientToFile() {
    string DataLine = _ConvertClientObjToLine(*this);
    fstream MyFile;
    MyFile.open(ClientsFile, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << DataLine << endl;
        MyFile.close();
    }
}

// func to put mark delete
bool clsBankClient::_PutMarkDelete(vector<clsBankClient> &vClients, clsBankClient client) {
    for (clsBankClient &C : vClients) {
        if (C._AccountNumber == client._AccountNumber) {
            C._MarkDelete = true;
            return true;
        }
    }
    return false;
}

// delete helper
void clsBankClient::Delete(clsBankClient &client) {
    // load client data from file
    vector<clsBankClient> vClients = _LoadClientsFromFile();
    // put mark for delete
    _PutMarkDelete(vClients, client);
    // save vector in file
    _SaveClientDataToFile(vClients);
    // Erase curr client obj
    client = _GetEmptyClientObj();
}

// Save changes in vector
void clsBankClient::_UpdateClient() {
    // Load clients data from file to vector
    vector<clsBankClient> vClients = _LoadClientsFromFile();
    // Update old client data with new one
    for (clsBankClient &C : vClients) {
        if (C.GetAccountNumber() == GetAccountNumber()) {
            C = *this;
            break;
        }
    }
    // Save updated vector in file
    _SaveClientDataToFile(vClients);
}

// Save update client
clsBankClient::svResult clsBankClient::save() {
    switch (_Mode) {
        case enMode::EmptyMode: {
            return enSaveFailed;
            break;
        }
        case enMode::UpdateMode: {
            _UpdateClient();
            return enSaveSucceed;
            break;
        }
        case enMode::AddClientMode: {
            if (isClientExist(_AccountNumber)) {
                return enFailedClientExist;
            } else {
                _AddClientToFile();
                _Mode = enMode::UpdateMode;
                return enSaveSucceed;
            }
            break;
        }
        default:
            break;
    }
}

// Get Total Balance
float clsBankClient::GetTotalBalances() {
    vector<clsBankClient> vClients = _LoadClientsFromFile();
    float TotalBalances = 0;
    for (clsBankClient &C : vClients) {
        TotalBalances += C.GetAccountBalance();
    }
    return TotalBalances;
}

// Get Clients list from file
vector<clsBankClient> clsBankClient::GetClientsList() {
    return _LoadClientsFromFile();
}

// perform deposit
void clsBankClient::Deposite(double Amount) {
    _AccountBalance += Amount;
    save();
}
// perform deposit
bool clsBankClient::Withdraw(double Amount) {
    if (Amount > _AccountBalance) {
        return false;
    } else {
        _AccountBalance -= Amount;
        save();
        return true;
    }
}

// transfer register
void clsBankClient::TransferRegister(clsUser User, string SourceClient, string DestinationClient, double Amount, string DateAndTime) {
    string TransferRegLine = _PrepareTransferRegister(User, SourceClient, DestinationClient, Amount, DateAndTime);
    fstream MyFile;
    MyFile.open(TransferRegFile, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << TransferRegLine << endl;
        MyFile.close();
    }
}

// transfer
bool clsBankClient::Transfer(clsBankClient &DestinationClient, double Amount) {
    if (Amount > _AccountBalance) {
        return false;
    }
    // Withdraw from the SourceClient
    Withdraw(Amount);
    // Deposite it to DestinationClient
    DestinationClient.Deposite(Amount);
    return true;
}

// get transfer register list from file
vector<clsBankClient::stTransferRegister> clsBankClient::GetTransferRegisterList() {
    vector<clsBankClient::stTransferRegister> vTransferReg;
    fstream MyFile;
    MyFile.open(TransferRegFile, ios::in);
    if (MyFile.is_open()) {
        string line = "";
        while (getline(MyFile, line)) {
            stTransferRegister TrReg = ConvertLineToTransferRegisterObj(line);
            vTransferReg.push_back(TrReg);
        }
        MyFile.close();
    }
    return vTransferReg;
}
