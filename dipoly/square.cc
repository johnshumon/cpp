//
//
//
#include "square.hh"


using std::cin;
using std::endl;


///square
///**************************************************************************


/// Assignment Operator

square& square::operator= (const square &cSource)
{
    // check for self-assignment by comparing the address of the
    // implicit object and the parameter
    if (this == &cSource)
    {
        return *this;
    }

    // do the copy
    squareType_ = cSource.squareType_;
    squareName_ = cSource.squareName_;
    squareID_ = cSource.squareID_;
    squarePrice_ = cSource.squarePrice_;
    shackPrice_ = cSource.shackPrice_;
    numberOfShacks_ = cSource.numberOfShacks_;
    maximumPosShacks_ = cSource.maximumPosShacks_;
    ownerID_ = cSource.ownerID_;

    // return the existing object
    return *this;
}



void square::showSquare()
{
    cout << "squareName = " << squareName_ << endl;
    cout << "squareID_ = " << squareID_ << endl;
    cout << "numberOfShacks_ = " << numberOfShacks_ << endl;
    cout << "maximumPosShacks = " << maximumPosShacks_ << endl;
    cout << "ownerID = " << ownerID_ << endl;
    cout << "squarePrice = " << squarePrice_ << endl;    // price of square
    cout << "shackPrice = " << shackPrice_ << endl;    // price of building one shack
    cout << "squareType = " << squareType_ << endl;
    cout << "##############################################" << endl;
}


void square::getSquare(string& squareName, int& squareID,
                       int& numberOfShacks,int& maximumPosShacks,
                       int& ownerID,int& squarePrice,int& shackPrice)
{
    squareName = squareName_;
    squareID = squareID_;
    numberOfShacks = numberOfShacks_;
    maximumPosShacks = maximumPosShacks_;
    ownerID = ownerID_;
    squarePrice = squarePrice_;    // price of square
    shackPrice = shackPrice_;

}


void square::reset()
{
    ownerID_ = 0;
    numberOfShacks_ = 0;
}


string square::getSquareName() const
{
    return squareName_;
}



int square::getSquarePrice() const
{
    return squarePrice_;
}



string square::getSquareType()const
{
    return squareType_;

}

///start
///**************************************************************************



/// SquareAction for start
void start::squareAction(int i, vector<player*> pl_,string inputOption,
                              InitReader::Cards& cards,vector<square*> sl_)
{   
	InitReader::Cards cd = cards;
	vector<square*> sl = sl_;
	string s = inputOption;
    pl_[i]->balanceUpdate( getSquarePrice () );
    cout << "start square: " << getSquarePrice () << endl;
	
	if (inputOption == "buy")
	{
		cout << "You can not buy the square." << endl;
	}
	
	else if(inputOption == "build")
	{
		cout << "YOu do not own the square. You can only build on streets you own." << endl;
	}
	
	else if(inputOption == "bribe")
	{
		cout << "Check your medication. You are not in the prison." << endl;
	}
	
}



///street
///**************************************************************************



int street::getNoOfShacks() const
{
    return numberOfShacks_;
}



void street::setOwnerID(int oID)
{
    ownerID_ = oID;

}

// function for OwnerID
//
int street::getOwnerID() const
{
    return ownerID_;
}

//
void street::buyStreet(int currentPlayer,vector<player*> pl)  // CHECK THIS REFERENCE
{

    setOwnerID(pl[currentPlayer]->getID());
    pl[currentPlayer]->balanceUpdate((-1)*squarePrice_);


}




//


bool street::checkAllowableShack()
{
    if(numberOfShacks_ == maximumPosShacks_)
    {
        return true;
    }
    else
    {
        return false;
    }

}
//
//

void street::buildShack(int currentPlayer, vector<player*> pl)
{
    if(numberOfShacks_ < maximumPosShacks_)
    {
        numberOfShacks_++;
        pl[currentPlayer]->balanceUpdate((-1)*shackPrice_);
//        cout << pl.getID(currentPlayer)<<" built a shack" << endl;
    }
}

