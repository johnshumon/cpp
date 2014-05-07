//UDS; OHJ-2016; Homework 1 - Directory  
//It sorts words alphabatically and prints longest and shortest words with length.
//It is implemented by Abu Shumon
//Student number: 224088

#include <iostream>
#include <string>
#include <vector>


#include "datastructure.hh"

using namespace std;
// built in constructor for Datastructure class
Datastructure::Datastructure(): WordList(0), lengthOfMinWord(),
				lengthOfMaxWord()
{
  
}
// built in destructor for Datastructure class
Datastructure::~Datastructure(){ 
}


// MSD radix function definition to sort words 
//lexicgraphically using most significat bits.
void Datastructure::radixSort(vector<string> tempOneDimWordList, 
			      unsigned int oneDimVecSize,  unsigned int offset)
{
  
  if(offset == lengthOfMaxWord.length ){
    return;
  }
  vector<string> towDimWordlist [MAX_LENGTH];
  
  for (unsigned int i = 0; i < oneDimVecSize; i++){
    if(offset < tempOneDimWordList[i].size()){
      char c = tempOneDimWordList[i][offset];
      
      if (c != '\0'){
	towDimWordlist[(((unsigned int)c) )].
	  push_back(tempOneDimWordList[i]);
      }
    }
    else{
      WordList.push_back(tempOneDimWordList[i]);
    }
  }
  
  // this loop is used to call the function recursively
  // to sort the words according to offset.
  for (unsigned int i = 0; i < (unsigned int)MAX_LENGTH; i++) {
    unsigned int sizeCheck = (unsigned int)towDimWordlist[i].size();
    if (sizeCheck > 1){			
      radixSort(towDimWordlist[i], sizeCheck, offset+1);		
    }
    else if(sizeCheck == 1)
      {
	WordList.push_back(towDimWordlist[i][0]);
      }
  }
  
  
  
}

// this is the sort function which call the radixSort Function.
void Datastructure::sort()
{
  
  vector<string> tempOneDimWordList;
  
  tempOneDimWordList = WordList;
  WordList.clear();
  
  radixSort(tempOneDimWordList, (unsigned int)tempOneDimWordList.size(), 0);	
}

// prints the sorted wordlist
void Datastructure::print()
{
  
  unsigned int iSize = (unsigned int)WordList.size();
  
  if(iSize == 0){
    cout << MSG_EMPTY_DS << endl;
  }
  else{
    for (unsigned int j = 0; j < WordList.size(); j++){
      cout << SEPARATOR << WordList[j];		
    }
    cout << endl;
  }
  
}

//Empty the datastructure
void Datastructure::empty()
{
  WordList.clear();
}

// Add all the words from the input files to the data strructure and 
// finds the max and min words eventually.
void Datastructure :: add(std::string& word)
{
  
  unsigned long i = WordList.size();
  
  WordDirectory eachword;
  eachword.wordname = word;
  eachword.length =  word.size();	
  
  if(i == 0){
    lengthOfMinWord.length = eachword.length;
    lengthOfMaxWord.length = eachword.length;		
      i = i + 1;
  }	
  
  if(eachword.length <= lengthOfMinWord.length){
    lengthOfMinWord.length=eachword.length;
    lengthOfMinWord.wordname = eachword.wordname;	   
  }
  
  if(eachword.length > lengthOfMaxWord.length){
    lengthOfMaxWord.length = eachword.length;
    lengthOfMaxWord.wordname = eachword.wordname;	  
  }
  
  WordList.push_back(word);
  
  
}

// Prints shortest word and length
void Datastructure::shortest()
{
  cout << SEPARATOR << lengthOfMinWord.wordname << 
    SEPARATOR << lengthOfMinWord.length << endl;
}

// Prints longest word and length
void Datastructure::longest()
{
  cout << SEPARATOR << lengthOfMaxWord.wordname <<
    SEPARATOR << lengthOfMaxWord.length << endl;
}
