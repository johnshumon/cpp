//
//
//

#include "player.hh"
#include "square.hh"

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

    name_ = "SHUMON";
    ID_ = 1;
    type_ = 0;
    balance_ = 0;
    position_ = 1;
    prisonStatus_ = false;
    rentStatus_ = true;
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
    rentStatus_ = cSource.rentStatus_;

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

// void player::setPlayer(string new_name, int new_ID, int new_type, int new_balance, int new_position,
                       // bool new_prisonStatus,bool new_rentStatus)
// {

    // name_ = new_name;
    // ID_ = new_ID;
    // type_ = new_type;
    // balance_ = new_balance;
    // position_ = new_position;
    // prisonStatus_= new_prisonStatus;
    // rentStatus_= new_rentStatus;
// }



// This function will update the position of the player based on die throwing
void player::positionUpdate(int D, vector <square*>  sl_)
{


     /// position update

    if(getPrisonStatus() == 1 && D == 6)
    {
        position_ = position_ + D;
        if (position_ > 15)
        {
            position_ = position_-16;
            balanceUpdate(sl_[0]->getSquarePrice () );
            cout << "start square: " << sl_[0]->getSquarePrice () << endl;
        }

        cout<< "you move to "<< sl_[getPosition()]->getSquareName()
            << endl;
        resetPrisonStatus();
    }

    else if(getPrisonStatus()==0)
    {
        position_ = position_ + D;
        if (position_ > 15)
        {
            position_ = position_-16;
            balanceUpdate(sl_[0]->getSquarePrice () );
            cout << "start square: " << sl_[0]->getSquarePrice () << endl;
        }

        cout<< "you move to "<< sl_[getPosition()]->getSquareName()
            << endl;

    }

    else if(getPrisonStatus() == 1 && type_ == 0)

    {
        cout<< "you are in prison" << endl;

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

///
void player::setRentStatus()
{
    rentStatus_ = true;

}

void player::resetRentStatus()
{
    rentStatus_ = false;
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

///
bool player::getRentStatus() const
{
    return rentStatus_;
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


/// Drawing the board
//vector<player>& pl, vector<square>& squareList_
void player::drawBoard(vector<player*> pl_,vector<square*> squareList_)
{
    BoardDrawer board;
//                        int currentSquare = 0;
    string squareName;
    int squareID = 0;
    int numberOfShacks = 0;
    int maximumPosShacks = 0;
    int ownerID = 0;
    int squarePrice = 0;
    int shackPrice = 0;
    char owner;
    char presentPlayer;
    int id = 0;


    for( int j=0; j<MAX_SQUARE; j++)
    {
        squareList_[j]-> getSquare(squareName, squareID,
                                   numberOfShacks, maximumPosShacks,
                                   ownerID,squarePrice,shackPrice);

        if (ownerID == 0)
        {
            owner = '-';
        }
        else
        {
            owner = char(ownerID + FORTY_EIGHT);
        }

        board.addSquare( squareName, squareID, maximumPosShacks, owner,squarePrice);
        //playerSize = ;

        int k = 0;

        for (k = 0; k < int(pl_.size()); k++)
        {
            presentPlayer= char(pl_[k]->getID()+ FORTY_EIGHT);
            id = pl_[k]->getPosition() + 1;
            board.addPlayer(id,presentPlayer);
        }

        board.changeShacks(squareID, numberOfShacks, maximumPosShacks);

//                         cout <<endl << i << " :numberOfShacks: " << numberOfShacks <<
//                         "   maximumPosShacks: " << maximumPosShacks << endl;
    }
    cout << endl;
    board.draw( cout );

}






///human
/////**************************************************************************
void human::showDiecast(int D)
{
	cout << "The die is cast: " << D <<endl;
} 

string human::playerAction(int i, vector<player*> pl_ ,string inputOption,
                        InitReader::Cards& cards_,vector<square*> squareList_)
{


	squareList_[pl_[i]->getPosition()]->squareAction(i, pl_, inputOption, cards_, squareList_);



	do
	{
		cout << pl_[i]->getName() << " \'" << pl_[i]->getID() << "\' "
			 << pl_[i]->getBalance() << " >";
		cin >> inputOption;


		if (inputOption == "quit")
		{
			// clearSquarelist();
			return inputOption;
		}

		else if (inputOption == "buy" || inputOption == "build"
				 || inputOption == "bribe")
		{
			squareList_[pl_[i]->getPosition()]->squareAction(i, pl_, inputOption, cards_, squareList_);

		}

		/// if "board" is pressed this condition will be executed
		else if (inputOption == "board")
		{
			drawBoard(pl_,squareList_);
		}


		else if (inputOption == "next")
		{
		   pl_[i]->setRentStatus();
		}

		else
		{
			cout <<"Wrong Input for present location" << endl;
		}

	}
	while (inputOption != "next");
	
	return inputOption;

} // completion for human player

///AI
/////**************************************************************************


string ai::playerAction(int i, vector<player*> pl_ ,string inputOption,
                        InitReader::Cards& cards_,vector<square*> squareList_)
{
	cout << pl_[i]->getName() << " \'" << pl_[i]->getID() << "\' "
		 << pl_[i]->getBalance() << " >";

	inputOption = "bribe";
	squareList_[pl_[i]->getPosition()]->squareAction(i, pl_, inputOption, cards_, squareList_);
	inputOption = "next";
	return inputOption;

} // complete for AI player
