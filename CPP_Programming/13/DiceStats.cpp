/*	DiceStats.cpp: this program inputs the number of dices to roll and the number of times to roll the dices
 *	This program then takes those two inputs and generates random numbers for that criteria.
 *	The results are output to the screen along with the mean and the standard deviation
*  	Authors: Colm Nolan
*  	Last modified: 28/03/11
***/
#include <iostream>
#include <iomanip>
#include <cstdlib> // needed for functions srand() and rand()
#include <ctime> // needed for function time()
#include <cmath> // needed for sqrt()

using namespace std;

const int MAXNUMTOROLL=10;
const int MAXROLLS=100;

// Prototypes of Functions to Implement:
// You MUST use these exact definitions, rather than writing your own

// output the values of the dice that are rolled in the array diceVals and return
// the sum of the values rolled

// rollDice returns the values of the dice that were rolled in the array diceVals[]
// It also returns the sum of the values rolled in its return value
int rollDice(int diceVals[], int numberToRoll=2);

// computeStats takes an array of roll sums as input, along with the total number
// of rolls carried out.  In the two output parameters, mean and std, it returns the mean
// and standard deviation of the set of roll sums
void computeStats(int rollSums[], int numRolls, double &mean, double &std);

// writeStats, takes an input parameter rollSums, which is a 2-dimensional array, 
// consisting of the roll sums for a rolling numToRoll dice a total of numRolls times. 
// It also takes input parameters mean[] and std[] - arrays of the means and standard deviations
// of the roll sums.
// It prints these values to the screen in the tabular form specified in the problem description
void writeStats(int rollSums[][MAXROLLS], double mean[], double std[], int numRolls, int numToRoll);

void text_formating();                          /* this funtion will format the text before cout*/
void set_diceVals_to_zero(int diceVals[]);      /* ensures the values that are send into the rollDice are set to zeore */
void print_characters(int numToRoll, char character); /* used for printing a certain number of characters in a certain format*/

int main()
{

  srand(time(0));                               /* this will seed the random number based on the current time */
  int sum;
  int rollSums[MAXNUMTOROLL][MAXROLLS];
  int diceVals[MAXROLLS];
  double mean[MAXNUMTOROLL], std[MAXNUMTOROLL];
  int numToRoll, numRolls;

  // STEP 1: Ask user to input the maximum number of dice to use:

  cout << "Please enter the maximum number of dice to use:" << endl;
  do 
    {
      cin >> numToRoll;                         /* numToRoll is the number of die to use */
    } while (numToRoll < 0 || numToRoll > MAXNUMTOROLL); 

  cout << "Please enter the number of rolls:" << endl;

  // STEP 2: Ask user to input the number of rolls to carry out:
  do
    {
      cin >> numRolls;                          /* numRolls is the number of times the dice will be rolled */
    } while (numRolls < 0 || numRolls > MAXROLLS);

  // STEP 3: For k=1 to numToRoll, simulated numRolls rolls of the dice
  // and store the sum of the numbers rolled in the array rollSums[][]

  for (int k=1;k<=numToRoll;k++)                /* loop until we have reached to total number of die to roll */
    {
      for (int i=0;i<numRolls;i++)              /* loop until we have reached the number of times we want roll the die */
	{
	  rollSums[k-1][i] = rollDice(diceVals, k);
	}
      cout<<endl;
    }

  // STEP 4: Compute the mean and standard deviation of the roll sums

  for (int i=1;i<=numToRoll;i++)
    computeStats(&rollSums[i-1][0], numRolls, mean[i-1], std[i-1]);

  // STEP 5: Write out the table of roll sums along with the mean and standard
  // deviation

  writeStats(&rollSums[0], mean, std, numRolls, numToRoll);

}


void set_diceVals_to_zero(int diceVals[])
{
  for (int z=0;z<100;z++)
  {
	  diceVals[z] = 0;
  }
}

int rollDice(int diceVals[], int numberToRoll)  /* this funtions return the sum of n number of dice rolls */ 
{
  	set_diceVals_to_zero(diceVals);
	int sum_of_total_rolls = 0;
	//srand(time(0));
	for(int i = 0; i < numberToRoll; i++)   /* this will loop through the diceVals array assigning random numbers beteeen 1 and 6
						   to its members. the total sum of the rolls will also be kept track of in the variable
						   sum_of_total_rolls*/
	{
		diceVals[i] =	(1 + rand() % 6);
		//cout<<diceVals[i]<<":";
		sum_of_total_rolls = sum_of_total_rolls + diceVals[i];
		//cout<<sum_of_total_rolls<<endl;
	}

	return sum_of_total_rolls;
}

void computeStats(int rollSums[], int numRolls, double &mean, double &std) /* this function calculates the mean and the standard deviation */
{
	double total_of_array = 0;
	for(int i = 0; i < numRolls; i++)
	{
		total_of_array = total_of_array + rollSums[i];
	}
	mean = total_of_array/numRolls;

	double sum_of_deviations = 0;
	double list_of_deviations[numRolls];

	for(int i = 0; i < numRolls; i++)
	{
		list_of_deviations[i] = mean - rollSums[i];
		list_of_deviations[i] = pow(list_of_deviations[i],2);
		sum_of_deviations = sum_of_deviations + list_of_deviations[i];
	}
	std = sqrt((sum_of_deviations/(numRolls - 1)));
}


void writeStats(int rollSums[][MAXROLLS], double mean[], double std[], int numRolls, int numToRoll) /* this function prints the stats to the screen */
{
	print_characters(numToRoll,'D');
	print_characters(numToRoll,'I');
	print_characters(numToRoll,'C');
	print_characters(numToRoll,'E');
	print_characters(numToRoll,'-');
	
	for(int j=1; j <= numToRoll; j++)
	{	
		text_formating();
		cout<<j;
	}
	cout<<endl;

	print_characters(numToRoll,'-');

	for (int k=0; k < numRolls;k++)
	{
		for (int i=0; i < numToRoll;i++)
		{
			text_formating();
			cout<<rollSums[i][k];
		}
		cout<<endl;
    	}

	print_characters(numToRoll,'-');

	for(int i = 0; i <numToRoll; i++)
	{
		text_formating();
		cout<<mean[i];
	}

	text_formating();
	cout<<"Mean\n";
	text_formating();
	for(int i = 0; i < numToRoll; i++)
	{
		text_formating();
		cout<<std[i];
	}
	text_formating();
	cout<<"STD\n";
	print_characters(numToRoll,'-');
}

void print_characters(int numToRoll, char character)
{
  	for(int j=1; j <= (numToRoll); j++)
	{	
		text_formating();
		cout<<character;
	}
	cout<<endl;
}

void text_formating()                           /* formats the text */
{
	cout.width(6);
	cout.precision(3);
	cout.setf(ios::showpoint);
	cout.setf(ios::right | ios::adjustfield);
}
 
