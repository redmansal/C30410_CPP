#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>                              /* iclude the libraries we need */
#include <iomanip>
using namespace std;
#include "array.h"                              /* include header file which contains the class deffinition */

Array::Array()  /*default constructor This will be a 2d arry of sixe 4 * 6*/
{
	int dimension_1 = 4;
	int dimension_2 = 6;

	double number = 10;
	int increment_by_dim_2 = dimension_2;
	int total_elements_in_array = dimension_1 * dimension_2; /* find the total size of memory that will be needed to hold the elements */
	array_2d_ptr = new double *[dimension_1]; /* assign memory for and array of pointers */

	array_2d_ptr[0] = new double [total_elements_in_array]; /* assign enough memory to hold all the elements in one contiguous
								   chunk of memeory*/

	for (int  i = 1; i < dimension_1; i++)  /* loop through the array of pointer assinging them to the correct element using
						   pointer arithmatic*/
	{
		array_2d_ptr[i] = array_2d_ptr[0] + increment_by_dim_2;
		increment_by_dim_2 = increment_by_dim_2 + dimension_2;
	}

	for (int i = 0; i < dimension_1; i++)
	{
		for (int j = 0 ; j < dimension_2; j++)
		{
			array_2d_ptr[i][j] = number;
			number = number + 10;   /* assignging values to the array */
			//cout<<array_2d_ptr[i][j]<<' ';
		}
	}

	dim_1_priv = dimension_1;
	dim_2_priv = dimension_2;               /* assigning values to private fields dimensions size */
	//cout<<dim_1_priv<<endl;
	//cout<<dim_2_priv<<endl;
	dim_3_priv = 0;
}

Array::Array(int dimension_1, int dimension_2)  /* 2d array constructor tating two parameters*/
{
	double number = 10;
	int increment_by_dim_2 = dimension_2;
	int total_elements_in_array = dimension_1 * dimension_2;/* find the total size of memory that will be needed to hold the elements */
	array_2d_ptr = new double *[dimension_1];/* assign memory for and array of pointers */

	array_2d_ptr[0] = new double [total_elements_in_array];/* assign enough memory to hold all the elements in one contiguous
								   chunk of memeory*/

	for (int  i = 1; i < dimension_1; i++)/* loop through the array of pointer assinging them to the correct element using
						   pointer arithmatic*/
	{

		array_2d_ptr[i] = array_2d_ptr[0] + increment_by_dim_2;
		increment_by_dim_2 = increment_by_dim_2 + dimension_2;

	}

	for (int i = 0; i < dimension_1; i++)
	{
		for (int j = 0 ; j < dimension_2; j++)
		{
			array_2d_ptr[i][j] = number;
			number = number + 10; /* assignging values to the array */
			//cout<<array_2d_ptr[i][j]<<' ';
		}
	}

	dim_1_priv = dimension_1;
	dim_2_priv = dimension_2; /* assigning values to private fields dimensions size */
	//cout<<dim_1_priv<<endl;
	//cout<<dim_2_priv<<endl;
	dim_3_priv = 0;
}

