/* copy.cpp: This program creates a copy of an exiting text file.
*  Authors: Colm Nolan
*  Last modified: 02/03/11
***/

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    char file_text[100];

    fstream input_file;							//declare object input_file of class fstream
    input_file.open("copy_me.txt",ios::in);		//use the function ios::in to bring the file copy_me.txt into the stream input_file

    fstream output_file;						//declare object output_file of class fstream
    output_file.open("i_am_new.txt", ios::out);	//use the function ios::out to make the stream out_file

    input_file.get(file_text,100);				//copy the input_file stream into the char array file_text array

    output_file<<file_text;						//copy from the array into the output_file

    cout<<"the text file has been copied"<<endl;

    input_file.close();							//close streams
    output_file.close();
	
    return 0;
}
