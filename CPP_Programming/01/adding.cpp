/* adding.cpp: This program adds and subtracts two numbers *  
 * Authors: Colm Nolan
*  Last modified: 01/03/11
***/
#include <iostream>
using namespace std;

int main ()
{
	int number1 = 0;
	int number2 = 0;
	int numbers_total = 0;
	int numbers_subtraction = 0;
	
	cout<<"Enter the first number"<<endl;
	cin>>number1;
	
	cout<<"Enter the second number"<<endl;
	cin>>number2;
	
	numbers_total = number1 + number2;
	cout << "The first number plus the second number is: "<<numbers_total<<endl;

	numbers_subtraction = number1 - number2;
	cout << "The first number minus the second number is: "<<numbers_subtraction<<endl;

	
	return 0;
}
