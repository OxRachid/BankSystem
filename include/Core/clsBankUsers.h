#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../Lib/clsString.h"
#include "../Lib/clsEnputValidate.h"
#include "../Lib/clsUtil.h"
#include "clsPerson.h"
using namespace std;

// Define the name of file where we will store data
const string UsersFile = "../Files/UsersFile.txt";
// Define the name of file where 1 will store logins data
const string RegisterLogInFile = "../Files/RegisterLogInFile.txt";

class clsBankUsers : public clsPerson  {

private :
	
	// Define enum of client mode
	enum eMode { e_EmptyMode=0, e_UpdateMode=1, e_AddNewUser=2};	
	
	eMode _Mode;
	string _Username;
	string _Password;
	int _Permission;
	bool _UserMarkDeletion=false;
	
	
	// Convert Line To User Object
	static clsBankUsers _ConvertLineToUserObject(string Line)
	{
		// Split line into vector of string
		vector<string> VUser = clsString::SplitString(Line,"#");
		// return constructor of  object 
		return clsBankUsers(e_UpdateMode, VUser[0], VUser[1], VUser[2], VUser[3], VUser[4], clsUtil::DecryptionText(VUser[5]), stoi(VUser[6]));
	}
	
	
	// Convert  User Object to line
	static string  _ConvertUserObjectToLine(clsBankUsers user)
	{
		string UserLine;

		UserLine+=user.GetFirstName()+"#";
		UserLine+=user.GetLastName()+"#";
		UserLine+=user.GetEmail()+"#";
		UserLine+=user.GetPhone()+"#";
		UserLine+=user.GetUsername()+"#";
		UserLine+=clsUtil::EncryptionText(user.GetPassword())+"#";
		UserLine+=to_string(user.GetPermission());
		
		return UserLine;
	}
	
	// Convert  Login user  to line
	 string  _ConvertUserLoginToLine()
	{
		string LoginLine;

		LoginLine+=clsDate::GetSystemDateAndTimeinString()+"#";
		LoginLine+=GetUsername()+"#";
		LoginLine+=clsUtil::EncryptionText(GetPassword())+"#";
		LoginLine+=to_string(GetPermission());
		
		return LoginLine;
	}
	
		// Add Login user data to file
	 void _AddLogInDataToFile()
	{
		fstream MyFile;
		MyFile.open(RegisterLogInFile, ios::app);
		if ( MyFile.is_open() )
		{
			string Line=_ConvertUserLoginToLine();
			MyFile<<Line<<endl;
			
			MyFile.close();
		}
	}
	
	
	
	// Save Users data in file
	static void _SaveUsersDataInFile(vector<clsBankUsers> VUser)
	{
		fstream MyFile;
		MyFile.open(UsersFile, ios::out);
		if ( MyFile.is_open() )
		{
			string Line="";
			for ( clsBankUsers &U : VUser )
			{
				if ( U._UserMarkDeletion==false)
				{
					Line=_ConvertUserObjectToLine(U);
					MyFile<<Line<<endl;
				}
			}
			
			MyFile.close();
		}
	}
	
	// Add one User data to file
	static void _AddOneUserDataToFile(clsBankUsers user)
	{
		fstream MyFile;
		MyFile.open(UsersFile, ios::app);
		if ( MyFile.is_open() )
		{
			string Line=_ConvertUserObjectToLine(user);
			MyFile<<Line<<endl;
			
			MyFile.close();
		}
	}
	
	// Get data from File
	static vector<clsBankUsers> _LoadDataFromFile()
	{
		vector<clsBankUsers>  VUsers;
		fstream MyFile;
		MyFile.open(UsersFile, ios::in); 
		if ( MyFile.is_open() )
		{
			string Line="";
			while ( getline(MyFile, Line) )
			{
				clsBankUsers user = _ConvertLineToUserObject(Line);
				VUsers.push_back(user);
			}
			MyFile.close();
		}
		return VUsers;
	}
	
	// Get Empty User Object
	static clsBankUsers _GetEmptyUserObject()
	{
		return clsBankUsers(e_EmptyMode, "","","", "","","",0);
	}
	
	// Get New User Object with its Mode and username
	static clsBankUsers _GetAddNewUserObject(string username)
	{
		return clsBankUsers ( e_AddNewUser, "", "","", "",username, "", 0);
	}
	
	
	// Update user 
	void _Update()
	{
		// Get data from file
		vector<clsBankUsers> Vusers=_LoadDataFromFile();
		// Search for user
		for ( clsBankUsers &U : Vusers )
		{
			if ( U._Username == _Username )
				{
					U=*this;
					break;
				}
		}
		
		// Save new data in file 
		_SaveUsersDataInFile(Vusers);
	}
	
	// Add new User
	void _AddNewUser()
	{
		_AddOneUserDataToFile(*this);
	}
	

/////////////// PUBLIC //////////////
public :

	// Parameterize constructor
	clsBankUsers(eMode mode, string Firstname, string Lastname, string Email, string Phone, string username, string password, int permission ) : clsPerson( Firstname, Lastname, Email, Phone) ,  _Mode(mode), _Username(username), _Password(password), _Permission(permission){}                           

