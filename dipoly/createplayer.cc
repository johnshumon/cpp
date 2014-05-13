// Implemnetation of createplayer.hh

#include "createplayer.hh"

#include <iostream>
#include<string>
#include<vector>
#include <cctype>
#include <cstdlib>


using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cin;
using std::toupper;

//
//
//
string UPPER( const string& target )
{
    string paluu;
    for( unsigned i = 0; i < target.size(); ++i )
    {
        switch( target.at(i) )
        {
            //case 'å': paluu += 'Å';
            //break;
            //case 'ä': paluu += 'Ä';
            //break;
            //case 'ö': paluu += 'Ö';
            //break;
        default:
            paluu += static_cast<char>( toupper( target.at(i) ) );
        };
    }
    return paluu;
}


//
//
//
bool CheckSameName (vector <string> Player_Name, string S)
{
    int Sz = int (Player_Name.size());
    if(Sz > 1 && S.length() == 0) return false;
    int S_size = S.length();
    if(S_size >10 || S_size < 2)
    {
        cout<<"The name of the player can be 2 to 10 characters long"<< endl;
        return true;
    }

    if (Sz < 1) return false;

    string SS;
    string SS1;
    for (int i = 0; i < Sz; i++)
    {
        SS = UPPER(Player_Name[i]);
        SS1  = UPPER(S);
        if(SS1 == SS)
        {
            cout << "ERROR: The players cannot have same names." << endl;
            return (true);
        }
    }
    return false;
}
// */

bool CheckTypeNumber (int aiCounter)
{

    if(aiCounter < 4)
    {
        return false;
    }

    else
    {
        cout << "AI player can not be more than 4" << endl;
        return true;
    }
}




vector <string> CreatePlayer (vector <string> Player_Name)
{

    int Player_counter = 1;
    int aiCounter = 0;

    string S;

    do
    {
        bool Check = true;

        do
        {
            cout << "name of the player " << Player_counter << ":";
            getline(cin, S);
            //Check = false;
            //Check1 = CheckSameName (Player_Name, S);
            //Check2 = CheckTypeNumber (aiCounter);
            Check = CheckSameName (Player_Name, S);
        }
        while(Check);

        if(Player_counter > 1 && S.length() == 0) break;
        Player_Name.push_back(S);
        if(S[0] == '#')
        {
            aiCounter++;
//            cout << aiCounter << endl;
            if(aiCounter ==5)
            {
//                Player_Name.pop_back(S);
                Player_Name.erase(Player_Name.end());
                cout << "AI player can not be more than 4" << endl;
            }
            else
            {
                Player_counter++;
            }

        }
        else
        {
            Player_counter++;

        }

    }
    while(Player_counter < 6);
    return Player_Name;
}



