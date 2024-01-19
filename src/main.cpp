#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>
#include "../include/Screens/User/clsBankLogin.h"
using namespace std;
	
	
	
int main()
{
	while ( true )
	{
		if ( !clsBankLogin::Login() )
		{
			break;
		}
	}

	
	return 0;
}
