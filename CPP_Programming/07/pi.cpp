/* pi.cpp: This program will calculate the value of PI (very slowley)
*  Authors: Colm Nolan 
*  Last modified: 18/03/11 ***/

#include <iostream>
#include <cmath>
using namespace std;

double arctan_calculation(double number, char q_answer);
double pi_calc(char q_answer);

int const DENOMINATOR_MAX = 1500000003;//this sets the maximum size the denominator can be

int main()
{
	double answer = 0;
	char question_answer = ' ';
	cout<<"If you want to view the calculations at each \nitteration enter y and if not enter n"<<endl;
	cin>>question_answer;
	answer = pi_calc(question_answer);
	cout<<"PI is: ";
	cout.precision(10);
	cout<<answer<<endl;
	
    	return 0;
}

double pi_calc(char q_answer)
{
	double arctan_of_1 = arctan_calculation(1,q_answer);
	return 4 * (arctan_of_1);			//this will return the value of pi
}

double arctan_calculation(double number,char q_answer) 	//this is the same funtion as used in the program portfolio number 6
							//except with extra parameter q_answer to see if the user wants print out the itterations during the calculations
							
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

		if(q_answer == 'y')
		{
			cout.precision(10);
			cout<<arctan_answer<<endl;
		}

	}
	return arctan_answer;
}
/* less efficient funtion
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
}
*/
