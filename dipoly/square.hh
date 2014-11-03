//
//
//
//
#ifndef SQUARE_HH
#define SQUARE_HH

#include "./julkinen/utility.hh"
#include "./julkinen/initreader.hh"
#include "playerlist.hh"

#include<string>
#include<vector>
#include<iostream>


using std::vector;
using std::string;
using std::cout;


/// type definitions for street and card vectors
//   typedef vector< Utility::Street > Streets;
//   typedef vector< Utility::Card > Cards;


///square
///**************************************************************************


class square
{
protected:

    string squareName_;
    int squareID_ ;
    int numberOfShacks_;
    int maximumPosShacks_;
    int ownerID_;
    int squarePrice_;
    string squareType_;
    int shackPrice_;


public:
    square() {}
    square(string squareName, int squareID,int numberOfShacks,
           int maximumPosShacks, int ownerID,int squarePrice,
           string squareType,int shackPrice):
        squareName_(squareName),
        squareID_(squareID),numberOfShacks_(numberOfShacks),
        maximumPosShacks_(maximumPosShacks),
        ownerID_(ownerID), squarePrice_(squarePrice),
        squareType_(squareType),shackPrice_(shackPrice) {}




/// Copy constructor

    square(const square &cSource)
    {
        squareType_ = cSource.squareType_;
        squareName_ = cSource.squareName_;
        squareID_ = cSource.squareID_;
        squarePrice_ = cSource.squarePrice_;
        shackPrice_ = cSource.shackPrice_;
        numberOfShacks_ = cSource.numberOfShacks_;
        maximumPosShacks_ = cSource.maximumPosShacks_;
        ownerID_ = cSource.ownerID_;
    }

/// Assignment Operator
    square& operator= (const square &cSource);

/// Destructor
    virtual ~square() {}

/// Methods for square class

    void getSquare(string&, int&,int&,int&,int&,int&,int&);
    void reset();


    void showSquare();
    string getSquareName() const;
    int getSquarePrice() const;
    string getSquareType() const;

    virtual void buyStreet(int, playerlist&) {}
    virtual bool checkAllowableShack()
    {
        return false;
    }
    virtual void buildShack(int, playerlist&) {}
    virtual int payRent(int, playerlist&)
    {
        return 0;
    }

    virtual void setOwnerID(int) {}
    virtual int getOwnerID() const
    {
        return 0;
    }
    virtual int getShackPrice() const
    {
        return 0;
    }
    virtual void drawCard(int, playerlist&, InitReader::Cards&) {}
    virtual void giveBribe(int, playerlist&) {}


};


///start
///**************************************************************************

class start:public square
{
public:

    start():square() {}

    start(string squareName, int squareID,int numberOfShacks,
          int maximumPosShacks, int ownerID,int squarePrice,
          string squareType,int shackPrice):
        square(squareName,squareID,numberOfShacks,maximumPosShacks,ownerID,squarePrice,squareType,shackPrice) {}


/// Copy constructor
    start(const start& cSource): square(cSource)
    {
        squareType_ = cSource.squareType_;
        squareName_ = cSource.squareName_;
        squareID_ = cSource.squareID_;
        squarePrice_ = cSource.squarePrice_;
        shackPrice_ = cSource.shackPrice_;
        numberOfShacks_ = cSource.numberOfShacks_;
        maximumPosShacks_ = cSource.maximumPosShacks_;
        ownerID_ = cSource.ownerID_;
    }


    /// Assignment Operator
    start& operator= (const start &cSource)
    {
        // check for self-assignment by comparing the address of the
        // implicit object and the parameter
        square::operator=(cSource);
        return *this;
    }


/// Destructor
    virtual ~start() {}


};


///street
///**************************************************************************


class street:public square
{
public:

    street():square() {}

    street(string squareName, int squareID,int numberOfShacks,
           int maximumPosShacks, int ownerID,int squarePrice,
           string squareType,int shackPrice):
        square(squareName,squareID,numberOfShacks,maximumPosShacks,ownerID,squarePrice,squareType,shackPrice) {}


/// Copy constructor
    street(const street& cSource): square(cSource)
    {
        squareType_ = cSource.squareType_;
        squareName_ = cSource.squareName_;
        squareID_ = cSource.squareID_;
        squarePrice_ = cSource.squarePrice_;
        shackPrice_ = cSource.shackPrice_;
        numberOfShacks_ = cSource.numberOfShacks_;
        maximumPosShacks_ = cSource.maximumPosShacks_;
        ownerID_ = cSource.ownerID_;
    }


    /// Assignment Operator
    street& operator= (const street &cSource)
    {
        // check for self-assignment by comparing the address of the
        // implicit object and the parameter
        square::operator=(cSource);
        return *this;
    }


/// Destructor
    virtual ~street() {}

/// methods



        int getNoOfShacks()const;
        //void setNoOfShacks();
        void setOwnerID(int);
        int getOwnerID() const;
        void buyStreet(int, playerlist&);
        bool checkAllowableShack();
        void buildShack(int, playerlist&);
        int payRent(int, playerlist&);
        int getShackPrice()const;
        //void checkBuildStatus();



};



///PRISON
///**************************************************************************

class prison:public square
{
public:

    prison():square() {}

    prison(string squareName, int squareID,int numberOfShacks,
          int maximumPosShacks, int ownerID,int squarePrice,
          string squareType,int shackPrice):
        square(squareName,squareID,numberOfShacks,maximumPosShacks,ownerID,squarePrice,squareType,shackPrice) {}


/// Copy constructor
    prison(const prison& cSource): square(cSource)
    {
        squareType_ = cSource.squareType_;
        squareName_ = cSource.squareName_;
        squareID_ = cSource.squareID_;
        squarePrice_ = cSource.squarePrice_;
        shackPrice_ = cSource.shackPrice_;
        numberOfShacks_ = cSource.numberOfShacks_;
        maximumPosShacks_ = cSource.maximumPosShacks_;
        ownerID_ = cSource.ownerID_;
    }


    /// Assignment Operator
    prison& operator= (const prison &cSource)
    {
        // check for self-assignment by comparing the address of the
        // implicit object and the parameter
        square::operator=(cSource);
        return *this;
    }


/// Destructor
    virtual ~prison() {}

///methods

void giveBribe(int, playerlist&);

};



///CARD
///**************************************************************************

class card:public square
{
public:

    card():square() {}

    card(string squareName, int squareID,int numberOfShacks,
          int maximumPosShacks, int ownerID,int squarePrice,
          string squareType,int shackPrice):
        square(squareName,squareID,numberOfShacks,maximumPosShacks,ownerID,squarePrice,squareType,shackPrice) {}


/// Copy constructor
    card(const card& cSource): square(cSource)
    {
        squareType_ = cSource.squareType_;
        squareName_ = cSource.squareName_;
        squareID_ = cSource.squareID_;
        squarePrice_ = cSource.squarePrice_;
        shackPrice_ = cSource.shackPrice_;
        numberOfShacks_ = cSource.numberOfShacks_;
        maximumPosShacks_ = cSource.maximumPosShacks_;
        ownerID_ = cSource.ownerID_;
    }


    /// Assignment Operator
    card& operator= (const card &cSource)
    {
        // check for self-assignment by comparing the address of the
        // implicit object and the parameter
        square::operator=(cSource);
        return *this;
    }


/// Destructor
    virtual ~card() {}


/// Mthods

void drawCard(int, playerlist&, InitReader::Cards&);


};



















#endif
