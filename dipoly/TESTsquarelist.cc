#include "die.hh"
#include "boarddrawer.hh"
#include "initreader.hh"
#include "initexception.hh"
#include "squarelist.hh"

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::string;
using std::endl;
using std::cout;
using std::vector;


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


        // read the streets from init reader
        InitReader::Streets streets = reader.getStreets();

        squarelist sl;
        sl.createSquareList(streets);
        sl.showSquareList();

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
