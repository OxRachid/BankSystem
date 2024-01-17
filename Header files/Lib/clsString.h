#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include "clsEnputValidate.h"
using namespace std;

class clsString{
private:
	string _value;
public:
	clsString ():_value(""){}
	
	clsString ( string s )
	{
		_value=s;
	}
	
	void setValue(string Value)
	{
		_value=Value;
	}
	
	string getValue()
	{
		return _value;
	}
	
	// get length
	int Length()
	{
		return _value.length();
	}
	
	// static  get lenght 
	static int getlength(clsString s)
	{
		return s.Length();
	}
	
	
	// remove anything after any Delimtry of one word
	static string RemoveDecimel(string text, string Delim=".")
	{
		short pos=0;
		pos=text.find(Delim);
		return text.substr(0,pos);
	}
	
	// warning message befor taking any  action
	static bool WarningMessage(string action)
	{
		char answer = 'Y';
		cout<<"    │"<<endl;
		cout<<"    □ Are u sure Wanna "<<action<<" ? y/n ≫ ";
		answer=clsEnputValidate::ReadChar();
		return ( toupper(answer) == 'Y' );
	}
	

	// Upper the first letter of each word
	void UpperFirstLetter()
	{
		_value=UpperFirstLetter(_value);
	}
	
	// static Upper the first letter of each word
	static string UpperFirstLetter(string text)
	{
		bool isfirstLetter=true;
		for ( int i=0; i<text.length(); i++)
		{
			if ( text[i] != ' ' && isfirstLetter )
			{
				text[i]=toupper(text[i]);
			}
			isfirstLetter=( text[i]==' ' ? true : false );
		}
		return text;
	}
	
	// Lower the first letter of each word
	void LowerFirstLetter()
	{
		_value=LowerFirstLetter(_value);
	}
	
	// static Lowerthe first letter of each word
	static string LowerFirstLetter(string text)
	{
		bool isfirstLetter=true;
		for ( int i=0; i<text.length(); i++)
		{
			if ( text[i] != ' ' && isfirstLetter )
			{
				text[i]=tolower(text[i]);
			}
			isfirstLetter=( text[i]==' ' ? true : false );
		}
		return text;
	}
	
	// static Upper All String
	static string UpperAllString(string text)
	{
		for(int i=0; i<text.length(); i++)
		{
			if ( text[i] != ' ' && text[i] > 96)
				text[i]=toupper(text[i]);
		}
		return text;
	}
	
	// upper all string
	void UpperAllString()
	{
		_value=UpperAllString(_value);
	}
	
	
	// static Lower All String
	static string LowerAllString(string text)
	{
		for(int i=0; i<text.length(); i++)
		{
			if ( text[i] != ' ' && text[i] < 91)
				text[i]=tolower(text[i]);
		}
		return text;
	}
	
	
	// lower all string
	void LowerAllString()
	{
		_value=LowerAllString(_value);
	}
	
	
	// invert section
	static char invertChar(char  c)
	{
		return ( isupper(c) ) ? tolower(c) : toupper(c);
	}

	static string invertAll(string s)
	{
		for ( int i=0; i<s.length(); i++)
		{
			s[i]=invertChar(s[i]);
		}
		return s;
	}
	
	void invertAll()
	{
		_value=invertAll(_value);
	}
	
	
	// count upper letters
	static int countUpperletters(string s)
	{
		int count=0;
		for ( int i=0; i<s.length(); i++)
		{
			if ( isupper(s[i]) )
				count++;
		}
		return count;
	}
	
	void countUpperletters()
	{
		_value=countUpperletters(_value);
	}
	
	// count upper letters
	static int countLowerletters(string s)
	{
		int count=0;
		for ( int i=0; i<s.length(); i++)
		{
			if ( islower(s[i]) )
				count++;
		}
		return count;
	}
	
	void countLowerletters()
	{
		_value=countLowerletters(_value);
	}
	
	enum countMethed { smallLetters , capitalLetters , digit , All };
	static int countletters(string s, countMethed whatToCount=countMethed::All)
	{
		int count=0;
		for ( int i=0; i<s.length(); i++)
		{
			if ( whatToCount==countMethed::All && ( islower(s[i]) || isupper(s[i]) )  )
				count++;
			if ( whatToCount==countMethed::smallLetters && islower(s[i]))
				count++;
			if ( whatToCount==countMethed::capitalLetters && isupper(s[i]))
				count++;
			if ( whatToCount==countMethed::digit && isdigit(s[i]) )
				count++;
		}
		return count;
	}
	
