// Definition of datastructure

#ifndef DATASTRUCTURE_HH
#define DATASTRUCTURE_HH

#include <string>
#include <iostream>
#include <vector>

// using namespace std;

static const char SEPARATOR = ' ';
static const int MAX_LENGTH = 125;
const std::string MSG_EMPTY_DS = "Data structure is empty.";




class Datastructure {
 public:
  
  Datastructure();

  ~Datastructure();

  // Adds one word to the datastructure
  void add(std::string& word);

  // Sorts the datastructure
  void sort();
  
  // Prints datastructure
  // Stream is given as a parameter and it is either cout or file
  void print();
  
   // Prints shortest word and length
  void shortest();
  
  // Prints longest word and length
  void longest();
  
  // Empties the datastructure
  void empty();
  
 private:
  // Copy constructor is forbidden
  Datastructure(const Datastructure&);
  // Assignment operator is forbidden
  Datastructure& operator=(const Datastructure&);

  // Student impelements data structure(s), private member(s) and
  // private function(s) here, if needed.

// This structure is used to save maximum and minimum length word 
  struct WordDirectory
 {
   unsigned long length;
   std::string wordname;
   //unsigned int _position;

 };
  // This is the main word list where words are stored sortely.
  std::vector<std::string> WordList;
  
  // structure object to keep max and min length of the word.
  WordDirectory lengthOfMinWord;
  WordDirectory lengthOfMaxWord; 

  // MSD radix function decleration to sort words 
  //lexicgraphically using most significat bits.
  void radixSort(std::vector<std::string> tempOneDimWordList, 
	unsigned int oneDimVecSize,  unsigned int offset);
 
 
};

#endif // DATASTRUCTURE_HH
