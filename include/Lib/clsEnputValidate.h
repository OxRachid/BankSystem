#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;

class clsEnputValidate{
	
public:

	clsEnputValidate(){}
	
	// check if specific number is between two other numbers
	template<typename T> static bool isNumberBetween( T value, T from , T to)
	{
		return ( value >= from && value <= to );
	}

	// Read string from a user 
	static string ReadString( string text)
	{
		string input;
		cout<<"    │"<<endl;
		cout<<"    □ Enter "<<text<<" : ";
		getline(cin>>ws, input);
		return input;
	}
	
	// Read Char
	static char ReadChar()
	{
		char c;
		cin>>c;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return c;
	}
	
	// Read  Number  and check validation
	template<typename T> static T ReadNumber(string StartMessage="", string ErrorMessage="    │\n    □ Error... \n    │\n    □ Please Enter a Number : " )
	{
		 // Write first message
		if ( StartMessage != "" )
		{
			cout<<"    │"<<endl;
			cout<<"    □ "<<StartMessage;
		}
		
		// check number validate
		T number=0;
		while ( !(cin>>number) )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<ErrorMessage;
		}
		return number;
	}
	
	
	//check validation of  input and if its between two numbers
	template<typename T> static T ReadNumberBetween( T From, T To, string ErrorMessage="    │\n    □ Out of Range ↔\n    │\n    □ Please Enter Between [")
	{
		T Number=ReadNumber<T>();
		while ( ! isNumberBetween ( Number , From, To) )
		{
			cout<<ErrorMessage<<From<<"-"<<To<<"] : ";
			Number=ReadNumber<T>();
		}
		return Number;
	}
	

};
