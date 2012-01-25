/* hanoi.cpp: this program allows the user to play the game tower of hanoi and also give the solution non recursivly(well its supposed to anyway!)
 * algorithim to solve is basically in steps
 * A: move the first disk from the sourse to the destination if the number of disks is odd
 * B: otherwise move it to the intermdiate peg
 * C: for the rest of the moves perform moves C and D for the rest 
 *    move the second smallest disk to its destination
 * D: move the smallest disk to the peg that it did not come from in its last move
 * The letters below match the parts of the olgorytim
*  Authors: Colm Nolan
*  Last modified: 21/03/11
***/

#include <iostream>
using namespace std;

char no_1_previous_location = 'x';

class hanoi
{
	int left[4];
	int middle[4];
	int right[4];
	public:
	hanoi ();
	void print_board();
	void make_move(char peg_select, char peg_destination);
	void move_logic(int select_array[], int destination_array[]);
	void clear_screen();
	void give_solution();                   /* A,B */
	bool game_completed();
	bool check_array_source(int source[], int& source_disk) /* C */
	bool check_array_destination(int destination[], int& source_disk); /* C */
	void take_note_of_no1_disk_location();/* D */
	bool check_array_source_d(int source[]);/* C */
	bool check_array_destination_d(int destination[], char check_1);/* C */

};

hanoi::hanoi()
{	
	int j = 4;
	for(int i = 0; i < 4; i++)
	{
		left[i] = j;
		middle[i] = 0;
		right[i] = 0;
		j--;
	}
}


void clear_screen()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void hanoi::print_board()
{
	for(int i = 3; i >= 0; i--)
	{
		cout<<endl;
		cout<<left[i]<<" ";
		cout<<middle[i]<<" ";
		cout<<right[i]<<endl;
		
	}
	cout<<"L "<<"M "<<"R"<<endl<<endl;
}

void hanoi::give_solution()

{
	char left_check = 'l';
	char middle_check = 'm';
	char right_check = 'r';
	
	if (2% left[0] == 1)
	{
		move_logic(left,right);
	}
	else
		move_logic(left,middle);
	while(game_completed() != true)
	{
		int source_disk = 100;
		if (((check_array_source(left, source_disk)) == true) && (check_array_destination(right, source_disk)) == true) /* C */
		{
			move_logic(left,right);
			print_board();
		}

		if(game_completed() == true)
			break;

		if((check_array_source_d(middle) == true) && (check_array_destination_d(right, right_check) == true))
			move_logic(middle, right);

			//fill in rest later		

	}
}
bool hanoi::check_array_source_d(int source[])
{
	int i = 3;
	int disk_number = 0;

	while((disk_number == 0) && (i >= 0))
	{
		if(source[i] > 0)
		{
			disk_number = source[i];
		}
		i--;
	}

	if(disk_number == 1)
		return true;
	else return false;
}

bool hanoi::check_array_destination_d(int destination[], char check_1)
{
	if (no_1_previous_location != check_1)
		return true;
	else return false;

}

bool hanoi::check_array_source(int source[], int& source_disk)
{
	int i = 3;
	int disk_number = 0;
	source_disk = disk_number;

	while((disk_number == 0) && (i >= 0))
	{
		if(source[i] > 0)
		{
			disk_number = source[i];
		}
		i--;
	}
	if (disk_number > 1)
		return true;
	else return false;
}
bool hanoi::check_array_destination(int destination[], int& source_disk)
{
	int i = 3;
	int disk_number = 0;

	while((disk_number == 0) && (i >= 0))
	{
		if(destination[i] > 0)
		{
			disk_number = destination[i];
		}
		i--;
	}

	if(disk_number < source_disk)
		return true;
	else
		return false;
}

bool hanoi::game_completed()
{
	int le[4];
	int mi[4];
	int ri[4];
	bool temp = false;

	int j = 4;
	int i = 0;
	for(i = 0; i < 4; i++)
	{
		le[i] = 0;
		mi[i] = 0;
		ri[i] = j;
		j--;
	}

	for(i = 0; i < 4; i++)
	{
		if ((le[i] == left[i]) && (mi[i] == middle[i]) && (ri[i] == right[i]))
			temp = true;
		else
			temp = false;
	}
	return temp;
}

