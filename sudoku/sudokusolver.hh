/* Design and Implementation of Data Structure 
*  project: Sudoku
*  declaration of data structure file with 
*  data member and member function.
*  implementation is written in .cc file
*  
*  implemented by ABU SHUMON
*  Student number: 224088
*/

#ifndef SUDOKUSOLVER_HH
#define SUDOKUSOLVER_HH


#define no_solution_found 0

// struct "Point" to set value in a square of the sudoku board.
typedef struct {
        bool set;
        int value;
        bool val_poss[32];//for a sudoku of 2 x 2, the value possible will be 1,2,3,4, So if a point can have value 0,1,4 then val_pass = {1,1,0,1}. where 1 is True and 0 is False.
        int count_val_possible;  //it keeps a count how many values are possible for each point.
                                 //This makes it easy to find when a point can be filled by only one point.
    }Point;			   

// class sudoku
class sudoku
{
	public:
		sudoku()
		{
				R = 0;
				C = 0;
		}
    
		void printSudokuGrid(); // prints the final board.
		bool solveSudoku(); // solve the sudoku if any
		bool iterative_SolveSudoku(); // solves the given sudoku 
		bool rec_solveSudoku(); // recursively solves the board.
		bool findEmptyGridSlot ( int&row, int&col); // finds the empty square grid if any
		bool numAlreadyInRow ( int row, int num );	// checks if the number already in the row	
		bool numAlreadyInCol ( int col, int num );  // checks if the number already in the column
		bool numAlreadyInBox ( int Row, int Col, int num ); // checks if the number already in the sub region
		bool canPlaceNum ( int row, int col, int num );  // checks if possible to place number
		void getinput();             // take inputs for a sudoku grid
		
	private:
		Point grid[32][32]; 
		int R,C;
		int Elem_in_1_row;

};
	
#endif