Array::Array(int dimension_1, int dimension_2, int dimension_3) /* 3d array constructor that takes 3 parameters*/
{
	int increment_by_dim_2 = dimension_2;
	int increment_by_dim_3 = dimension_3;   /* declaring ints to keep track of pointer assignment */
	int array_of_pointer_size = dimension_2 * dimension_1; /* total size needed for the array of pointers */
	int total_elements = dimension_1 * dimension_2 * dimension_3; /* total size needed to hold all the double elements */
	double number = 1000;
	array_3d_ptr = new double**[dimension_1]; /* create memory for array of pointers to pointers to doubles and assign to array_3d_ptr*/

	array_3d_ptr[0] = new double *[array_of_pointer_size]; /* make memory for the array of pointers to doubles */
	array_3d_ptr[0][0] = new double [total_elements]; /* make memory to actually hold the element values */

	for (int i = 1; i < dimension_1; i++)   /* loop through array of pointers assigning the correct pointer to pointers */
	{
		array_3d_ptr[i] = array_3d_ptr[0] + increment_by_dim_2 ;
		increment_by_dim_2 = increment_by_dim_2 + dimension_2;
	}

	for (int i = 1; i < array_of_pointer_size; i++) /* loop through array of pointers assigning the correct loctation of the elements */
	{
		array_3d_ptr[0][i] = array_3d_ptr[0][0] + increment_by_dim_3;
		increment_by_dim_3 = increment_by_dim_3 + dimension_3;
	}


	for(int i = 0; i < dimension_1; i++)
	{
		for(int j = 0; j < dimension_2; j++)
		{
			for(int k = 0; k < dimension_3; k++)
			{
				array_3d_ptr[i][j][k] = 1.34 * number++; /* assign values to the 3d array */
				//cout<<array_3d_ptr[i][j][k]<<' ';
			}
		}
	}

	dim_1_priv = dimension_1;               /* assign values to the private fields */
	dim_2_priv = dimension_2;
	dim_3_priv = dimension_3;
}

                                                /* copy constructor */
Array::Array(const Array &array_ref)            /* this constructor takes in an existing object as parameter which then has
						   its values assigned to the new object*/
{

	if(array_ref.dim_3_priv == 0)           /* if the object that is being copied has a 3rd dimension == 0 it means its a 2d array
	therefor the matrix needs to be treated so*/
	{                                       /* this section continues much like Array(int dimension_1, int dimension_2)
						   except at the end values from array_ref are copied into this object*/
		int increment_by_dim_2 = array_ref.dim_2_priv;
		int total_elements_in_array = array_ref.dim_1_priv * array_ref.dim_2_priv;

		array_2d_ptr = new double *[array_ref.dim_1_priv];

		array_2d_ptr[0] = new double [total_elements_in_array];

		for (int  i = 1; i < array_ref.dim_1_priv; i++)
		{

			array_2d_ptr[i] = array_2d_ptr[0] + increment_by_dim_2;
			increment_by_dim_2 = increment_by_dim_2 + array_ref.dim_2_priv;

		}

		for (int i = 0; i < array_ref.dim_1_priv; i++)
		{
			for (int j = 0 ; j <  array_ref.dim_2_priv; j++)
			{
				array_2d_ptr[i][j] = array_ref.array_2d_ptr[i][j];
				//cout<<array_2d_ptr[i][j]<<' ';
			}
		}

		dim_1_priv = array_ref.dim_1_priv;
		dim_2_priv = array_ref.dim_2_priv;
		dim_3_priv = 0;
	}
	else
	{                                       /* this is the same as above except for a 3d matrix */
		int increment_by_dim_2 = array_ref.dim_2_priv;
		int increment_by_dim_3 = array_ref.dim_3_priv;
		int array_of_pointer_size = array_ref.dim_1_priv * array_ref.dim_2_priv;
		int total_elements = array_ref.dim_1_priv * array_ref.dim_2_priv * array_ref.dim_3_priv;

		array_3d_ptr = new double**[array_ref.dim_1_priv];

		array_3d_ptr[0] = new double *[array_of_pointer_size];
		array_3d_ptr[0][0] = new double [total_elements];

		for (int i = 1; i < array_ref.dim_1_priv; i++)
		{
			array_3d_ptr[i] = array_3d_ptr[0] + increment_by_dim_2 ;
			increment_by_dim_2 = increment_by_dim_2 + array_ref.dim_2_priv;
		}

		for (int i = 1; i < array_of_pointer_size; i++)
		{
			array_3d_ptr[0][i] = array_3d_ptr[0][0] + increment_by_dim_3;
			increment_by_dim_3 = increment_by_dim_3 + array_ref.dim_3_priv;
		}


		for(int i = 0; i < array_ref.dim_1_priv; i++)
		{
			for(int j = 0; j < array_ref.dim_2_priv; j++)
			{
				for(int k = 0; k < array_ref.dim_3_priv; k++)
				{
					array_3d_ptr[i][j][k] = array_ref.array_3d_ptr[i][j][k];
					//cout<<array_3d_ptr[i][j][k]<<' ';
				}
			}
		}

		dim_1_priv = array_ref.dim_1_priv;
		dim_2_priv = array_ref.dim_2_priv;
		dim_3_priv = array_ref.dim_3_priv;
	}

}

