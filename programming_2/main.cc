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
void option(); // User selects the option from the menu.
// Execute options depending on the selected option
void selectOption(vector<QuesType> &contvec, vector<int> &john, QuesType &n1, QuesType &n2, int on /*string filename*/);
int randnumber(int ub); // Function to generate the random number.

int main(){ // Main function where program begis to execute
   vector<QuesType> contvec; // Class type vector
   vector<int> john; // Vector used to print the generated question.
   vector<QuesType >::iterator myit; // Class type iterator to iterate
   QuesType n1; // An object of the class QuesType
   QuesType n2; // An object of the class QuesType
   string line; // variable to hold the input from file line by line
   int opnumber; // variable that holds the option given by the user
   string d_level; // variable that holds difficulty level
   string question; // variable that holds question description
   string o1; // variable that holds answer A
   string o2; // variable that holds answer B
   string o3; // variable that holds answer C
   string o4; // variable that holds answer D
   string c_ans; // variable that holds correct answer
   char in_or_out; // variable that holds answer exit or stay
   string filename;
   cout << "Enter the file name: ";
   cin >> filename;
   
   ifstream reading_data(filename.c_str());
   if(!reading_data){
    cout<<"Error opening file!"<<endl;
   }
    else{
	cout << "Text file successfully loaded." << endl; //
   // ifstream reading_data("b.txt");
   while(!reading_data.eof()){ // reading data till end of file
	getline (reading_data, line); // reading data line by line
	d_level = line; // assigning it to variable
	getline (reading_data, line, '?'); // reading data line by line
	question = line; // assigning it to variable
	reading_data.ignore(); // reading data line by line
	getline (reading_data, line); // reading data line by line
	o1 = line; // assigning it to variable
	getline (reading_data, line); // reading data line by line
	o2 = line; // assigning it to variable
	getline (reading_data, line); // reading data line by line
	o3 = line; // assigning it to variable
	getline (reading_data, line); // reading data line by line
	o4 = line; // assigning it to variable
	getline (reading_data, line); // reading data line by line
	c_ans = line; // assigning it to variable
	n1.AddfromFile(d_level, question, o1, o2, o3, o4, c_ans); //
	contvec.push_back(n1); // pushing back the object to the vector
	} // end of reading from file
    cout << "Number of Questions - " << contvec.size() << endl;
	
   do{
	option();  // Calling the option function to select the menu
	//filename=argv[1]; //
	cin >> opnumber; // Putting the given value to option number
	selectOption(contvec, john, n1, n2, opnumber /*filename*/); //
	// Ask user whether to continue or not
	cout << "Press y to continue, exit otherwise: "; //
	cin >> in_or_out; // Putting the input to the variable		
     }while(in_or_out == 'y' || in_or_out == 'Y'); //endl of dowhile
	}

   return 0;
}//end of main

/*
 * Option function definitation
 * It gives the user to select different option from the manu
 * Its a void function, so it returns nothing
 */
void option(){ //
   cout << "Select menu item: " << endl; //
   // Option for add a new question
   cout << "[1] Add a new question" << endl; 
   cout << "[2] Edit a question" << endl; // Option for edit a question
   // Option for delete a question
   cout << "[3] Remove a question" << endl; 
   //Option for print all questions
   cout << "[4] Print all questions" << endl;
   // Option for print specific question
   cout << "[5] Print a question by number" << endl; 
   // Option for print question based on difficulty level
   cout << "[6] Print questions of a given difficulty level" << endl; 
   // Option for save questions to file
   cout << "[7] Save questions to a file" << endl; 
   // Option for generate question set
   cout << "[8] Generate a question set" << endl; 
   // Option for print the generated question set
   cout << "[9] Print the generated question set" << endl; 
   cout << "Your choice:"; //
}

/* Function defination of selectFunction
 * It performs the specific task based on the option selected 
 * by the user. It receives two ojects of the class, and the option number
 * And after completing the task, it returns cursor to the main function.
 */
void selectOption(vector<QuesType> &contvec, vector<int> &john, QuesType &n1, QuesType &n2, int on /*string filename*/){
   vector<QuesType >::iterator myit; // Class type iterator to iterate
   int qno; // integer variable that holds the question number
   signed int target_qno; // integer variable hold the target question
   int vanuhi = 0; // integer variable holds the size of john vector
   string target_dlevel; // string variable holds the target difficulty
   int bal = contvec.size();
   switch(on){ // selects options based on the user input     
      case 1: // perform the add new question task
	n2.AddQuestion(contvec, n1); // call the member function
	break; // breaks after case 1			
      case 2: // perform the edit question task
	cout << "Select question number [1-" << contvec.size() << "]: "; //
	cin >> target_qno; // takes the question number from the user			
	n2.EditQuestion(target_qno, n2, contvec); // pass it to the member function
	break; // breaks after case 2			
      case 3: // perform remove question task
	cout << "Enter the question number you wish to delete: " << endl; //
	cin >> qno; // takes the question number from the user
	n2.RemoveQuestion(qno, contvec); // pass it to the member function
	break; // breaks after case 3			
      case 4: // perform print all the questions task
	// irerates over the vector and prints all the question
	for (myit = contvec.begin(); myit< contvec.end(); myit++) //
	  myit->PrintAll(); //
	break; // breaks after case 4	
      case 5: // perform print a specific question task
	
	cout << "Enter the question number [1 - " << contvec.size() << "]: "; //
	cin >> target_qno; // takes the question number from the user
	// irerates over the vector and prints that question
	if (target_qno > 0 && target_qno < bal){
	for (myit = contvec.begin()+target_qno-1; myit < contvec.begin()+target_qno; myit++)
	  myit -> PrintAQuestion(); //
	}
	else{
	   cout << "ERROR: Question number should be from 1 to" << contvec.size() << endl;
	}
	break; // breaks after case 5			
      case 6: // perform the print by difficulty level task
	cout << "Enter the difficulty level to print the questions: ";
	cin >> target_dlevel; // takes the diffculty level from the user
	n2.PrintByDLevel(target_dlevel, contvec); //
	break; // breaks after case 6			
      case 7: // perform the save questions to file task
	n2.SaveQuestion(contvec /*filename*/); // call the member function
	break; // breaks after case 7			
      case 8: // perform the generate question set task.
	john = n2.GenerateSet(contvec); // call the member function			
	break; // breaks after case 8			
      case 9: // perform the print generate function
	vanuhi = john.size(); //
	for (int i = 0; i < vanuhi; i++){ //
	     myit = contvec.begin()+ john[i]; // 
	     myit -> PrintAQuestion(); //
	  } // end fo for
	break; // breaks after case 8
     } // endl of switch	
} // end of function

