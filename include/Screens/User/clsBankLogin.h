#pragma once
#include <iostream>
#include <string>
#include "../../Lib/clsEnputValidate.h"
#include "../clsScreen.h"
#include "../../Core/clsBankUsers.h"
#include "../clsMainScreen.h"
#include "../../Core/Global.h"
using namespace std;

class clsBankLogin : protected clsScreen {
	
private :
	
	// Check if the user is new or already existe
	static bool _isAccountExiste(string &Username, string &Password)
	{
			clsBankUsers User=clsBankUsers::FindUser(Username,Password );
			return ( !User.isEmpty() );
	} 
	
	// Check login
	static bool _CheckLogin()
	{
		
		string Username, Password;
		
		// Bool for login verification
		bool LoginSucceed=false;
		
		short LoginTrials=3;
		
			do {
				
				if (LoginSucceed)
				{
					--LoginTrials;
					// Print header screen
					clsScreen::headrScreen("Login Screen 🖥️","",true);
					clsScreen::PrintMessage("⊷ Username or Password is incorrect ⊗");               
					clsScreen::PrintMessage(" Trials Remaining ", to_string(LoginTrials) );
				
					if ( LoginTrials == 0 )
					{
						clsScreen::PrintMessage(" You are locked after 3 Trials" );
						return false;
					}
				}
				
				//Read Username & Password
				 Username=clsEnputValidate::ReadString("Username");
				 Password=clsEnputValidate::ReadString("Password");
				
				// search for user and get object Empty or filled
				CurrentUser=clsBankUsers::FindUser(Username,Password);
				// here we check if this object is empty or not
				LoginSucceed=CurrentUser.isEmpty();
			
		} while (LoginSucceed);
		
		// Register login in file
		CurrentUser.RegisterLogIn();
		// after  the  login is succeed we open the main menu screen
		clsMainScreen::ShowMainMenu();
		return true;
	}
	
	
public :

	static bool Login()
	{
		// Print header screen
		clsScreen::headrScreen("Login Screen 🖥️","",true);
		
		// Read and check username and password
			return _CheckLogin();
	}
	
};