//
//
//

#include "player.hh"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;


player::player()     // default constructor
{

    name_ = "MINHAZ";
    ID_ = 1;
    type_ = 0;
    balance_ = 0;
    position_ = 1;
    prisonStatus_ = false;
}


// Assignment operator


player& player::operator= (const player &cSource)
{
    // check for self-assignment by comparing the address of the
    // implicit object and the parameter
    if (this == &cSource)
        return *this;

    // do the copy
	name_ = cSource.name_;
	ID_ = cSource.ID_;
	type_ = cSource.type_;
	balance_ = cSource.balance_;
	position_ = cSource.position_;
	prisonStatus_ = cSource.prisonStatus_;

    // return the existing object
    return *this;
}

player::~player()
{
}




/*player::player(string new_name, int new_ID, int new_balance, int new_position,
               bool new_prison_status) {   // constructor

    name = new_name;
    ID = new_ID;
    balance = new_balance;
    position = new_position;
    prison_status = new_prison_status;
}

*/

void player::setPlayer(string new_name, int new_ID, int new_type, int new_balance, int new_position,
                       bool new_prisonStatus)
{

    name_ = new_name;
    ID_ = new_ID;
    type_ = new_type;
    balance_ = new_balance;
    position_ = new_position;
    prisonStatus_= new_prisonStatus;
}



// This function will update the position of the player based on die throwing
void player::positionUpdate(int NewPosition)
{
    position_ = position_ + NewPosition;
    if (position_ > 15)
    {
        position_ = position_-16;
    }
}

// This function will update the balance of the player based on purchasing street,
// building shack, escaping prison, getting or giving rent etc.
void player::balanceUpdate(int amount)
{
    balance_ = balance_ + amount;

}



void player::setPrisonStatus()
{
    prisonStatus_ = true;

}

void player::resetPrisonStatus()
{
    prisonStatus_ = false;

}



//
//

int player::getID()const
{
    return ID_;
}

int player::getPosition()const
{
    return position_;
}

//
//
int player::getBalance() const
{
    return balance_;
}


//
///
//
int player::getType() const
{
    return type_;
}

//
//
//

bool player::getPrisonStatus() const
{
    return prisonStatus_;
}


// Calling this function will show the details profile of the player
void player::showPlayerStatus()const
{
    cout << "#######PLAYER STATUS#######";
    cout << "name: " << name_ << endl;
    cout << "ID: " << ID_ << endl;
    cout << "type: " << type_ << endl;
    cout << "balance: " << balance_ << endl;
    cout << "position: " << position_ << endl;
    cout << "prison_status: " << prisonStatus_ << endl;
}

string player::getName() const
{
    return name_;
}

