/* pi2.cpp: this program calculates pi using a more efficient formula 
*  Authors: Colm Nolan 
*  Last modified: 18/03/11 ***/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double arctan_calculation(double number);
double pi_calc();

int const DENOMINATOR_MAX = 23;

int main ()
{
	double answer = 0;
	cout<<"PI is to 14 decimal places: ";
	answer = pi_calc();                     /* no parameters are needed since we know all the details that required to calculate pi */
	cout.precision(16);

	cout<<answer<<endl;
	
    	return 0;
}


double pi_calc()		//this function represents the formula "pi = 4 * (4arctan(1/5) - arctan(1/239))  
{
	double numerator_1 = 1;
	double denominator_1 = 239;
	double denominator_2 = 5; 
	double answer = 0;
	double x = 0; 
	double y = 0; 
	double z = numerator_1/denominator_2; 
	double k = 0; 
	k = numerator_1/denominator_1; 
	//cout<<"test"<<k<<"test";

	//cout<<setprecision(10)<<k<<endl;
	//cout<<z<<endl;
	

	x = 4 * (arctan_calculation(z));
	y = arctan_calculation(k);
	answer = (x - y) * 4;

	return answer; 

}

double arctan_calculation(double number)//this function represents the formula "arctan(x) = x - (x^3)/3 + (x^5)/5 - (x^7)/7 +..."
{
	double arctan_answer;
	double denominator = 1;
	arctan_answer = number;
	double numerator = 0;
	numerator = number;
	double fraction = 0;

	while(denominator <= DENOMINATOR_MAX)
	{
		numerator = numerator * number * number;
		denominator = denominator + 2;
		fraction = numerator / denominator;
		arctan_answer = arctan_answer - fraction;

		numerator = numerator * number * number;
		denominator = denominator + 2;
		fraction = numerator / denominator;
		arctan_answer = arctan_answer + fraction;

	}
	return arctan_answer;
}
/*
double arctan_calculation(double number)
{
	double arctan_answer;
	double factor = 3;
	double power = 0;

	arctan_answer = number;

	while(factor <= DENOMINATOR_MAX)
	{
		power = pow(number,factor);
		arctan_answer = arctan_answer - (power/factor);
		factor = factor + 2; 

		power = pow(number,factor);//need to make this more efficient
		arctan_answer = arctan_answer + (power/factor);
		factor = factor + 2;
	}
	return arctan_answer;
}*/
