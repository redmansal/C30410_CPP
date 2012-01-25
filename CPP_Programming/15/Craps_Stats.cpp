/*	Craps_Stats.cpp: this programs run 1000 games of craps and records the results of each game. Statistics are then 
 *	printed out relating to the 1000 game.
*  	Authors: Colm Nolan
*  	Last modified: 28/03/11
***/
#include <iostream>
#include <iomanip>
#include <cstdlib> // needed for functions srand() and rand()
#include <ctime> // needed for function time()
#include <vector>


using namespace std;


enum Status {CONTINUE, WON, LOST};

struct game_record{                             /* this struct will be used to record each game
						   it will store how many turns each game took and also if the player won or lost*/
	int no_of_turns;
	Status win_or_loose;
};

const int NO_OF_GAMES_PLAYED = 1000;

typedef struct game_record game;

int rollDice(int diceVals[], int numberToRoll=2);
                                                /* generates a number between between 1 and 12 using to dice */
void calculating_statistics(game *array_results_of_games, int array_size, vector<int>& won_array, vector<int>& lost_array, int largest_no_of_rolls_for_a_game);
                                                /* this funtion copies info from array_results_of_games into won_array and lost_array */
void one_game_of_craps(game *array_results_of_games, int& array_index_for_game_record, int& largest_no_of_rolls_for_a_game);
                                                /* this runs the game of craps, records its results and finds the game that had the largest amount of turns */
void print_out_stats(const vector<int>& won_array, const vector<int>& lost_array, const int largest_no_of_rolls_for_a_game);
                                                /* prints out the stats for how many game won on 1st roll etc. */
void chances_of_winning(const vector<int>& won_array, const int largest_no_of_rolls_for_a_game, const int total_games_played);
                                                /* calculates the chances of winning at craps */
void average_length_of_the_game(game *array_results_of_games, int array_size);
                                                /* calculates the average number of turns each game takes */
void improoving_winnig_chance(const vector<int>& won_array, const vector<int>& lost_array, const int array_size);
                                                /* shows how the chances of winning throughout the game changes */
void text_formating();
                                                /* formats the text prior to print out */
void print_characters(int times_to_print, char character);
                                                /* prints out the characters */


int main()
{
	srand(time(0));                         /* sedding the ramdom number funtion with the current time */
	int largest_no_of_rolls_for_a_game = 1; /* this will store the number of turns it took for whichever game had the largest amount of 						      turns.  This will then be used to decide the size of the won_array and the lost_array */
	game *array_results_of_games = new game[NO_OF_GAMES_PLAYED];
                                                /* declaring an array of game structs of size NO_OF_GAMES_PLAYED */
	int array_index_for_game_record = 0;    /* declaring the first elemement of the array_results_of_games
						   this variable will be used to keep track of each element in the array_results_of_games
						   array*/
	cout<<"Statistics from "<<NO_OF_GAMES_PLAYED<<" games of Craps"<<endl<<endl;

	for(int i=0 ;i < NO_OF_GAMES_PLAYED; i++)
	{
		one_game_of_craps(array_results_of_games, array_index_for_game_record, largest_no_of_rolls_for_a_game);                    
                                                /* calling funtion one_game_of_craps and sending in ferences to array_results_of_games, 
						 * array_index_for_game_record and largest_no_of_rolls_for_a_game */
	}

	vector<int> won_array(largest_no_of_rolls_for_a_game, 0); /* after playing the game 1000 time, recording the results and also we 
								     know the game that had the most turns, we can make an array 
								     the right size to hold how many games are won on the 1st roll
								     , 2nd roll, etc. */
	vector<int> lost_array(largest_no_of_rolls_for_a_game, 0); /* As for won_array we can do the same with lost_array */
	
	calculating_statistics(array_results_of_games, NO_OF_GAMES_PLAYED, won_array, lost_array, largest_no_of_rolls_for_a_game);

	print_out_stats(won_array, lost_array, largest_no_of_rolls_for_a_game);

	chances_of_winning(won_array, largest_no_of_rolls_for_a_game, NO_OF_GAMES_PLAYED);
	
	average_length_of_the_game(array_results_of_games, NO_OF_GAMES_PLAYED);

	improoving_winnig_chance(won_array, lost_array, largest_no_of_rolls_for_a_game);

	delete [] array_results_of_games;
	return 0;
}

int rollDice(int diceVals[], int numberToRoll)  /* this funtions return the sum of n number of dice rolls */ 
{
	//set_diceVals_to_zero(diceVals);
	int sum_of_total_rolls = 0;
	//srand(time(0));
	for(int i = 0; i < numberToRoll; i++)
	{
		diceVals[i] =	(1 + rand() % 6);
		//cout<<diceVals[i]<<":";
		sum_of_total_rolls = sum_of_total_rolls + diceVals[i];
		//cout<<sum_of_total_rolls<<endl;
	}

	return sum_of_total_rolls;
}

