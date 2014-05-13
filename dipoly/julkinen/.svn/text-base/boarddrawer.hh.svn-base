// BoardDrawer -- for priting the game board

#ifndef BOARD_DRAWER_HH
#define BOARD_DRAWER_HH

#include <iostream>
#include <vector>
#include <string>

class BoardDrawer
{
public:
 
   static const int MAX_PLAYERS = 5;
   static const int SQUARES = 16;
   static const int SQUARES_X = 5;
   static const int SQUARES_Y = 5;

   BoardDrawer();
   ~BoardDrawer();

   // draw the board into given stream
   void draw( std::ostream& out ) const;
      
   // Adds a square to the board
   bool addSquare( std::string name, int id, int shackMax,
                   char owner, int price );

   // Changes the price of the square
   bool changePrice( int squareID, int price );

   // change the owner of the square
   bool changeOwner( int squareID, char symbol );

   // adds a player to a square (player id 1..5)
   bool addPlayer( int squareID, char  player );

   // removes  a player from a square (player id 1..5)
   bool removePlayer( int squareID, char player );
 
   // changes the number of shacks in the square
   bool changeShacks( int squareID, int shackAmount, int maxAmount );

private:

   // No need to copy or make assignment operations for the board
   BoardDrawer( const BoardDrawer& );
   BoardDrawer& operator =( const BoardDrawer& ); 

   void putPlayers( int id );
   void putText( int x, int y, std::string text );
   void putChar( int x, int y, char symbol );
   void putShacks( int sID, int shacks, int max );
   void putOwner( int sID, char owner );
   void putMoney( int sID, int money );
   void putID( int sID ); 

   typedef std::vector< std::string > Board;
   Board board_;
   typedef std::vector< std::string > Players;
   Players players_;
};


#endif
