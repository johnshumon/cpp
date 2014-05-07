/*
 * Author: Abu Shumon
 * Student number: 224088
 * Program name: Distinct word Counter
 * Version : 1.0
 * All right reserved by the author.
 * The program basically ask user to give the file name from where
 * input will be taken.
 * After taking the string from the file, the program removes all 
 * white spaces, punctions(except "\'"), seperate each words, counts
 * the total number of words, and display all the unique words in a nice table
 * Two function(customize and display) are written in this purpose and this
 * file contains them
 */
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <algorithm>

#include "header.hh"


using namespace std;
/*
 * Function customize
 * Argument: string, vector of string, integer
 * It takes then string temp2, and then put it into stringstream
 * From the sringstream it puts into the vector word by word
 * And afterwards it sorts the vector using the builtin function sort
 * When the sort is completed, it call the display function to show
 * desired output written in the specification  
 */

void customize( string temp2, vector<string>& words, int& counter)
{
   string t; // it will take the value of temp2 and put it in vector
   
   stringstream c(temp2); // taking temp2 into the stringstream
   
   // taking each word from the stringstream and putting into the vector
   while(c >> t){
      words.push_back(t);  // putting the words into the vector words
   }
   
   sort(words.begin(), words.end());  // sorting the vector
   
   display(words, counter);  // calling the display function
}

/*
 * Function: Display
 * Arguments: vector of string, integer
 * It takes the reference of the word vector and number of words in it
 * And show the output as specified
 * It prints the so far statistics in the out.txt file, but if the input file
 * contains more than 1000 distinct words, then it prints the 1000 words
 * in a ascending order, and the total number of words in the input file.
 */
void display(vector<string>& words, int& counter)
{
   // declaration of an stream used to write values in the out.txt file
   ofstream output_data("out.txt",ios::app);
   
   int max_length = 0; // variable declaration
   int length = 0;     // variable declaration
   int space = 0;      // variable declaration
   int x = 0;          // variable declaration
   if ( counter > FIXED_PRINT){ // checking the condition for more then 1000 words
      x = 1;    // keeping track for more than 1000 words
   }
   if ( x == 1){ // if words are > 1000, it will show this error message
      output_data << "Error: too many words in input" << endl; // error mesage
   } // it will keep the length of the largest word in the file.
   for ( int i = 0; i < int(words.size()); i++){
      length = words[i].length();      // taking the length of the word
      if ( length > max_length){       // searching the maximum length
	  max_length = length;             // taking maximum length to max_length
      }
   }
   output_data << '|' << " " << "word";  // prints "word" at the top 
   space = max_length - 4;    // prints the required space after word
   
   for ( int i = 0; i < space; i++){
      output_data << " "; // prints the necessary space after "word"
   }
   output_data << " " << '|' << endl; // prints side line
   
   for (int i = 0; i < max_length + 4; i++ ){
      output_data << '-'; // prints the line after "word"
   }
   output_data << endl;
   if( x == 1 ){ // it will print upto 1000 words
      for ( int i = 0; i < FIXED_PRINT; i++){
	 output_data << '|' << " " << words[i]; // prints side bar
	 int space_after_word = words[i].length();  // takes length of the word
	 space = max_length - space_after_word;  // necessary spaces calculation
	 for (int t = 0; t < space; t++) {
	    output_data << " "; // prints space
	 }
	 output_data << " " << '|' << endl;  // prints sideline after words
      }
   }
   
   else{ // if the word is < 1000, then it will print so far.
      for ( int i = 0; i < int(words.size()); i++){
	 output_data << '|' << " " << words[i]; // prints side bar
	 int space_after_word = words[i].length(); // takes length of the word
	 space = max_length - space_after_word; // necessary spaces calculation
	 for (int t = 0; t < space; t++) {
	    output_data << " "; // prints space
	 }
	 output_data << " " << '|' << endl; // prints the side line
      }
   }
   for (int i = 0; i < max_length + 4; i++ ){
      output_data << '-'; // prints the line before "total"
   }
   output_data << endl; // prints the newline
   output_data << "TOTAL: " << counter << endl; // prints the total number of words
}