Array& Array::operator=(const Array &array_ref) /* assignment operator overload */
{
                                                /* overloading assignment operator takes in rhs object as a parameter and is then assign
						 * to this object. *this is then retruned to the main function*/
	if (array_ref.dim_3_priv == 0)
	{


		for (int i = 0; i < array_ref.dim_1_priv; i++)
		{
			for (int j = 0 ; j <  array_ref.dim_2_priv; j++)
			{
				array_2d_ptr[i][j] = array_ref.array_2d_ptr[i][j];
				//cout<<array_2d_ptr[i][j]<<' ';
			}
		}
		
		dim_1_priv = array_ref.dim_1_priv;
		dim_2_priv = array_ref.dim_2_priv;
		dim_2_priv = array_ref.dim_2_priv;

		return *this;
	}
	else
	{
		for(int i = 0; i < array_ref.dim_1_priv; i++)
		{
			for(int j = 0; j < array_ref.dim_2_priv; j++)
			{
				for(int k = 0; k < array_ref.dim_3_priv; k++)
				{
					array_3d_ptr[i][j][k] = array_ref.array_3d_ptr[i][j][k];
					//cout<<array_3d_ptr[i][j][k]<<' ';
				}
			}
		}	
		return *this;
	}

}

Array& Array::operator*(const Array &array_ref)
{
	bool valid_to_multipy = true;
	if(dim_1_priv != array_ref.dim_1_priv || dim_2_priv != array_ref.dim_2_priv || dim_3_priv != array_ref.dim_3_priv)
                                                /* checking to make sure the two matrixes are the correct shape
						 * if not an exit occurs*/
	{
		valid_to_multipy =false;
	}
	if(valid_to_multipy == true)
	{
		if(array_ref.dim_3_priv == 0)
		{
			for (int i = 0; i < array_ref.dim_1_priv; i++)
			{
				for (int j = 0 ; j <  array_ref.dim_2_priv; j++)
				{
					array_2d_ptr[i][j] = array_2d_ptr[i][j] * array_ref.array_2d_ptr[i][j];
                                                /* multiply element by element and assign to array_2d_ptr[i][j] which 
						 * will be returned to the main funtion
						 * Please note this is hardly ideal since this bject getting modified when it realy should not*/
				}
			}
			return *this;
		}
		else 
		{
			for(int i = 0; i < array_ref.dim_1_priv; i++)
			{
				for(int j = 0; j < array_ref.dim_2_priv; j++)
				{
					for(int k = 0; k < array_ref.dim_3_priv; k++)
					{
						array_3d_ptr[i][j][k] = array_3d_ptr[i][j][k] * array_ref.array_3d_ptr[i][j][k];
                                                /* assigning values for the 3d array */
						//cout<<array_3d_ptr[i][j][k]<<' ';
					}
				}
			}	
			return *this;
		}
	}
	else
	{
		cout<<"This is not a valid multiplication. Exiting now."<<endl;
		exit(1);
	}
	
}

void Array::reshape(int dimension_1, int dimension_2) /* turn a 3d array into a 2d array */
{
	int existing_total_elements = 0;
	int total_elememets_input = 0;
	total_elememets_input = dimension_1 * dimension_2;
	existing_total_elements = dim_1_priv * dim_2_priv * dim_3_priv;

	if(existing_total_elements == total_elememets_input) /* ensuring the correct number of elements are in the parameter for this array to be reshaped */
	{

		int increment_by_dim_2 = dimension_2;

		array_2d_ptr = new double *[dimension_1];

		array_2d_ptr[0] = array_3d_ptr[0][0]; /* this is where the new 2d array is being assigned the address of the existing
						         memory block*/

		for(int i = 1; i < dimension_1; i++) /* assigning the pointers to the single block of memory */
		{
			array_2d_ptr[i] = array_2d_ptr[0] + increment_by_dim_2;
			increment_by_dim_2 = increment_by_dim_2 + dimension_2;
		}

		delete [] array_3d_ptr[0];      /* to make it truly 2d array the old 3d pointer arrays must be deleted  */
		delete [] array_3d_ptr;

		dim_1_priv = dimension_1;
		dim_2_priv = dimension_2;       /* reasigning the new private fields */
		dim_3_priv = 0;
		cout<<endl;
	}
	else
	{
		cout<<"You entered an invalid number of elements to change to. Exiting now."<<endl;
		exit(1);
	}
}

