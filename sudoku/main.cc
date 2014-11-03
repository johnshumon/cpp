/* Design and Implementation of Data Structure
*  project: Sudoku
*  main file.
*    
*  implemented by ABU SHUMON
*  Student number: 224088
*/

#include <iostream>

#include "sudokusolver.hh"

using namespace std;

int main()
{
	sudoku example;
	example.getinput();//Take input.
	if(example.solveSudoku()){
		example.printSudokuGrid();
	}
	else{
		cout<<no_solution_found<<endl;
	}
	
	return 0;	
}
