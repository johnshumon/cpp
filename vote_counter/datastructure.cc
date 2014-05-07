//UDS; OHJ-2016; Homework 2 - vote count  
//It counts votes for contestents, and display the
// vote list according to highest to lowest % of votes.
//It is implemented by Abu Shumon
//Student number: 224088


#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#include "datastructure.hh"

using namespace std;

// Default constructor for the class Datastructure.
Datastructure::Datastructure():head(NULL),currentPtr(NULL){

  for(unsigned int i=0; i<TABLE_SIZE; i++){
    nodeArray[i] = NULL;
  }

  for(unsigned int i=0; i<AMOUNT_OF_ARTISTS; i++){
    iVote_count[i] = 0;
  }
}

Datastructure::~Datastructure()
{	
  empty();
}


// Adds one vote from one phone number (phoneNumber) for one artist
// (id). Time stamp (timestamp) is used to control voting.  
void Datastructure::add(unsigned int id, std::string& 
			phoneNumber, std::string& timestamp)
{
   unsigned int iTSindex=0;
   unsigned int index = (unsigned)hashFunction(phoneNumber);   
   bool flag_sameTS = false;
   bool flag_samePN = false;
   Node* locate = nodeArray[index];  
   
   // in the begining if the bucket of generated
   // index is empty then node is inserted.
   if(nodeArray[index] == NULL){
     
     nodeArray[index] = new Node;
     nodeArray[index]->iCID = id;
     nodeArray[index]->sVoting_PN = phoneNumber;
     nodeArray[index]->sTS[0] = timestamp;
     nodeArray[index]->iCounter[id] = nodeArray[index]->iCounter[id] + 1;
     iVote_count[id] = iVote_count[id] + 1;	  
     head = nodeArray[index];
     currentPtr = head;
     head->next = NULL;		
   }
   else{ // if the bucket is already occupied then conditions are checked
     // to add votes to its appropriate location
     
     if(locate->next == NULL){ // if exactly one object in a index
       if(locate->sVoting_PN == phoneNumber){
	 iTSindex = 0;
	 while(locate->sTS[iTSindex] != "\0"){

	   if(locate->sTS[iTSindex] == timestamp){
	     cout << ERROR_TIMESTAMP;
	     flag_sameTS = true;
	     break;
	   }					
	   iTSindex++;
	 }
	 
	 if(!flag_sameTS){

	   if(locate->iCounter[id] < 10 ){ // this "if" works if 
	     //same phone number is voting to an id. max 10 votes.
	     
	     locate->iCounter[id] += 1;
	     locate->sTS[iTSindex] = 
	       timestamp;							
	     iVote_count[id] = 
	       iVote_count[id] + 1;
	   }
	   else{							
	     cout << ERROR_TOO_MANY_VOTES;
	   }
	 }
	 
       }
       else{ // if the phone number is different, but index is same, then
	 // this else works to add that node.
	 head = nodeArray[index];			
	 currentPtr = new Node;
	 currentPtr->iCID = id;
	 currentPtr->sVoting_PN = phoneNumber;
	 currentPtr->sTS[0] = timestamp;
	 currentPtr->iCounter[id] = currentPtr->iCounter[id] + 1;
	 head->next = currentPtr;
	 head = currentPtr;
	 head->next = currentPtr->next;
	 head->next = NULL;
	 iVote_count[id] = iVote_count[id] + 1;
       }
       
     }
     else{ 
       // if there is more than 
       //one object in that index.			
       iTSindex = 0;
       while(locate->next != NULL){ // then this while loop checks
	 // possible conditions			
	 if(locate->sVoting_PN == phoneNumber){
	   flag_samePN = true;
	   while(locate->sTS[iTSindex] != "\0"){
	     if(locate->sTS[iTSindex] == timestamp){
	       cout << ERROR_TIMESTAMP;
	       flag_sameTS = true;
	       break;
	     }
	     
	     iTSindex++;
	   }
	 }
	 else{ // if phone no is different, then pointer moves to
	   // next object.
	   locate = locate->next;
	 }
	 if(flag_sameTS || flag_samePN){ 
	   // if either PN or TS is
	   break;		
	   // same, then both loop breaks.					
	 }
	 
       }
       if((!flag_sameTS) ||  (!flag_samePN)){
	 if(locate->sVoting_PN == phoneNumber){
	   iTSindex = 0;
	   flag_samePN = true;	
	   while(locate->sTS[iTSindex] != "\0"){
	     if(locate->sTS[iTSindex] == timestamp){
	       cout << ERROR_TIMESTAMP;
	       flag_sameTS = true;
	       break;
	     }
	     
	     iTSindex++;
	   }
	 }
       }
			
       if(flag_samePN){
	 if(!flag_sameTS){
	   if(locate->iCounter[id] < 10 ){ // this if works if
	     locate->iCounter[id] += 1;	// same phone number is
	     locate->sTS[iTSindex] = timestamp; // voting to an id.
	     iVote_count[id] = iVote_count[id] + 1; 
	     // max 10 votes.						
	   }
	   else{
	     cout << ERROR_TOO_MANY_VOTES;
	   }					
	 }
       }
       else{
	 if(!flag_sameTS){
	   head = nodeArray[index];
	   while(head->next != NULL){
	     head = head->next;
	   }
	   
	   currentPtr = new Node;
	   currentPtr->iCID = id;
	   currentPtr->sVoting_PN = phoneNumber;
	   currentPtr->sTS[0] = timestamp;
	   currentPtr->iCounter[id] = currentPtr->iCounter[id] + 1;
	   head->next = currentPtr;
	   head = currentPtr;
	   head->next = currentPtr->next;
	   head->next = NULL;
	   
	   iVote_count[id] = iVote_count[id] + 1;
	 }
	 
       }
     }
   }  
}	