void Array::reshape(int dimension_1, int dimension_2, int dimension_3) /* turn a 2d array into a 3d array */
{
	int existing_total_elements = 0;
	int total_elememets_input = 0;
	total_elememets_input = dimension_1 * dimension_2 * dimension_3;
	existing_total_elements = dim_1_priv * dim_2_priv;

	if(existing_total_elements == total_elememets_input)/* ensuring the correct number of elements are in the parameter for this array to be reshaped */
	{
		int increment_by_dim_2 = dimension_2;
		int increment_by_dim_3 = dimension_3;
		int array_of_pointer_size = dimension_1 * dimension_2;

		array_3d_ptr = new double**[dimension_1];

		array_3d_ptr[0] = new double *[array_of_pointer_size];

		array_3d_ptr[0][0] = array_2d_ptr[0]; /* this is where the existing block of memory is being assigned to the new 3d method of accessing the array */
		
		for (int i = 1; i < dimension_1; i++) /* reasigning pointers to the correct locations */
		{
			array_3d_ptr[i] = array_3d_ptr[0] + increment_by_dim_2 ;
				increment_by_dim_2 = increment_by_dim_2 + dimension_2;
		}

		for (int i = 1; i < array_of_pointer_size; i++) /* reasigning pointers to the correct locations */
		{
			array_3d_ptr[0][i] = array_3d_ptr[0][0] + increment_by_dim_3;
			increment_by_dim_3 = increment_by_dim_3 + dimension_3;
		}

		delete [] array_2d_ptr;         /* now the old way of referencing the array can be deleted */

		dim_1_priv = dimension_1;       /* reassigning the new private fields */
		dim_2_priv = dimension_2;
		dim_3_priv = dimension_3;


		}
	else
	{
		cout<<"You entered an invalid number of elements to change to"<<endl;
		exit(1);
	}
	
}

void Array::set_array_element_value(int x,int y ,double value) /* setting the value of a 2d array */
{
	array_2d_ptr[x][y] = value;
	//cout<<array_2d_ptr[x][y]<<" ";
}

