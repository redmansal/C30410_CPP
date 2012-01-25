/*	3d_array.cpp: This program creates a 3 dimensional array using dynamic memory, assigns values to to it and then prints the array
 *	to the screen. The memory is then freed.
*  	Authors: Colm Nolan
*  	Last modified: 13/04/11
***/

#include <iostream>
using namespace std;

void text_formating();

const int X_AXIS = 20;                          /* 1st dimension */
const int Y_AXIS = 30;                          /* 2nd dimension */
const int Z_AXIS = 40;                          /* 3rd dimension */

int main ()
{
	int ***a;                               /* declaring a pointer to a pointer to a pointer to an integer */

	a = new int**[X_AXIS];                  /* allocating an array of pointers to pointers of size X_AXIS which will point to integers */
	
	for (int i = 0; i < X_AXIS; i++)
	{
		a[i] = new int*[Y_AXIS];        /* iterating through the X_AXIS array pointers and allocating to each of them an an array of 
						   Y_AXIS pointers*/

		for(int j = 0; j < Y_AXIS; j++)
			a[i][j] = new int[Z_AXIS];   /* each element of the size Y_AXIS array of pointers is now been allocated the final array
						   of integers of size Z_AXIS*/

	}
	
	for (int i = 0; i < X_AXIS; i++)
	{
		for(int j = 0; j < Y_AXIS; j++)
		{
			for(int k = 0; k < Z_AXIS; k++)
				a[i][j][k] = i + j + k;
                                                /* assigning values to the 3 dimensional array */
		}
	}

	for (int i = 0; i < X_AXIS; i++)
	{
		for(int j = 0; j < Y_AXIS; j++)
		{
			for(int k = 0; k < Z_AXIS; k++)
			{
				text_formating();
				cout<<"a["<<i<<"]"<<"["<<j<<"]"<<"["<<k<<"] = "<<a[i][j][k];
				if( k % 3 == 0)
					cout<<endl;
			}
                                                /* outputing what is in each element of the array */
		}
	}

	for (int i = 0; i < X_AXIS; i++)
	{

		for(int j = 0; j < Y_AXIS; j++)
			delete [] a[i][j];      /* freeing the memory for each of int arrays*/

		delete [] a[i];                 /* freeing the memory for X_AXIS no Y_AXIS element array */
	}
	delete [] a;                            /* finally freeing the array that contains X_AXIS pointers */
	
	return 0;
}

void text_formating()
{
	cout.width(10);
	cout.precision(3);
	cout.setf(ios::showpoint);
	cout.setf(ios::right | ios::adjustfield);
}