// Prints top n. Stream is given as a parameter and it is either
// cout or file. Student implements printing also.
void Datastructure::top(unsigned int n)
{
  unsigned int iTotal_vote = 0;	
  
  for(unsigned int i=0; i<AMOUNT_OF_ARTISTS; i++){
    iTotal_vote = iTotal_vote + iVote_count[i];
    
  }
  if( iTotal_vote == 0){
    for(unsigned int i=0; i<n; i++){
      
      cout << right << setw(WIDTH_PLACE_NUMBER_FIELD) << i+1 <<". ";
      cout << left<<setw(WIDTH_ARTIST_NAME_FIELD) << ARTISTS[i];
      cout << right << setw(PERCENT_NUMBER_WIDTH)
	   << fixed << setprecision(2) << (double)iTotal_vote << TEXT_VOTES;
    }
    cout<<iTotal_vote<<VOTES_GIVEN;
    
  }
  
  else if( iTotal_vote != 0 && n == 0 ){
    cout << iTotal_vote << VOTES_GIVEN;
  }
  else{	
    sortVote();    
    for (unsigned int i = 0; i < n; i++){
      cout<<right<<setw(WIDTH_PLACE_NUMBER_FIELD) << i+1 <<". ";
      
      cout<< left << setw(WIDTH_ARTIST_NAME_FIELD) 
	  << finalList[i].sArtist_name;
      
      cout << fixed;
      
      cout<<right<<setw(PERCENT_NUMBER_WIDTH)
	  << fixed << setprecision(2) << double(finalList[i].iNo_of_votes)/
	double(iTotal_vote) * PERCENT_MULTIPLIER;
      cout << TEXT_VOTES ;
      
    }
    cout<< iTotal_vote << VOTES_GIVEN;
  }
}

// Counts and returns votes for artist given as a parameter
// (artist). Main function prints needed error messages if any.
unsigned int Datastructure::count(unsigned int artist){
  unsigned int iVote_for_artist = iVote_count[artist];
  
  return iVote_for_artist;
}

// Empties the data structure and also frees all allocated memory
void Datastructure::empty()
{
  Node* tempDel;   
  for(unsigned int i=0; i<TABLE_SIZE; i++){
    if(nodeArray[i] != NULL){
      
      head = nodeArray[i];
      if(head){
	if(head->next == NULL){						
	  
	  for(unsigned int k=0; k<AMOUNT_OF_ARTISTS; k++){
	    head->iCounter[k] = 0;
	  }
	  delete head;
	  head=NULL;
	  nodeArray[i] = NULL;					
	}
	else{
	  while(head->next != NULL){
	    tempDel = head;
	    for(unsigned int k=0; k<AMOUNT_OF_ARTISTS; k++){
	      head->iCounter[k] = 0;
	    }
	    head = head->next;						
	    delete tempDel;
		tempDel=NULL;
	  }
	  for(unsigned int k=0; k<AMOUNT_OF_ARTISTS; k++){
	      head->iCounter[k] = 0;
	  }
	  delete head;
	  head=NULL;
	  nodeArray[i] = NULL;
	}
      }
    }
    
  }
  
  for(unsigned int i=0; i<AMOUNT_OF_ARTISTS; i++){
    iVote_count[i] = 0;
    
    finalList[i].sArtist_name = "\0";
    finalList[i].iNo_of_votes = 0;	 
  }
   
}

// hash function that generates the hashvalue 
// of the string timestamp
unsigned long Datastructure::hashFunction(std::string phoneNumber){
//start hashString
  
  unsigned int n = (unsigned)phoneNumber.length();
  unsigned long h = 0;
  
  for(unsigned int i=0; i<n; i++){
    //To get almost fair distributions of nodes over the array
    h = (h << 3) ^ (unsigned)phoneNumber[i];
  }
  return (h % HASH_PRIME );
}//end hashString

// this function sorts the list of contestent 
// according to the number of votes they got
// from highest to lowest.

void Datastructure::sortVote()
{
  for(unsigned int l=0; 
      l<AMOUNT_OF_ARTISTS; l++){				
    finalList[l].iNo_of_votes = iVote_count[l];
    finalList[l].sArtist_name = ARTISTS[l];
  }		
  unsigned int j;
  struct finalList tmp;
  
  for (unsigned int i = 1; i < AMOUNT_OF_ARTISTS; i++) {
    j = i;
    while (j > 0 && finalList[j - 1].iNo_of_votes 
	   < finalList[j].iNo_of_votes) {
      tmp.iNo_of_votes = finalList[j].iNo_of_votes;
      tmp.sArtist_name = finalList[j].sArtist_name;
      finalList[j].iNo_of_votes = finalList[j - 1].iNo_of_votes;
      finalList[j].sArtist_name = finalList[j - 1].sArtist_name;
      finalList[j - 1].iNo_of_votes = tmp.iNo_of_votes;
      finalList[j - 1].sArtist_name = 
	tmp.sArtist_name;				
      j--;
    }
  }
}

