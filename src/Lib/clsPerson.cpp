#include "../../headers/Lib/clsPerson.h"
#include <iostream>
#include <string>
using namespace std;

// constructor parameter
clsPerson::clsPerson(string firstname, string lastname, string email, string phone) {
    _FirstName = firstname;
    _LastName = lastname;
    _Email = email;
    _Phone = phone;
}

// Setter
void clsPerson::SetFirstName(string firstname) {
    _FirstName = firstname;
}
// Getter
string clsPerson::GetFirstName() {
    return _FirstName;
}
// Setter
void clsPerson::SetLastName(string lastname) {
    _LastName = lastname;
}
// Getter
string clsPerson::GetLastName() {
    return _LastName;
}
// Setter
void clsPerson::SetEmail(string email) {
    _Email = email;
}
// Getter
string clsPerson::GetEmail() {
    return _Email;
}
// Setter
void clsPerson::SetPhone(string phone) {
    _Phone = phone;
}
// Getter
string clsPerson::GetPhone() {
    return _Phone;
}
// Getter
string clsPerson::GetFullName() {
    return _FirstName + " " + _LastName;
}
