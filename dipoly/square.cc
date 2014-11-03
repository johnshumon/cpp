//
//
//
#include "square.hh"
#include "playerlist.hh"

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
void street::buyStreet(int currentPlayer,playerlist& pl)  // CHECK THIS REFERENCE
{

    setOwnerID(pl.getID(currentPlayer));
    pl.balanceUpdate(currentPlayer,(-1)*squarePrice_);
//    cout << pl.getID(currentPlayer)<<"bought a street" << endl;

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

void street::buildShack(int currentPlayer, playerlist& pl)
{
    if(numberOfShacks_ < maximumPosShacks_)
    {
        numberOfShacks_++;
        pl.balanceUpdate(currentPlayer,(-1)*shackPrice_);
//        cout << pl.getID(currentPlayer)<<" built a shack" << endl;
    }
}

//
// function for RENT
//
int street::payRent(int currentPlayer, playerlist& pl)
{
    int serial = 0;
    int rentAmount = 0;
    rentAmount = squarePrice_/4 +(numberOfShacks_)*(numberOfShacks_)*squarePrice_/10;
    serial = pl.findPlayerSerial(getOwnerID());
    pl.balanceUpdate(serial,rentAmount);
    pl.balanceUpdate(currentPlayer,(-1)*rentAmount);
    return rentAmount;
}
//
////


int street::getShackPrice() const
 {
     return shackPrice_;
 }








///PRISON
///**************************************************************************


void prison::giveBribe(int currentPlayer, playerlist& pl)
{
    pl.balanceUpdate(currentPlayer,(-1)*squarePrice_);
    pl.resetPrisonStatus(currentPlayer);

}


///CARD
///**************************************************************************

void card::drawCard(int currentPlayer, playerlist& pl, InitReader::Cards& cards )
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
        pl.setPrisonStatus(currentPlayer);
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

    pl.balanceUpdate(currentPlayer,money);
    pl.positionUpdate(currentPlayer,move);
    if(prison== true)
    {
        int move1 = 0;
        move1 = 4- pl.getPosition(currentPlayer);
        pl.positionUpdate(currentPlayer,move1);

    }

}


















