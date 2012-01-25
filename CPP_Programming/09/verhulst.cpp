/* verhulst.cpp: This program uses four funtions to implement the verhulst population equation
*  Authors: Colm Nolan
*  Last modified: 21/03/11
***/

#include <iostream>
#include <vector>
using namespace std;

void method_1(const double rate, vector<double>& results_1,  double population); /* prototype for for implementations of verhulst equation */
void method_2(const double rate,  vector<double>& results_2,  double population);
void method_3(const double rate,  vector<double>& results_3,  double population);
void method_4(const double rate,  vector<double>& results_4,  double population);

int main ()
{
	double rate = 1.83;
	double population = 0.27;

    	vector<double> results_1(10, 0);        /* declaring vector array of size 10 with values set at 0 */
    	vector<double> results_2(10, 0);
    	vector<double> results_3(10, 0);
    	vector<double> results_4(10, 0);

	//cout<<"Enter the rate of population growth: "<<endl;
	//cin>>rate;
	//
	//cout<<"Enter the starting population: "<<endl;
	//cin>>population;
	method_1(rate,results_1,population);
	method_2(rate,results_2,population);
	method_3(rate,results_3,population);
	method_4(rate,results_4,population);
	
	cout<<fixed<<"Result 1\t\tResult 2\t\tResult 3\t\tResult 4"<<endl;
	for(int i = 0; i < 10; i++)
	{
		cout<<fixed<<results_1[i]<<"\t\t"<<results_2[i]<<"\t\t"<<results_3[i]<<"\t\t"<<results_4[i]<<endl;
	}


    	return 0;
}

void method_1(const double rate, vector<double>& results_1,  double population)
{
	int j = 0;
	double increment = 1;
	for(int i = 1; i <= 100; i++)
	{
		population = ((rate + increment) * population - rate * (population * population));
		if ( i%10 == 0)                 /* every tenth calculation will be assigned to an element in the array */
		{
			results_1[j] = population;
			//cout<<results_1[j];
			j++;
		}
	}
	cout<<endl<<endl;

}

void method_2(const double rate, vector<double>& results_2,  double population)
{
	int j = 0;
	for(int i = 1; i <= 100; i++)
	{
		population = (rate + 1) * population - (rate * population) * population;
		//cout<<population<<"   ";
		if ( i%10 == 0)
		{
			results_2[j] = population;
			//cout<<results_2[j];
			j++;
		}
	}
	cout<<endl<<endl;
}

void method_3(const double rate, vector<double>& results_3,  double population)
{
	int j = 0;
	for(int i = 1; i <= 100; i++)
	{
		population = ((rate + 1) - (rate * population)) * population;
		//cout<<population<<"   ";
		if ( i%10 == 0)
		{
			results_3[j] = population;
			//cout<<results_3[j];
			j++;
		}
	}
	cout<<endl<<endl;
}

void method_4(const double rate, vector<double>& results_4,  double population)
{
	int j = 0;
	//cout<<population<<endl;
	for(int i = 1; i <= 100; i++)
	{
		population = population + rate * (population - population * population);
		//cout<<population<<"   ";
		if ( i%10 == 0)
		{
			results_4[j] = population;
			//cout<<results_4[j];
			j++;
		}
	}
	cout<<endl<<endl;
}

