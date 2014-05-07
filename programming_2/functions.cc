/*
 * Author: Abu Shumon
 * Student number: 224088
 * Program name: Who wants to be a millioner
 * Version : 1.0
 * All right reserved by the author.
 * This is implementation file of a reknown game "Who wants to be a millioner"
 * Details information about the game can be found here: 
 * http://www.cs.tut.fi/~prog2/homework/
 * 
 */

#include<iostream>
#include<vector>
#include<string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include<algorithm>
#include <ctime>
#include "main.hh"

using namespace std;

int randnumber(int ub); // Function to generate the random number.

/*
 * Member function decleration of AddfromFile
 * it maps the input to the data member
 */
void QuesType::AddfromFile(string d_level, string question, string o1, string o2, string o3, string o4, string c_ans){
   diflevel = d_level; // mapping to the data member for difficulty level
   ques  = question; // mapping the data member for question description
   option1 = o1; // mapping the data member for answer A 
   option2 = o2; // mapping the data member for answer B
   option3 = o3; // mapping the data member for answer C
   option4 = o4; // mapping the data member for answer D
   corrans = c_ans; // mapping the data member for correct answer
   cout << endl; //
   
}

/*
 * Member function decleration of AddQuestion
 * it maps the input to the data member
 * It vector and its one object is passed by reference.
 */
void QuesType::AddQuestion(vector<QuesType> &cv, QuesType &n2){
   string a; // Local variables in this scope
   string b; // Local variables in this scope
   string c; // Local variables in this scope
   string d; // Local variables in this scope
   string e; // Local variables in this scope
   string f; // Local variables in this scope
   string g; // Local variables in this scope
   cin.ignore(); //
   cout << "Enter difficulty level: "; // prompting the user for input
   getline (cin, a); // holding to the variable
   cout << "Enter question description: ";// prompting the user for input
   getline (cin, b, '?'); // holding to the variable
   cin.ignore(); //
   
   cout << "Enter Answer A: "; //
   getline (cin, c); // holding to the variable   
   cout << "Enter Answer B: "; // prompting the user for input
   getline (cin, d); // holding to the variable   
   cout << "Enter Answer C: "; // prompting the user for input
   getline (cin, e); // holding to the variable   
   cout << "Enter Answer D: "; // prompting the user for input
   getline (cin, f); // holding to the variable   
   cout << "Enter correct answer: "; // prompting the user for input
   getline (cin, g); // holding to the variable
   n2.AddfromFile(a, b, c, d, e, f, g); // binding the inputs to data members
   cv.push_back(n2); // adding the values to the vector	
}

/* Member function decleration of EditQuestion
 * it maps the input to the data member
 * It receives the specific question number from the user
 * and a reference of an object is passed as well
 */
void QuesType::EditQuestion(signed int target_qno, QuesType &n2, vector<QuesType > &contvec){
   vector<QuesType >::iterator myit; // class type iterator
   string a; // Local variables in this scope
   string b; // Local variables in this scope
   string c; // Local variables in this scope
   string d; // Local variables in this scope
   string e; // Local variables in this scope
   string f; // Local variables in this scope
   string g; // Local variables in this scope
   int i = contvec.size(); // Local variables in this scope
   int red_value = target_qno - 1;	 // Local variables in this scope	
   // checking whether the question is in valid range or not
   if(target_qno >= 0 && target_qno <= i){ //
	// printing the description of the question to be edited
	cout << "Editing question #" << target_qno << endl; //
	cout << "-------------------" << endl; //
	for (myit = contvec.begin()+red_value; myit < contvec.begin()+target_qno; myit++) //
	  myit -> PrintAQuestion(); //
	cout << "-------------------" << endl; //
	cin.ignore(); //
	cout << "Enter difficulty level: "; // prompting the user for input
	getline (cin, a); // holding to the variable
	cout << "Enter question description: "; //prompting the user for input
	getline (cin, b, '?'); // holding to the variable
	cin.ignore(); // 	
	cout << "Enter Answer A: "; // prompting the user for input
	getline (cin, c); // holding to the variable	
	cout << "Enter Answer B: "; // prompting the user for input
	getline (cin, d); // holding to the variable	
	cout << "Enter Answer C: "; // prompting the user for input
	getline (cin, e); // holding to the variable	
	cout << "Enter Answer D: "; // prompting the user for input
	getline (cin, f); // holding to the variable	
	cout << "Enter correct answer: "; // prompting the user for input
	getline (cin, g); // holding to the variable
	n2.AddfromFile(a, b, c, d, e, f, g); // binding the values	
	myit = contvec.begin()+red_value; // defining value of myit
	contvec.erase(myit); // erasing that specific content
	myit = contvec.begin()+red_value; // defining value of myit
	contvec.insert(myit, n2); // inserting the values to the location		
     }
   else{ //
      cout << "ERROR: Question number should be from 1 to " << contvec.size() << endl;
   } //
} //

/* Member function decleration of RemoveQuestion
 * it deletes the specific question based on the user input.
 * it reveives the specific question number the user wish to delete
 */
void QuesType::RemoveQuestion(int qno, vector<QuesType > &contvec){ //
   contvec.erase(contvec.begin() + qno - 1); //
} //

/* Member function decleration of PrintAll
 * it prints all the questions
 */
void QuesType::PrintAll(){ //
   cout << diflevel << endl; // printing difficulty level
   cout << ques << endl; // printing question description
   cout << option1 << endl; // printing option A
   cout << option2 << endl; // printing option B
   cout << option3 << endl; // printing option C
   cout << option4 << endl; // printing option D
   cout << corrans << endl; // printing correct answer
   
}

/* Member function decleration of PrintAQuestion
 * it prints a specific question
 */
