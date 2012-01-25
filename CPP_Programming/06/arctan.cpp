/* arctan.cpp: this program calculates the arctan of a number to 9 decimal places 
*  Authors: Colm Nolan 
*  Last modified: 19/03/11 ***/

#include <iostream>
#include <cmath>
using namespace std;

double arctan_calculation(double number);
int const DENOMINATOR_LIMIT = 1500000003;

int main ()
{
	double user_entry = 0;
	double answer = 0;
	cout<<"Please enter a number and it's arctan will be calculated to 9 decimal places"<<endl;
	cin>>user_entry;
	answer = arctan_calculation(user_entry);
	cout.precision(10);

	cout<<"The arctan of "<<user_entry<<" is "<<answer<<endl;
	
    	return 0;
}

double arctan_calculation(double number)	//this function represents the formula "arctan(x) = x - (x^3)/3 + (x^5)/5 - (x^7)/7 +..."
{
	double arctan_answer;			//corresponds to "artan(x)"
	double denominator = 1;
	arctan_answer = number;
	double numerator = 0;
	numerator = number;			//corresponds to "x"	
	double fraction = 0;

	while(denominator <= DENOMINATOR_LIMIT)			//this while loop will keep going until the DENOMINATOR_LIMIT is reached
	{
		numerator = numerator * number * number;	
		denominator = denominator + 2;
		fraction = numerator / denominator;		//the 3 lines coresponds to "(x^3)/3"
		arctan_answer = arctan_answer - fraction;	//corresponds to the minus in " x - (x^3)/3"

		numerator = numerator * number * number;
		denominator = denominator + 2;
		fraction = numerator / denominator;		//this line and the above 2 lines corespond to "(x^5)/5"
		arctan_answer = arctan_answer + fraction;	//this line corresponds to the plus in "(x^3)/3 + (x^5)/5"

	}
	return arctan_answer;
}

// the following is a less efficient function that was written before the above one
// it represents the "pie = 4 artan(1.0)" formula in a much more lotteral sense
//
//double arctan_calculation(double number)
//{
//	double arctan_answer;
//	double factor = 3;
//	double power = 0;
//
//	arctan_answer = number;
//
//	while(factor <= DENOMINATOR_LIMIT)
//	{
//		power = pow(number,factor);
//		arctan_answer = arctan_answer - (power/factor);
//		factor = factor + 2;
//
//		power = pow(number,factor);
//		arctan_answer = arctan_answer + (power/factor);
//		factor = factor + 2;
//	}
//	return arctan_answer;
//}

