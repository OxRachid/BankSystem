#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include<string>
#include "clsString.h"
using namespace std;

class clsDate{
private:
	int _day;
	int _mon;
	int _year;
public:
	// inisialize constructor
	clsDate()
	{
		time_t now= time(0);
		tm* str_time=localtime(&now);
		_day=str_time->tm_mday;
		_mon=str_time->tm_mon+1;
		_year=str_time->tm_year+1900;
	}
	// convert datestring to dateStructure using constructor
	clsDate(string s)
	{
		vector<string> Vstring;
		Vstring=clsString::SplitString(s, "/");
		_day=stoi(Vstring[0]);
		_mon=stoi(Vstring[1]);
		_year=stoi(Vstring[2]);
	}
	
	// convert datestring to dateStructure
	static clsDate StringToDateStructure(string DateString)
	{
		clsDate date;
		vector<string> Vstring=clsString::SplitString(DateString,"/");
		date._day=stoi(Vstring[0]);
		date._mon=stoi(Vstring[1]);
		date._year=stoi(Vstring[2]);
		return date;
	}
	
	clsDate(int d, int m, int y)
	{
		_day=d;
		_mon=m;
		_year=y;
	}
	
	// convert dateStructure to DateString format using constructor
	string dateTostring()
	{
		return to_string(_day)+"/"+to_string(_mon)+"/"+to_string(_year);
	}
	
	// convert dateStructure to DateString format
	static string DateToString(clsDate date)
	{
		return to_string(date._day)+"/"+to_string(date._mon)+"/"+to_string(date._year);
	}
	
	void setDate(short d, short m, short y)
	{
		_day=d;
		_mon=m;
		_year=y;
	}
	
	// Format date
	static string FormateDate(clsDate date, string Format)
	{
		string DateFormat="";
		DateFormat=clsString::ReplaceWordInString(Format, "dd", to_string(date._day));
		DateFormat=clsString::ReplaceWordInString(DateFormat, "mm", to_string(date._mon));
		DateFormat=clsString::ReplaceWordInString(DateFormat, "yyyy", to_string(date._year));
		
		return DateFormat;
	}
	
	// swaping dates
	static void SwapDate(  clsDate &date1, clsDate &date2)
	{
		clsDate tempDate;
		tempDate=date1;
		date1=date2;
		date2=tempDate;
	}

	// Enum of Months
	enum eMonths{January=1, February, March, April, May, June, July, August, September, October, November, December};
	
	// Read year from the user
	static short  ReadYear()
	{
		short  year;
		cout<<"Enter the Year : ";
		cin>>year;
		return year;
	}
	// Read month from the user	
	static short  ReadMonth()
	{
		short  month;
		cout<<"Enter the month  : ";
		cin>>month;
		return month;
	}
	// Read day from the user
	static short ReadDay()
	{
		short  Day;
		cout<<"Enter the Day  : ";
		cin>>Day;
		return Day;
	}
	
	// Read Date from the user
	static clsDate ReadDate()
	{
		clsDate date;
		date._day=ReadDay();
		date._mon=ReadMonth();
		date._year=ReadYear();
		return date;
	}
	
	// get The system date (curr)
	static clsDate GetSystemDate()
	{
		clsDate date;
		time_t now=time(0);
		tm* TimeString=localtime(&now);
		date._day=TimeString->tm_mday;
		date._mon=TimeString->tm_mon+1;
		date._year=TimeString->tm_year+1900;
		return date;
	}

	// get the system time in string (curr)
	static string GetSystemTimeinString()
	{
		int hour, min, sec;
		time_t now=time(0);
		tm* TimeString=localtime(&now);
		hour=TimeString->tm_hour;
		min=TimeString->tm_min;
		sec=TimeString->tm_sec;
		return to_string(hour)+":"+to_string(min)+":"+to_string(sec);
	}

	// get the system time in string (curr)
	static string GetSystemDateAndTimeinString()
	{
		return DateToString(clsDate())+" - "+ GetSystemTimeinString();
	}
	
	
	// check if the year is it leap or not
	static bool isLeapYear(short year)
	{
		 return (  ( year % 400 == 0 ) || ( (year % 4 == 0) && (year % 100 != 0) ) );
	}
	