void QuesType::PrintAQuestion(){ //
   cout << diflevel << endl; // printing difficulty level
   cout << ques << endl; // printing question description
   cout << option1 << endl; // printing option A
   cout << option2 << endl; // printing option B
   cout << option3 << endl; // printing option C
   cout << option4 << endl; // printing option D
   cout << corrans << endl; // printing correct answer   
}

/* Member function decleration of PrintByDLevel
 * it receives the specific difficulty level from the user
 * and prints the question(s)
 */
void QuesType::PrintByDLevel(string target_dlevel, vector<QuesType > &contvec){
   vector<QuesType >::iterator myit; // class type iterator
   string x; // Local variables in this scope
   int boundary; // Local variables in this scope
   // converting the string to integer value using stringstream
   stringstream(target_dlevel) >> boundary;
   // checking the valid range of the given difficulty level
   if(boundary > 0 && boundary <= Z){ //	
	// iterate over the class type vector.
	for(myit = contvec.begin(); myit< contvec.end(); myit++){ //
	     x = myit -> ReturnDLevel(); // it returns the difficulty level
	     if(target_dlevel == x) // if it matches with use's input
	       myit -> PrintAll();	// it prints the question.
	  } // end of for
     } // end of if
   else{ //
     cout << "Error: Difficulty level should be from 1 to 12" << endl; 
	} // end of else
}// end of function

/*
 * Member function decleration of ReturnDLevel
 * it returns the difficulty level of a question via private data member
 */
string QuesType::ReturnDLevel(){ //
   return diflevel; //
} //

/*
 * Member function decleration of SaveQuestion
 * it saves all the question with details to a file.
 */
void QuesType::SaveQuestion(vector<QuesType > &contvec /*string filename*/){ //
   // ofstream output_data(filename.c_str()); // stream to write in file
   // if(!output_data){
      // cout << "Error writing on file!" << endl;
   // }
   // else{
   ofstream output_data("224088_write.txt");
   string strarray[7]; // a string array
   vector<QuesType >::iterator myit; // class type iterator
   // iterate over the class type vector from begin to end
   for(myit = contvec.begin(); myit< contvec.end(); myit++){ //
	strarray[0] = myit -> diflevel; // storing value of difficulty level
	strarray[1] = myit -> ques; // storing value of question description
	strarray[2] = myit -> option1; // storing value of answer A
	strarray[3] = myit -> option2; // storing value of answer B
	strarray[4] = myit -> option3; // storing value of answer C
	strarray[5] = myit -> option4; // storing value of answer D
	strarray[6] = myit -> corrans; // storing value of correct answer
	
	for(int i = 0; i < 7; i++){ //
	  output_data << strarray[i] << endl;	// writing it to a file
	  } // end of for
     } // end of for
   cout << "successfully saved to a file" << endl;
  //}
} // end of function

/*
 * Member function decleration of SaveQuestion
 * it saves all the question with details to a file.
 * 
 */
vector<int> QuesType::GenerateSet(vector<QuesType > &contvec){
   vector<QuesType >::iterator myit; // class type iterator
   vector<vector<int> > twodimvec; // two dimentional vector declaration
   vector<int > empty; // one dimentional vector declaration
   for(int i = 0; i < Z; i++) // pushing the one dimentional vector to
     twodimvec.push_back(empty);	 // two dimentional vector
   int lu; // local variable in this scope
   int k = 0; // local variable in this scope
   string temp; // local variable in this scope	
   int tr = 0; // local variable in this scope
   int c = 0; // local variable in this scope
   tr = twodimvec.size(); // assigning the size of twodimvec to tr
   // iterate over the class type vector.
   for(myit = contvec.begin(); myit< contvec.end(); myit++){ //
	temp = myit -> ReturnDLevel(); // assigning difficulty level to temp
	stringstream(temp) >> lu; // converting temp to integer
	lu--; // reducing the value of integer by 1	
	// checking for the specific location to put the value of c
	if(lu == 0) //
	  twodimvec[lu].push_back(c);
	else if(lu == 1) //
	  twodimvec[lu].push_back(c);
	else if(lu == 2) //
	  twodimvec[lu].push_back(c); //
	else if(lu == 3) //
	  twodimvec[lu].push_back(c); //
	else if(lu == 4) //
	  twodimvec[lu].push_back(c); //
	else if(lu == 5) //
	  twodimvec[lu].push_back(c); //
	else if(lu == 6) //
	  twodimvec[lu].push_back(c); //
	else if(lu == 7) //
	  twodimvec[lu].push_back(c);//
	else if(lu == 8) //
	  twodimvec[lu].push_back(c); //
	else if(lu == 9) //
	  twodimvec[lu].push_back(c); //
	else if(lu == 10) //
	  twodimvec[lu].push_back(c); //
	else if(lu == (10+1)) //
	  twodimvec[lu].push_back(c); //
	
	c++; // increasing the value of c after each specific push back
     }	
   for(int i = 0; i < tr; i++){ //
	// checking the size of each row of twodimvec
	if(twodimvec[i].size() > 0){ //
	     // pasing the size to generate the random number
	     k = randnumber(twodimvec[i].size()); 
	     k--; // decreasing the value each time to keep track of index			
	     empty.push_back(twodimvec[i][k]); // pushing this to empty vector
	  } // end of if		
     } // end of for
   return empty; // returning that empty vector
} // end of function

/*
 * Funtction defination of randomnumber
 * it takes the upper bound as a parameter and generates a random number
 * in that range(0-uper bound)
 */
int randnumber(int ub){ //
   int upperBound = ub; // 
   srand(time(NULL));  // Initializes the random number generator. 
   int randomNumber = rand() % upperBound + 1; //
   return randomNumber;	//
} // end of function
