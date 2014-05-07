// Tiraka/UDS homework 2 - Idols related, main program. 
// First version 2010, updated 4/2012.

// Student implements datastructure specified in file
// datastructure.hh.  Datastructure contains datastructures and
// operations for datastructure and also sorting algorithm.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>

// Definition of data structure. Student implements.
#include "datastructure.hh"

//using namespace std;

const std::string PROMPT = "> ";
const std::string SEPARATOR = " ";

// Error messages for read and write errors
const std::string ERROR_FILE_READ = "Error: could not read file: ";
//const string ERROR_FILE_WRITE = "Error: could not write file: ";
const std::string ERROR_ARTISTID = "Illegal artist id.\n";
const std::string ERROR_ILLEGAL_AMOUNT = "Illegal amount of artists.\n";

// Commands which shell recognizes
const char READ = 'R';
const char TOP = 'T';
const char COUNT = 'C';
const char EMPTY = 'E';
const char QUIT = 'Q';

// Function: Shell(char command, Datastructure& ds)
// Parameters: command - given command (one of listed above)
//             ds      - data structure implemented by student
// Return value: bool, false if command Q was given, otherwise true
bool shell(char command, Datastructure& ds);

// Function: ReadFile(string const& filename, Datastructure& ds)
// Parameters: filename - name of file where words are stored
//             ds       - data structure implemented by student
// Return value: bool, true if all went fine, otherwise false
bool readFile(std::string const& filename, Datastructure& ds);

int main() {
  
  char command = QUIT;
  
  Datastructure ds;
  
  // Loop asks for command and then calls shell()-function, which
  // performs asked operations. Command Q causes return value false,
  // which terminates execution of program. Parameters are read from
  // cin stream in shell()-function.
  do {
    std::cout << PROMPT;
    std::cin >> command;
    std::cout << command; // Uutta toteutusta (ts. yhtenäistetään pääohjelmat)
  } while (shell(command, ds));
  
  std::cout << std::endl;
  return EXIT_SUCCESS;
}

bool shell(char command, Datastructure& ds) {
  // Variable n tells "how many" in top n list
  unsigned int n = 0;
  std::string filename;
  
  if (command == READ) {
    std::cin >> filename;
    std::cout << SEPARATOR << filename << std::endl;
    // If file can not be read, prints error message and
    // quits. Otherwise stores data from file to data structure
    
    if(!readFile(filename, ds)) {
      return true;
    }
  } else if (command == TOP) {
    
    if(std::cin >> n && n <= AMOUNT_OF_ARTISTS) {
      std::cout << SEPARATOR << n << std::endl;
      ds.top(n);
    } else {
      std::cout << ERROR_ILLEGAL_AMOUNT;
    }
  } else if (command == COUNT) {
    unsigned int artist = 0;
    // Counts votes for artist artist and prints it
    if(std::cin >> artist && artist < AMOUNT_OF_ARTISTS) {
      std::cout << SEPARATOR << artist << std::endl;
      std::cout << "Artist " << ARTISTS[artist] << " got " << ds.count(artist) 
	   << " votes!" << std::endl;
    } 
    else {
      // Error message defined in datastructure.hh file
      std::cout << ERROR_ARTISTID << std::endl;
    }
  } 
  
  else if (command == EMPTY) {
    ds.empty();
    std::cout << std::endl;
  } else if (command == QUIT) {
    return false;
  }
  // In all other cases returns true
  return true;
}

bool readFile(std::string const& filename, Datastructure& ds) {

  std::ifstream file(filename.c_str());
  std::string line;
  
  if(!file) {
    std::cout << ERROR_FILE_READ << filename << std::endl;
    file.close();
    return false;
  }
  unsigned int id = 0;
  std::string phoneNumber;
  std::string timestamp;
  
  while(getline(file, line)) {
    // Format of votes file below, timestamp, phone, id
    // 2008-12-27T09:51Z 5874053 11
    std::istringstream ss(line);
    ss >> timestamp;
    ss >> phoneNumber;
    ss >> id;
    
    // Now data for one vote entry is collected. Then calls add()
    // function, which adds entry to the data structure.
    if(id > AMOUNT_OF_ARTISTS - 1) {
      std::cout << ERROR_ARTISTID << std::endl;
      continue;
    }
    ds.add(id, phoneNumber, timestamp);

  }
  
  file.close();
  
  return true;
}

