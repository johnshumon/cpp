/* Design and Implementation of Data Structure
*  project: Sudoku
*  definition of data structure file with 
*  data member and member function.
*    
*  implemented by ABU SHUMON
*  Student number: 224088
*/

#include <iostream>

#include "sudokusolver.hh"

using namespace std;

// Function prints the sudoku grid	
void sudoku::printSudokuGrid()
{
	for(int i=0;i<R*C;i++){
		for(int j=0;j<R*C;j++){
			cout<<grid[i][j].value<<" ";
		}
		cout<<endl; 
	}
}


bool sudoku::solveSudoku()
{
	if(iterative_SolveSudoku()){
		return rec_solveSudoku();
	}
	else{
		return false;
	}
}

bool sudoku::iterative_SolveSudoku()
{
	//Find out possible values for each element that is not set.
	for(int i = 0;i<Elem_in_1_row;i++)
	{
		for(int j = 0;j<Elem_in_1_row;j++)
		{
			if(grid[i][j].set)
			{
				int temp = grid[i][j].value;
				for(int k=0;k<Elem_in_1_row;k++)
					{
						if(!grid[i][k].set)//Checking each element in the row of grid[i][j], make all elements that are not set cannot have value grid[i][j].value
						{
							if(grid[i][k].val_poss[temp-1])
							{
								grid[i][k].count_val_possible--;
								grid[i][k].val_poss[temp-1] = false;//Since, index 0 represents whether 1 can be inserted in box or not
							}								
						}
						if(!grid[k][j].set)//Checking each element in the column of grid[i][j], make all elements that are not set cannot have value grid[i][j].value
						{
							if(grid[k][j].val_poss[temp-1])
							{
								grid[k][j].count_val_possible--;
								grid[k][j].val_poss[temp-1] = false;//Since, index 0 represents whether 1 can be inserted in box or not
							}
						}
					}
				for(int k=(i/R)*R;k<(i/R + 1)*R;k++)//Checking each element in the subgrid of grid[i][j], make all elements that are not set cannot have value grid[i][j].value
				{
					for(int l=(j/C)*C;l<(j/C+1)*C;l++)
					{
						if(!grid[k][l].set)
						{
							if(grid[k][l].val_poss[temp-1])
							{
								grid[k][l].count_val_possible--;
								grid[k][l].val_poss[temp-1] = false;//Since, index 0 represents whether 1 can be inserted in box or not
							}
						}
					}
				}
			}
		}
	}
	//Now, we have set all the possible values for each element possible.
	//If number of values possible for an element is zero, that element cannot be set and sudoku will not be solved.
	//If number of values possible for an element is one, that element can be set by only one element.
	//Therefore, we set the element and update all elements in its row, column and subgrid that no other 
	//element can have that value.
	bool change;//We keep iterating till no change is made for a whole iteration over the grid.
	do
	{
		change=false;
		for(int i=0;i<Elem_in_1_row;i++)
		{
			for(int j=0;j<Elem_in_1_row;j++)
			{
				if(!grid[i][j].set&&grid[i][j].count_val_possible==0)//i,j th element cannot have any value
				{
					return false;
				}
				else if(!grid[i][j].set&&grid[i][j].count_val_possible==1)//update ith row, jth column and the subgrid containing (i,j)th element.
				{
					//
					grid[i][j].set = true;
					change = true;
					for(int k=0;k<Elem_in_1_row;k++)//set the value for i,j th element
					{
						if(grid[i][j].val_poss[k])
						{
							grid[i][j].value = k+1;
						}
					}

					int temp = grid[i][j].value;
					for(int k=0;k<Elem_in_1_row;k++)
					{
						if(!grid[i][k].set)//Checking each element in the row of grid[i][j], make all elements that are not set cannot have value grid[i][j].value
						{
							if(grid[i][k].val_poss[temp-1])
							{
								grid[i][k].count_val_possible--;
								grid[i][k].val_poss[temp-1] = false;//Since, index 0 represents whether 1 can be inserted in box or not
							}								
						}
						if(!grid[k][j].set)//Checking each element in the column of grid[i][j], make all elements that are not set cannot have value grid[i][j].value
						{
							if(grid[k][j].val_poss[temp-1])
							{
								grid[k][j].count_val_possible--;
								grid[k][j].val_poss[temp-1] = false;//Since, index 0 represents whether 1 can be inserted in box or not
							}
						}
					}
					for(int k=(i/R)*R;k<(i/R + 1)*R;k++)//Checking each element in the subgrid of grid[i][j], make all elements that are not set cannot have value grid[i][j].value
					{
						for(int l=(j/C)*C;l<(j/C+1)*C;l++)
						{
							if(!grid[k][l].set)
							{
								if(grid[k][l].val_poss[temp-1])
								{
									grid[k][l].count_val_possible--;
									grid[k][l].val_poss[temp-1] = false;//Since, index 0 represents whether 1 can be inserted in box or not
								}
							}
						}
					}
				}
			}
		}
	}while(change);
	return true;
}
     
