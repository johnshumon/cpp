// player -- for creating and executing players in the dipoly
//
//
//

#ifndef PLAYER_HH
#define PLAYER_HH

#include "julkinen/utility.hh"
#include "julkinen/initreader.hh"
#include "julkinen/boarddrawer.hh"

#include <string>
#include <vector>

#define MAX_SQUARE 16
#define FORTY_EIGHT 48

using std::string;
using std::vector;

class square;
class player;

class player{

protected:
    string name_;       // Name of the player
    int ID_;            // Player's Serial number
    int type_;          // Player Type 0 for human and 1 for AI
    int balance_;       // The amount of money a player has
    int position_;      // players position on the game board
    bool prisonStatus_; // If if is 1 player is impriosned. Otherwise Free
    bool rentStatus_;
    
	public:
    player();
	
	player(string name,int ID,int type,int balance,int position,
		bool prisonStatus, bool rentStatus):name_(name),ID_(ID),type_(type),
		balance_(balance),position_(position),prisonStatus_(prisonStatus),
		rentStatus_(rentStatus){}	
	
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
        rentStatus_ = cSource.rentStatus_;
    }
// Assignment Operator
    player& operator= (const player &cSource);

// Methods for player class

    // void setPlayer(string, int, int, int, int, bool,bool);
    void positionUpdate(int, vector <square*>);
    void balanceUpdate(int);
    void setPrisonStatus();
    void resetPrisonStatus();
    void setRentStatus();
    void resetRentStatus();
    int getID()const;
    int getPosition()const;
    int getBalance() const;
    int getType() const;
    bool getPrisonStatus() const;
    bool getRentStatus() const;
    void showPlayerStatus()const;
    string getName() const;
	void drawBoard(vector<player*>,vector<square*>);
	virtual void showDiecast(int){}
	virtual string playerAction(int, vector<player*>,string,
                              InitReader::Cards&,vector<square*>)
							  {return "next";}

};

//////////////////////////////////

///human
///**************************************************************************

class human:public player
{
public:
	human():player() {}
	
	human(string name,int ID,int type,int balance,int position,
		bool prisonStatus, bool rentStatus):player(name,ID,type,balance,position,prisonStatus,rentStatus){}	

// Copy constructor
   human(const human &cSource): player(cSource)
   {
		name_ = cSource.name_;
		ID_ = cSource.ID_;
		type_ = cSource.type_;
		balance_ = cSource.balance_;
		position_ = cSource.position_;
		prisonStatus_ = cSource.prisonStatus_;
		rentStatus_ = cSource.rentStatus_;
   }
/// Assignment Operator
   human& operator= (const human &cSource)
   {
       // check for self-assignment by comparing the address of the
       // implicit object and the parameter
       player::operator=(cSource);
       return *this;
   }


/// Destructor
   virtual ~human() {}

// Methods for player class
    void showDiecast(int); 
	string playerAction(int, vector<player*>,string,
                              InitReader::Cards&,vector<square*>);
};

///ai
///**************************************************************************

class ai:public player
{
public:
	ai():player() {}
	
	ai(string name,int ID,int type,int balance,int position,
		bool prisonStatus, bool rentStatus):player(name,ID,type,balance,position,prisonStatus,rentStatus){}	

// Copy constructor
   ai(const ai &cSource): player(cSource)
   {
	name_ = cSource.name_;
	ID_ = cSource.ID_;
	type_ = cSource.type_;
	balance_ = cSource.balance_;
	position_ = cSource.position_;
	prisonStatus_ = cSource.prisonStatus_;
	rentStatus_ = cSource.rentStatus_;
   }
/// Assignment Operator
   ai& operator= (const ai &cSource)
   {
       // check for self-assignment by comparing the address of the
       // implicit object and the parameter
       player::operator=(cSource);
       return *this;
   }


/// Destructor
   virtual ~ai() {}

// Methods for player class
	string playerAction(int, vector<player*>,string,
                              InitReader::Cards&,vector<square*>);
};


#endif


