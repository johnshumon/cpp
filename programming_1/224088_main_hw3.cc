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
 * this is the main function of the program
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

// This is the main function
int main(){
   string filename;  // variable decleration that keeps the input file name
   vector<string> words; // decleration of a vector of string
   string line; // string decleration that keeps data of input file
   string temp; string temp2;   string temp3; // decleration of 3 temporary string
   // decleration of 3 integer variable used for length, hash position and countig words
   int leng = 0;   int hash_pos = 0;   int counter = 0;
   ifstream reading_data;  // object of stream class to read from file
   ofstream output_data ("out.txt"); // object of stream class to write on file
   do{
      cout << "Enter the file name:"; //ask user to give the correct file name
      getline (cin, filename);  // reads the file name in "filename"
      if(filename == "a.txt"){ // check whether the filename is correct or not
	 reading_data.open(filename.c_str()); // opens the input file
	 while(!reading_data.eof()){ // reads the file until end
	    reading_data >> line; // reading the file and putting data into line
	    leng = line.size();   // gets the size of each line
	    hash_pos = line.find("#", 0); // finds whether the line contain hash
	    if(line == "#" && leng == 1 && counter == 0){ // if hash at begining
	       output_data << "Empty input" << endl; // it shows the error
	    }
	    else if(line == "#" && leng == 1 && counter != 0){ // end condition
	       break; // end of input is indicated by a line  
	    }     // with only the character # on it.
	    if( hash_pos >= 0 && leng > 1 ){  // if hash appears anywhere else
	       output_data << "Misplaced # found" << endl; // it shows the error
	    }
	    for(int i = 0; i < int (line.size()); i++){
	       if( (ispunct(line[i]) && (line[i]!='\'') ) ){ // if there is a 
		  line.erase(i,1);  // punctuation except ' then it erase that.
		  i--;						
	       }
	    }
	    for(int i = 0; i < int (line.size()); i++){
	       line[i] = char(tolower(line[i])); // putting all the elements to 
	    }								   // lower character
	    stringstream a(line);  // taking them into stringstream
	    while(a >> temp){      // putting them into the temp string
	       counter++;              // counting the words
	    }
	    stringstream ab(line); // taking them into stringstream
	    int flag = 0;          // a flag variable is initialized
	    while(ab >> temp){     // putting them into the temp string
	       flag = 0;
	       stringstream bc(temp2); // taking them into stringstream
	       while( bc >> temp3){    // putting them into the temp3 string
		  if (temp == temp3){  // comparing them for duplicate words
		     flag = 1;         // if yes then incresing the flag value
		  }
	       }if ( flag == 0){       // if not then
		  temp2.append(temp); // then are appending into the temp string
		  temp2.append(" ");  // appending space after each words
	       }
	    }
	 }
      } else{ // if the input file name is worng then this eror message appears
	 cout << "Error failed to read the file" << endl; // promp user again.
      }
   }while(filename != "a.txt"); // loop continues until the correct file name
   customize(temp2, words, counter); // calling the customize function
   return 0; } // return value

