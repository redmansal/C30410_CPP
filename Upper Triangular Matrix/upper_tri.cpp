/*	upper_tri.cpp: This program creates an upper triangular matrix of n size using dynamic memory
*  	Authors: Colm Nolan
*  	Last modified: 13/04/11
***/

#include <iostream>
using namespace std;

const int MATRIX_SIZE = 12;

int ** upper_triangular_matrix(int array_size); /* this function takes a parameter the size that the matrix will be
						   and returns a pointer to its location*/
void delete_array(int **a, int array_size);     /* this function frees the memeory for the array */
void print_array(int **a, int array_size);      /* prints the array */
void assign_values_to_array(int **a, int array_size); /* assigns values to the array */
void text_formating();                          /* formats the text print out */

int main ()
{
	int **a;                                /* declaring a pointer to a pointer to an integer */
	int array_size = MATRIX_SIZE;
	a = upper_triangular_matrix(array_size); /* calling upper_triangular_matrix function and assigning its return value to a */

	assign_values_to_array(a, array_size);  /* assigns values to the array */
	print_array(a, array_size);		/* prints the array */
	delete_array(a, array_size); 		/* this function frees the memeory for the array */

	return 0;
}

void assign_values_to_array(int **a, int array_size)
{
	int second_dimension = 0;
	for(int i = 0; i < array_size; i++)
	{
		for(int j = second_dimension; j < array_size; j++)
			a[i][j] = 50 + i + j;   /* assign values to the array for demonstration purposes. */
		second_dimension++;
	}
}

void print_array(int **a, int array_size)
{
	text_formating();
	cout<<" ";
	text_formating();
	cout<<" ";
	for(int i = 0; i < array_size; i++)     /* printing out the second dimension index */
	{
		text_formating();
		cout<<i;
	}
	cout<<endl<<endl;
	
	int second_dimension = 0;
	for(int i = 0; i < array_size; i++)     /* looping through first dimension */
	{
		text_formating();
		cout<<i;                        /* printing out the first dimension index */
		for(int y = 0; y <= i; y++)     /* this loop is used here to print the blank spaces before the values are printed */
		{
			text_formating();
			cout<<" ";
		}

		for(int j = second_dimension; j < array_size; j++) /* prints out the values of the array */
		{
			text_formating();
			cout<<a[i][j];
		}
		second_dimension++;
		cout<<endl;
	}
}

int ** upper_triangular_matrix(int array_size)
{
	int **a;                                /* declare pointer to a pointer to an integer */
	int decrement = 0;
	int second_dimension = 0;
	a = new int*[array_size];               /* assign array of pointers to a */

	decrement = array_size;

	for(int i = 0; i < array_size; i++)
	{
		a[i] = new int[decrement];      /* loop through array of pointers and allocate a block of memory to hold an array of 
						   integers of size decrement*/
		decrement--;                    /* this decrement will ensure that each time a new array is assigned it will be one 
						   elemet smaller than the previous */
	}

                                                /* say if you want to access element a[3][3]  currently
						 * you will need to enter a[3][0]. This is not ideal. To get the referencing to 
						 * work correctly we must change the address value in the element a[3] to 3 places back.
						 * To do this using pointer arithmatic we decrement the value of a[3] by 3
						 * ie a[3] = a[3] - 3 */
	for(int i = 1; i < array_size; i++)     /* to ensure that referencing the elements in an array works correctly 
						   we must modify the pointers*/
	{
		a[i] = a[i] - i;                /* using pointer arithmatic each element of the array of pointers values is changed to
						 * suit in the loop as explained above*/
	}
	return a;
}

void delete_array(int **a, int array_size)
{
	for(int i = 1; i < array_size; i++)     /* because the array of pointers values have been changed before
						 * we need to changed them back to the way they were prior to deleteing or else
						 * an error will be thrown*/
	{
		a[i] = a[i] + i;                /* increment by the appropriate amount*/
	}

	for(int i = 0; i < array_size; i++)     /* loop through array of pointers deletting all the arrays of integers */
		delete [] a[i];

	delete [] a;                            /* delete the array of pointers */
}

void text_formating()
{
	cout.width(5);
	cout.precision(3);
	cout.setf(ios::showpoint);
	cout.setf(ios::right | ios::adjustfield);
}
