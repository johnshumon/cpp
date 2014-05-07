/*
 * Author: Abu Shumon
 * Student number: 224088
 * Program name: Counter
 * Version : 1.0
 * All right reserved by the author.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <istream>
#include <sstream>
#include <cctype>

using namespace std;

#define A_SIZE 2000
#define FIXED_PRINT 1000

char word_count( string sentence[A_SIZE], int length );
char dup_check( char temp2[A_SIZE][A_SIZE], int j );
char display ( string unique[A_SIZE], int j, int d);


//this is the main function for the execution of the program
int main ()
{
  string sentence [A_SIZE]; // decleration of string array
  int element = 0;  // decleration of variable
  int mp_tracker = 0;  // decleration of variable
  
  while ( 1 ) // intfine loop starts
  {
    getline (cin, sentence[element] ); // taking input from the user
	
	mp_tracker = sentence[element].find("#", 0); // if input conatins #
	//sentence[element].find("#", 0) != string::npos
	
	if ( mp_tracker > 0 ) // error conditon checking
	{  
	  cout << "Misplaced # found" << endl; // error message
	}
	else if ( sentence[0][0]  == '#' ) // if # appears at the begining
	{
	  cout << "Empty input" << endl;  // error message
	  continue;
	}
	
	element++; // incrementing the line of the stirng array
	
	if ( sentence[element-1][0]=='#') // end condition of the program
	{
	  word_count (sentence, element); // calling function word_count
	  break;
	}
    
	
  } 
  return 0;
}

char word_count (string sentence[A_SIZE], int element) // function defination
{
  char temp2 [A_SIZE][A_SIZE];   // character array decleration
  char temp3 [A_SIZE][A_SIZE];  // character array decleration
  char temp [A_SIZE][A_SIZE];  // character array decleration
   
  // variable decleration
  int line = 0;
  int line_length = 0;
  int total_line = 0;
  int each_char = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  
  total_line = element; // taking the value of element into the variable
   
  for ( line = 0; line < total_line-1; line++ )  // for loop started
  {
	// taking the length of each line
	line_length = sentence[line].length(); 
	
	for ( each_char = 0; each_char < line_length; each_char++){
	  temp[line][each_char] = char ( sentence[line] [each_char] );
	  l = char ( sentence[line] [each_char] );
	  
	  //checking whether its letter, digit or '
	  if ( isalpha(temp[line][each_char]) || 
		   isdigit(temp[line][each_char]) || 
		   l == (6*6+3)){
	    // putting the value into array
		temp2[j][k] = char (tolower(temp[line][each_char]));
                temp3[j][k] = char (tolower(temp[line][each_char]));  
		k++;  // increasing column value
	  }
	  else
	  {
		// checking to put the null character at the end of a word
		if ( (temp[line][each_char] == ' ') &&
		    (temp[line][each_char+1] != ' ') && k!='\0' )
		{
		  temp2[j][k] = '\0';
		  j++;  // increasing row value
		  k = 0;  // setting the column position at the begining
		}
	  }
	    
	}
	
	if ( k != 0 ) // checking to put the null character 
				  //at the end of the line
	{
	  temp2[j][k] = '\0';
	  j++;  // increasing row value
	  k = 0;  // setting the column position at the begining
	}
	
  }
  dup_check ( temp2, j ); // calling the function
  return 0;
}

char dup_check( char temp2[A_SIZE][A_SIZE], int j )  // function defination
{
  // variable decleration 
  string unique [A_SIZE];
  int m = 0;
  int n = 0; 
  //int d = 1
  int p = 1;
  int q = 0;
  
  
  string unq1 = "\0";
  string unq2 = "\0";

  unique [0] = temp2[0];
  
  //unq1 = temp2[m];
  //unq2 = temp2[n];
   
  for ( m = 1; m < j; m++)
  {
    for ( n = 0; n < j; n++)
	{
	  
          unq1 = temp2[m];
	  unq2 = unique[n];

	  // comparing two string using member function "compare"
	  if ( (unq1.compare(unq2) == 0) )  
	  {
	    
            if (n !=  m)
	    {
	      cout<< unique[p] << endl;
              q = 1;
              break;
	    }
            
	  }
	    
	}
	
	// if it doesn't match then its inserted.
	if ( q != 1)
	{
	  unique[p] = unq1;
          //cout<< unique[p] << endl;
	  p++;
	  

	}
	q = 0;
  }
   
  
  display(unique, j, p);  // calling the display function
   
  return 0;
   
}

char display ( string unique[A_SIZE], int j, int p) {
  // variable decleration
  int count = j;
  //int uniq_word = d;
  int max_length = 0;
  int space = 0;
  int x = 0;
  if ( p > FIXED_PRINT){
     x = 1;
  }
  // taking the length of largest word
  for ( int i = 0; i < p; i++) {
    int length = unique[i].length();
	if ( length > max_length){
	  max_length = length;
	}
  }
  if ( x == 1){
    cout << "Error: too many words in input" << endl;
  }
 // printing as defined in the specification
  cout << '|' << " " << "word";  
  space = max_length - 4;
  for ( int i = 0; i < space; i++){
    cout << " "; // prints the necessary space after "word"
  }
  cout << " " << '|' << endl; // prints side bar
  for (int i = 0; i < max_length + 4; i++ ){
    cout << '-'; // prints the line after "word"
  }
  cout << endl;
  if ( x == 1){
    for ( int i = 0; i < FIXED_PRINT; i++){
      cout << '|' << " " << unique[i]; // prints side bar
      int length_ew = unique[i].length();
      space = max_length - length_ew;
      for (int t = 0; t < space; t++) {
	  cout << " "; // prints space
      }
	cout << " " << '|' << endl;
    }
  }
  else{
    for ( int i = 0; i < p; i++){
      cout << '|' << " " << unique[i]; // prints side bar
      int length_ew = unique[i].length();
      space = max_length - length_ew;
      for (int t = 0; t < space; t++) {
	cout << " "; // prints space
      }
      cout << " " << '|' << endl;
    }
  }
  for (int i = 0; i < max_length + 4; i++ ){
    cout << '-'; // prints the line before "total"
  }
  cout << endl;
  cout << "TOTAL: " << count << endl; // prints the total number of words
   return 0;
}