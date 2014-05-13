#include "die.hh"
#include "boarddrawer.hh"
#include "initreader.hh"
#include "initexception.hh"

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
      reader.printData( cout );
      cout << "seed value: " << reader.dieSeed() << endl;
      cout << "starting money: " << reader.startMoney() << endl;
      cout << "board name: " << reader.boardName() << endl;

      // create a die and initialize it with the seed
      Die die( reader.dieSeed() );

      // cast the die
      for( unsigned i(0); i < 20; ++i )
      {
         cout << "die cast: " << die.cast() << endl;
      } 


      // read the streets from init reader
      InitReader::Streets streets = reader.getStreets();
      // iterate the vector using an iterator
      for( InitReader::Streets::iterator it = streets.begin(); 
           it != streets.end(); ++it )
      {
         Utility::Street tempStr = *it;
         // a test draw using boarddrawer, first we add the squares
         board.addSquare( tempStr.name, tempStr.id, tempStr.shackMax, 
                          '-', tempStr.price );
      }
      board.draw( cout );
      InitReader::Cards cards = reader.getCards();
      for( InitReader::Cards::const_iterator it = cards.begin();
           it != cards.end(); ++it )
      {
         Utility::Card tempCard = *it;
         cout << tempCard.description;
         if( tempCard.prison ){ cout << " (a go-to-prison card)" << endl; }
         else { cout << " (NOT a go-to-prison card)" << endl; }
      }
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
