#ifndef CLSPERSON_H
#define CLSPERSON_H

#include <iostream>
#include <string>
using namespace std;

class clsPerson {
    private:
        string _FirstName;
        string _LastName;
        string _Email;
        string _Phone;

    public:
        // constructor parameter
        clsPerson(string firstname, string lastname, string email, string phone);
        // Setter
        void SetFirstName(string firstname);
        // Getter
        string GetFirstName();
        // Setter
        void SetLastName(string lastname);
        // Getter
        string GetLastName();
        // Setter
        void SetEmail(string email);
        // Getter
        string GetEmail();
        // Setter
        void SetPhone(string phone);
        // Getter
        string GetPhone();
        // Getter
        string GetFullName();
};

#endif // !CLSPERSON_H