	bool isLeapYear()
	{
		 return isLeapYear(_year);
	}
	
	
	// Year
	static short  NumberOfDaysinYear(short  Year)
	{
		return ( isLeapYear(Year) ? 366 : 365 );
	}
	
    short  NumberOfDaysinYear()
	{
		return NumberOfDaysinYear( _year);
	}
	
	static short  NumberOfHoursinYear(short  Year)
	{
		return NumberOfDaysinYear(Year)*24;
	}
	
	short  NumberOfHoursinYear()
	{
		return NumberOfHoursinYear(_year);
	}
	
	static short  NumberOfMinutesinYear(short  Year)
	{
		return NumberOfHoursinYear(Year)*60;
	}
	
	 short  NumberOfMinutesinYear()
	{
		return NumberOfMinutesinYear(_year);
	}
	
	static short  NumberOfSecondsinYear(short  Year)
	{
		return NumberOfMinutesinYear(Year)*60;
	}
	
	short  NumberOfSecondsinYear()
	{
		return NumberOfSecondsinYear(_year);
	}
	
	// Month
	static short  NumberOfDaysinMonth(short year, eMonths  mon)                                                                                                       
	{
		if ( mon<=0 || mon>12) return 0;
		
		return( mon==February) ? ( isLeapYear(year) ? 29 : 28 ) : ( ( mon==April || mon==June || mon==September || mon==November ) ? 30 : 31 );                                                                   
	}
	
    short  NumberOfDaysinMonth()                                                                                                       
	{
		return  NumberOfDaysinMonth(_year,  (eMonths)_mon);                                                       
	}
	
	static short  NumberOfHoursinMonth(short year, eMonths  mon)
	{
		return NumberOfDaysinMonth(year, mon)*24;
	}
	
	short  NumberOfHoursinMonth()
	{
		return NumberOfHoursinMonth(_year,  (eMonths)_mon);    
	}
		
	static short  NumberOfMinutesinMonth(short year ,eMonths  mon)
	{
		return NumberOfHoursinMonth(year, mon)*60;
	}
	
	short  NumberOfMinutesinMonth()
	{
		return NumberOfMinutesinMonth(_year,  (eMonths)_mon);   
	}
	
	static short  NumberOfSecondsinMonth(short year, eMonths  mon)
	{
		return NumberOfMinutesinMonth(year, mon)*60;
	}
	
	short  NumberOfSecondsinMonth()
	{
		return NumberOfSecondsinMonth(_year,  (eMonths)_mon);   
	}
	
	// convert days to date
	static clsDate ConvertDaysToDate(short days, short year)
	{
		clsDate date;
		short TotalOfDays=days;
		short DaysInMonth=0;
		short CountMonths=1;
		while ( true )
		{
			DaysInMonth=NumberOfDaysinMonth(year, (eMonths) CountMonths);
			if ( TotalOfDays >= DaysInMonth )
			{
				TotalOfDays-=DaysInMonth;
				CountMonths++;
			}
			else 
			{
				date._day=TotalOfDays;
				break;
			}
		}	
		
		date._mon=CountMonths;
		date._year=year;
		return date;
	}
	
	// check if date is a validate
	static bool isDateValidate(clsDate date)
	{
		return  ( (date._day > 0) ? (date._day <= NumberOfDaysinMonth(date._year, (eMonths) date._mon) ) : false );
	} 
	
	// check if date is a validate without static
	bool isDateValidate()
	{
		return isDateValidate(*this) ;
	} 
	
	
	// is date1 Equal date2
	static bool isDate1EqualDate2(clsDate date1, clsDate date2)
	{
		return ( date1._year==date2._year ) ? ( (date1._mon==date2._mon) ?  ( ( date1._day==date2._day ) ? true : false) : false  ) : false  ;
	}
	
	// is date1 Equal date2 without static
	bool isDate1EqualDate2(clsDate date2)
	{
		return   isDate1EqualDate2 (*this, date2) ;
	}
	
