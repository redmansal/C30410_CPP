/*	2_dim.cpp: This program creates a 2 dimensional array with its elements allocated in one contiguous block of memory
*  	Authors: Colm Nolan
*  	Last modified: 13/04/11
***/

#include <iostream>
using namespace std;

int arraySum(int **a, int n, int m);            /* this funtion will add up the elements in the array and return it as an integer */

int main()
{
	int **a;                                /* declare a pointer to a pointer to an integer */
	int i,j;                                /* used to itterate through arrays */
	a = new int*[5];                        /* allocate memory for an array of pointers to integers
	      					   the new operater will return an address to the block of memory*/
	*(a + 0) = new int[15];                 /* declare an array of integers of size 15  */
                                                
						/* since the only element in the array of pointers with an integer array 
						   assigned to it is *(a + 0).  *(a + 0) has been deliberately allocated with enough 
						   memory for parts of it to be realocated to the rest of the pointers in the array*/
	*(a + 1) = *(a) + 3;                    /* using pointer arithmatic we assign the address of the 3rd element in the array
						   to the *(a + 1) pointer elment.  The array *(a + 1) element now has the value 
						   of the address where the int array is stored*/
	*(a + 2) = *(a) + 6;                    /* pointer aritmatic is used here again to assign the correct address to *(a +2) */
	*(a + 3) = *(a) + 9;                    /* dito */
	*(a + 4) = *(a) + 12;                   /* dito */

	// now we can use a as if we had declared it as int a[5][3]
	for (i=0;i<5;i++)
		for (j=0;j<3;j++)
			a[i][j] = i + j;        /* assignig values to the array */

	for (i=0;i<5;i++)
	{
		for (j=0;j<3;j++)
			cout<<a[i][j]<<"\t";    /* outputting to the screen to show values of array */
		cout<<endl;
	}
	cout << "The sum of the array elements is " << arraySum(a,5,3) << endl; /* calculating the sum of the array elements */
	delete [] a[0];                         /* freeing the array of integers */
	delete  [] a;                           /* freeing the array of pointers */
	return 0;
}

int arraySum(int **a, int n, int m)		/* this funtion will add up the elements in the array and return it as an integer */
{
	int i,j;
	int sum=0;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			sum+=a[i][j];
	return sum;
}

