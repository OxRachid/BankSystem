#pragma once
#include <iostream>
#include <string>
#include "../../Lib/clsEnputValidate.h"
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"
using namespace std;

class clsDrposit : protected clsScreen {
private :
	
	// Display client info 
	 static void _Printclient(clsBankClient client)
	{
		cout << "┌──┘" << endl;
		cout << "│" << endl;
		cout<<left<<setw(20)<<"≡ FirstName"<<":  "<<client.GetFirstName()<<endl;
		cout<<left<<setw(20)<<"≡ LastName"<<":  "<<client.GetLastName()<<endl;
		cout<<left<<setw(20)<<"≡ Email"<<":  "<<client.GetEmail()<<endl;
		cout<<left<<setw(20)<<"≡ Phone"<<":  "<<client.GetPhone()<<endl;
		cout<<left<<setw(20)<<"≡ Account N"<<":  "<<client.GetAccountNumber()<<endl;
		cout<<left<<setw(20)<<"≡ PincCode"<<":  "<<client.GetPinCode()<<endl;
		cout<<left<<setw(20)<<"≡ Account Balance"<<":  "<<client.GetAccountBalance()<<endl;
		cout << "│" << endl;
		cout << "└──┐" << endl;
		cout << "    ∞" << endl;
	}
	
	
public :
	
	// deposit
	static void DepositScreen()
	{
		// Draw header screen
		clsScreen::headrScreen("Deposit Menu","",true);
		
		// Ask user to Enter the Account Number
		string AcNumber=clsEnputValidate::ReadString("Account Number");
		// Force user  to Enter an exsisting client
		clsBankClient::isAccountNumberExiste(AcNumber);
		// Find and Return the client object
		clsBankClient client=clsBankClient::Find(AcNumber);
		// Print the client info befor making deposit
		_Printclient(client);
		// Ask for Amount to deposit
		double Amount;
		clsScreen::PrintMessage("How much do y want to Deposit ? ","",false);
		Amount=clsEnputValidate::ReadNumber<double>();
		// Deposit Actions
		 if (clsScreen::WarningMessage("Deposit",to_string(Amount))) // Ask befor making deposit
			{
				// Making deposit
				client.MakeDeposit(Amount);
				clsScreen::PrintMessage("Added Succesfuly √ ", to_string(Amount));
				clsScreen::PrintMessage("Your New Balance is : ","",false);
				cout<<"["<<client.GetAccountBalance()<<"]"<<endl;
			}
		else
			{
				clsScreen::PrintMessage(" Deposit Canceled √");
			}
	}
	
};