	// is date1 Befor date2
	static bool isDate1BeforDate2( clsDate date1, clsDate date2 )
	{
		return ( date1._year < date2._year ) ? true : ( ( date1._year == date2._year ) ?  ( ( date1._mon < date2._mon ) ? true : ( ( date1._mon == date2._mon )  ?   ( date1._day < date2._day ) : false )  ) : false ) ;        
	}
	
	// is date1 Befor date2 without static
	bool isDate1BeforDate2(clsDate date2 )
	{
		return isDate1BeforDate2 (*this, date2) ;        
	}
		
	// is date1 after date2
	static bool isDate1AfterDate2(clsDate date1, clsDate date2)
	{
		return ( !isDate1BeforDate2(date1, date2) && !isDate1EqualDate2(date1, date2) );
	}
	
	// is date1 after date2 without static
	bool isDate1AfterDate2(clsDate date2)
	{
		return isDate1AfterDate2(*this, date2) ;
	}
	
	// Compare two dates
	enum eCompareDateCase{Befor=-1, Equal=0, After=1};
	static eCompareDateCase CompareDate(clsDate date1, clsDate date2)
	{
		return ( ( isDate1BeforDate2(date1, date2) ) ? eCompareDateCase::Befor : ( isDate1EqualDate2(date1, date2) ) ? eCompareDateCase::Equal : eCompareDateCase::After );
	}
	
	
	// is date between two dates
	static bool isDateBetween(clsDate date, clsDate date1, clsDate date2)
	{
		return ( CompareDate(date1, date)==clsDate::Befor && CompareDate(date2, date)==clsDate::After );
	}
	
	bool isDateBetween(clsDate date1, clsDate date2)
	{
		return isDateBetween(*this,date1,date2);
	}
				
	// Total of days from beginning of year
	static short TotalDaysFromBegOfYear(clsDate date)
	{
		short total=0;
		for ( short i=1; i<date._mon; i++)
		{
			total+=NumberOfDaysinMonth(date._year, (eMonths)i);
		}
		
		return total+date._day;
	}
	
	short TotalDaysFromBegOfYear()
	{
		return TotalDaysFromBegOfYear(*this) ;
	}
	
	
	// check if day is the last day in Month
	static bool isLastDayinMonth(clsDate date)
	{
		return ( date._day == NumberOfDaysinMonth(date._year, (eMonths) date._mon) );
	}
	
	// check if month is the last month in year
	static bool isLastMonthinYear(short mon)
	{
		return (mon==12);
	}
	
	// Add one day to date
	static clsDate IncreaseDateByOneDay(clsDate &date)
	{
		if ( isLastDayinMonth(date) )
		{
				if ( isLastMonthinYear(date._mon) )
				{
					date._day=1;
					date._mon=1;
					date._year++;
				}
				else 
				{
					date._day=1;
					date._mon++;
				}
		}
		else date._day++;
		
		return date;
	}
	
	clsDate IncreaseDateByOneDay()
	{
		return IncreaseDateByOneDay(*this);
	}
	
	//  Add X of Days to Date
	static clsDate IncreaseDateByXDays(clsDate &DateTemp, short XDays)
	{
		for ( int i=0; i<XDays; i++)
		{
			DateTemp=IncreaseDateByOneDay(DateTemp);
		}
		return DateTemp;
	}
	
	clsDate IncreaseDateByXDays(short XDays)
	{
		return IncreaseDateByXDays(*this, XDays) ;
	}

	//  Add Number of Days to Date ( fast methed )
	static clsDate AddNumberOfDaystoDate(clsDate &DateTemp, short AddDays)
	{
		short TotalofDays=TotalDaysFromBegOfYear(DateTemp)+AddDays;
		short DaysInMonth=0;
		DateTemp._mon=1;
		while ( true )
		{
				DaysInMonth=NumberOfDaysinMonth(DateTemp._year, (eMonths)DateTemp._mon);
				if ( TotalofDays >= DaysInMonth )
				{
					TotalofDays-=DaysInMonth;
					DateTemp._mon++;
					if ( DateTemp._mon > 12 ){
						DateTemp._year++;
						DateTemp._mon=1;
					}
				}
				else 
				{
					DateTemp._day=TotalofDays;
					break;
				}					
		}
		return DateTemp;
	}
	
