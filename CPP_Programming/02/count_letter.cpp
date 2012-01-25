/* count_letters.cpp: This program reads is a line from the user and outputs the number of alphabetical characters entered
*  Authors: Colm Nolan
*  Last modified: 01/03/11
****/

#include <iostream>
#include <vector>
#include <cstring>//
using namespace std;
const int MAXLENGTH = 200;

int main ()
{

    char letter = 'a';
    char capital_letter = 'A';
    int string_length = 0;

    int z = 0;


    char sentence[MAXLENGTH];
    vector<int> total_letters(26, 0);			//vector was used here to declare the array

    cout<<"Enter some words and the letters will be counted\n"<<endl;
    cin.getline(sentence,MAXLENGTH);

    string_length = strlen(sentence);


    while(letter <= 'z')						//loop through the alphabet and check any letters are in the sentence
    {
		for(int j = 0; j < string_length; j++)	//this loop will go through the element of the sentence array and check if the match the current letter
												//if it does the total_letters[] value will be incremented
		{
			if((letter == sentence[j]) || (capital_letter == sentence[j])) //both lower and higher case are checked here
			total_letters[z]++;
		}
		letter++;
		capital_letter++;
		z++;
    }


    letter = 'a';
    for(int i = 0; i < 26; i++)					//output the letters and the array containing the number of each letter
    {
		cout<<letter<<" = "<<total_letters[i]<<endl;
		letter++;
    }



    return 0;
}

