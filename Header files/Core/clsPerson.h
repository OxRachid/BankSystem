#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson{
private :

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public :

	// Constructor for initialize  member varaibles
	clsPerson()
	{
		_FirstName="";
		_LastName="";
		_Email="";
		_Phone="";
	}
	
	// Constructor parameterize for asigning values
	clsPerson ( string Firstname, string Lastname, string Email, string Phone) : _FirstName(Firstname), _LastName(Lastname), _Email(Email), _Phone(Phone){}                                           
	
	// Set FirstName
	void SetFirstName(string Firstname)
	{
		_FirstName=Firstname;
	}
	// Get FirstName
	string GetFirstName()
	{
		return _FirstName;
	}
	
	// Set LastName
	void SetLastName(string Lastname)
	{
		_LastName=Lastname;
	}
	// Get LastName
	string GetLastName()
	{
		return _LastName;
	}
	
	// Get fullname
	 string GetFullName()
	 {
	 	return _FirstName+" "+_LastName;
	 }
	
	
	// Set Email
	void SetEmail(string Email)
	{
		_Email=Email;
	}
	// Get Email
	string GetEmail()
	{
		return _Email;
	}
	
	// Set Phone
	void SetPhone(string Phone)
	{
		_Phone=Phone;
	}
	// Get Phone
	string GetPhone()
	{
		return _Phone;
	}
	
};