// CreatePlayer -- for creating the playername according to specification mentioned in OHJ-1406

#ifndef CREATEPLAYER_HH
#define CREATEPLAYER_HH

#include<string>
#include<vector>

using std::vector;
using std::string;


// This function will convert all the characters in a string to uppercae.
// If any character is already uppercase then that will be remain unchanged.

string UPPER(const string&);


// This funtion will check the repeative name from Player_Name vector
// It  will check the new name S with all the exixting name in the vector

bool CheckSameName (vector <string> Player_Name, string S);

// This function will check the number of AI player. It limits the numberto 4
bool CheckTypeNumber (int aiCounter);

// This funtion will create the Player_Name vector

vector <string> CreatePlayer (vector <string> Player_Name);


#endif
