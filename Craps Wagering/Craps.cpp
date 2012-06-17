/*	Craps.cpp: This program simulates a game of craps with wagering
*  	Authors: Colm Nolan
*  	Last modified: 28/03/11
***/
#include <iostream>
#include <iomanip>
#include <cstdlib> // needed for functions srand() and rand()
#include <ctime> // needed for function time()


using namespace std;

enum Status {CONTINUE, WON, LOST};

int rollDice(int diceVals[], int numberToRoll=2); /* this function return a random number between 1 and 12(the sum of two dice rolled)*/
void one_game_of_craps();                       /* seperate funtion for each game of craps */
void print_characters(int no_to_print, char character) /* print fomratted line of characters */
void print_newlines();                          /* print new lines */
void format_title_text();                       /* format text to be printed */

const int TOTAL_BANK_ROLL = 1000;

int main()
{
	format_title_text();
	cout<<"CRAPS";
	format_title_text();
	cout<<"NEW GAME";
	print_characters(80,'_');

	char reply = 'y';

	cout<<"\nDo you want to start a new game of Craps"<<endl;  
	cout<<"Enter y to play a game or n to exit"<<endl;  
	cin>>reply;
	while(reply == 'y')                     /* this loop will control the initiation of each game */
	{
		one_game_of_craps();            /* this call starts the first game of Craps */
		format_title_text();
		cout<<"CRAPS";
		format_title_text();
		cout<<"NEW GAME";
		print_characters(80,'_');
		cout<<"Do you want to start a new game of Craps"<<endl;  
		cout<<"Enter y to play a game or n to exit"<<endl;  
		cin>>reply;
	} 
	return 0;
}

void format_title_text()/* format text to be printed */
{
	cout.setf(ios::right | ios::adjustfield);
	cout.fill('_');
	cout.width(40);
}

int rollDice(int diceVals[], int numberToRoll) /* this function return a random number between 1 and 12(the sum of two dice rolled)*/
{
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

void one_game_of_craps()                       /* seperate funtion for each game of craps */
{
		char cash_in = 'y';
		char newline = ' ';
		int sum;
		int myPoint;
		int diceVals[2];
		int bankBalance = TOTAL_BANK_ROLL;
		int wager = 0;
		int round_no = 1;
		float calculation = 0.0;

		Status gameStatus;                            /* can either be CONTINUE = 0, WON = 1, LOST = 2, other = -1 */
		srand(time(0));

	do
	{                                       /* this loop controls each deal in the game */
		format_title_text();
		cout<<"ROUND";
		format_title_text();
		cout<<round_no<<endl;
		format_title_text();
		cout<<"BANK BALANCE";
		format_title_text();
		cout<<bankBalance<<endl;
		newline = ' ';

		cout<<"How much do you want to bet that you will win this round?"<<endl;
		do 
		{
			cin>>wager;             /* inputting the wager from the player */
			cin.get(newline);

			if(wager == bankBalance)
			{
				cout<<"Oh, you are going for broke now, Best of luck"<<endl;
				cout<<"Press, Enter to continue"<<endl;
				cin.get(newline);
			}

			if(wager < 0 || wager > bankBalance)
				cout<<"You enter an impossible wager, please try again"<<endl;
			
		} while (wager < 0 || wager > bankBalance); /* this condition ensures that the player is entereing valid ammounts */

		calculation = bankBalance/100;
		if(wager < calculation)         /* this condition comes into effect when the player enteres a very small amount */
		{
			cout<<"Ah c'mon, take a chance!"<<endl;
			cout<<"Enter, more than that if your feeling lucky"<<endl;
			cin>>wager;
			cin.get(newline);
		}

			

		sum = rollDice(diceVals);

		cout << "Player rolled " << diceVals[0] << " + " << diceVals[1] << endl; /* tell the user what he/she rolled */

		switch(sum)                     /* use switch statment check players roll */
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
			cout << "Point is " << myPoint << endl;
			break;
		}

		while (gameStatus == CONTINUE)  /* keep looping while gameStatus == CONTINUE */
		{
			sum = rollDice(diceVals);
			cout << "Player rolled " << diceVals[0] << " + " << diceVals[1] << endl;
			if (sum==myPoint)
			gameStatus=WON;
			else
			if (sum==7)
				gameStatus = LOST;
		}
		if (gameStatus == WON)
		{
			cout << "Player wins" << endl;
			bankBalance = bankBalance + wager;
			cout<<"Well done you now have: "<<bankBalance<<endl;
		}
		
		else
		{
			cout << "Player loses" << endl; 
			bankBalance = bankBalance - wager;
			cout<<"Sorry, You lost so you now have: "<<bankBalance<<endl;
		}

		calculation = 3 * TOTAL_BANK_ROLL;
		if (bankBalance > calculation)  /* if the player is winning well this condition will kick in */
		{
			cout<<"Your really on a winning streak here, maybe its time to cash in"<<endl;
		}

		if (bankBalance > 0)
		{
			cout<<"Do, you want to keep going? Enter 'y' to keep playing or 'n' to stop "<<endl;
			cin.get(cash_in);
			cin.get(newline);
		}
		if (bankBalance <= 0)           /* if the player has no money left give him/her a notification */
		{
			cout<<"Sorry you lost, Press return to leave this game before you end up owing us money!!!"<<endl;
			cin.get(newline);
		}
		cout<<endl<<endl;
		round_no++;
	}while (bankBalance > 0 && cash_in == 'y'); /* keep looping as long as the player wants to play */
	print_newlines();

}

void print_newlines() /* print new lines */ 
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}

void print_characters(int no_to_print, char character)/* print fomratted line of characters */
{
  	for(int j=1; j <= no_to_print; j++)
	{	
		cout<<character;
	}
	cout<<endl;
}


