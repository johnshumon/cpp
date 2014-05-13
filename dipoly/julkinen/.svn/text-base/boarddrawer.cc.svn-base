#include "boarddrawer.hh"
#include "utility.hh"

using std::string;
using std::vector;
using std::ostream;
using std::endl;
using std::cout;

// nameless namespace for constants used in board
namespace
{
   const int SQUARE_SIZE_X = 15;
   const int SQUARE_SIZE_Y = 6;

   const int NAME_OFSET_X = 2;
   const int NAME_OFSET_Y = 1;

   const int SHACK_OFSET_X = 7;
   const int SHACK_OFSET_Y = 2;

   const int MONEY_OFSET_X = 6;
   const int MONEY_OFSET_Y = 3;

   const int PLR_OFSET_X = 2;
   const int PLR_OFSET_Y = 4;

   const int ID_OFSET_X = 2;
   const int ID_OFSET_Y = 2;

   const int OWNER_OFSET_X = 2;
   const int OWNER_OFSET_Y = 3;

   const char EDGE_MARK = '#';
   const char EMPTY = ' ';
   const string SQUARE_EDGE( SQUARE_SIZE_X, EDGE_MARK );
   const string OWNER = "O:";
   const string SHACK = "S:";
   const string PLR_ID = "id:";
   const string MONEY = "$:";
   const string PLAYERS = "P:";
   const string PLAYER_IDS( "12345" );



   struct Location
   {
      Location( int xx, int yy ): x( xx ), y( yy ){}
      int x;
      int y;
   };


   // conversion from square id to coordinates on board
   // Indexed using indexes from 1-number_of_squares
   const Location locations[ BoardDrawer::SQUARES+1 ] =
   {
     Location( SQUARE_SIZE_X*0, SQUARE_SIZE_Y*0 ),
     Location( SQUARE_SIZE_X*0, SQUARE_SIZE_Y*0 ),
     Location( SQUARE_SIZE_X*1, SQUARE_SIZE_Y*0 ),
     Location( SQUARE_SIZE_X*2, SQUARE_SIZE_Y*0 ),
     Location( SQUARE_SIZE_X*3, SQUARE_SIZE_Y*0 ),
     Location( SQUARE_SIZE_X*4, SQUARE_SIZE_Y*0 ),
     Location( SQUARE_SIZE_X*4, SQUARE_SIZE_Y*1 ),
     Location( SQUARE_SIZE_X*4, SQUARE_SIZE_Y*2 ),
     Location( SQUARE_SIZE_X*4, SQUARE_SIZE_Y*3 ),
     Location( SQUARE_SIZE_X*4, SQUARE_SIZE_Y*4 ),
     Location( SQUARE_SIZE_X*3, SQUARE_SIZE_Y*4 ),
     Location( SQUARE_SIZE_X*2, SQUARE_SIZE_Y*4 ),
     Location( SQUARE_SIZE_X*1, SQUARE_SIZE_Y*4 ),
     Location( SQUARE_SIZE_X*0, SQUARE_SIZE_Y*4 ),
     Location( SQUARE_SIZE_X*0, SQUARE_SIZE_Y*3 ),
     Location( SQUARE_SIZE_X*0, SQUARE_SIZE_Y*2 ),
     Location( SQUARE_SIZE_X*0, SQUARE_SIZE_Y*1 )
   };
   
}

BoardDrawer::BoardDrawer():
   board_( SQUARE_SIZE_Y*SQUARES_Y,
           std::string( SQUARE_SIZE_X*SQUARES_X, EMPTY ) ),
   players_( SQUARES, string( MAX_PLAYERS, EMPTY ) )
{
}

BoardDrawer::~BoardDrawer()
{
}

bool BoardDrawer::addSquare( string name, int id, int shackMax, 
			     char owner, int price )
{

   if( id < 1 || id > SQUARES )
   {
      return false;
   }

   // the borders of the square are drawn
   putText( locations[id].x, locations[id].y, SQUARE_EDGE );
   putText( locations[id].x, locations[id].y + SQUARE_SIZE_Y-1, SQUARE_EDGE );
   for( int i(1); i < SQUARE_SIZE_Y-1; ++i )
   {
      putChar( locations[id].x, locations[id].y + i, EDGE_MARK );
      putChar( locations[id].x+SQUARE_SIZE_X-1, locations[id].y + i, 
	       EDGE_MARK );
   }

   // draw the name of the square (clip the name if it would be
   // too long to fit inside the square)
   putText( locations[id].x+NAME_OFSET_X, locations[id].y+NAME_OFSET_Y,
            name.substr( 0, SQUARE_SIZE_X-3 ) );

   // put all the other information 
   putOwner( id, owner );
   putShacks( id, 0, shackMax );
   putMoney( id, price );
   putID( id );
   putPlayers( id );
   return true;
}