	clsDate AddNumberOfDaystoDate(short XDays)
	{
		return AddNumberOfDaystoDate(*this, XDays) ;
	}
	
	//  Add one week to Date
	static clsDate IncreaseDateByOneWeek(clsDate &DateTemp)
	{
		for ( int i=0; i<7; i++)
		{
			DateTemp=IncreaseDateByOneDay(DateTemp);
		}
		return DateTemp;
	}
	
	clsDate IncreaseDateByOneWeek()
	{
		return IncreaseDateByOneWeek(*this);
	}
	
	//  Add X weeks to Date
	static clsDate IncreaseDateByXWeeks(clsDate &DateTemp, short XWeeks)
	{
		for ( int i=0; i<XWeeks; i++)
		{
			DateTemp=IncreaseDateByOneWeek(DateTemp);
		}
		return DateTemp;
	}
	
	clsDate IncreaseDateByXWeeks(short XWeeks)
	{
		return IncreaseDateByXWeeks(*this, XWeeks);
	}
	
	//  Add one Month to Date
	static clsDate IncreaseDateByOneMonth(clsDate &DateTemp)
	{
		if ( DateTemp._mon==12 )
		{
			DateTemp._mon=1;
			DateTemp._year++;
		}
		else ++DateTemp._mon;
		
		short CheckDays=NumberOfDaysinMonth(DateTemp._year, (eMonths)DateTemp._mon);
		if ( DateTemp._day > CheckDays )
			DateTemp._day = CheckDays;
			
		return DateTemp;
	}
	
	clsDate IncreaseDateByOneMonth()
	{
		return IncreaseDateByOneMonth(*this);
	}
	
	//  Add X Months to Date
	static clsDate IncreaseDateByXMonths(clsDate &DateTemp, short XMonths)
	{
		for ( int i=0; i<XMonths; i++)
		{
			DateTemp=IncreaseDateByOneMonth(DateTemp);
		}
		return DateTemp;
	}
	
	clsDate IncreaseDateByXMonths(short XMonths)
	{
		return IncreaseDateByXMonths(*this,XMonths) ;
	}
	
	//  Add One Year to Date
	static clsDate IncreaseDateByOneYear(clsDate &DateTemp)
	{
		++DateTemp._year;
		return DateTemp;
	}
	
	clsDate IncreaseDateByOneYear()
	{
		return IncreaseDateByOneYear(*this);
	}
	
	//  Add X Year to Date
	static clsDate IncreaseDateByXYears(clsDate &DateTemp, short XYears)
	{
		for ( int i=0; i<XYears; i++)
		{
			DateTemp=IncreaseDateByOneYear(DateTemp);
		}
		return DateTemp;
	}
	
	clsDate IncreaseDateByXYears(short XYears)
	{
		return IncreaseDateByXYears(*this, XYears) ;
	}
	
	
	//  Add X Year to Date using faster way
	static clsDate IncreaseDateByXYearsFaster(clsDate &DateTemp, short XYears)
	{
		DateTemp._year+=XYears;
		return DateTemp;
	}
	
	clsDate IncreaseDateByXYearsFaster(short XYears)
	{
		return IncreaseDateByXYearsFaster(*this, XYears);
	}
	
	//  Add One decade to Date
	static clsDate IncreaseDateByDecade(clsDate &DateTemp)
	{
		DateTemp._year+=10;
		return DateTemp;
	}
	
	clsDate IncreaseDateByDecade()
	{
		return IncreaseDateByDecade(*this);
	}
	
	//  Add X decade to Date
	static clsDate IncreaseDateByXDecade(clsDate &DateTemp, short XDecade)
	{
		for ( int i=0; i<XDecade; i++)
		{
			DateTemp=IncreaseDateByDecade(DateTemp);
		}
		return DateTemp;
	}
	
	clsDate IncreaseDateByXDecade(short XDecade)
	{
		return IncreaseDateByXDecade(*this, XDecade);
	}
	
	//  Add X decade to Date using faster way
	static clsDate IncreaseDateByXDecadeFaster(clsDate &DateTemp, short XDecade)
	{
		DateTemp._year+=(XDecade*10);
		return DateTemp;
	}
	
