/*
 * Autho  r: Abu Shumon
 * Student number: 224088
 * Program name: Who wants to be a millioner
 * Version : 1.0
 * All right reserved by the author.
 * This is specific ation file of a reknown game "Who wants to be a millioner"
 * Details informati	  on about the game can be found here: 
 * http://www.cs.tut.fi/~p   rog2/homework/
 * 			     
 */			     

#ifndef MAIN_HH		     
#define MAIN_HH		     
	
#include<iostream>
#include<vector>	     	       
#include<string>
#include<sstream>	
#include<fstream>	
#include<cstdlib>	
#include<algorithm>	
#include<fstream>	
	
#define Z 12		
	
using namespace std;
    
class QuesType
{	  	  
	private:  
		string diflevel;
		string ques;
		string option1;
		string option2;	 
		string option3;	 
		string option4;	 
		string corrans;	 
	public:	
		void AddfromFile(string, string, string, string, string, string, string);
		void AddQuestion(vector<QuesType> &cv, QuesType &n2);
		void EditQuestion(signed int target_qno, QuesType &n2, vector<QuesType > &contvec);
		void RemoveQuestion(int, vector<QuesType > &contvec);	       
		void PrintAll();		       
		void PrintAQuestion();		       
		void PrintByDLevel(string target_dlevel, vector<QuesType > &contvec);
		void SaveQuestion(vector<QuesType > &contvec);	  
		vector<int> GenerateSet(vector<QuesType > &contvec);	
		void PrintGenerated();		
		string ReturnDLevel();		
};
#endif			
