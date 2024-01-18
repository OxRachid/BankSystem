#pragma once
#include <iostream>
#include <string>
#include "clsEnputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsTransfer : protected clsScreen {

private :
	
	static string _ReadAccountNumber()
	{
		string AccountNumber;
		
		AccountNumber=clsEnputValidate::ReadString("Whitch Account you want to transfer from ?");
		// Check if client existe or not
		clsBankClient::isAccountNumberExiste(AccountNumber);
		
		return AccountNumber;
	}
	
	// Display client info 
	 static void _Printclient(clsBankClient client)
	{
		cout << "┌──┘" << endl;
		cout << "│" << endl;
		cout<<left<<setw(20)<<"≡ FullName"<<":  "<<client.GetFullName()<<endl;
		cout<<left<<setw(20)<<"≡ Account N"<<":  "<<client.GetAccountNumber()<<endl;
		cout<<left<<setw(20)<<"≡ Account Balance"<<":  "<<client.GetAccountBalance()<<endl;
		cout << "│" << endl;
		cout << "└──┐" << endl;
		cout << "    ∞" << endl;
	}
	
	
public :

	static void Transfer()
	{
		// Draw header screen
		clsScreen::headrScreen("Transfer Screen 💸","",true);
		
		// Get client Account whitch we will transfer from
		clsBankClient FromClient=clsBankClient::Find(_ReadAccountNumber());
		// Print the client data
		_Printclient(FromClient);
		
		// Get the client Account whitch we will transfer To
		clsBankClient ToClient=clsBankClient::Find(_ReadAccountNumber());
		// Print the client data
		_Printclient(ToClient);
		
		double Amount;
		clsScreen::PrintMessage("How Much do you want to transfer ? ","",false);
		Amount=clsEnputValidate::ReadNumber<double>();
		
		if ( clsScreen::WarningMessage("Transfer", to_string(Amount)) )
		{
				// Check Again and Making Withdraw
					if ( FromClient.Transfer(Amount,ToClient, CurrentUser.GetUsername()) )
					{
						clsScreen::PrintMessage("Transfered Succesfuly √ ", to_string(Amount));
						clsScreen::PrintMessage("⊷ New Balance is : ");
						_Printclient(FromClient);
						_Printclient(ToClient);
					}
					else {
						clsScreen::PrintMessage("Transfer Failed...");
					}		
		}
		else
		{
			clsScreen::PrintMessage(" Transfer Canceled √");
		}
	}
	
};