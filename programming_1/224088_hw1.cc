/*
* Author: Abu Shumon
* Student number: 224088
*/

/*
* This is a c++ program to caltulate the postage fee for Itella Corporation.
* What it does basically; takes amount of letter(s), weight of one letter, and
* the destination of the letter(s) as input. 
* And then give output to the user the total
* postage fee that is needed to send the letter(s).  
*/

#include <iostream>
#include <vector>
#include <iomanip>

// Constant declaration thats used in functions
const int TWENTY = 10*2;
const int FIFTY = 10*5;
const int HUNDRED = 10*10;
const int T_FIFTY = 10*10+10*5;
const int F_HUNDRED = 10*10*5;
const int ONE_T = 10*10*10;
const int TWO_T = 10*10*10*2;

using namespace std;

/*
* Function: cost_domestic
* Argument: two integer type parameter
* It takes the letter amount and letter weight and calculate
* the total cost for domestic destination of the letter(s)
*/


//function declaration and definitation
float cost_domestic (int letter_amount, int letter_weight)      
{
  int l_a = 0;      //variable declaration and initialization
  int l_w = 0;      //variable declaration and initialization
  double cost = 0;  //variable declaration and initialization
  
  // Assigns the values to local variables
  l_a = letter_amount;  
  l_w = letter_weight;
  
  // It checks the weight of the letter and 
  //afterwords calculate the total cost and display it.   
  if ( l_w <= FIFTY ){
	cost = l_a * (0.10 * 8);                           // calculates the cost
	cout << fixed << setprecision(2) << cost << endl;  // display the post fee with fixed precision
  }
  
  else if ( l_w <= HUNDRED ){
	cost = l_a * 1.10;                                 // calculates the cost
	cout << fixed << setprecision(2) << cost << endl;  // display the post fee with fixed precision
  }
  
  else if ( l_w <= T_FIFTY ){
	cost = l_a * (1.00 + 0.10 * 6);                     // calculates the cost
	cout << fixed << setprecision(2) << cost << endl;   // display the post fee with fixed precision
  }
  
  else if ( l_w <= F_HUNDRED ){
	cost = l_a * 3.00;									// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;   // display the post fee with fixed precision
  }
  
  else if ( l_w <= ONE_T ){
	cost = l_a * (4.00 + 0.10 * 5);						// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;   // display the post fee with fixed precision
  }
  
  else if ( l_w <= TWO_T ){
	cost = l_a * (7.00 + 0.10 * 5);						// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  return 0;
  
}


/*
* Function: cost_europe
* Argument: two integer type parameter
* It takes the letter amount and letter
* weight and calculate the total cost for Europian destination of the letter(s)
*/

//function declaration and definitation
float cost_europe (int letter_amount, int letter_weight)
{
  int l_a = 0;       //variable declaration and initialization
  int l_w = 0;       //variable declaration and initialization
  double cost = 0;   //variable declaration and initialization
  
  // Assigns the values to local variables
  l_a = letter_amount;
  l_w = letter_weight;
  
  // It checks the weight of the letter and 
  // afterwords calculate the total cost and display it.   
  if ( l_w <= TWENTY ){
	cost = l_a * 0.8;                                  // calculates the cost
	cout << fixed << setprecision(2) << cost << endl;  // display the post fee with fixed precision 
  }
  
  else if ( l_w <= FIFTY ){
	cost = l_a * 1.10;									// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;   // display the post fee with fixed precision
  }
  
  else if ( l_w <= HUNDRED ){
	cost = l_a * 1.00 + 0.10 * 5.5;						// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  else if ( l_w <= T_FIFTY ){
	cost = l_a * (2.00 + 0.10 * 5.5);					// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  else if ( l_w <= F_HUNDRED ){
	cost = l_a * (4.00 + 0.10 + 0.10);					// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  else if ( l_w <= ONE_T ){
	cost = l_a * (7.00 + 0.10 * 6);						// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  else if ( l_w <= TWO_T ){
	cost = l_a * (10.00 + 3.00 + 0.10 * 8);				// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  return 0;
  
}


/*
* Function: cost_other
* Argument: two integer type parameter
* It takes the letter amount and letter weight
* and calculate the total cost for the other 
* destination of the letter(s)
*/


//function declaration and definitation
float cost_other (int letter_amount, int letter_weight)      
{
  int l_a = 0; //variable declaration and initialization
  int l_w = 0; //variable declaration and initialization
  double cost = 0; //variable declaration and initialization
  
  // Assigns the values to local variables
  l_a = letter_amount;
  l_w = letter_weight;
  
  // It checks the weight of the letter and
  // afterwords calculate the total cost and display it.   
  if ( l_w <= TWENTY ){
	cost = l_a * 0.8; 									// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;   // display the post fee with fixed precision
  }
  
  else if ( l_w <= FIFTY ){
	cost = l_a * (1.00 + 0.10 * 5.5); 					// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  else if ( l_w <= HUNDRED ){
	cost = l_a * (3.00 + 0.10 + 0.10); 					// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  else if ( l_w <= T_FIFTY ){
	cost = l_a * (5.00 + 0.10 + 4);						// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  else if ( l_w <= F_HUNDRED ){
	cost = l_a * (8.00 + 0.10 * 8);						// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  else if ( l_w <= ONE_T ){
	cost = l_a * (10.00 + 5.00 + (0.10 * (9.00 + 0.10*5)));	// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;		// display the post fee with fixed precision
  }
  
  else if ( l_w <= TWO_T ){
	cost = l_a * (10.00 + 10.00 + 8.00 + 0.10 * 6);		// calculates the cost
	cout << fixed << setprecision(2) << cost << endl;	// display the post fee with fixed precision
  }
  
  return 0;
  
}

int main ()
{
  char letter_destination;	//variable declaration
  int letter_amount = 0;	//variable declaration and initialization
  int letter_weight = 0;	//variable declaration and initialization
  do
  {
    center: // Center declaration because of "goto" 
			// implementation in the main function. 
		
	cout << "Enter the amount of letters to send:" << endl;   		// Ask user to give input the amount of letter    		
    cin >> letter_amount;
	
	if ( letter_amount > 0 ){   									// Checks valid weight.
	  top:						// Another "goto" statement declaration.
								// It takes the user to put the weight again 
								//if the given weight is invalid.
		
		cout << "Enter the weight of one letter in grams:" << endl;  // Ask user to give input the weight of letter   
		cin >> letter_weight;
		if ( letter_weight <= 0 ){									 // Checks if the letter weight is less than equal zero.
		  cout << "Error: invalid weight" << endl;					 // error message 
		  goto top;
		}
		else if ( letter_weight > TWO_T ){			    			 // Checks if the letter weight is greater than 2000.
		  cout << "Error: cannot be sent as a letter" << endl; 		 //error message
		  break;													 // breaks the loop instead the looping condition is not false yet.
		}
		else {
		  cout << "Enter the destination (D)omestic, (E)urope, (O)ther:" << endl;  // Ask user to give input the destination of letter 
	      cin >> letter_destination;
		  
		  // Compare the destination to call the appropriate function
		  if ( letter_destination == 'D' || letter_destination == 'E' || letter_destination == 'O' ){
		    if (letter_destination == 'D'){
			  cost_domestic(letter_amount, letter_weight);  //Calling function
			}
		    else if ( letter_destination == 'E' ){
			  cost_europe(letter_amount, letter_weight);  	// Calling function
			}
		    else if ( letter_destination == 'O' ){
			  cost_other(letter_amount, letter_weight);  	// Calling function
			}
		  }
		  else{
		    cout << "Error: unknown destination" << endl; 	//error message 
			goto center;												
		  }
		}
	}
	else{
	  break;
	}
  }while( letter_amount != 0 );
  return 0;
}