void Array::printout() const
{
	if(dim_3_priv ==0)                      /* printing the 2d matrix */
	{
	cout<<setw(5)<<" ";
	for(int i = 0; i < dim_2_priv; i++)     /* printing out the second dimension index */
	{
		cout<<setw(6)<<i;
	}
	cout<<endl<<endl;
		for(int i = 0; i < dim_1_priv; i++)
		{
			cout<<setw(5)<<i;
		   	cout<<' ';
			for(int j = 0; j < dim_2_priv; j++)
			{
				cout<<setw(5)<<array_2d_ptr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	else
	{                                       /* printing out the 3d matrix to the screen */
		for(int i = 0; i < dim_1_priv; i++)
		{
			for(int j = 0; j < dim_2_priv; j++)
			{
				for(int k = 0; k < dim_3_priv; k++)
				{
					cout<<"3d_matrix["<<i<<"]"<<"["<<j<<"]"<<"["<<k<<"] = "<<array_3d_ptr[i][j][k]<<' '<<endl;
				}
			}
		}
	}
}

double ** Array::get_array_2d_ptr()const        /* find pointer to an array */
{
	return array_2d_ptr;
}

int Array::get_dimension_3_value()const         /* find the private field value of a matrix */
{
	return dim_3_priv;
}

double Array::operator()(int dimension_1, int dimension_2)const
{
	bool valid_input = true;
	if (dimension_1 >= dim_1_priv || dimension_2 >= dim_2_priv || dimension_1 < 0 || dimension_2 < 0) 
		valid_input = false;
                                                /* ensuring valid user entries */

	if(valid_input == true)
	{
		return array_2d_ptr[dimension_1][dimension_2]; /* returning the value at an element for a 2d array */
	}
	else
	{
		cout<<"Invalid reference"<<endl;
		exit(1);
	}

}

double Array::operator()(int dimension_1, int dimension_2, int dimension_3)const
{
	bool valid_input = true;
	if (dimension_1 >= dim_1_priv || dimension_2 >= dim_2_priv || dimension_3 >= dim_3_priv || dimension_1 < 0 || dimension_2 < 0 || dimension_3 < 0 || dim_3_priv == 0) 
		valid_input = false;
                                                /* ensuring valid user entries */
	if(valid_input == true)
		return array_3d_ptr[dimension_1][dimension_2][dimension_3]; /* returing value at elemetnt in 3d array */
	else
	{
		cout<<"Invalid reference"<<endl;
		exit(1);
	}
}

void Array::transpose()
{
	if(dim_3_priv != 0)                     /* check to make sure it is a 2d array firstly */
	{
		cout<<"This array cannot be transposed, Exiting now"<<endl;
		exit(1);
	}
	else
	{
		int increment_by_dim_1 = dim_1_priv;
		int x = 0;                      /* x and y will be used to keep track of new transposed locations will be */
		int y = 0;
		double * temp_address_location = 0;
		Array Temp(dim_1_priv, dim_2_priv);               /* make temerory array the same size as array_2d_ptr */

		for (int i = 0; i < dim_1_priv; i++)
		{
			for (int j = 0 ; j < dim_2_priv; j++)
			{
				if(x >= dim_1_priv)
				{
					x =0;
					y++;
				}
				Temp.array_2d_ptr[i][j]  = array_2d_ptr[x][y] ; /* assign values to the temp array that will
										   contain the new transposed values in the corrrect position*/
				x++;
			}
		}

		for(int i = 0; i < dim_1_priv; i++)
		{
			for(int j = 0; j < dim_2_priv; j++)
			{
				array_2d_ptr[i][j] = Temp.array_2d_ptr[i][j]; /* assign temp values back to array_2d_pts values which will
										 now have their elements in the right positions for a
										 transposed array*/
			}
			cout<<endl;
		}
		temp_address_location = array_2d_ptr[0]; /* this variable will temporaly hold the address of the starting ellement in the array */
		
		delete [] array_2d_ptr;         /* we can now delete to old pointer referencing */

		array_2d_ptr = new double *[dim_2_priv]; /* we now alocate enough memory for the new way to access our 
							   now transposed block of memeory*/
		array_2d_ptr[0] = temp_address_location; /* re asigning pointer to block af memory */
		
		for (int  i = 1; i < dim_2_priv; i++) /*  assigning the pointers to the correct locations */
		{

			array_2d_ptr[i] = array_2d_ptr[0] + increment_by_dim_1;
			increment_by_dim_1 = increment_by_dim_1 + dim_1_priv;

		}

		dim_1_priv = Temp.dim_2_priv;                     /* re assign the dimensions tot the correct values */
		dim_2_priv = Temp.dim_1_priv;
		dim_3_priv = 0;
                                                /* please note throughout this method the original location of the block of memeory holding the elements was never changed */
	}
}

Array::~Array()                                 /* 2d and 3d array destructor */
{
	if(dim_3_priv == 0)                     /* if the dim_3_value is == 0 we know the object is a 2d matrix and needs to be destructed
				      		   as below*/
	{
		delete [] array_2d_ptr[0];
		delete [] array_2d_ptr;
		
	}
	else                                    /* if it is a 3d matrix it needs to be destructed as below. */
	{
		delete [] array_3d_ptr[0][0];      
		delete [] array_3d_ptr[0];                 
		delete [] array_3d_ptr;                            
	}
}