    clsDate IncreaseDateByXDecadeFaster( short XDecade)
	{
		return IncreaseDateByXDecadeFaster(*this,XDecade) ;
	}
	
	//  Add One Century to Date
	static clsDate IncreaseDateByCentury(clsDate &DateTemp)
	{
		DateTemp._year+=100;
		return DateTemp;
	}
	
	clsDate IncreaseDateByCentury()
	{
		return IncreaseDateByCentury(*this);
	}
	
	//  Add One Millennium to Date
	static clsDate IncreaseDateByOneMillennium(clsDate &DateTemp)
	{
		DateTemp._year+=1000;
		return DateTemp;
	}
	
	clsDate IncreaseDateByOneMillennium()
	{
		return IncreaseDateByOneMillennium(*this);
	}
	
	
	// get name of day based on order of day
	static string NameOfDay(short OrderOfDayInWeek)
	{
		string days[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
		return days[OrderOfDayInWeek];
	}
	
	string NameOfDay()
	{
 		return NameOfDay(_day);
	}
	
	// Order of day in week
	static short OrderOfDayInWeek(short year, short mon, short day)
	{
		short a=(14-mon)/12;
		short y= year-a;
		short m=(mon+(12*a))-2;
		short d=( day+y+(y/4)-(y/100)+(y/400)+((31*m)/12) )%7;
		return d;
	}
	
	// Overleading function Order of day in week by passing A class clsDate
	static short OrderOfDayInWeek(clsDate date)
	{
		return OrderOfDayInWeek(date._year, date._mon, date._day);
	}
	
	short OrderOfDayInWeek()
	{
		return OrderOfDayInWeek(*this);
	}
	
	
	// Calculate the deffrence between two dates
	static int DeffrenceInDays(clsDate date1, clsDate date2, bool EncludeEndDay=false )
	{
		int DefDays=0;
		short swapFlag=1;
		if ( isDate1AfterDate2(date1, date2) )
		{
			SwapDate(date1, date2);
			swapFlag=-1;
		}
		while ( isDate1BeforDate2(date1, date2) )
		{
			++DefDays;
			date1=IncreaseDateByOneDay(date1);
		}
			return  (EncludeEndDay) ? (++DefDays)*swapFlag : DefDays*swapFlag;
	}
	
	int DeffrenceInDays(clsDate date)
	{
			return DeffrenceInDays(*this, date);
	}


	// Decrease one day from date
	static clsDate DecreaseDatebyOneDay(clsDate &date)
	{
		if ( date._day==1)
		{
			if ( date._mon==1)
			{
				date._day=31;
				date._mon=12;
				date._year--;
			}
			else {
				date._mon--;
				date._day= NumberOfDaysinMonth(date._year, (eMonths)date._mon);
			}
		}
		else date._day--;
	
		return date;
	}
	
	clsDate DecreaseDatebyOneDay()
	{
		return DecreaseDatebyOneDay(*this);
	}
	
	// Decrease X days from date
	static clsDate DecreaseDatebyXDays(clsDate &date, short XDays)
	{
		for ( int i=0; i<XDays; i++)
		{
			date=DecreaseDatebyOneDay(date);
		}
		return date;
	}
	
	clsDate DecreaseDatebyXDays(short XDays)
	{
		return DecreaseDatebyXDays(*this,XDays) ;
	}
		
	
	// Decrease One Week from date
	static clsDate DecreaseDatebyOneWeek(clsDate &date)
	{
		for ( int i=0; i<7; i++)
		{
			date=DecreaseDatebyOneDay(date);
		}
		return date;
	}
	
	clsDate DecreaseDatebyOneWeek()
	{
		return DecreaseDatebyOneWeek(*this);
	}
	
	
	// Decrease X Weeks from date
	static clsDate DecreaseDatebyXWeeks(clsDate &date, short XWeeks)
	{
		for ( int i=0; i<XWeeks; i++)
		{
			date=DecreaseDatebyOneWeek(date);
		}
		return date;
	}
	
	clsDate DecreaseDatebyXWeeks(short XWeeks)
	{
		return DecreaseDatebyXWeeks(*this, XWeeks);
	}
	
	
	// Decrease One Month from date
	static clsDate DecreaseDatebyOneMonth(clsDate &date)
	{
		if ( date._mon==1)
			 {
			 	date._mon=12;
			 	--date._year;
			 }
		else --date._mon;
		
	short DaysInPrvMonth=NumberOfDaysinMonth(date._year, (eMonths) date._mon);
	if ( date._day > DaysInPrvMonth )
		date._day=DaysInPrvMonth;
		
		return date;
	}
	
	clsDate DecreaseDatebyOneMonth()
	{
		return DecreaseDatebyOneMonth(*this);
	}
	
	
	// Decrease X Months from date
	static clsDate DecreaseDatebyXMonths(clsDate &date, short XMonths)
	{
		for ( int i=0; i<XMonths; i++)
		{
			date=DecreaseDatebyOneMonth(date);
		}
		return date;
	}
	
	clsDate DecreaseDatebyXMonths(short XMonths)
	{
		return DecreaseDatebyXMonths(*this, XMonths);
	}
	
	// Decrease One Year from date
	static clsDate DecreaseDatebyOneYear(clsDate &date)
	{
		--date._year;
		return date;
	}
	
	clsDate DecreaseDatebyOneYear()
	{
		return DecreaseDatebyOneYear(*this);
	}
	
	// Decrease X Years from date
	static clsDate DecreaseDatebyXYears(clsDate &date, short XYears)
	{
		for ( int i=0; i<XYears; i++)
		{
			date=DecreaseDatebyOneYear(date);
		}
		return date;
	}
	
	clsDate DecreaseDatebyXYears(short XYears)
	{
		return DecreaseDatebyXYears(*this, XYears);
	}
	
	// Decrease X Years from date faster
	static clsDate DecreaseDatebyXYearsFaster(clsDate &date, short XYears)
	{
		date._year-=XYears;
		return date;
	}
	
	clsDate DecreaseDatebyXYearsFaster(short XYears)
	{
		return DecreaseDatebyXYearsFaster(*this,XYears) ;
	}
	
	// Decrease One Decade from date faster
	static clsDate DecreaseDatebyOneDecade(clsDate &date)
	{
		date._year-=10;
		return date;
	}
	
	clsDate DecreaseDatebyOneDecade()
	{
		return DecreaseDatebyOneDecade(*this);
	}
	
	// Decrease X Decade from date faster
	static clsDate DecreaseDatebyXDecades(clsDate &date, short XDecades)
	{
		for ( int i=0; i<XDecades; i++)
		{
			date=DecreaseDatebyOneDecade(date);
		}
		return date;
	}
	
	clsDate DecreaseDatebyXDecades( short XDecades)
	{
		return DecreaseDatebyXDecades(*this, XDecades);
	}
	
	// Decrease X Decade from date faster
	static clsDate DecreaseDatebyXDecadesFaster(clsDate &date, short XDecades)
	{
		date._year-=(XDecades*10);
		return date;
	}
	
	clsDate DecreaseDatebyXDecadesFaster(short XDecades)
	{
		return DecreaseDatebyXDecadesFaster(*this, XDecades);
	}
	
	// Decrease One Decade from date faster
	static clsDate DecreaseDatebyOneCentury(clsDate &date)
	{
		date._year-=100;
		return date;
	}
	
	clsDate DecreaseDatebyOneCentury()
	{
		return DecreaseDatebyOneCentury(*this);
	}
	
	// Decrease One Millennium from date faster
	static clsDate DecreaseDatebyOneMillennium(clsDate &date)
	{
		date._year-=1000;
		return date;
	}
	
	clsDate DecreaseDatebyOneMillennium()
	{
		return DecreaseDatebyOneMillennium(*this);
	}
	
	// Check day if it is End of week
	static bool isEndOfWeek(clsDate date)
	{
		return ( OrderOfDayInWeek(date) == 6 );
	}
	
	bool isEndOfWeek()
	{
		return isEndOfWeek(*this);
	}
	
	// Check day if it is a weekend
	static bool isWeekend(clsDate date)
	{
		return ( OrderOfDayInWeek(date) == 5 || OrderOfDayInWeek(date) == 6 );
	}
	
	bool isWeekend()
	{
		return isWeekend(*this);
	}
	
	// Check day if it is a business day
	static bool isBusninesDay(clsDate date)
	{
		return !isWeekend(date);
	}
	
	bool isBusninesDay()
	{
		return isBusninesDay(*this);
	}
	
	// How many days left to reach the end of week
	static short DaysUntilTheEndOfWeek(clsDate date)
	{
		return ( 6 - OrderOfDayInWeek(date) );
	}
	
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}
	
