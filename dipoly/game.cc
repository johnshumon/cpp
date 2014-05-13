//
//
//

#include "game.hh"
#include "julkinen/die.hh"

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


///
bool operator <(const SquareSort &lhs, const SquareSort &rhs)
{
    return lhs.id < rhs.id;
}



///
game& game::operator = (const game &cSource)
{
    // check for self-assignment by comparing the address of the
    // implicit object and the parameter
    if (this == &cSource)
        return *this;

    // do the copy
//    sl_= cSource.sl_;
    pl_= cSource.pl_;
    seed_= cSource.seed_;
    cards_= cSource.cards_;

    // return the existing object
    return *this;
}


void game::createPlayerList(int initialBalance)
{
    vector <string> Player_Name; // Vector for Creation of player names
    Player_Name = CreatePlayer(Player_Name); //Creation of player names
    player p;
    int new_type = 0;
    string S;
	pl_.resize(int(Player_Name.size()));
	
    for(int i=0; i< int(Player_Name.size()); i++)
    {
        S = Player_Name[i];
        if(S[0] == '#')
        {
            new_type = 1;
			pl_.at(i) = new ai(Player_Name[i], (i+1), new_type, initialBalance, 0,false,true);
			
        }
        else
        {
            new_type = 0;
			pl_.at(i) = new human(Player_Name[i], (i+1), new_type, initialBalance, 0,false,true);
        }
        
    }

}


void game::createSquareList(InitReader::Streets streets)

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


///

void game::clearSquarelist()
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


/// Clear Playerlist


void game::clearPlayerlist()
{

    while( !pl_.empty() )
    {
		player* p = pl_.at( int(pl_.size())-1 );
		delete p;
		p = 0;
		pl_.pop_back();
    }
}


/// Delete Bankrupted player

void game::deletePlayer(int currentPlayer)
{
	player* p = pl_.at( currentPlayer );
    delete p;
    p = 0;
    pl_.erase(pl_.begin() + currentPlayer);

}




/// Having seed and cards

void game::createGame(int seed, InitReader::Cards cards)
{
    seed_ = seed;
    cards_ = cards;
}



///PlayGame

void game::playGame()
{
    /// Necessary initialization
    int playerSize = 0;
    playerSize = int(pl_.size());
    Die die(seed_);
    int D = 0;
    string inputOption;

    /// This loop will play one turn and will iterate if players want to play more
    do
    {
        /// This loop will play once for  single player and then iterate upto all  players
        for(int i = 0; i < playerSize; i++)
        {
            cout << endl << "new turn: " << pl_[i]->getName() << " \'" <<
                 pl_[i]->getID() << "\' " << pl_[i]->getBalance() << endl;
            D = int(die.cast());

            ///Show diecast for human
			
			pl_[i]->showDiecast(D);


            /// position update

            pl_[i]->positionUpdate(D,squareList_);

            /// set rentstatus
            pl_[i]->setRentStatus();
			
			/// PLAYER ACTION
			inputOption = pl_[i]->playerAction(i, pl_, inputOption,cards_,squareList_);
			
			if (inputOption == "quit")
			{
			// clearSquarelist();
			return;
			}

        } // completion for single loop of all



        int s =0;
        int i1 = 0;
        s = int(pl_.size());

        while(i1<s)
        {
            if (pl_[i1]->getBalance() < 0)
            {

                for(int j=0; j<MAX_SQUARE; j++)
                {
                    if(squareList_[j] -> getOwnerID() == pl_[i1]->getID())
                    {
                        squareList_[j]->reset();

                    }
                }

                cout << endl << pl_[i1]->getName() << " has been bankrupted" <<endl;
                deletePlayer(i1);
            }

            else
            {
                i1++;
            }

            s = int(pl_.size());
        }



        playerSize = int(pl_.size());
        pl_[0]->drawBoard(pl_,squareList_);
        cout << endl;


    }
    while(playerSize > 1);

    if(playerSize == 1)
    {
        cout << pl_[0]->getName() <<" won" << endl;

    }

    clearSquarelist();
}






