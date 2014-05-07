// Tiraka/UDS homework hw1 dir, main program. 
// First version 2009, but updated 2012.

// Student implements datastructure specified in file
// datastructure.hh. Datastructure contains datastructures and
// operations for datastructure and also sorting algorithm.

#include <iostream>
#include <cstdlib>
#include <fstream>

// Definition of data structure. Student implements.
#include "datastructure.hh"

const std::string PROMPT = "> ";

// Error messages
const std::string E_FILE_NOT_FOUND = "Error: file not found.\n";

// Commands as constant variables of type 'char'
// Command READ takes one parameter which is filename where words are
// stored. Command reads that file to data structure.
const char READ = 'R';
const char SORT = 'S';
const char PRINT = 'P';
const char MAXMIN = 'X';
const char EMPTY = 'E';
const char QUIT = 'Q';

// Constant MAX is used when asking biggest value and MIN for smallest
const std::string MAX = "max";
const std::string MIN = "min";

// Function: ReadFile(std::string const& filename, Datastructure& ds)
// Parameters: filename - name of file where words are stored
//             ds       - data structure implemented by student
// Return value: bool, true if all went fine, otherwise false
// Function reads file filename and adds words read from file to data
// structure ds.
void readFile(std::string const& filename, Datastructure& ds);

int main() {
  
  // Initialized with some good value, it does not matter which it is
  // becaus of reading command char in 'do'
  char command = QUIT;
  
  Datastructure ds;
  
  // Very simple shell for using data structure ds
  do {
    std::cout << PROMPT;
    std::cin >> command;
    std::cout << command;

    if (command == READ) {
      std::string filename;
      
      std::cin >> filename;
      std::cout << SEPARATOR << filename << std::endl;
      readFile(filename, ds);
    }
    else if (command == SORT) {
      ds.sort();
      std::cout << std::endl;
    }
    else if (command == PRINT) {
      // Prints contents of data structure on display
      std::cout << std::endl;
      ds.print();
    } else if (command == MAXMIN) {
      std::string parameter;
      std::cin >> parameter;
      std::cout << SEPARATOR << parameter << std::endl;
      
      if(parameter == MIN) {
	ds.shortest();
      } else if(parameter == MAX) {
	ds.longest();
      }
    } else if (command == EMPTY) {
      std::cout << std::endl;      
      ds.empty();
    } 

  } while (command != QUIT);
  
  std::cout << std::endl;
  return EXIT_SUCCESS;
}

void readFile(std::string const& filename, Datastructure& ds) {

  std::ifstream file(filename.c_str());
  
  // If file does not exists or is write protected, returns false.
  if(!file) {
    file.close();
    std::cout << E_FILE_NOT_FOUND;
    return;
  }
  
  std::string word;

  // Reads one word at time from file and adds it to the data
  // structure.
  while(file >> word) {
    ds.add(word);
  }
  
  file.close();
}
