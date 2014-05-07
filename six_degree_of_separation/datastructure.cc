// UDS; OHJ-2016; Homework 3 - Social network  
//
//
// It is implemented by Abu Shumon
// Student number: 224088


#include <iostream>
#include <string>
// #include <map>
// #include <list>
#include <queue>
#include <algorithm>


#include "datastructure.hh"

using namespace std;

// Default constructor for the class Datastructure.
Datastructure::Datastructure()
{
  
}


// Default destructor for the class Datastructure.
Datastructure::~Datastructure()
{	
  empty();
}


// Adds user to the data struture.
void Datastructure::add(int id, std::string const& name)
{
  int iMap_size = (int)userList.size();
  bool flag = false;
  
  if(iMap_size == 0){ // map size 0 means there is no element inserted yet.
    each_UU.iUser_id = id;
    each_UU.sUser_name = name;		
    each_UU.bRelation_status = false;
    
    userList.insert(make_pair(id, each_UU));		
  }
  else{
    it1 = userList.find(id); // otherwise checks if the id is there.
    if(it1 != userList.end()){ // if found then flag goes up.
      
      flag = true;
    }
    
    if(!flag){ // means id is not in the map
      
      each_UU.iUser_id = id;
      each_UU.sUser_name = name;		
      each_UU.bRelation_status = false;			
      
      userList.insert(make_pair(id, each_UU));
      
    }
    else{
      
      cout << ERROR_ID_IN_USE;
    }
  }	
}	

// Performs an query to find if id1 and id2 have relation
// Type Relation is defined above.
void Datastructure::query(char relation, int id1, int id2)
{
  bool flag_id1 = false;
  bool flag_id2 = false;
  bool temp = false;
  
  it1 = userList.find(id1); // checks if the id1 is there.
  if(it1 != userList.end()){ // if id1 is found
    
    it2 = userList.find(id2); // checks if the id2 is there.
    if(it2 != userList.end()){
      
      flag_id1 = true;
      flag_id2 = true;	
    }
  }
  
  if(flag_id1 && flag_id2){ // if both id's are found
    
    each_UU = userList[id1];
    for(list_it = each_UU.relation_list.begin();
	list_it != each_UU.relation_list.end(); list_it++){		
      
      // checks relation with id2
      if( (list_it->iRelation_with == id2) && 
	  (list_it->cRelation_type == relation) )
	{ 
	  // if found then it prints the relation.
	  cout << userList[id1].sUser_name
	       << SEPARATOR
	       << list_it->cRelation_type
	       << SEPARATOR
	       << userList[list_it->iRelation_with].sUser_name				
	       << endl;				
	  temp = true;
	  break;
	}
      
      
    }
    if(!temp){ // temp remains false means there is no relation.
      
      cout << ERROR_NO_RELATION;			
    }
  }
  else{
    
    cout << ERROR_ID_NOT_FOUND;
  }
}


// Adds relation relation between id1 and id2 with desription
void Datastructure::addRelation(int id1, int id2, char relation, 
				std::string const& description)
{
  // if both ids are same
  if(id1 == id2){
    
    cout << ERROR_SAME_ID;
  }
  else{
    
    
    bool flag_id1 = false;
    bool flag_id2 = false;
    bool check_id1 = false;
    bool check_id2 = false;
    
    // checking if both the id are in the data structure.
    it1 = userList.find(id1);
    if(it1 != userList.end()){ // if first one is found
      
      it2 = userList.find(id2);
      if(it2 != userList.end()){ // if second one is found
	
	flag_id1 = true;
	flag_id2 = true;	
      }			
    }
    
    // if both id are found, then relation is added in the list
    if(flag_id1 && flag_id2){
      
      // this is true means this user has realtions.
      if(userList[id1].bRelation_status){
	
	// searching over his lsit to see if there is any relation 
	// with id2.
	for(list_it = userList[id1].relation_list.begin();
	    list_it != userList[id1].relation_list.end(); ++list_it){
	  
	  // if both users already have relation between them
	  // and type of their relation is changed, then latest
	  // relation is updated in the data structure
	  if(list_it->iRelation_with == id2){
	    
	    list_it->iRelation_with = id2;
	    list_it->cRelation_type = relation;
	    list_it->sDescription = description;
	    check_id1 = true;
	  }
	}
      }
      
      if(userList[id2].bRelation_status){
	
	for(list_it = userList[id2].relation_list.begin();
	    list_it != userList[id2].relation_list.end(); ++list_it){
	  if(list_it->iRelation_with == id1){					
	    list_it->iRelation_with = id1;
	    list_it->cRelation_type = relation;
	    list_it->sDescription = description;
	    check_id2 = true;
	  }
	}
      }
      
      // if no realtion exists, then its added to the DS.
      if( (!check_id1) && (!check_id2) ){
	
	// this relation would be added to id1's list
	each_RE.cRelation_type = relation;
	each_RE.iRelation_with = id2;
	each_RE.sDescription = description;				
	userList[id1].relation_list.push_back(each_RE);
	
	// this relation would be added to id2's list
	each_RE.cRelation_type = relation;
	each_RE.iRelation_with = id1;
	each_RE.sDescription = description;
	userList[id2].relation_list.push_back(each_RE);
      }
      
      // making this true means this user has friend
      if( !userList[id1].bRelation_status ){
	
	userList[id1].bRelation_status = true;
      }
      if( !userList[id2].bRelation_status ){
	
	userList[id2].bRelation_status = true;
      }
    }
    else{
      
      cout << ERROR_ID_NOT_FOUND;
    }	
  }
}

