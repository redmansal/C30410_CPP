/* 20_lines.cpp: This program reads a text file to a stream and then outputs it onto the screen 20 lines at a time.
 * Please note the file name will need to be entered in on the command line
*  Authors: Colm Nolan
*  Last modified: 03/03/11
***/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])		//read in from the command line
{
	fstream stream_1;			//make an object stream_1

	stream_1.open(argv[1], ios::in);	//copy the infoe from the command line argument into the stream_

	char c;

	int newline = 0;

	char answer = '\n';

	cout<<"Press Return to start viewing text or q to quit. ";
	cin.get(answer);			

	stream_1.get(c);			//take a character fromt the stream and put in c	

	while((!stream_1.eof()) && (answer != 'q'))//keep looping whe thes statements are true.
	{
		cout<<c;
		if(c=='\n')
		newline++;

		if((newline % 20 == 0) && (newline > 0) && (c=='\n'))	//the if statement is only true when the newline counter is 
									//divisable by 20 evenly,newline counter is 
									//greater than 0 and c is equal to a newline character
									//The program will then be paused to take the user info
		{
			cout<<"Press Return to see the next twenty lines or q to quit. ";
			cin.get(answer);
		}
		stream_1.get(c);
	}

	return 0;
}
