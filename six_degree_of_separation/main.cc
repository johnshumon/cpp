// Tiraka/UDS homework 3 - yasn, main program. Student implements
// datastructure specified in file datastructure.hh. 

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

// Definition of data structure. Student implements.
#include "datastructure.hh"

using namespace std;

const string PROMPT = "> ";

// Commands as constant variables of type 'char'
// RELATION adds relation of type F, R or K between two persons given
// as parameters
const char RELATION = 'R';
// INQUIRY performs query which checks if two ids has given relation
const char INQUIRY = 'I';
// EMPTY empties the data structure and of course releases all memory
// allocated for data structure.
const char EMPTY = 'E';
// ADD adds given person with given id to the data structure
const char ADD = 'A';
// QUIT quits program and releases all allocated memory
const char QUIT = 'Q';
// SIX_DEGREES checks if six degrees of separation exists between two
// ids, ie. less than six steps between two person, see:
// http://en.wikipedia.org/wiki/Six_degrees_of_separation
const char SIX_DEGREES = 'S';
// FRIENDS prints all type of friends of given person (id)
const char FRIENDS = 'F';

int main() {
  
  // Initialized with some good value, it does not matter which it is
  // becaus of reading command char in 'do'
  char command = ' ';
  Datastructure ds;
  
  int id = 0;
  int id1 = 0;
  int id2 = 0;
  char rel = ' ';
  string name;
  string description;
  
  do {
    cout << PROMPT;
    cin >> command;
    cout << command;

    if(command == ADD) {
      cin >> id >> ws;
      getline(cin, name);
      cout << " "<< id << " " << name << endl;
      ds.add(id, name);
    } 
	else if (command == RELATION) {
      cin >> rel >> id1 >> id2 >> ws;
      getline(cin, description);
      cout << " " << rel << " " << id1 << " " << id2 << " " << description 
	   << endl;
      ds.addRelation(id1, id2, rel, description);
    } 
	else if(command == INQUIRY) {
      cin >> rel >> id1 >> id2;
      cout << " " << rel << " " << id1 << " " << id2 << endl;
      ds.query(rel, id1, id2);
    } 
	else if(command == EMPTY) {
      ds.empty();
    } 
	else if(command == SIX_DEGREES) {
      cin >> id1 >> id2;
      cout << " " << id1 << " " << id2 << endl;
      ds.sixDegrees(id1, id2);
    } 
	else if(command == FRIENDS) {
      cin >> id;
      cout << " " << id << endl;
      ds.printFriends(id);
    }

  } while (command != QUIT);

  cout << endl;

  return EXIT_SUCCESS;
}
