// playerlist -- for creating and executing players in the dipoly


#include "playerlist.hh"
#include "player.hh"
#include "createplayer.hh"

#include <string>
#include <vector>

using std::string;
using std::vector;


playerlist::playerlist()
  {
  }

// Destructor

playerlist::~playerlist()
  {
  }

// Assignment Operator

playerlist& playerlist::operator = (const playerlist &cSource)
{
    // check for self-assignment by comparing the address of the
    // implicit object and the parameter
    if (this == &cSource)
        return *this;

    // do the copy
    playerList_ = cSource.playerList_;

    // return the existing object
    return *this;
}






void playerlist::createPlayerList(int initialBalance)
{

    vector <string> Player_Name; // Vector for Creation of player names
    Player_Name = CreatePlayer(Player_Name); //Creation of player names
    player p;
    int new_type = 0;
    string S    ;
    for(int i=0; i< int(Player_Name.size()); i++)
    {
        S = Player_Name[i];
        if(S[0] == '#')
        {
            new_type = 1;
        }
        else
        {
            new_type = 0;
        }
        p.setPlayer(Player_Name[i], (i+1), new_type, initialBalance, 0,false);
        playerList_.push_back(p);
    }

}


// This function will update the position of the player based on die throwing
void playerlist::positionUpdate(int playerID,int NewPosition)
{
    playerList_[playerID].positionUpdate(NewPosition);
}

// This function will update the balance of the player based on purchasing street,
// building shack, escaping prison, getting or giving rent etc.
void playerlist::balanceUpdate(int playerID,int amount)
{
    playerList_[playerID].balanceUpdate(amount);

}



void playerlist::setPrisonStatus(int playerID)
{
    playerList_[playerID].setPrisonStatus();
}

void playerlist::resetPrisonStatus(int playerID)
{
    playerList_[playerID].resetPrisonStatus();
}






//
//

int playerlist::getID(int playerID)const
{
    return playerList_[playerID].getID();
}

//
int playerlist::getPosition(int playerID)const
{
    return playerList_[playerID].getPosition();
}




//
int playerlist::getBalance(int playerID) const
{
    return playerList_[playerID].getBalance();
}


//
///
//
int playerlist::getType(int playerID) const
{
    return playerList_[playerID].getType();;
}

//
//
//

bool playerlist::getPrisonStatus(int playerID) const
{
    return playerList_[playerID].getPrisonStatus();
}



void playerlist::showPlayerList() const
{
    for(int i = 0; i < int(playerList_.size()); i++)
    {
        playerList_[i].showPlayerStatus();

    }

}

int playerlist::findPlayerSerial(int playerid)
{
    //int playerSerial = 0;
    for(int i = 0; i < int(playerList_.size()); i++)
    {
        if (playerid == getID(i)){
            return i;

        }
    }
            //cout << "Player of this ID is not found in the playerlist" << endl;
            return 0;

}



int playerlist::sizePlayerList() const
{
    return playerList_.size();
}


void playerlist::deletePlayer(int currentPlayer)
{
    playerList_.erase(playerList_.begin() + currentPlayer);

}


string playerlist::getName(int playerid)const
{
    return playerList_[playerid].getName();
}

