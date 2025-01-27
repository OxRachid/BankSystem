#ifndef CLSUSER_H
#define CLSUSER_H

#include "../../headers/Lib/clsPerson.h"
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class clsUser : public clsPerson {
    private:
        enum enMode {
            EmptyMode = 0,
            UpdateMode = 1,
            AddUserMode = 2
        };
        enMode _Mode;
        string _Username = "";
        string _Password = "";
        short _Permission = 0;
        bool _MarckDelete = false;
        // get empty user obj
        static clsUser _GetEmptyUserObj();
        // convert line to user obj
        static clsUser _ConvertLineToUserObj(string Userline);
        // Convert user obj to line
        static string _ConvertUserObjToLine(clsUser user, string seperator);
        // load users data from file
        static vector<clsUser> _LoadUsersDataFromFile();
        // Save users data in file
        static void _SaveUsersDataInFile(vector<clsUser> vUsers);
        // Add one user to file
        void _AddUserToFile();
        // Save changes in vector
        void _UpdateUser();
        // func to put mark delete
        static bool _PutMarkDelete(vector<clsUser> &Users, clsUser user);
        // get user log info in string
        string _PrepareLogInRecord(string seperator = "#-#");

    public:
        // constructor parameter
        clsUser(enMode mode, string firstname, string lastname, string email, string phone, string username, string password, short permission);
        // Define struct for user LogIn info
        struct stLoginRegister {
                string Username = "";
                string Password = "";
                short Permission = 0;
                string DateAndTime = "";
                // constructor
                stLoginRegister(string username, string password, short permissions, string dateAndtime)
                    : Username(username),
                      Password(password),
                      Permission(permissions),
                      DateAndTime(dateAndtime) {}
        };
        // enum for permissions options
        enum enPermissionAccess {
            pAll = -1,
            pClientsList = 1,
            pAddNewClient = 2,
            pDeleteClient = 4,
            pUpdateClient = 8,
            pFindClient = 16,
            pTransaction = 32,
            pManageUsers = 64,
            pLoginRegister = 128,
        };

        // setter
        void SetUsername(string username);
        void SetPassword(string password);
        void SetPermission(short permission);
        // getter
        string GetUsername();
        string GetPassword();
        short GetPermission();
        // Get Users list from file
        static vector<clsUser> GetUsersList();
        // Find User by _Username
        static clsUser Find(string username);
        // Find User by _Username and password
        static clsUser Find(string username, string password);
        // is empty
        bool isEmpty();
        // is user exist
        static bool isUserExist(string username);
        // define enum for handl save Update
        enum svResult {
            enSaveFailed = 0,
            enSaveSucceed = 1,
            enFailedUserExist = 2
        };
        // Save update user
        svResult save();
        // delete user (static)
        static void Delete(clsUser &user);
        // Get addNewUser Mode
        static clsUser GetAddUserMode(string username);
        // check access permission
        bool CheckAccessPermissions(enPermissionAccess FuncPermission);
        // save user login in log file
        void RegisterLogIn();
        // Convert line to stLoginRegister obj
        static stLoginRegister ConvertLineToLogRegisterObj(string line);
        // Get User Login Register from file
        static vector<stLoginRegister> GetLoginRegisterList();
};

#endif // !CLSUSER_H