// Checks if id1 and id2 are at most six steps away from each
// other. Also called Six Degrees of Separation
void Datastructure::sixDegrees(int id1, int id2)
{
  bool flag_id1 = false;
  bool flag_id2 = false;
  
  // if both ids are same
  if(id1 == id2){
    
    cout << ERROR_SAME_ID;
  }
  else{
    
    
    // checking if both the id are in the data structure.
    it1 = userList.find(id1);
    if(it1 != userList.end()){ // if first one is found
      
      it2 = userList.find(id2);
      if(it2 != userList.end()){ // if second one is found
	
	flag_id1 = true;
	flag_id2 = true;	
      }
      
      
    }
		
    // ids are found
    if(flag_id1 && flag_id2){			
      queue<int> Q;
      queue<int> six_step;
      multimap<int, int> bfs_check;
      multimap<int,int>::iterator bfs;
      
      int tmp;
      bool found = false;
      int depth = 1;
      
      Q.push(id1);		
      
      while( (!Q.empty()) && (depth < 7) ){
	
	tmp = Q.front();
	each_UU = userList[tmp];
	bfs_check.insert ( pair<int,int>(Q.front(),Q.front()) );
	
	Q.pop();
	
	for(list_it = each_UU.relation_list.begin();
	    list_it != each_UU.relation_list.end(); ++list_it){
	  
	  if(list_it->iRelation_with == id2){					
	    cout << userList[id1].sUser_name << endl;
	    cout << userList[list_it->iRelation_with].
	      sUser_name << endl;
	    
	    found = true;
	    break;
	  }
	  else{					
	    bfs=bfs_check.find(list_it->iRelation_with);
	    if(bfs == bfs_check.end()){
	      
	      six_step.push(list_it->iRelation_with);
	      bfs_check.insert ( pair<int,int>
				 (list_it->iRelation_with,
				  list_it->iRelation_with) );
	    }
	  }
	}
	if(Q.empty()){
	  depth++;
	  swap(Q, six_step);
	}			
	if(found){break;}
	
	
      }
      if(!found){
	cout << ERROR_NO_RELATION;
      }
      
    }
    else{
      cout << ERROR_ID_NOT_FOUND;
    }		
  }	
}



// Prints all friends of person with id id
void Datastructure::printFriends(int id)
{
  bool flag_id = false;
  
  // checking if the id is in the data structure.
  it1 = userList.find(id);
  if(it1 != userList.end()){
    flag_id = true;		
  }
  
  // if id is found then it checks the user's friend list
  if(flag_id){
    
    // relation status true means he/she has friends
    // if this is false, then it doesn't need to iterate over the 
    // whole list.
    if(userList[id].bRelation_status){
      each_UU = userList[id];
      cout << userList[id].sUser_name << HAS_FRIENDS;
      for(list_it = each_UU.relation_list.begin();
	  list_it != each_UU.relation_list.end(); list_it++){
		cout << userList[(*list_it).iRelation_with].sUser_name 
		 << SEPARATOR 
	     << (*list_it).cRelation_type << SEPARATOR
	     << (*list_it).sDescription << endl;
      }
    }
    else{
      cout << userList[id].sUser_name << HAS_FRIENDS;
      cout << NO_FRIENDS;
    }	
  }
  else{
    cout << ERROR_ID_NOT_FOUND;
  }	
}


// Empties the data structure and also frees all allocated memory
void Datastructure::empty()
{
  userList.clear();
}


