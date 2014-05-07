// Tiraka and UDS homework 2, definition of data structure which
// student implements.

#ifndef DATASTRUCTURE_HH
#define DATASTRUCTURE_HH

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <vector>

// Array of artists which can be indexed with given index. This array
// is given for students
static const std::string ARTISTS[] = {
  "Claire", "Hiro", "Isaac", "Jessica", "Matt", "Micah", "Mohinder", 
  "Nathan", "Niki", "Noah", "Peter", "Simone" };

static const unsigned int AMOUNT_OF_ARTISTS = 12;
// Note, that error messages contains line break.
static const std::string ERROR_TIMESTAMP = "Same timestamp, vote declined.\n";
static const std::string ERROR_TOO_MANY_VOTES = "Too many votes.\n";

// Other constants, which helps printing. Place is printed right side
// of the field and artists name is printed to the left side of field
static const unsigned int WIDTH_PLACE_NUMBER_FIELD = 2;
static const unsigned int WIDTH_ARTIST_NAME_FIELD = 20;
static const unsigned int PERCENT_NUMBER_WIDTH = 6;
static const unsigned int PERCENT_MULTIPLIER = 100;
static const unsigned int TABLE_SIZE = 25000;
static const unsigned int HASH_PRIME = 24979;
static const unsigned int T_LITTRAL = 1000;

// Note, that next constant contains space and two after first one
// contains line break.
static const std::string DELIMITER = ". ";
static const std::string TEXT_VOTES = "% of votes.\n";
static const std::string VOTES_GIVEN = " votes given totally.\n";

static const char ZERO_LITTRAL = 'O';

class Datastructure {
public:
  
  Datastructure();
  
  ~Datastructure();
  
  // Adds one vote from one phone number (phoneNumber) for one artist
  // (id). Time stamp (timestamp) is used to control voting.  
  void add(unsigned int id, std::string& phoneNumber, std::string& timestamp);
  
  // Prints top n. Stream is given as a parameter and it is either
  // cout or file. Student implements printing also.
  void top(unsigned int n);
  
  // Counts and returns votes for artist given as a parameter
  // (artist). Main function prints needed error messages if any.
  unsigned int count(unsigned int artist);
  
  // Empties the data structure and also frees all allocated memory
  void empty();
  
 private:
  
  // Copy constructor is forbidden
  Datastructure(const Datastructure&);
  // Assignment operator is forbidden
  Datastructure& operator=(const Datastructure&);
  
  
  unsigned long hashFunction(std::string phoneNumber);
  void sortVote();
  
  // this struct is maintaining the list of contestent
  // with highest to lowest votes
  struct finalList{
    std::string sArtist_name;
    unsigned int iNo_of_votes;
  };
  finalList finalList[AMOUNT_OF_ARTISTS];
  
  
  // this is the main node pointer array to keep
  // track of buckets and its chain.
  struct Node {
    Node(): iCID(0), sVoting_PN("") {
      
      for(unsigned int l=0;l<T_LITTRAL;l++){
			
	sTS[l]="";
	if(l<AMOUNT_OF_ARTISTS){
	  iCounter[l]=0;
	}
      }
      
    }
    
    //member variables 
    unsigned int iCID;
    std::string sVoting_PN;
    std::string sTS[T_LITTRAL];
    unsigned int iCounter[AMOUNT_OF_ARTISTS];	
 	
    Node *next;
  };
  Node* nodeArray[TABLE_SIZE];
  Node* head;
  Node* currentPtr;
  
  unsigned int iVote_count[AMOUNT_OF_ARTISTS];
  
  
};
#endif // DATASTRUCTURE_HH

