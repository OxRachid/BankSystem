#include "../../headers/Core/clsUser.h"
#include "../../headers/Lib/clsDate.h"
#include "../../headers/Lib/clsString.h"
#include "../../headers/Lib/clsUtil.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// declare users file
string UsersFile = "data/Users.txt";
// Define LogFile
string LogFile = "data/LogFile.txt";

// constructor parameter
clsUser::clsUser(enMode mode, string firstname, string lastname, string email, string phone, string username, string password, short permission)
    : clsPerson(firstname, lastname, email, phone),
      _Mode(mode),
      _Username(username),
      _Password(password),
      _Permission(permission) {}

// setter
void clsUser::SetUsername(string username) {
    _Username = username;
}
void clsUser::SetPassword(string password) {
    _Password = password;
}
void clsUser::SetPermission(short permission) {
    _Permission = permission;
}
// getter
string clsUser::GetUsername() {
    return _Username;
}
string clsUser::GetPassword() {
    return _Password;
}
short clsUser::GetPermission() {
    return _Permission;
}

// get empty user obj
clsUser clsUser::_GetEmptyUserObj() {
    return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
}

// Get addNewUser Mode
clsUser clsUser::GetAddUserMode(string username) {
    return clsUser(enMode::AddUserMode, "", "", "", "", username, "", 0);
}

// convert line to user obj
clsUser clsUser::_ConvertLineToUserObj(string Userline) {
    vector<string> vUser = clsString::Split(Userline, "#-#");
    return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], clsUtil::DecryptText(vUser[5]), stoi(vUser[6]));
}

// Convert line to stLoginRegister obj
clsUser::stLoginRegister clsUser::ConvertLineToLogRegisterObj(string line) {
    vector<string> vStr = clsString::Split(line, "#-#");
    return stLoginRegister(vStr[0], clsUtil::DecryptText(vStr[1]), stoi(vStr[2]), vStr[3]);
}

// Convert user obj to line
string clsUser::_ConvertUserObjToLine(clsUser user, string seperator) {
    string Userline = "";
    Userline += user.GetFirstName() + seperator;
    Userline += user.GetLastName() + seperator;
    Userline += user.GetEmail() + seperator;
    Userline += user.GetPhone() + seperator;
    Userline += user._Username + seperator;
    Userline += clsUtil::EncryptText(user._Password) + seperator;
    Userline += to_string(user._Permission);
    return Userline;
}

// get user log info in string
string clsUser::_PrepareLogInRecord(string seperator) {
    string strLogInfo = "";
    strLogInfo += _Username + seperator;
    strLogInfo += clsUtil::EncryptText(_Password) + seperator;
    strLogInfo += to_string(_Permission) + seperator;
    strLogInfo += clsDate::GetDateAndTime();
    return strLogInfo;
}

// load users data from file
vector<clsUser> clsUser::_LoadUsersDataFromFile() {
    vector<clsUser> vUsers;
    fstream MyFile;
    MyFile.open(UsersFile, ios::in);
    if (MyFile.is_open()) {
        string Userline = "";
        while (getline(MyFile, Userline)) {
            clsUser user = _ConvertLineToUserObj(Userline);
            vUsers.push_back(user);
        }
        MyFile.close();
    }

    return vUsers;
}

// Get Login Register list from file
vector<clsUser::stLoginRegister> clsUser::GetLoginRegisterList() {
    vector<clsUser::stLoginRegister> vLoginRegisters;
    fstream MyFile;
    MyFile.open(LogFile, ios::in);
    if (MyFile.is_open()) {
        string line = "";
        while (getline(MyFile, line)) {
            stLoginRegister LoginReg = ConvertLineToLogRegisterObj(line);
            vLoginRegisters.push_back(LoginReg);
        }
        MyFile.close();
    }
    return vLoginRegisters;
}

// Save users data in file
void clsUser::_SaveUsersDataInFile(vector<clsUser> vUsers) {
    fstream MyFile;
    MyFile.open(UsersFile, ios::out);
    if (MyFile.is_open()) {
        string UserLine = "";
        for (clsUser &user : vUsers) {
            if (user._MarckDelete == false) {
                UserLine = _ConvertUserObjToLine(user, "#-#");
                MyFile << UserLine << endl;
            }
        }
        MyFile.close();
    }
}