	static int countSpecialletter(string s, char c, bool special=true)
	{
		int count=0;
		for ( int i=0; i<s.length(); i++)
		{
			if ( special )
			{
					if ( s[i] == c )
						count++;
			}
			else {
					if ( toupper(s[i]) == toupper(c) )
						count++;
			}
		}
		return count;
	}
	
	static bool checkVowel(char c)
	{
		c=tolower(c) ;
	     return ( c == 'a' || c == 'e' || c == 'u' ||  c == 'o' || c == 'i' );
	}
	
	static int countVowels(string s)
	{
		int count =0;
		for ( int i=0; i<s.length(); i++)
		{
			if ( checkVowel(s[i]) )
				count++;
		}
		return count;
	}
	
	
	static void printVowels(string s )
	{
		if ( countVowels(s) == 0 )
		{
				cout<<" there is no vowels "<<endl;
		}
		else {
				cout<<" the vowels are : ";
				for ( int i=0; i<s.length(); i++)
				{
					if ( checkVowel(s[i]) )
						cout<<setw(3)<<s[i];
				}
		}
	}
	
	// print each word in string
	static void printEachWord(string s)
	{
		string temp;
		string delim=" ";
		short pos=0;
		while ( (pos=s.find(delim)) != string::npos )
		{
			temp=s.substr(0,pos);
			if ( temp != "" )
					cout<<temp<<endl;
			
			s.erase(0,pos+delim.length());
		}
				if ( s != "" )
					cout<<s<<endl;
	}
	
	// count Words in string
	static int countWords(string s)
	{
		int count=0;
		string temp;
		string delim=" ";
		short pos=0;
		while ( (pos=s.find(delim)) != string::npos )
		{
			temp=s.substr(0,pos);
			if ( temp != "" )
					count++;
			
			s.erase(0,pos+delim.length());
		}
				if ( s != "" )
					count++;
					
			return count;
	}
	
	short countWords()
	{
		return countWords(_value);
	}
	
	
	// Split a string and put it  vector of string
	static vector<string> SplitString(string line, string Delim)
	{
		vector<string> Vstring;
		short pos=0;
		string temp;
		while ( (pos=line.find(Delim)) != string::npos )
		{
			temp=line.substr(0,pos);
			if ( temp != "" )
				Vstring.push_back(temp);
			
			line.erase(0,pos+Delim.length());
		}
		if ( line != "" )
			Vstring.push_back(line);
		
		return Vstring;
	}
	
	
	// making left Trim ( cut any aditional spaces in the left string)
	static string trim_left(string s)
	{
		short pos=0;
		while ( s[pos] == ' ')
		{
			pos++;
		}

		return s.substr(pos, s.length()-1);
	}
	
	// making right Trim ( cut any aditional spaces in the right string)
	static string trim_right(string s)
	{
		short pos=s.length()-1;
		while ( s[pos] == ' ')
		{
			pos--;
		}
		
		return s.substr(0,pos+1);
	}
	
	//  making Trim ( cut any aditional spaces in left and right of string )
	static string Trim(string s)
	{
		return ( trim_left( trim_right(s) ) );
	}
	
	// joind vector of words in one string
	static string joindString( vector <string> words , string delim )
	{
		string joind;
		for ( string &w : words )
		{
			joind=joind+w+delim;
		}
		return joind.substr(0, joind.length()-delim.length());
	}
	//  joind Array of words in one string (overloeading)
	static string joindString( string words[], int size, string delim )
	{
		string joind;
		for (int i=0; i<size; i++ )
		{
			joind=joind+words[i]+delim;
		}
		return joind.substr(0, joind.length()-delim.length());
	}
	
	// reversing string
	static string ReversString(string str)
	{
		vector <string> words;
		string revers="";
		words=SplitString(str, " ");
		vector <string>::iterator it;
		for ( it=words.end()-1; it != words.begin()-1; it--)
		{
			revers=revers+*it+" ";
		}
		return revers.substr(0, revers.length()-1);
	}
	
	// replacing words in string
	static string ReplaceWordInString(string text , string oldWord, string newWord)
	{
		short pos=0;
		while ((pos=text.find(oldWord)) != string::npos)
		{
			text.replace(pos,oldWord.length(), newWord);
		}
		
		return text;
	}
	
	// Remov Punctuations from string
	static string RemovPunctuations( string str)
	{
		string res="";
		for ( int i=0; i<str.length(); i++)
		{
			if ( !ispunct(str[i]) )
				res+=str[i];
		}
		return res;
	}
	
	// display value
	void display()
	{
		cout<<_value<<endl;
	}


};