void one_game_of_craps(game *array_results_of_games, int& array_index_for_game_record, int& largest_no_of_rolls_for_a_game)
{
	int sum;
	int myPoint;
	int diceVals[2];
	int no_of_turns = 0;

	Status gameStatus;
	//srand(time(0));

	sum = rollDice(diceVals);
	no_of_turns++;

	//cout << "Player rolled " << diceVals[0] << " + " << diceVals[1] << endl;


	switch(sum)
	{
		case 7:
		case 11:
		gameStatus = WON;
		break;
		case 2:
		case 3:
		case 12:
		gameStatus = LOST;
		break;
		default:
		gameStatus = CONTINUE;
		myPoint = sum;
		//cout << "Point is " << myPoint << endl;
		break;
	}

	while (gameStatus == CONTINUE)
	{
		sum = rollDice(diceVals);
		no_of_turns++;
		//cout << "Player rolled " << diceVals[0] << " + " << diceVals[1] << endl;
		if (sum==myPoint)
			gameStatus=WON;
		else
		if (sum==7)
			gameStatus = LOST;
		
	}
	if (gameStatus == WON)
		;
		//cout << "Player wins" << endl;
	else
		;
		//cout << "Player loses" << endl;
	//cout<<no_of_turns<<endl;

	array_results_of_games[array_index_for_game_record].no_of_turns = no_of_turns;
	if(gameStatus == WON)
		array_results_of_games[array_index_for_game_record].win_or_loose = WON;
	else
		array_results_of_games[array_index_for_game_record].win_or_loose = LOST;

	array_index_for_game_record++;
	if (no_of_turns > largest_no_of_rolls_for_a_game)
			largest_no_of_rolls_for_a_game = no_of_turns;

}

void calculating_statistics(game *array_results_of_games, int array_size, vector<int>& won_array, vector<int>& lost_array, int largest_no_of_rolls_for_a_game)
{
	for(int i = 0; i < array_size; i++)     /* itterate through array_results_of_games pull out the results we want
						   and assign them to won_array and lost_array*/
	{
		for(int j = 0; j < largest_no_of_rolls_for_a_game; j++)
		{
			if(array_results_of_games[i].no_of_turns == (j + 1) && array_results_of_games[i].win_or_loose== WON)
				won_array[j]++;
			if(array_results_of_games[i].no_of_turns == (j + 1) && array_results_of_games[i].win_or_loose == LOST)
				lost_array[j]++;
		}
	}
}


void print_out_stats(const vector<int>& won_array, const vector<int>& lost_array, const int largest_no_of_rolls_for_a_game)
{		
	                                        /* print out the stats in a certain format */
	text_formating();
	cout<<"Roll No";
	text_formating();
	cout<<"Games Won";
	text_formating();
	cout<<"Games Lost"<<endl;
	print_characters(3, '-');
	for(int i = 0; i < largest_no_of_rolls_for_a_game; i++)
	{
		text_formating();
		cout<<i+1;
		text_formating();
		cout<<won_array[i];
		text_formating();
		cout<<lost_array[i]<<endl;
	}
}


void chances_of_winning(const vector<int>& won_array, const int largest_no_of_rolls_for_a_game, const int total_games_played)
{
	double winning_chance = 0;
	double winning_sum = 0;

	for(int i = 0; i < largest_no_of_rolls_for_a_game; i++) /* loop through won_array and add up it's members to find how many times games were won */
		winning_sum = won_array[i] + winning_sum;

	winning_chance = winning_sum/total_games_played; /* calculate winning chance here */
	winning_chance = winning_chance * 100;
	cout<<endl<<"You have a "<<winning_chance<<" % chance of winning."<<endl;
}
		
void average_length_of_the_game(game *array_results_of_games, int array_size)
{
	double total_turns = 0;
	double average_turns = 0;
	for(int i = 0; i < array_size; i++)
		total_turns = array_results_of_games[i].no_of_turns + total_turns;
	average_turns = total_turns / array_size; /* calculate average number of turns here */

	cout<<endl<<"A game takes an average of "<<average_turns<<" rolls to complete."<<endl<<endl;
}


void improoving_winnig_chance(const vector<int>& won_array, const vector<int>& lost_array, const int array_size)
{
	double total_rolls = 0;
	double winning_chance = 0;
	double one_hundred = 100;

	
	cout<<"No.Rolls     Winning_chance"<<endl;
	for(int i = 0; i < array_size; i++)
	{
		
		total_rolls = won_array[i] + lost_array[i];
		winning_chance = won_array[i]/total_rolls;
		winning_chance = winning_chance * 100;
		cout<<total_rolls<<"\t";

		cout<<setw(5)<<"  "<<winning_chance;
		for(int j = 0; winning_chance > 0; j++) /* use for loop to print out trends in the winning chance */
		{
			winning_chance = winning_chance - 2.5; /* this subtraction will control the number of pluses that are
								  printied out. The pluses will add a visula element to the winning
								  chance figures*/
			cout<<"+";
		}
		cout<<endl;
		

	}
	cout<<"As can be seen from the histogram above the chance of winning decrease as the game goes on"<<endl;
	cout<<"Also please note that the later results in the chart are not reliable statistics because there is so few"<<endl;
}

void text_formating()
{
	cout.width(15);
	cout.precision(3);
	cout.setf(ios::showpoint);
	cout.setf(ios::right | ios::adjustfield);
}

void print_characters(int times_to_print, char character)
{
  	for(int j=1; j <= (times_to_print); j++)
	{	
		text_formating();
		cout<<character;
	}
	cout<<endl;
}
