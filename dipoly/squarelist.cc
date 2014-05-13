#include "squarelist.hh"

#include "square.hh"

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::string;
using std::endl;
using std::cout;
using std::vector;


bool operator <(const SquareSort &lhs, const SquareSort &rhs)
{
    return lhs.id < rhs.id;
}


//squarelist::~squarelist()

void squarelist::clearSquarelist()
{

    while( !squareList_.empty() )
    {
        //cout<<"destructor";
        square* p = squareList_.at( int(squareList_.size())-1 );
        delete p;
        p = 0;
        squareList_.pop_back();
    }
}




squarelist& squarelist::operator = (const squarelist &cSource)
{
    // check for self-assignment by comparing the address of the
    // implicit object and the parameter
    if (this == &cSource)
        return *this;

    // do the copy
    squareList_ = cSource.squareList_;

    // return the existing object
    return *this;
}








void squarelist::createSquareList(InitReader::Streets streets )

{
    // iterate the vector using an iterator
    vector<SquareSort > SquareSort1;
    SquareSort SquareSort2;

    for( InitReader::Streets::iterator it = streets.begin();
            it != streets.end(); ++it )
    {
        Utility::Street tempStr = *it;
        // a test draw using boarddrawer, first we add the squares
        SquareSort2.stype = tempStr.stype;
        SquareSort2.name = tempStr.name;
        SquareSort2.id = tempStr.id;
        SquareSort2.price = tempStr.price;
        SquareSort2.shackPrice = tempStr.shackPrice;
        SquareSort2.shackMax = tempStr.shackMax;

        SquareSort1.push_back (SquareSort2);

    }

    std::sort(SquareSort1.begin(), SquareSort1.end()); // sorts by id

    SquareSort tempStr;

    squareList_.resize(16);


    for( int i= 0; i< int(SquareSort1.size()); ++i )
    {
        tempStr = SquareSort1[i];

        if (tempStr.stype =="START")
        {
            squareList_.at(i) = new start(tempStr.name, tempStr.id, 0, tempStr.shackMax, 0,
                                          tempStr.price, tempStr.stype, tempStr.shackPrice);

        }

        if (tempStr.stype =="CARD")
        {
            squareList_.at(i) = new card(tempStr.name, tempStr.id, 0, tempStr.shackMax, 0,
                                         tempStr.price, tempStr.stype, tempStr.shackPrice);



        }

        if (tempStr.stype =="PRISON")
        {
            squareList_.at(i) = new prison(tempStr.name, tempStr.id, 0, tempStr.shackMax, 0,
                                           tempStr.price, tempStr.stype, tempStr.shackPrice);



        }

        if (tempStr.stype =="STREET")
        {

            //    sq = new street(squareName, squareID, numberOfShacks, maximumPosShacks, ownerID,
//                squarePrice, squareType, shackPrice);
            squareList_.at(i) = new street(tempStr.name, tempStr.id, 0, tempStr.shackMax, 0,
                                           tempStr.price, tempStr.stype, tempStr.shackPrice);

        }

    }

}


// SHOW the created squarelist
void squarelist::showSquareList()
{

    for( int i =0; i< int(squareList_.size()); ++i )
    {
        squareList_[i]->showSquare();
    }
}


void squarelist::buyStreet(int currentSquare,int currentPlayer, playerlist& pl)
{
    squareList_[currentSquare]->buyStreet(currentPlayer, pl);
}


void squarelist::buildShack(int currentSquare,int currentPlayer, playerlist& pl)
{
    squareList_[currentSquare]->buildShack(currentPlayer, pl);
}


int squarelist::payRent(int currentSquare,int currentPlayer, playerlist& pl)
{
    return squareList_[currentSquare]->payRent(currentPlayer, pl);
}

void squarelist::drawCard(int currentSquare,int currentPlayer, playerlist& pl, InitReader::Cards& cards)
{
    squareList_[currentSquare]->drawCard(currentPlayer, pl,cards);
}

void squarelist::giveBribe(int currentSquare,int currentPlayer, playerlist& pl)
{
    squareList_[currentSquare]->giveBribe(currentPlayer, pl);
}

string squarelist::getSquareName(int currentSquare) const
{
    return squareList_[currentSquare]->getSquareName();
}


int squarelist::getSquarePrice (int currentSquare) const
{
    return squareList_[currentSquare]->getSquarePrice();
}



int squarelist::getShackPrice (int currentSquare) const
{
    return squareList_[currentSquare]->getShackPrice();
}


bool squarelist::checkAllowableShack(int currentSquare) const
{
    return squareList_[currentSquare]->checkAllowableShack();
}





int squarelist::getSquareOwner (int currentSquare) const
{
    return squareList_[currentSquare]->getOwnerID();
}

string squarelist::getSquareType(int currentSquare) const
{
    return squareList_[currentSquare]->getSquareType();
}


void squarelist::reset(int currentSquare)
{
    squareList_[currentSquare]->reset();
}


void squarelist::getSquare(string& squareName, int& squareID,
                           int& numberOfShacks,int& maximumPosShacks,
                           int& ownerID,int& squarePrice,int& shackPrice, int currentSquare)
{
    squareList_[currentSquare]-> getSquare(squareName, squareID,
                                           numberOfShacks, maximumPosShacks,
                                           ownerID,squarePrice,shackPrice);

}



