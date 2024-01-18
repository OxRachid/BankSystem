#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsBankUsers.h"
#include "Global.h"
using namespace std;

class clsScreen{

protected:

	// Header screen
	static void headrScreen(string Title, string Subtitle="",  bool ScreenWithOptions=false )
	{
		system("cls");
		
		cout << "               ┌" << "                    " << "┐" << endl;
		cout << "                  "<<Title<<endl;
		if ( Subtitle != "" )
		{
			 cout<<"                  ["<<Subtitle<<"]"<< endl;
		}
		cout << "               └" << "                    " << "┘"<< endl;    
		// Print Name of user and date
		cout << "               ┌─────────────────┐" << endl;      
		cout << "                  User  : "<<CurrentUser.GetUsername()<<endl;
		cout << "                  Date  : "<<clsDate::DateToString(clsDate())<<endl;
		cout << "               └─────────────────┘" << endl;        
		 
		 if ( ScreenWithOptions )
		 {
		 	cout << "    ┌──────────────────┘" << endl;
			 cout << "    │" << endl;
			 cout << "    │" << endl;
		 }
		 
	}
	
	// warning message befor taking any  action
	static bool WarningMessage(string action, string Value="")
	{
		char answer = 'Y';
		cout<<"    │"<<endl;
		if ( Value != "" )
			cout<<"    □ Are u sure Wanna "<<action<<" ["<<Value<<"] ? y/n ≫ ";
		else
			cout<<"    □ Are u sure Wanna "<<action<<" ? y/n ≫ ";
		answer=clsEnputValidate::ReadChar();
		return ( toupper(answer) == 'Y' );
	}
	
	// Message display after task finish 
	static void PrintMessage(string Message, string value = "", bool isEndMessage=true)
	{
		if ( isEndMessage )
		{
				if ( value != "")
					{
						cout << "    │" << endl;
						cout <<"    ⊗──["<<value<<"] "<<Message<<endl;
					}
				else
					{
						cout << "    │" << endl;
						cout << "    ⊗──"<<Message<<endl;
					}
		}
		else
		{
			cout << "    │" << endl;
			cout << "    □ "<<Message;
		}	

	}
	
	// Message Access denied
	static bool CheckAccess(clsBankUsers::enPermissions Permission)
	{
		if ( !CurrentUser.CheckPermissions(Permission) )
		{
			system("cls");
			cout << "    ┌" << "                                          " << "┐" << endl;
			cout << "      Access denied , pleae contact your Admin " << endl;
			cout << "    └" << "                                          " << "┘" << endl << endl;
			return false;
		}
		else
			return true;
	}


	
};