void hanoi::take_note_of_no1_disk_location()
{

	int i = 3;
	int left_disk = 0;
	int middle_disk = 0;
	int right_disk = 0;

	while((left_disk == 0) && (i >= 0))
	{
		if(left[i] > 0)
		{
			left_disk = left[i];
		}
		i--;
	}

	while((middle_disk == 0) && (i >= 0))
	{
		if(middle[i] > 0)
		{
			middle_disk = middle[i];
		}
		i--;
	}

	while((right_disk == 0) && (i >= 0))
	{
		if(right[i] > 0)
		{
			right_disk = right[i];
		}
		i--;
	}
	if (left_disk == 1)
		no_1_previous_location = 'l';
	if (middle_disk == 1)
		no_1_previous_location = 'm';
	if (right_disk == 1)
		no_1_previous_location = 'r';
}

void hanoi::make_move(char peg_select, char peg_destination)
{

	if((peg_select == 'l') && (peg_destination == 'r'))
	{
		move_logic(left, right);
		//cout<<"l r"<<endl;
	}	
	if((peg_select == 'l') && (peg_destination == 'm'))
	{
		move_logic(left, middle);
		//cout<<"l m"<<endl;
	}

	if((peg_select == 'm') && (peg_destination == 'l'))
	{
		move_logic(middle,left);
		//cout<<"m l"<<endl;
	}
	if((peg_select == 'm') && (peg_destination == 'r'))
	{
		move_logic(middle,right);
		//cout<<"m r"<<endl;
	}
	
	if((peg_select == 'r') && (peg_destination == 'l'))
	{
		move_logic(right,left);
		//cout<<"r l"<<endl
	}
	
	if((peg_select == 'r') && (peg_destination == 'm'))
	{
		move_logic(right,middle);
		//cout<<"r m"<<endl;
	}

			
 
			
}
void hanoi::move_logic(int select_array[], int destination_array[])
{	
	int i = 3;
	int j = 3;
	int no_to_move = 0;
	char newline = ' ';
	while((no_to_move == 0) && (i >= 0))//find the number to move
	{
		if(select_array[i] > 0)
		{
			no_to_move = select_array[i];
		}
		i--;
	}
	if(select_array[0] == 0)
	{
		cout<<"You entered the wrong peg name, there is no disk here"<<endl;
		cout<<"Press enter to continue"<<endl;
		cin.get(newline);
	}
	i = 3;

	take_note_of_no1_disk_location();
	//cout<<"tester"<<no_to_move<<endl;
	while (i >= 0)//this loop will loop through the array and place the disk into the array at the correct position
	{
		if((destination_array[i] > 0) && (no_to_move < destination_array[i]))
		{
			destination_array[i + 1] = no_to_move;
			while(j >= 0)
			{
				if(select_array[j] > 0)
				{
					select_array[j] = 0;
					break;
				}
				j--;
			}
			break;

		}
		if(destination_array[0] == 0)
		{
			destination_array[0] = no_to_move;
			while(j >= 0) //this loop will assign zero to the peg that the disk was taken off
			{
				cout<<j<<endl;
				if(select_array[j] > 0)
				{
					select_array[j] = 0;
					break;
				}
				j--;
			}
			break;
		}
		if((no_to_move > destination_array[i]) && (destination_array[i] != 0))
		{
			cout<<"The disk can not be placed here"<<endl;
			cout<<"Press enter to continue"<<endl;
			cin.get(newline);
			break;
		}
		i--;
	}
}



int main ()
{

	char newline = ' ';
	char peg_select = ' ';
	char peg_destination = ' ';
	hanoi game1;
	char ans = ' ';

	cout<<"Do you want to see the solution enter y to see or n to plan"<<endl;
	cin.get(ans);
	cin.get(newline);
	if(ans == 'y')
		game1.give_solution();
	
	while ((peg_select != 'q') || (peg_destination != 'q'))
	{
		clear_screen();
		game1.print_board();
		cout<<"Select which peg you want to take a disk off of:"<<endl;
		cout<<"l for the left peg \tm for the middle peg\tr for the right peg"<<endl;
		cout<<"q to quit"<<endl;
		cin.get(peg_select);
		cin.get(newline);
		if (peg_select == 'q')
			break;
		cout<<"Select the peg that you want to place the disk onto"<<endl;
		cout<<"l for the left peg"<<endl;
		cout<<"m for the middle peg"<<endl;
		cout<<"r for the right peg"<<endl;
		cout<<"q to quit"<<endl;
		cin.get(peg_destination);
		cin.get(newline);
		if (peg_destination == 'q')
			break;
		game1.make_move(peg_select, peg_destination);

	}
	
    	return 0;
}
