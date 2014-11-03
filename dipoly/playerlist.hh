// playerlist -- for creating and executing players in the dipoly

#ifndef PLAYER_LIST_HH
#define PLAYER_LIST_HH

#include "player.hh"
#include <string>
#include <vector>

using std::string;
using std::vector;



class playerlist
{

private:
    vector <player> playerList_; // This is the vector consist of all players

public:
    playerlist();  // parameterless default constructor

// Destructor

    ~playerlist();

// Copy constructor
    playerlist(const playerlist &cSource)
    {
        playerList_ = cSource.playerList_;
    }

// Assignment Operator
    playerlist& operator= (const playerlist &cSource);




    void createPlayerList(int);
    void positionUpdate(int,int);
    void balanceUpdate(int,int);
    void setPrisonStatus(int);
    void resetPrisonStatus(int);
    int getID(int)const;
    int getPosition(int)const;
    int getBalance(int) const;
    int getType(int) const;
    bool getPrisonStatus(int) const;
    void showPlayerList() const;
    int findPlayerSerial(int);
    int sizePlayerList() const;
    void deletePlayer(int);
    string getName(int)const;


};



#endif