	// How many days left to reach the end of month
	static short DaysUntilTheEndOfMonth(clsDate date)                                                                                               
	{
		return ( NumberOfDaysinMonth(date._year, (eMonths)date._mon) - (date._day) + 1);
	}
	
	short DaysUntilTheEndOfMonth()                                                                                               
	{
		return DaysUntilTheEndOfMonth(*this);
	}
	
	// How many days left to reach the end of Year
	static short DaysUntilTheEndOfYear(clsDate date)
	{
		return ( NumberOfDaysinYear(date._year) - (TotalDaysFromBegOfYear(date)) +1 );
	}
	
	short DaysUntilTheEndOfYear( )
	{
		return DaysUntilTheEndOfYear(*this);
	}
	
	// Calculate Actual Vacation Days
	static short ActualVacationDays(clsDate FromDate, clsDate ToDate)
	{
		short ActVacationDays=0;
		while ( isDate1BeforDate2(FromDate,ToDate) )
		{
			if (isBusninesDay(FromDate) )
			{
				ActVacationDays++;
			}
			FromDate=IncreaseDateByOneDay(FromDate);
		}
		return ActVacationDays;
	}
	
	// get Vacation Returned Days
	static clsDate VacationReturnedDays(clsDate FromDate, short VacationDays)
	{
		short count=0;
		
		while ( isWeekend(FromDate) )
		{
			FromDate=IncreaseDateByOneDay(FromDate);
		}
		
		while ( true )
		{
			if ( count < VacationDays )
			{
				if (isBusninesDay(FromDate) )
				{
					count++;
				}
				FromDate=IncreaseDateByOneDay(FromDate);
			}
			else break;
		}
		
		while ( isWeekend(FromDate) )
		{
			FromDate=IncreaseDateByOneDay(FromDate);
		}
		
		return FromDate;
	}
	
	
	
