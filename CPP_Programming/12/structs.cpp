/* structs.cpp: this program places data into an struct. the data from this struct is then copied into another struct which
*  is printed out to the screen.
*  Authors: Colm Nolan
*  Last modified: 08/03/11
***/

#include <iostream>
#include <cstring>
using namespace std;
const int MAXLEN=100;

struct person                                   /* A struct is declared here with members
						fname,sname,age height,weight*/
{
	char fname[MAXLEN];
	char sname[MAXLEN];
	int age;
	double height;
	double weight;
};

typedef struct person record;                   /* creatiaing an alias called record for struct record */

void fillperson(record& record_name, const char fname[], const char sname[], const int years_old, const double p_height, const double p_weight);
                                                /* this prototype will take a "record" type which is the only variable that can be altered in the funtion sense all the rest are consts*/
void makecopy(const record& record_name, record& new_record); /* this takes in to parameters of type record and only the second parameter can be altered */
void printperson(const record& record_person);
                                                
int main ()
{
	record fred, fredcpy;                   /* creating instances of the class record */
	fillperson(fred, "fred", "murphy", 22, 180.0, 83.2); /* sending in the data to the struct fred */
	makecopy(fred, fredcpy);                /* calling the copy funtion with two parameters fred and fredcpy */
	printperson(fredcpy);
	return 0;
}

void fillperson(record& record_name, const char fname[], const char sname[], const int years_old, const double p_height, const double p_weight)
{
	strcpy(record_name.fname, fname);       /* copying the the details into the struct */
	strcpy(record_name.sname, sname);
	record_name.age = years_old;
	record_name.height = p_height;
	record_name.weight = p_weight;
}

void makecopy(const record& record_name, record& new_record)
{
	strcpy(new_record.fname, record_name.fname); /* copying from one struct to the next */
	strcpy(new_record.sname, record_name.sname);
	new_record.age = record_name.age;
	new_record.height = record_name.height;
	new_record.weight = record_name.weight;
}

void printperson(const record& record_person)
{
	cout<<"First Name: "<<record_person.fname<<endl; /* printing out the data witin the struct */
	cout<<"Surname: "<<record_person.sname<<endl;
	cout<<"Age: "<<record_person.age<<endl;
	cout<<"Height: "<<record_person.height<<endl;
	cout<<"Weight: "<<record_person.weight<<endl;
}