bool BoardDrawer::changeShacks( int squareID, int shackAmount, int max )
{
   if( squareID < 1 || squareID > SQUARES ){ return false; }
   if( shackAmount > max ){ return false; }
   putShacks( squareID, shackAmount, max );
   return true;
}


bool BoardDrawer::changePrice( int squareID, int price )
{
   if( squareID < 1 || squareID > SQUARES ){ return false; }
   putMoney( squareID, price );
   return true;
}


bool BoardDrawer::addPlayer( int squareID, char player )
{
   if( squareID < 1 || squareID > SQUARES ){ return false; }
   if( PLAYER_IDS.find_first_of( player ) == string::npos )
   { return false; }
   players_.at( squareID-1 ).at(  PLAYER_IDS.find_first_of( player ) ) = 
      player;

   putPlayers( squareID ); // update the view
   return true;
}


bool BoardDrawer::removePlayer( int squareID, char player )
{
   // Check if the removal operation is legal or not
   if( squareID < 1 || squareID > SQUARES ){ return false; }
   if( PLAYER_IDS.find_first_of( player ) == string::npos &&
       players_.at( squareID-1 ).find_first_of( player ) == string::npos )
   { return false; }

   players_.at( squareID-1 ).at( PLAYER_IDS.find_first_of( player ) ) = 
      EMPTY;
   putPlayers( squareID ); // update the view
   return true;
}


// Change the owner of the square
bool BoardDrawer::changeOwner( int squareID, char symbol )
{
   if( squareID < 1 || squareID > SQUARES ){ return false; }
   putOwner( squareID, symbol );
   return true;
}


void BoardDrawer::putOwner( int sID, char owner )
{
   string owna = OWNER + owner;
   putText( locations[sID].x + OWNER_OFSET_X, 
            locations[sID].y + OWNER_OFSET_Y, owna );
}


void BoardDrawer::putShacks( int sID, int shacks, int max )
{
  string shack;

  // If the square id is more than 1 char long, make "shift" to right
  if( sID > 9 ){ shack += " "; }

  shack += SHACK + Utility::int2string( shacks ) + "/" + 
     Utility::int2string( max );
  putText( locations[sID].x + SHACK_OFSET_X, 
           locations[sID].y + SHACK_OFSET_Y, shack );
}


void BoardDrawer::putMoney( int sID, int money )
{
   // we clear the area from previous entries before putting money on it
   string empty( 8, ' ' );
   putText( locations[sID].x + MONEY_OFSET_X, 
               locations[sID].y + MONEY_OFSET_Y, empty );
   string mon = MONEY + Utility::int2string( money );
   putText( locations[sID].x + MONEY_OFSET_X, 
               locations[sID].y + MONEY_OFSET_Y, mon );

}


void BoardDrawer::putID( int sID )
{
   string id = PLR_ID + Utility::int2string( sID );
   putText( locations[sID].x + ID_OFSET_X, 
               locations[sID].y + ID_OFSET_Y, id );
}


void BoardDrawer::putPlayers( int sID )
{
   // Clear the slot from previous entries
   string empty( 12, ' ' );
   putText( locations[sID].x + PLR_OFSET_X, 
            locations[sID].y + PLR_OFSET_Y, empty );

   string plr;
   // go through the players and add "," between ids if more than 1 
   for( unsigned i(0); i < PLAYER_IDS.size(); ++i )
   {
      if( PLAYER_IDS.at( i ) == players_.at( sID-1 ).at( i ) )
      {
         if( !plr.empty() ){ plr += ","; }
         plr += PLAYER_IDS.at( i );
      }
   }
   plr = PLAYERS + plr;
   putText( locations[sID].x + PLR_OFSET_X, 
            locations[sID].y + PLR_OFSET_Y, plr );
}



void BoardDrawer::putText( int x, int y, string text )
{
   board_.at( y ).replace( x, text.size(), text );
}


void BoardDrawer::putChar( int x, int y, char symbol )
{
   board_.at( y ).at( x ) = symbol;
}


void BoardDrawer::draw( ostream& out ) const
{
   for( unsigned i(0); i < board_.size(); ++i )
   {
      out << board_.at(i) << endl;
   }
}
