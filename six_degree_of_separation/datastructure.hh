// Tiraka and UDS homework 3, definition of data structure which
// student implements.

#ifndef DATASTRUCTURE_HH
#define DATASTRUCTURE_HH

#include <iostream>
#include <string>
#include <map>
#include <list>

static const std::string ERROR_ID_NOT_FOUND = "ID not found.\n";
static const std::string ERROR_SAME_ID = "Error: Id1 is equal to Id2.\n";
static const std::string ERROR_NO_RELATION = "No relation found.\n";
static const std::string ERROR_ID_IS_ALREADY_MEMBER = 
  "Person is already member.\n";
static const std::string ERROR_ID_IN_USE = "Error: Id is already taken.\n";
static const std::string NO_FRIENDS = "No friends.\n";
static const std::string HAS_FRIENDS = " has friends:\n";
static const char SEPARATOR = ' ';


enum Color {WHITE, GRAY, BLACK, RED};

class Datastructure {
public:
  
  Datastructure();
  
  ~Datastructure();
  
  // Adds one person with identifier <id> and name <name> to the data
  // structure, returns true if person was really added and false if
  // person existed already in the data structure.
  void add(int id, std::string const& name);
  
  // Performs an query to find if id1 and id2 have relation
  // relation. Type Relation is defined above.
  void query(char relation, int id1, int id2);
  
  // Adds relation relation between id1 and id2 with desription
  // description
  void addRelation(int id1, int id2, char relation, 
		   std::string const& description);
  
  // Checks if id1 and id2 are at most six steps away from each
  // other. Also called Six Degrees of Separation
  void sixDegrees(int id1, int id2);
  
  // Prints all friends of person with id id
  void printFriends(int id);
  
  // Empties the data structure
  void empty();
  
private:
  // Copy constructor is forbidden
  Datastructure(const Datastructure&);
  // Assignment operator is forbidden
  Datastructure& operator=(const Datastructure&);
  
  // holds the relation between two user
  struct relation_edge {
    char cRelation_type;
    // int iU_id;
    int iRelation_with;
    std::string sDescription;    
  };  
  relation_edge each_RE;
  
  // holds the information of a unique user along with its relations.
  struct unique_users {	
    int iUser_id;
    std::string sUser_name;	
    bool bRelation_status;
    std::list<relation_edge> relation_list;
  };  
  unique_users each_UU;
  
  std::map<int, unique_users> userList; // map for keep track of unique uners.
  std::map<int, unique_users>::iterator it1; // map iterator1
  std::map<int, unique_users>::iterator it2; // map iterator1
  std::list<relation_edge>::iterator list_it; // list iterator1
  
};

#endif // DATASTRUCTURE_HH