//
// function for RENT
//
int street::payRent(int currentPlayer, vector <player*> pl)
{
    int i = 0;
    int serial = 0;
    int rentAmount = 0;
    rentAmount = squarePrice_/4 +(numberOfShacks_)*(numberOfShacks_)*squarePrice_/10;

    for(i =0; i < int(pl.size()); i++)
    {
        if (getOwnerID() == pl[i]->getID())
        {
            break;

        }
    }

    serial = i;
    pl[serial]->balanceUpdate(rentAmount);
    pl[currentPlayer]->balanceUpdate((-1)*rentAmount);
    return rentAmount;
}
//
////


int street::getShackPrice() const
{
    return shackPrice_;
}


/// SquareAction for street
void street::squareAction(int i, vector<player*> pl_,string inputOption,
                              InitReader::Cards& cards,vector<square*> sl_)

{
	InitReader::Cards cd = cards;
	vector<square*> sl = sl_;
    /// Pay rent if player's present position is owned by someone.
    string owner;
    int counter = 0;
//    cout<<"RENT OPTION = " << pl_[i].getRentStatus();

    if(getOwnerID() != pl_[i]->getID() &&
            getOwnerID() > 0 && pl_[i]->getRentStatus()== true )
    {
        do
        {
            if(pl_[counter]->getID() == getOwnerID())
            {
                owner = pl_[counter]->getName();
                break;
            }
            else
            {
                counter++;
            }


        }
        while(true);

        cout << getSquareName() <<" owned by " <<
             owner
             << ": "<< payRent(i, pl_) << "$" << endl;
             pl_[i]->resetRentStatus();

    } // Rent Finish.

    if(pl_[i]->getType() == 0)
    {


        /// if "buy" is pressed this condition will be executed
        if (inputOption == "buy" )
        {

            if(getOwnerID() == 0 && pl_[i]->getBalance() >= getSquarePrice() )
            {
                buyStreet(i, pl_);
                cout << "you bought "<< getSquareName() << endl;
            }


            else if(getOwnerID() != pl_[i]->getID())
            {
                cout << "you cannot buy the square." << endl;
    //
            }

            else if(pl_[i]->getBalance() < getSquarePrice() )
            {
                cout << "you do not have enough money to buy "
                     << getSquareName() << endl;

            }

            else
            {
                cout << "You already bought the street" << endl;
            }

        }

        /// if "build" is pressed this condition will be executed

        else if (inputOption == "build")
        {
        if(getOwnerID() == pl_[i]->getID() && pl_[i]->getBalance() >=
           getShackPrice()&& !checkAllowableShack() )
        {
            buildShack(i, pl_);
            cout << "you built a new shack on "<< getSquareName() << endl;
        }

        else if(getOwnerID() != pl_[i]->getID() )
        {
            cout << "you do not own the square. you can only build on streets you own" << endl;

        }


        else if(checkAllowableShack())
        {
            cout << "The street already contains the maximum amount of shacks."<< endl;

        }


        else if(pl_[i]->getBalance() < getShackPrice())
        {
            cout << "you do not have enough money to build a new shack "<< endl;

        }

        else
        {
            cout << "Some error in building shack" << endl;
        }


    }

    }

    else
    {

        /// if "buy" is pressed this condition will be executed

            if(getOwnerID() == 0 &&
                    pl_[i]->getBalance() >= getSquarePrice () )
            {
                buyStreet(i, pl_);
                cout << "you bought "<< getSquareName() << endl;
            }

            if(getOwnerID() == pl_[i]->getID() &&
                    pl_[i]->getBalance() >= getShackPrice()&&
                    !checkAllowableShack() )
            {
                buildShack(i, pl_);
                cout << "you built a new shack on "<< getSquareName() << endl;
            }


    } // complete for AI player


	if(inputOption == "bribe")
	{
		cout << "Check your medication. You are not in the prison." << endl;
	}



}






