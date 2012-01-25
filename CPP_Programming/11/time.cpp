/* time.cpp: This program calculated the sum of two times and also subtracts the second time form the first
*  Authors: Colm Nolan
*  Last modified: 06/03/11
***/
#include <iostream>

using namespace std;

struct time_s {									/*time struct formatted here. Please note time_t was changed
								  	  	  	  to time_s because time_t is a reserved word and was causing
								  	  	  	  problems */
int hours;
int minutes;
int seconds;
};

typedef struct time_s time_type;				//typedef used here to create the alias time_type

time_type add_time(time_type in1, time_type in2);		//prototype for function to add the times	
time_type subtract_time(time_type in1, time_type in2);		//prototype for function to subtract the times
void check_entry(time_type in);					//prototype for function used to ensure correct parameters 

int main()
{
	time_type input1;							//object of struct time_type called input1
	time_type input2;

	time_type sumation;
	time_type subtraction;

	input1.hours = 6;
	input1.minutes = 30;
	input1.seconds = 20;						//initializing the members of the object input1

	input2.hours = 4;
	input2.minutes = 59;
	input2.seconds = 50;

	sumation = add_time(input1, input2);		/*assigning the returned calculations from the time function
								  	  	  	  	  to the object summation */
	subtraction = subtract_time(input1, input2);	//calling function subtract_time
	cout<<"Time 1    \t"<<input1.hours<<":"<<input1.minutes<<":"<<input1.seconds<<endl; 		//outputting the calculated hours, minutes and seconds
	cout<<"Time 2    \t"<<input2.hours<<":"<<input2.minutes<<":"<<input2.seconds<<endl<<endl;
	
	check_entry(input1);  //this function will check to see if correct parameters were entered
	check_entry(input2);

	cout<<"Time 1 will now be added to Time 2\nAlso Time 2 will be subtracted from Time 1"<<endl<<endl;

	cout<<"Sum = \t\t"<<sumation.hours<<":"<<sumation.minutes<<":"<<sumation.seconds<<endl;
	
	cout<<"Subtraction = \t"<<subtraction.hours<<":"<<subtraction.minutes<<":"<<subtraction.seconds<<endl;


	return 0;
}

time_type add_time(time_type in1, time_type in2) 	//two time parameters will be entered and the time_type will be returned
{
	time_type temp;                         /* local variable temp created here */
	temp.hours = 0;
	temp.minutes = 0;
	temp.seconds = 0;


	if (in1.seconds + in2.seconds >= 60)    /* the general algorithm here was to add the smallest values first ie the seconds and
						and if greater or equal to to 60,add 1 to the minutes*/
	{
		in1.minutes++;
		temp.seconds = in1.seconds + in2.seconds - 60;
	}

	if (in1.seconds + in2.seconds < 60)
		temp.seconds = in1.seconds + in2.seconds;

	if (in1.minutes + in2.minutes >= 60)
	{
		in1.hours++;
		temp.minutes = in1.minutes + in2.minutes - 60;
	}

	if (in1.minutes + in2.minutes <60)
		temp.minutes = in1.minutes + in2.minutes;

	temp.hours = temp.hours + in1.hours + in2.hours;

	return temp;
	
}

time_type subtract_time(time_type in1, time_type in2)
{
	time_type temp;
	temp.hours = 0;
	temp.minutes = 0;
	temp.seconds = 0;

	if(in2.seconds > in1.seconds)           /* this if statement ensures that if the in2.seconds is greater than in1.seconds, 
						   in1.minutes will be subtracted by and the correct seconds calculated in the
						   temp struct which will be returned*/
	{
		in1.minutes--;
		temp.seconds = (in1.seconds - in2.seconds) + 60;
	}

	if (in2.seconds <= in1.seconds)
		temp.seconds = in1.seconds - in2.seconds;

	if (in2.minutes > in1.minutes)
	{
		in1.hours--;
		temp.minutes = (in1.minutes - in2.minutes) + 60;
	}

	if (in2.minutes <= in1.minutes)
		temp.minutes = in1.minutes - in2.minutes;


	temp.hours = in1.hours - in2.hours;
	return temp;

}

void check_entry(time_type in)                  /* this function will cause the program to terminate if the user enters an incorrect parameter*/
{
	char c = ' ';
	if ((in.seconds >= 60) || (in.seconds < 0))
	{
		cout<<"You entered an invalid seconds number, Press return to exit"<<endl;
		cin.get(c);
		exit(1);
	}
	if ((in.minutes >= 60) || (in.minutes < 0))
	{
		cout<<"You entered an invalid minutes number, Press return to exit"<<endl;
		cin.get(c);
		exit(1);
	}
	if (in.hours < 0)
	{
		cout<<"You entered an invalid hours number, Press return to exit"<<endl;
		cin.get(c);
		exit(1);
	}
}