	// Define structure of user for register log in
	struct stLoginRegisterRecord{
		string DateTime;
		string UserName;
		string PassWord;
		int Permission;
	};
	
	// Convert Line To Login User structure
	static stLoginRegisterRecord  ConvertLineToLoginUserStructure(string line)
	{
		// Split line into vector of string
		vector<string> VUser = clsString::SplitString(line,"#");
		stLoginRegisterRecord LoginUser;
		LoginUser.DateTime=VUser[0];
		LoginUser.UserName=VUser[1];
		LoginUser.PassWord=clsUtil::DecryptionText(VUser[2]);
		LoginUser.Permission=stoi(VUser[3]);
		return LoginUser;
	}
	
	//  Get Register LogIn from File
	static vector<stLoginRegisterRecord> GetRegisterLogInfromFile()
	{
		vector<stLoginRegisterRecord> VLogin;
		string line; 
		fstream MyFile;
		MyFile.open(RegisterLogInFile, ios::in);
		if ( MyFile.is_open() )
		{
			while ( getline(MyFile,line) )
			{
				stLoginRegisterRecord LoginUser=ConvertLineToLoginUserStructure(line);
				VLogin.push_back(LoginUser);
			}
			MyFile.close();
		}
		return VLogin;
	}
	
	
	// enum of permissions
	enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pRegisterLogIn=128};
    
    
	// Set username
	void SetUsername( string username)
	{
		_Username=username;
	}
	// Get username
	string GetUsername()
	{
		return _Username;
	}
	
	// Set Password
	void SetPassword( string password)
	{
		_Password=password;
	}
	// Get Password
	string GetPassword()
	{
		return _Password;
	}
	
	// Set Password
	void SetPermission( int permission)
	{
		_Permission=permission;
	}
	// Get Password
	int GetPermission()
	{
		return _Permission;
	}
	
	// Check if the user object empty or not 
	bool isEmpty()
	{
		return ( _Mode==e_EmptyMode);
	}
	
	// Check if user existe or not
	static bool isUserExiste(string username)
	{
		clsBankUsers user = FindUser(username);
		return  !user.isEmpty();
	}
	
	// Get new User object initialize with username mode
	static clsBankUsers GetAddNewUserObject(string username)
	{
		return _GetAddNewUserObject(username);
	} 
	
	// Get user list from file
	static vector<clsBankUsers> GetUsersList()
	{
		return _LoadDataFromFile();
	}
	


	
	// Define enum of Save Result
	enum eSaveResult { e_SaveFailed=0, e_SaveSucceed=1, e_UserAlreadyExsist=2};
	// Save data and return enum result
	eSaveResult Save()
	{
		switch (_Mode)
		{
				case eMode::e_EmptyMode :
				{
					return e_SaveFailed;
					break;
				}
				case eMode::e_UpdateMode :
				{
					_Update();
					return e_SaveSucceed;
					break;
				}		
				case eMode::e_AddNewUser:
				{
					if ( isUserExiste(GetUsername()) )
					{
						return e_UserAlreadyExsist;
					}
					else
					{
						_AddNewUser();
						_Mode=e_UpdateMode;
						return e_SaveSucceed;
					}
				}
		}
	}
	
	
	// Find user by usrname
	static clsBankUsers FindUser(string username)
	{
		fstream MyFile;
		MyFile.open(UsersFile, ios::in); // read mode
		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline(MyFile, Line) )
			{
				clsBankUsers user=_ConvertLineToUserObject(Line);
				if ( user.GetUsername() == username)
				{
					MyFile.close();
					return user;
				}
			}
			
			MyFile.close();
		}
		
		return _GetEmptyUserObject();
	}
	
	// Find user by usrname and password
	static clsBankUsers FindUser(string username, string password)
	{
		fstream MyFile;
		MyFile.open(UsersFile, ios::in); // read mode
		if ( MyFile.is_open() )
		{
			string Line;
			while ( getline(MyFile, Line) )
			{
				clsBankUsers user=_ConvertLineToUserObject(Line);
				if ( user.GetUsername() == username && user.GetPassword()==password)
				{
					MyFile.close();
					return user;
				}
			}
			
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	
	// Delete user
	bool Delete()
	{
		// Check if the user is Admin to refuse process
			if ( _Username == "Admin" )
				return false;
		
		// Get data from file
		vector<clsBankUsers> Vusers=_LoadDataFromFile();
		// Put true Mark delete  in the exact user 
		for ( clsBankUsers &U : Vusers )
		{
			if ( U._Username == _Username )
			{
				U._UserMarkDeletion=true;
				break;
			}
		}
		// Save new data in the file
		_SaveUsersDataInFile(Vusers);
		// Make the current user object Empty 
		*this=_GetEmptyUserObject();
		return true;
	}
	
	// Check permission
	 bool CheckPermissions(enPermissions permission)
	{
		if ( this->GetPermission() == enPermissions::eAll )
			return true;
		if ( (this->GetPermission() & permission )==permission )
			return true;
		else 
			return false;
	}
	
	// Register login to file
	void RegisterLogIn()
	{
		_AddLogInDataToFile();
	}
	
	
};