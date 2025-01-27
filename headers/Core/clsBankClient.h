#ifndef CLSBANKCLIENT_H
#define CLSBANKCLIENT_H
#include "../Lib/clsPerson.h"
#include "clsUser.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsBankClient : public clsPerson {
    private:
        enum enMode {
            EmptyMode = 0,
            UpdateMode = 1,
            AddClientMode = 2
        };
        enMode _Mode;
        string _AccountNumber;
        string _PinCode;
        float _AccountBalance;
        bool _MarkDelete = false;
        // Convert line to client obj
        static clsBankClient _CovertLineToClientObj(string line, string seperator = "#-#");
        // Convert client obj to line
        static string _ConvertClientObjToLine(clsBankClient client, string seperator = "#-#");
        // Get Empty client obj
        static clsBankClient _GetEmptyClientObj();
        // get add new client obj
        static clsBankClient _GetAddClientMode(string AccountNumber);
        // Save changes in vector
        void _UpdateClient();
        // load client date from file to vector
        static vector<clsBankClient> _LoadClientsFromFile();
        // save vector in file
        static void _SaveClientDataToFile(vector<clsBankClient> vClients);
        // Add client to file
        void _AddClientToFile();
        // func to put mark delete
        static bool _PutMarkDelete(vector<clsBankClient> &vClients, clsBankClient client);
        // prepare transfer register line
        static string _PrepareTransferRegister(clsUser User, string Sender, string Reciever, double Amount, string DateAndTime);

    public:
        // constructor parameter
        clsBankClient(enMode mode, string firstname, string lastname, string email, string phone, string accountnumber, string pincode, float accountbalance);
        // struct for transfer register
        struct stTransferRegister {
                string Username = "";
                string SourceClient = "";
                string DestinationClient = "";
                double Amount = 0;
                string DateAndTime = "";
                // constructor
                stTransferRegister(string username, string source, string destination, double amount, string dateAndtime)
                    : Username(username),
                      SourceClient(source),
                      DestinationClient(destination),
                      Amount(amount),
                      DateAndTime(dateAndtime) {}
        };
        // Setter
        void SetPinCode(string pincode);
        void SetAccountBalance(float accountbalance);
        // Getter
        string GetAccountNumber();
        string GetPinCode();
        float GetAccountBalance();
        // check obj if is Empty
        bool isEmpty();
        // is client exist
        static bool isClientExist(string AccountNumber);
        // find client By Account Number (static)
        static clsBankClient Find(string AccoutNumber);
        // find client By Account Number && PinCode (static)
        static clsBankClient Find(string AccoutNumber, string PinCode);
        // define enum for handl save Update
        enum svResult {
            enSaveFailed = 0,
            enSaveSucceed = 1,
            enFailedClientExist = 2
        };
        // Save update client
        svResult save();
        // Get Total Balance
        static float GetTotalBalances();
        // Get Clients list from file
        static vector<clsBankClient> GetClientsList();
        // Get addNewClient Mode
        static clsBankClient GetAddClientMode(string AccountNumber);
        // delete client (static)
        static void Delete(clsBankClient &client);
        // perform deposit
        void Deposite(double Amount);
        // perform withdraw
        bool Withdraw(double Amount);
        // transfer
        bool Transfer(clsBankClient &DestinationClient, double Amount);
        // transfer register
        static void TransferRegister(clsUser User, string SourceClient, string DestinationClient, double Amount, string DateAndTime);
        // convert line to transfer register obj
        static stTransferRegister ConvertLineToTransferRegisterObj(string line);
        // get transfer register list from file
        static vector<stTransferRegister> GetTransferRegisterList();
};

#endif // ! CLSBANKCLIENT_H