	// Print Calendar Of Month
	static void CalendarOfMonth(short year, short mon)
	{
		string Mon[] = {
	        " ","Jan", "Feb", "Mar", "Apr", "Ma", "Jun",
	        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	    };
	    
	    int DaysOfMon=NumberOfDaysinMonth(year, (eMonths)mon);
	    int curr=OrderOfDayInWeek(year,mon,1);
	    
	    cout<<" ____________"<<Mon[mon]<<"_____________"<<endl;                                               
		cout<<"\n Sun "<<"Mon "<<"Tue "<<"Wed "<<"Thu "<<"Fri "<<"Sat"<<endl;
		
		short i;
		for ( i=0; i<curr; i++)
				cout<<"    ";
		for ( short day=1; day<=DaysOfMon; day++)
		{
					cout<<setw(4)<<day;
					if ( ++i==7) 
					{
						i=0;
						cout<<endl;
					}
		}
		cout<<"\n ____________________________"<<endl;
		cout<<endl<<endl;
	}
	
	void CalendarOfMonth()
	{
		CalendarOfMonth(_year, _mon);
	}
	
	// print Calendar Of  year
	static void CalendarOfYear(short year)
	{
		string Mon[] = {
	        " ","Jan", "Feb", "Mar", "Apr", "Ma", "Jun",
	        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	    };
	    cout<<"\n____________________________\n"<<endl;
	    cout<<"       Calendar - "<<year<<endl;
	    cout<<"____________________________\n"<<endl;
	    
		for ( short mon=1; mon<=12; mon++)
		{
			 CalendarOfMonth(year,mon);
		}
	}
	
	 void print()
	{
		cout<<"  "<<_day<<"/"<<_mon<<"/"<<_year<<endl;                          
	}
	
};

