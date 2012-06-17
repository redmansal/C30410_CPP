class Array {
	private: 
		 double ** array_2d_ptr;        /* pointer for 2d array */
		 double *** array_3d_ptr;       /* pointer for 3d array */

		 int dim_1_priv;                /* int to hold dimension 1 size */
		 int dim_2_priv;                /* int to hold dimension 2 size */
		 int dim_3_priv;                /* int to hold dimension 3 size */

	public: Array();                        /* defult constructer */
		Array(int dimension_1, int dimension_2); /* overloaded constructer that takes 2 parameters to make a 2d array */

		Array(int dimension_1, int dimension_2, int dimension_3); /* overloaded constructer that takes 3 parameters to make a 3d array */


		Array(const Array &array_ref);  /* copy constructor */

		Array& operator=(const Array &array_ref); /* overloaded = operator */
		Array& operator*(const Array &array_ref); /* overloaded * operator */


		void set_array_element_value(int x,int y, double value); /* change value in array */

		void printout()const;                /* print matrix */

		double ** get_array_2d_ptr() const;   /* get objects pointer */

		void reshape(int dimension_1, int dimension_2); /* change 3d matrix to 2d matrix */

		void reshape(int dimension_1, int dimension_2, int dimension_3); /* chnage 2d to 3d matrix */

		double operator()(int dimension_1, int dimension_2)const; /* overload () operater that takes two parameters */
		double operator()(int dimension_1, int dimension_2, int dimension_3)const; /* overload () that takes 3 parameters */

		void transpose();               /* transpose a matrix */

		int get_dimension_3_value()const;    /* value accessor */

		~Array();                       /* destruct the matrix */
};
