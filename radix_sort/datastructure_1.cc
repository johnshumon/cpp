//UDS; OHJ-2016; Homework 1 - Directory
//It sorts words alphabatically and prints longest and shortest words with length.
//It is implemented by Abu Shumon
//Student number: 224088

#include <iostream>
#include <string>
#include <vector>


#include "datastructure.hh"

using namespace std;

Datastructure::Datastructure()
{

}

Datastructure::~Datastructure(){ 
  WordList.clear();
}

void Datastructure::sort()
{

	WordDirectory objtemp;
	
	
	bool bRet = false;
	unsigned int iSize = 0;
	iSize = WordList.size();
	unsigned int iCharacterPosition = 0;
	
	int iTotalLoop = 0;
	
	while(bRet != true)
	{
		iTotalLoop++;
		
		if(iCharacterPosition >= _lengthOfMaxWord._length)
		{
			bRet = true;
			break;
		}
		else
		{
			for(unsigned int i = 0; i < (iSize-1); i++)
			{
				iTotalLoop++;
				
				
				char character = 0;
				char smallestcharacter = 0;
				unsigned int iSwapPosition = 0;
				string sFistword;
				bool bTrue = false;
				sFistword = WordList[i]._wordname;							
				unsigned int iWordsize = sFistword.size();
				
				if(iCharacterPosition < iWordsize)
				{	
					character = sFistword[iCharacterPosition];					
					string sSecondWord;
					char seccharacter;
					bool bFound = true;
					
					for(unsigned int j = i+1 ; j < iSize; j++)
					{
						iTotalLoop++;
					
						if (i != j)
						{
							sSecondWord = WordList[j]._wordname;
							
							if(iCharacterPosition < sSecondWord.size())
							{
								seccharacter = sSecondWord[iCharacterPosition];
								
								if(character > seccharacter)
								{
									if( !bFound )
									{
										if(!(smallestcharacter < seccharacter) )
										{
											if(iCharacterPosition > 0 && sFistword[0] == sSecondWord[0])
											{
												if(iCharacterPosition == 1)
												{
													smallestcharacter = seccharacter; 
													iSwapPosition = j;
													bTrue = true;
													bFound = false;
												}
												else
												{
													bool bDictionarysort = true; 
													for(unsigned int k=0; k < iCharacterPosition; k++)
													{
														iTotalLoop++;
													
														if( sFistword[k] != sSecondWord[k] || sFistword[k] > sSecondWord[k])
														{
															bDictionarysort = false;
															break; 
														}
														else
														{
															bDictionarysort = true;
														}
													}
													if(bDictionarysort)
													{
														smallestcharacter = seccharacter; 
														iSwapPosition = j;
														bTrue = true;
														bFound = false;
													}
												}
											}
											else
											{
												if(iCharacterPosition > 0)
												{
													break;
												}
												else
												{
													smallestcharacter = seccharacter; 
													iSwapPosition = j;
													bTrue = true;
													bFound = false;
												}
											}
										}
									}
									else
									{
										if(iCharacterPosition > 0 && ( sFistword[0] == sSecondWord[0]))
										{
											if(iCharacterPosition == 1 )
											{
												smallestcharacter = seccharacter; 
												iSwapPosition = j;
												bTrue = true;
												bFound = false;
											}
											else
											{
												bool bDictionarysort = true; 
												for(unsigned int k=0; k < iCharacterPosition; k++)
												{
													iTotalLoop++;
													
													if( sFistword[k] != sSecondWord[k] || sFistword[k] > sSecondWord[k])
													{
														bDictionarysort = false;
														break; 
													}
													else
													{
														bDictionarysort = true;
													}
												}
												if(bDictionarysort)
												{
													smallestcharacter = seccharacter; 
													iSwapPosition = j;
													bTrue = true;
													bFound = false;
												}
											}
										}
										else
										{
											if(iCharacterPosition > 0)
											{
												break;
											}
											else
											{
												smallestcharacter = seccharacter; 
												iSwapPosition = j;
												bTrue = true;
												bFound = false;
											}
										}
									}
								
								}
							}
						}
					}
				}
				if(bTrue)
				{
					objtemp = WordList[i];
					WordList[i] = WordList[iSwapPosition];						
					WordList[iSwapPosition] = objtemp;
					
				}
			}
			
			iCharacterPosition++;
		}
	}
	
	cout << "total sorting loop: " << iTotalLoop << endl;
	

	
}

void Datastructure::print()
{
	
	unsigned int iSize = WordList.size();	
	
	for(unsigned int i = 0; i < iSize; i++){
		cout << SEPARATOR << WordList[i]._wordname ;		
	}
	cout << endl;
	
}
  
  
void Datastructure::empty()
{
	WordList.clear();
}

void Datastructure :: add(std::string& word)
{

	unsigned int i = WordList.size();	
	
	WordDirectory _eachword;
	_eachword._wordname = word;
	_eachword._length =  word.size();	
	
	while(i == 0)
	{
		_lengthOfMinWord._length = _eachword._length;
		_lengthOfMaxWord._length = _eachword._length;
		i = i + 1;
	}	
	
	if(_eachword._length <= _lengthOfMinWord._length)
    {
       _lengthOfMinWord._length=_eachword._length;
       _lengthOfMinWord._wordname = _eachword._wordname;	   
    }
	
	if(_eachword._length > _lengthOfMaxWord._length)
    {
      _lengthOfMaxWord._length = _eachword._length;
      _lengthOfMaxWord._wordname = _eachword._wordname;	  
    }
	
	WordList.push_back(_eachword);
	
   
}

 // Prints shortest word and length
  void Datastructure::shortest()
  {
	cout << SEPARATOR << _lengthOfMinWord._wordname << SEPARATOR << _lengthOfMinWord._length << endl;
  }
  
  // Prints longest word and length
  void Datastructure::longest()
  {
	cout << SEPARATOR << _lengthOfMaxWord._wordname << SEPARATOR << _lengthOfMaxWord._length << endl;
  }
