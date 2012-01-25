/* compare.cpp: This program compares two text files and checks if they are identical
*  Authors: Colm Nolan
*  Last modified: 02/03/11
***/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])				//take arguments from the command line
{
	fstream stream_1;							//make object stream_1 from class fstream
	stream_1.open(argv[1], ios::in);

	fstream stream_2;							//make object stream_2 from class fstream
	stream_2.open(argv[2], ios::in);			//copy parameter from argv array into stream_2

	char c1,c2;

	stream_1.get(c1);
	stream_2.get(c2);

	while(!stream_1.eof() && !stream_2.eof() && c1 == c2)	//the loop will continue only when the statements are true that we are not
															//at the end of file and that each character is the same
	{    
		stream_1.get(c1);
		stream_2.get(c2); 
	}

	if (c1 == c2)								//this if statement compares two characters and if its true "The files are identical will be displayed
		cout<<"The files are identical"<<endl;
	else if (c1 != c2)
		cout<<"The files are different"<<endl;

	return 0;
}
