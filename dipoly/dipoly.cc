//
//
//

#include "julkinen/die.hh"
#include "julkinen/boarddrawer.hh"
#include "julkinen/initreader.hh"
#include "julkinen/initexception.hh"
#include "game.hh"

#include <iostream>
#include <cstdlib>

using std::string;
using std::endl;
using std::cout;

int main(int argc, char** argv )
{
   string temp;
   if( argc != 2 )
   {
      cout << "Give (only) the name of the init file as parameter..."
           << endl;
      return EXIT_FAILURE;
   }
   temp += argv[1];
   try
   {
      InitReader reader;
      BoardDrawer board;
      reader.readFile( temp );
      cout << "seed value: " << reader.dieSeed() << endl;
      cout << "starting money: " << reader.startMoney() << endl;
      cout << "board name: " << reader.boardName() << endl;
      Die die( reader.dieSeed() );// create a die and initialize it with the seed
      InitReader::Streets streets = reader.getStreets(); // read the streets from init reader
      InitReader::Cards cards = reader.getCards(); // read the cards from init reader

      int initialBalance = 0;
      initialBalance = reader.startMoney();
      int seed = 0;
      seed = reader.dieSeed();

      game dipoly;
      dipoly.createGame(seed,cards);
      dipoly.createPlayerList(initialBalance);
      dipoly.createSquareList(streets);
      //dipoly.show2();
      dipoly.playGame();
//      dipoly.drawBoard();
      dipoly.clearSquarelist();
	  dipoly.clearPlayerlist();

   }
   catch( FileError& fe )
   {
      cout << fe.description() << endl;
   }
   catch( TypeConversionError& te )
   {
      cout << te.description() << endl;
   }
   catch( ... )
   {
      cout << "An exception..." << endl;
   }
}
