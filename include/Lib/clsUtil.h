#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include "clsDate.h"
using namespace std;


class clsUtil{
private:

public:
	clsUtil() {}
	enum typeofletters { S_letters =1, C_letters=2, D_letters=3,  M_letters=4 };

	static void sRand()
	{
		srand(time(NULL));
	}
	
	// get Random Number from Specific Rang 
	static int randomNumber(int from, int to)
	{
		return (rand()%(to-from+1)+from);
	}
	
	// get Random char
	static char getRandomChar( typeofletters x )
	{
			if ( x == M_letters )
			{
				x= (typeofletters)randomNumber(1,3);
			}
		
			switch ( x )
			{
				case typeofletters::C_letters :
				{
					return char(randomNumber(65, 90));
					break;
				}
				case typeofletters::S_letters :
				{
					return char(randomNumber(97, 122));
					break;
				}
				case typeofletters::D_letters :
				{
					return char(randomNumber(48, 57));
					break;
				}
				default : break;
			}
	}
	
	static string GenerateWord(typeofletters x, int s)
	{
		string res="";
		for ( int i=0; i<s; i++)
		{
			res+=getRandomChar(x);
		}
		return res;
	}
	
	static string generateKey( typeofletters x )
	{
		string res;
		res+=GenerateWord(x, 4);
		res+='-';
		res+=GenerateWord(x, 4);
		res+='-';
		res+=GenerateWord(x, 4);
		return res;
	}
	
	static void generateKeys( int y,typeofletters x)
	{
		for ( int s=0; s<y; s++)
		{
			cout<<" Key ["<<s+1<<"] : "<<generateKey(x)<<endl;
		}
	}

	static void swap( int &x, int &y)
	{
		int t=x;
		x=y;
		y=t;
	}
	
	static void swap( double &x, double &y)
	{
		double t=x;
		x=y;
		y=t;
	}
	
	static void swap( string &x, string &y)
	{
		string t=x;
		x=y;
		y=t;
	}
	
	static void shuffleArray(int arr[], int s)
	{
		int x=s;
		while ( x-- )
		{
			swap(arr[rand()%s],arr[rand()%s]);
		}
	}
	
	
	static void fillArraywithrandomNumbers(int arr[], int size, int f, int l)
	{
		for ( int i=0; i<size; i++)
		{
			arr[i]=randomNumber(f,l);
		}
	}
	
	static void fillArraywithrandomWords(string arr[], int size, typeofletters x, int length)
	{
		for ( int i=0; i<size; i++)
		{
			arr[i]=GenerateWord(x,length);
		}
	}
		                                                                                                    
	static string EncryptionText( string text, int key=4)
	{
		const string RandCharacters="ABC7Dno5pqrs6tuvEFGH1IJKLMN2OPQRSTUV3WXYZ9abcde4fghij8klmwxyz@?%_&-+#!";
		string res;
		for ( int i=0; i<text.length(); i++)
		{
			for ( int j=0; j<RandCharacters.length(); j++)
			{
				if ( text[i] == RandCharacters[j] )
				{
					res+=RandCharacters[j+key];
				}
			}
			 if ( text[i] == ' ')
				{
					char v='$';
					res+=v;
				}
			res+=GenerateWord(M_letters,2);
		}
		return res;
	}
	

	
	static string DecryptionText( string text, int key=4)
	{
		const string RandCharacters="ABC7Dno5pqrs6tuvEFGH1IJKLMN2OPQRSTUV3WXYZ9abcde4fghij8klmwxyz@?%_&-+#!";
		string res;
		for ( int i=0; i<text.length(); i+=3)
		{
			for ( int j=0; j<RandCharacters.length(); j++)
			{
				if ( text[i] == RandCharacters[j] )
				{
					res+=RandCharacters[j-key];
				}
			}
			 if ( text[i] == '$')
				{
					char v=' ';
					res+=v;
				}
		}
		return res;
	}
	
	
	static bool isDateBetween(clsDate d1, clsDate d2, clsDate d3)
	{
		if ( (clsDate::isDate1AfterDate2(d1,d2)) && (clsDate::isDate1BeforDate2(d1,d3))  )
			return true;
		if ( (clsDate::isDate1BeforDate2(d1,d2)) && (clsDate::isDate1AfterDate2(d1,d3))  )
			return true;
			
		return false;
	}
	
	static bool isvalidateDate(clsDate d)
	{
		return clsDate::isDateValidate(d);
	}
	
	static string  Tabs(short NumberOfTabs)
   {
       string t = "";

       for (int i = 1; i < NumberOfTabs; i++)
       {
           t = t + "\t";
           cout << t;
       }
       return t;

   }

	// Convert Number to text
   static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";
       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }

   }

};
