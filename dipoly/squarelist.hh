// squarelist -- for creating and executing squares in the dipoly

#ifndef SQUARELIST_HH
#define SQUARELIST_HH

#include "./julkinen/initreader.hh"
#include "square.hh"

#include <string>
#include <vector>

using std::string;
using std::vector;


struct SquareSort
{
    string stype ;
    string name  ;
    int id  ;
    int price  ;
    int shackPrice ;
    int shackMax ;
};


bool operator <(const SquareSort &lhs, const SquareSort &rhs);


class squarelist
{

private:
    vector <square*> squareList_; // This is the vector consist of all squares

public:
    squarelist(){}
//    ~squarelist();
// Copy constructor
    squarelist(const squarelist &cSource)
    {
        squareList_ = cSource.squareList_;
    }

// Assignment Operator
    squarelist& operator= (const squarelist &cSource);

    void clearSquarelist();
    void createSquareList(InitReader::Streets streets);
    void showSquareList();
    void getSquare(string& squareName, int& squareID,
                    int& numberOfShacks,int& maximumPosShacks,
                    int& ownerID,int& squarePrice,int& shackPrice, int currentSquare);

    void reset(int currentSquare);
    void buyStreet(int currentSquare,int, playerlist&);
    void buildShack(int currentSquare,int, playerlist&);
    int payRent(int currentSquare,int currentPlayer, playerlist& pl);
    void drawCard(int currentSquare,int currentPlayer, playerlist& pl, InitReader::Cards& cards);
    void giveBribe(int currentSquare,int currentPlayer, playerlist& pl);
    string getSquareName(int currentSquare) const;
    int getSquarePrice (int currentSquare) const;
    int getShackPrice (int currentSquare) const;
    int getSquareOwner (int currentSquare) const;
    string getSquareType(int currentSquare) const;
    bool checkAllowableShack(int currentSquare) const;

};


#endif