///PRISON
///**************************************************************************


void prison::giveBribe(int currentPlayer, vector <player*> pl)
{
    pl[currentPlayer]->balanceUpdate((-1)*squarePrice_);
    pl[currentPlayer]->resetPrisonStatus();

}


/// SquareAction for Prison
void prison::squareAction(int i, vector<player*> pl_,string inputOption,
                              InitReader::Cards& cards,vector<square*> sl_)

{
	InitReader::Cards cd = cards;
	vector<square*> sl = sl_;
    if( (pl_[i]->getType() == 0) & (inputOption == "bribe") )
    {
        if(pl_[i]->getPrisonStatus()== true &&
            pl_[i]->getBalance() > getSquarePrice() )

        {
            giveBribe(i, pl_);
            cout << "You bribed your way out of prison" << endl;

        }
        else if(pl_[i]->getPrisonStatus()== false)
        {
            cout << "Check your medication. You are not in the prison" << endl;
        }

        else if(pl_[i]->getBalance() < getSquarePrice()
                && pl_[i]->getPrisonStatus()== true)
        {
            cout << pl_[i]->getBalance() <<endl;
            cout << getSquarePrice() << endl;
            cout << pl_[i]->getPrisonStatus() << endl;
            cout << " You do not have enough money for bribe" << endl;
        }

        else
        {
            cout <<"some problem with 'bribe' command" << endl;
        }

    } //end of if for player type.

    else if(pl_[i]->getType() == 1)
    {
        if(pl_[i]->getPrisonStatus()== true &&
            pl_[i]->getBalance() > getSquarePrice() )
            {
                giveBribe(i, pl_);
                cout << "You bribed your way out of prison" << endl;

            }
    }//end of else
	
	if (inputOption == "buy")
	{
		cout << "You can not buy the square." << endl;
	}
	
	else if(inputOption == "build")
	{
		cout << "YOu do not own the square. You can only build on streets you own." << endl;
	}
	
}//end of function.



///CARD
///**************************************************************************

void card::drawCard(int currentPlayer, vector <player*> pl, InitReader::Cards& cards,
                    vector <square*> sl )
{

    int i = 0;
    string description;
    description = cards[i].description;

    int money = 0;
    money = cards[i].money;

    int move = 0;
    move = cards[i].move;

    bool prison;
    prison = cards[i].prison;

    cout << description << endl;
    cout << "money: " << money << endl;
    cout << "move: " << move << endl;
    cout << "prison: " ;

    if(prison == true)
    {
        cout << "YES" << endl;

    }
    else
    {
        cout << "NO" << endl;
    }

    cards.erase (cards.begin());


    Utility::Card Card ;
    Card.description = description;
    Card.money = money;
    Card.move = move;
    Card.prison = prison;
    cards.push_back( Card );

    pl[currentPlayer]->balanceUpdate(money);
//    pl[currentPlayer].positionUpdate(move,sl);
    if(prison== true)
    {
        int move1 = 0;
        move1 = 4- pl[currentPlayer]->getPosition();
        pl[currentPlayer]->positionUpdate(move1,sl);
//        cout << "PRISON is TRUE so"
//        << pl[currentPlayer].getPosition() << endl;
        pl[currentPlayer]->setPrisonStatus();

    }
    else
    {
        pl[currentPlayer]->positionUpdate(move,sl);
//        cout << "PRISON is FALSE so move = " << move
//        << pl[currentPlayer].getPosition() << endl;
    }

}



/// SquareAction for card

void card::squareAction(int i, vector<player*> pl_,string inputOption, InitReader::Cards& cards,
                        vector<square*> sl)
{
    /// Card Drawing
	string s = inputOption;
    do
    {
        drawCard(i, pl_,cards, sl);

    } while(false);
//    while(getSquareType() == "CARD");
}

















