// player -- for creating and executing players in the dipoly
//
//
//

#ifndef PLAYER_HH
#define PLAYER_HH

#include <string>
#include <vector>
using std::string;
using std::vector;


class player{

private:
    string name_;       // Name of the player
    int ID_;            // Player's Serial number
    int type_;          // Player Type 0 for human and 1 for AI
    int balance_;       // The amount of money a player has
    int position_;      // players position on the game board
    bool prisonStatus_; // If if is 1 player is impriosned. Otherwise Free

    public:
    player();  // parameterless default constructor
    //player(string new_name, int new_ID, int new_balance, int new_position,
    //       bool new_prison_status); //  constructor with parameters

// Destructor

~player();

// Copy constructor
    player(const player &cSource)
    {
        name_ = cSource.name_;
	ID_ = cSource.ID_;
	type_ = cSource.type_;
	balance_ = cSource.balance_;
	position_ = cSource.position_;
	prisonStatus_ = cSource.prisonStatus_;
    }
// Assignment Operator
    player& operator= (const player &cSource);

    void setPlayer(string, int, int, int, int, bool);
    void positionUpdate(int);
    void balanceUpdate(int);
    void setPrisonStatus();
    void resetPrisonStatus();
    int getID()const;
    int getPosition()const;
    int getBalance() const;
    int getType() const;
    bool getPrisonStatus() const;
    void showPlayerStatus()const;
    string getName() const;

};



#endif


