/*	array_main.cpp: This program contains a class which represents a general multi-dimensional array. It also contains a main program
 *	illustrating an implementation of this class
*  	Authors: Colm Nolan
*  	Last modified: 25/04/11
****/

#include <iostream>                             /* includding all the libraries needed for this class to work */
#include <fstream>
#include <new>
#include <cstdlib>
#include <iomanip>
using namespace std;
#include "array.h"                              /* including array.h which contains the multi-dimensional array definition */

int main()
{
	int input_1 = 0;
	int input_2 = 0;
	int input_3 = 0;
	double return_value = 0;
	char answer = ' ';                      /* these values will be used in the main funtion to track input */

	cout<<"Please enter 1st dimension size for a matrix 1"<<endl;
	cin>>input_1;

	cout<<"Please enter 2nd dimension size for matrix 1"<<endl;
	cin>>input_2;

	Array matrix_1(input_1, input_2);       /* calling the constructer which takes two parameters to create a 2d array */
	cout<<endl<<endl<<"MATRIX 1------"<<endl;
	matrix_1.printout();                    /* print new 2d matrix to screen */
	
	cout<<"Please enter 1st dimension size for a matrix 2"<<endl;
	cin>>input_1;

	cout<<"Please enter 2nd dimension size for matrix 2"<<endl;
	cin>>input_2;

	cout<<"Please enter 3rd dimension size for matrix 2"<<endl;
	cin>>input_3;

	Array matrix_2(input_1, input_2, input_3); /* calling the constructor which takes 3 paramenters to create a 3d array */
	cout<<endl<<endl<<"MATRIX 2------"<<endl;
	matrix_2.printout();

	cout<<"Do you want to reshape matrix 1 into a 3d array, \nPlease note the total new elements will need to remane the same"<<endl;
	cout<<"Enter y to change or n not to change and continue"<<endl;
	cin>>answer;
	if (answer == 'y')
	{
		cout<<"Enter new 1st dimension please"<<endl;
		cin>>input_1;
		cout<<"Enter new 2nd dimension please"<<endl;
		cin>>input_2;
		cout<<"Enter new 3rd dimesnion please"<<endl;
		cin>>input_3;
		matrix_1.reshape(input_1,input_2,input_3); /* calling the reshape method to turn a 2d array into a 3d array */
		cout<<endl<<endl<<"MATRIX 1------"<<endl;
		matrix_1.printout();
	}

	cout<<"Do you want to reshape matrix 2 into a 2d array, \nPlease note the total new elements will need to remane the same"<<endl;
	cout<<"Enter y to change or n not to change and continue"<<endl;
	cin>>answer;
	if (answer == 'y')
	{
		cout<<"Enter new 1st dimension please"<<endl;
		cin>>input_1;
		cout<<"Enter new 2nd dimension please"<<endl;
		cin>>input_2;
		matrix_2.reshape(input_1,input_2); /* calling the reshape method to turn a 3d array into a 2d array */
		cout<<endl<<endl<<"MATRIX 2------"<<endl;
		matrix_2.printout();
	}

	cout<<"Do you want to access an element in matrix 1"<<endl;
	cout<<"Enter y to view or n not to view and continue"<<endl;
	cin>>answer;
	if (answer == 'y')
	{
		if(matrix_1.get_dimension_3_value() == 0)
		{
			cout<<"Enter 1st dimension please"<<endl;
			cin>>input_1;
			cout<<"Enter 2nd dimension please"<<endl;
			cin>>input_2;
			return_value = matrix_1(input_1,input_2); /* calling the overloaded bracket operater () to find the value
								     at a certain location in the matrix*/
			cout<<"The value is: "<<return_value<<endl;
		}
		else
		{
			cout<<"Enter 1st dimension please"<<endl;
			cin>>input_1;
			cout<<"Enter 2nd dimension please"<<endl;
			cin>>input_2;
			cout<<"Enter 3rd dimension please"<<endl;
			cin>>input_3;
			return_value = matrix_1(input_1,input_2, input_3);/* calling the overloaded bracket operater () to find the value
									     at certain location in the 3d matrix */
			cout<<"The value is: " <<return_value<<endl;
		}
	
	}

	cout<<"Do you want to access an element in matrix 2"<<endl;
	cout<<"Enter y to view or n not to view and continue"<<endl;
	cin>>answer;
	if (answer == 'y')
	{
		if(matrix_2.get_dimension_3_value() == 0)
		{
			cout<<"Enter 1st dimension please"<<endl;
			cin>>input_1;
			cout<<"Enter 2nd dimension please"<<endl;
			cin>>input_2;
			return_value = matrix_2(input_1,input_2);/* calling the overloaded bracket operater () to find the value
								     at a certain location in the matrix*/
			cout<<"The value is: "<<return_value<<endl;
		}
		else
		{
			cout<<"Enter 1st dimension please"<<endl;
			cin>>input_1;
			cout<<"Enter 2nd dimension please"<<endl;
			cin>>input_2;
			cout<<"Enter 3rd dimension please"<<endl;
			cin>>input_3;
			return_value = matrix_2(input_1,input_2, input_3);/* calling the overloaded bracket operater () to find the value
									     at certain location in the 3d matrix */
			cout<<"The value is: "<< return_value<<endl;
		}
	
	}

	cout<<"Do you want to transpose matrix 1. Please note its needs o be a 2d array to transpose"<<endl;
	cin>>answer;
	if(answer == 'y')
	{
		matrix_1.transpose();           /* calling the transpse method on matrix_1 object */
		cout<<endl<<endl<<"MATRIX 1------"<<endl;
		matrix_1.printout();
	}
	
	cout<<"Do you want to transpose matrix 2. Please note its needs o be a 2d array to transpose"<<endl;
	cin>>answer;
	if(answer == 'y')
	{
		matrix_2.transpose();		/* calling the transpse method on matrix_1 object */
		cout<<endl<<endl<<"MATRIX 2------"<<endl;
		matrix_2.printout();
	}

	cout<<"Do you want to multiply matrix 1 by another matrix"<<endl;
	cin>>answer;

	if(answer == 'y')
	{
		cout<<"Please enter dimensions the same shape as matrix 1 or else it will not be possible to multiply them"<<endl;
		if(matrix_1.get_dimension_3_value() == 0)
		{
			cout<<"Enter 1st dimension please"<<endl;
			cin>>input_1;
			cout<<"Enter 2nd dimension please"<<endl;
			cin>>input_2;
			Array matrix_3(input_1, input_2);
			Array matrix_4(input_1, input_2);
			matrix_4 = matrix_3 * matrix_1; /* calling the overloaded operater* which multiplies matrix_3 by matrix_1
							   and returns result.
							   the overloaded assigmnet operater = is then used to assign the result
							   to matrix_4*/
			cout<<endl<<endl<<"MATRIX 1 when multiplied by another matrix------"<<endl;
			matrix_4.printout();    /* print the result */


		}                               /* matrix_3 and matrix_4 go out of scope here destructor called */
		else
		{
			cout<<"Enter 1st dimension please"<<endl;
			cin>>input_1;
			cout<<"Enter 2nd dimension please"<<endl;
			cin>>input_2;
			cout<<"Enter 3rd dimension please"<<endl;
			cin>>input_3;

			Array matrix_3(input_1, input_2, input_3);
			Array matrix_4(input_1, input_2, input_3);
			matrix_4 = matrix_3 * matrix_1;/* calling the overloaded operater* which multiplies matrix_3 by matrix_1
							   and returns result.
							   the overloaded assigmnet operater = is then used to assign the result
							   to matrix_4*/
			cout<<endl<<endl<<"MATRIX 1 when multiplied by another matrix------"<<endl;
			matrix_4.printout();
		}                               /* matrix_3 and matrix_4 go out of scope here destructor called */
	}
	
	cout<<"Do you want to multiply matrix 2 by another matrix"<<endl;
	cin>>answer;

	if(answer == 'y')
	{
		cout<<"Please enter dimensions the same shape as matrix 2 or else it will not be possible to multiply them"<<endl;
		if(matrix_2.get_dimension_3_value() == 0)
		{
			cout<<"Enter 1st dimension please"<<endl;
			cin>>input_1;
			cout<<"Enter 2nd dimension please"<<endl;
			cin>>input_2;
			Array matrix_3(input_1, input_2);
			Array matrix_4(input_1, input_2);
			matrix_4 = matrix_3 * matrix_2;;/* calling the overloaded operater* which multiplies matrix_3 by matrix_2
							   and returns result.
							   the overloaded assigmnet operater = is then used to assign the result
							   to matrix_4*/
			cout<<endl<<endl<<"MATRIX 2 when multiplied by another matrix------"<<endl;
			matrix_4.printout();

		}                               /* matrix_3 and matrix_4 go out of scope here destructor called */
		else
		{
			cout<<"Enter 1st dimension please"<<endl;
			cin>>input_1;
			cout<<"Enter 2nd dimension please"<<endl;
			cin>>input_2;
			cout<<"Enter 3rd dimension please"<<endl;
			cin>>input_3;

			Array matrix_3(input_1, input_2, input_3);
			Array matrix_4(input_1, input_2, input_3);
			matrix_4 = matrix_3 * matrix_2;;/* calling the overloaded operater* which multiplies matrix_3 by matrix_2
							   and returns result.
							   the overloaded assigmnet operater = is then used to assign the result
							   to matrix_4*/
			cout<<endl<<endl<<"MATRIX 2 when multiplied by another matrix------"<<endl;
			matrix_4.printout();
		}                               /* matrix_3 and matrix_4 go out of scope here destructor called */
	}
	
	return 0;
} /* matrix_1 and matrix_2 go out of scope here destructor called */