// add one user to file
void clsUser::_AddUserToFile() {
    fstream MyFile;
    MyFile.open(UsersFile, ios::out | ios::app);
    if (MyFile.is_open()) {
        string UserLine = _ConvertUserObjToLine(*this, "#-#");
        MyFile << UserLine << endl;
    }
    MyFile.close();
}

// save user login in log file
void clsUser::RegisterLogIn() {
    fstream MyFile;
    MyFile.open(LogFile, ios::out | ios::app);
    if (MyFile.is_open()) {
        string LogLine = _PrepareLogInRecord();
        MyFile << LogLine << endl;
    }
    MyFile.close();
}

// is empty
bool clsUser::isEmpty() {
    return (_Mode == enMode::EmptyMode);
}

// is user exist
bool clsUser::isUserExist(string username) {
    clsUser user = Find(username);
    return (!user.isEmpty());
}

// Save changes in vector
void clsUser::_UpdateUser() {
    // Load users data from file to vector
    vector<clsUser> vUsers = _LoadUsersDataFromFile();
    // Update old user data with new one
    for (clsUser &U : vUsers) {
        if (U._Username == _Username) {
            U = *this;
            break;
        }
    }
    // Save updated vector in file
    _SaveUsersDataInFile(vUsers);
}

// func to put mark delete
bool clsUser::_PutMarkDelete(vector<clsUser> &vUsers, clsUser user) {
    for (clsUser &U : vUsers) {
        if (U._Username == user._Username) {
            U._MarckDelete = true;
            return true;
        }
    }
    return false;
}

// delete user (static)
void clsUser::Delete(clsUser &user) {
    // load users data from file
    vector<clsUser> vUsers = _LoadUsersDataFromFile();
    // put mark for delete
    _PutMarkDelete(vUsers, user);
    // save vector in file
    _SaveUsersDataInFile(vUsers);
    // Erase curr client obj
    user = _GetEmptyUserObj();
}

// Find User by _Username
clsUser clsUser::Find(string username) {
    fstream MyFile;
    MyFile.open(UsersFile, ios::in);
    if (MyFile.is_open()) {
        string UserLine = "";
        while (getline(MyFile, UserLine)) {
            clsUser user = _ConvertLineToUserObj(UserLine);
            if (user._Username == username) {
                MyFile.close();
                return user;
            }
        }
        MyFile.close();
    }
    // if user not found then return empty obj
    return _GetEmptyUserObj();
}
// Find User by _Username and password
clsUser clsUser::Find(string username, string password) {
    fstream MyFile;
    MyFile.open(UsersFile, ios::in);
    if (MyFile.is_open()) {
        string UserLine = "";
        while (getline(MyFile, UserLine)) {
            clsUser user = _ConvertLineToUserObj(UserLine);
            if (user._Username == username && user._Password == password) {
                MyFile.close();
                return user;
            }
        }
        MyFile.close();
    }
    // if user not found then return empty obj
    return _GetEmptyUserObj();
}

// Save update user
clsUser::svResult clsUser::save() {
    switch (_Mode) {
        case enMode::EmptyMode: {
            return enSaveFailed;
            break;
        }
        case enMode::UpdateMode: {
            _UpdateUser();
            return enSaveSucceed;
            break;
        }
        case enMode::AddUserMode: {
            if (isUserExist(_Username)) {
                return enFailedUserExist;
            } else {
                _AddUserToFile();
                _Mode = enMode::UpdateMode;
                return enSaveSucceed;
            }
            break;
        }
        default:
            break;
    }
}

// Get Users list from file
vector<clsUser> clsUser::GetUsersList() {
    return _LoadUsersDataFromFile();
}

// check access permission
bool clsUser::CheckAccessPermissions(enPermissionAccess FuncPermission) {
    return (this->_Permission == enPermissionAccess::pAll) ? true : (FuncPermission & this->_Permission) == FuncPermission ? true : false;
}