bool sudoku::rec_solveSudoku()        // If a solution to the Sudoku problem exists, it returns true, otherwise it returns false.
{	
	int row, col;
	if (findEmptyGridSlot ( row, col )){
		for(int num = 1; num<= Elem_in_1_row; num++)
		{
			if(canPlaceNum ( row, col, num )){
				grid[row][col].value = num;
				grid[row][col].set = true;
				if (rec_solveSudoku( ) )   // recursive call
					return true;
				grid[row][col].value = 0;
				grid[row][col].set = false;
			}
		}
	return false;	// backtrack call
	}
	else{
		return true;	// there are no empty slots, puzzle is solved
	}
	
}


// Function to determine if the grid slot specified by row and col is empty.
// Postcondition: Returns true if grid[row][col] = 0;
bool sudoku::findEmptyGridSlot ( int&row, int&col)
{
	int i,j;
	for(i=0;i<Elem_in_1_row;i++){
		for(j=0;j<Elem_in_1_row;j++){
			if(!grid[i][j].set){
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}

// Function to determine if num is in grid[row][]
// Postcondition: Returns true if num is in grid[row][] otherwise it returns false.
bool sudoku::numAlreadyInRow ( int row, int num )
{
	int j;
	for(j=0;j<Elem_in_1_row;j++){
		if(grid[row][j].value==num){
			return true;
		}
	}
	return false;
}


// Function to determine if num is in grid[][col]
// Postcondition: Returns true if num is in grid[][col]
// otherwise it returns false.
bool sudoku::numAlreadyInCol ( int col, int num )
{
	int j;
	for(j=0;j<Elem_in_1_row;j++){
		if(grid[j][col].value==num){
			return true;
		}
	}
	return false;
}


// Function to determine if num is in the small grid.
// Postcondition: Returns true if num is in small grid otherwise it returns false.
bool sudoku::numAlreadyInBox ( int Row, int Col, int num )
{
	int start_row,end_row,start_col,end_col;
	start_row = (Row/R)*R;
	end_row = (Row/R + 1)*R;
	start_col = (Col/C)*C;
	end_col = (Col/C + 1)*C;
	for(int i=start_row;i<end_row;i++){
		for(int j=start_col;j<end_col;j++){
			if(grid[i][j].value==num)
			return true;
		}
	}
	return false;
}


// Function to determine if num can be placed in grid[row][col]
// Postcondition: Returns true if num can be placed in grid[row][col]
bool sudoku::canPlaceNum ( int row, int col, int num )
{
	if((numAlreadyInRow(row,num))||(numAlreadyInCol(col,num))||(numAlreadyInBox(row,col,num)))
		return false;
	return true;
}



void sudoku::getinput()
{
	char s[100];
	//Taking inputs: size of sudoku
	cin>>R>>C;
	Elem_in_1_row = R*C;//Initializing max number of elements in a row

	for(int i=0;i<Elem_in_1_row;i++){
		cin.getline(s,R*C+C,'\n');
		
		while(s[0]=='\0'){
			cin.getline(s,R*C+C,'\n');        
		}
		int index=0;
		for(int j=0;j<R*C+C-1;j++){        
			if(s[j]=='.'){
				grid[i][index].set = false;
				grid[i][index].value = 0;
				grid[i][index].count_val_possible = Elem_in_1_row;
				for(int k=0;k<Elem_in_1_row;k++)
				grid[i][index].val_poss[k] = true;
				index++;
			}
			else if(s[j]<='9'&&s[j]>='0'){
				grid[i][index].set = true;
				grid[i][index].value = (int)(s[j]-48);//48 is ascii value of '0'         
				index++;
			}
			// else if(s[j]<='z'&&s[j]>='a'){
				// grid[i][index].set = true;
				// grid[i][index].value = (int)( (s[j] - 'a') +10);          
				// index++;
			// }
			else if(s[j]<='Z'&&s[j]>='A'){
				grid[i][index].set = true;
				grid[i][index].value = (int)( (s[j] - 'A') + 10);          
				index++;
			}
			
			else{
				continue;
			}
		}
	}
}


