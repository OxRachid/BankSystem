#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsWithdraw : protected clsScreen {

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

	// Withdraw
	static void WithdrawScreen()
	{
		// Draw header screen
		clsScreen::headrScreen("Withdraw Menu","",true);
		
		// Ask user to Enter the Account Number
		string AcNumber=clsEnputValidate::ReadString("Account Number");
		// Force user  to Enter an exsisting client
		clsBankClient::isAccountNumberExiste(AcNumber);
		// Find and Return the client object
		clsBankClient client=clsBankClient::Find(AcNumber);
		// Print the client info befor making Withdraw
		_Printclient(client);
		// Ask for Amount to Withdraw
		double Amount;
		clsScreen::PrintMessage("How much do y want to Withdraw ? ","",false);
		Amount=clsEnputValidate::ReadNumber<double>();
		// Check if Amount to withdraw is valid
		client.isAmountCanBeWithdraw(Amount);
		// Withdraw Actions
		 if (clsScreen::WarningMessage("Withdraw", to_string(Amount))) // Ask befor making deposit
			{
					// Check Again and Making Withdraw
					if ( client.MakeWithdraw(Amount) )
					{
						clsScreen::PrintMessage("Withdraw Succesfuly √ ", to_string(Amount));
						clsScreen::PrintMessage("Your New Balance is : ","",false);
						cout<<"["<<client.GetAccountBalance()<<"]"<<endl;
					}
					else {
						clsScreen::PrintMessage("Amount is invalid...");
					}		
			}
		else
			{
				clsScreen::PrintMessage(" Withdraw Canceled √");
			}
	}
	
};