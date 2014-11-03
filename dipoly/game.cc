//
//
//

#include "game.hh"
#include "./julkinen/boarddrawer.hh"
#include "./julkinen/die.hh"
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;



game& game::operator = (const game &cSource)
{
    // check for self-assignment by comparing the address of the
    // implicit object and the parameter
    if (this == &cSource)
        return *this;

    // do the copy
    sl_= cSource.sl_;
    pl_= cSource.pl_;
    seed_= cSource.seed_;
    cards_= cSource.cards_;

    // return the existing object
    return *this;
}





void game::createGame(playerlist& pl, squarelist& sl, int seed, InitReader::Cards cards)
{
    sl_ = sl;
    pl_ = pl;
    seed_ = seed;
    cards_ = cards;
}


void game::drawBoard(playerlist& pl, squarelist& sl)
{
    BoardDrawer board;
//                        int currentSquare = 0;
    string squareName;
    int squareID = 0;
    int numberOfShacks = 0;
    int maximumPosShacks = 0;
    int ownerID = 0;
    int squarePrice = 0;
    int shackPrice = 0;
    char owner;
    char presentPlayer;
    int id = 0;


    for( int j=0; j<MAX_SQUARE; j++)
    {
        sl.getSquare(squareName, squareID, numberOfShacks,
                      maximumPosShacks, ownerID, squarePrice, shackPrice, j);

        if (ownerID == 0)
        {
            owner = '-';
        }
        else
        {
            owner = char(ownerID + FORTY_EIGHT);
        }

        board.addSquare( squareName, squareID, maximumPosShacks, owner,squarePrice);
        //playerSize = ;

        int k = 0;

        for (k = 0; k < pl.sizePlayerList(); k++)
        {
            presentPlayer= char(pl_.getID(k)+ FORTY_EIGHT);
            id = pl.getPosition(k) + 1;
            board.addPlayer(id,presentPlayer);
        }

        board.changeShacks(squareID, numberOfShacks, maximumPosShacks);

//                         cout <<endl << i << " :numberOfShacks: " << numberOfShacks <<
//                         "   maximumPosShacks: " << maximumPosShacks << endl;
    }

    board.draw( cout );

}



void game::playGame()
{
//    pl_.showPlayerList();
//    sl_.showSquareList();

    /// Necessary initialization
    int playerSize = 0;
    playerSize = pl_.sizePlayerList();
    Die die(seed_);
    int D = 0;
    string inputOption;

    /// This loop will play one turn and will iterate if players want to play more
    do
    {
        /// This loop will play once for  single player and then iterate upto all  players
        for(int i = 0; i < playerSize; i++)
        {
            cout << "new turn: " << pl_.getName(i) << " \'" <<
                 pl_.getID(i) << "\' " << pl_.getBalance(i) << endl;
            D = int(die.cast());

            if(pl_.getType(i)==0)
            {
                cout << "The die is cast: " << D <<endl;

            }



            /// Start money

            if ( (pl_.getPosition(i) + D) >15 )
            {
                pl_.balanceUpdate(i,sl_.getSquarePrice (0) );
                cout << "start square: " << sl_.getSquarePrice (0) << endl;
            }



            /// position update

            if(pl_.getPrisonStatus(i)==1 && D==6)
            {
                pl_.positionUpdate(i,D);
                cout<< "you move to "<< sl_.getSquareName(pl_.getPosition(i))
                    << endl;
                pl_.resetPrisonStatus(i);
            }

            else if(pl_.getPrisonStatus(i)==0)
            {
                pl_.positionUpdate(i,D);
                cout<< "you move to "<< sl_.getSquareName(pl_.getPosition(i))
                    << endl;

            }

            else if(pl_.getPrisonStatus(i)==1 && pl_.getType(i)==0)

            {
                cout<< "you are in prison" << endl;

            }




            /// Card Drawing
//            cout <<"TYPE OF SQUARE YOU ARE IN" << endl;
//            cout << sl_.getSquareType(pl_.getPosition(i)) << endl;

            do
            {
                if(sl_.getSquareType(pl_.getPosition(i)) =="CARD")
                {
                    sl_.drawCard(pl_.getPosition(i), i, pl_,cards_);

                }

            }
            while(sl_.getSquareType(pl_.getPosition(i)) =="CARD");






            /// Pay rent if player's present position is owned by someone.
            string owner;
            int counter = 0;


            if(sl_.getSquareType(pl_.getPosition(i)) =="STREET" &&
                    sl_.getSquareOwner(pl_.getPosition(i)) != pl_.getID(i) &&
                    sl_.getSquareOwner(pl_.getPosition(i)) > 0 )
            {
                do
                {
                    if(pl_.getID(counter) ==sl_.getSquareOwner(pl_.getPosition(i)))
                    {
                        owner = pl_.getName(counter);
                        break;
                    }
                    else
                    {
                        counter++;
                    }


                }while(true);

                cout << sl_.getSquareName(pl_.getPosition(i)) <<" owned by " <<
                      owner
                     << ": "<< sl_.payRent(pl_.getPosition(i), i, pl_) << "$" << endl;
            }







            if(pl_.getType(i)==0)
            {

                /// This loop will continue infinitely for each player until
                /// the player press "next"

                do
                {
                    cout << pl_.getName(i) << " \'" << pl_.getID(i) << "\' "
                    << pl_.getBalance(i) << " >";
                    cin >> inputOption;
                    /// if "buy" is pressed this condition will be executed
                    if (inputOption == "buy" &&
                            sl_.getSquareType(pl_.getPosition(i)) =="STREET")
                    {

                        if(sl_.getSquareOwner(pl_.getPosition(i)) == 0 &&
                                pl_.getBalance(i) >= sl_.getSquarePrice (pl_.getPosition(i)) )
                        {
                            sl_.buyStreet(pl_.getPosition(i),i, pl_);
                            cout << "you bought "<< sl_.getSquareName(pl_.getPosition(i)) << endl;
                        }


                        else if(sl_.getSquareOwner(pl_.getPosition(i)) != pl_.getID(i))
                        {
                            cout << "you cannot buy the square." << endl;
//
                        }

                        else if(pl_.getBalance(i) < sl_.getSquarePrice (pl_.getPosition(i)) )
                        {
                            cout << "you do not have enough money to buy "
                                 << sl_.getSquareName(pl_.getPosition(i)) << endl;

                        }

                        else
                        {
                            cout << "You already bought the street" << endl;
                        }

                    }

                    /// if "build" is pressed this condition will be executed

                    else if (inputOption == "build" && sl_.getSquareType(pl_.getPosition(i)) =="STREET")
                    {
                        if(sl_.getSquareOwner(pl_.getPosition(i)) == pl_.getID(i) &&
                                pl_.getBalance(i) >= sl_.getShackPrice(pl_.getPosition(i))&&
                                !sl_.checkAllowableShack(pl_.getPosition(i)) )
                        {
                            sl_.buildShack(pl_.getPosition(i),i, pl_);
                            cout << "you built a new shack on "<< sl_.getSquareName(pl_.getPosition(i)) << endl;
                        }

                        else if(sl_.getSquareOwner(pl_.getPosition(i)) != pl_.getID(i) )
                        {
                            cout << "you do not own the square. you can only build on streets you own" << endl;

                        }


                        else if(sl_.checkAllowableShack(pl_.getPosition(i)))
                        {
                            cout << "The street already contains the maximum amount of shacks."<< endl;

                        }


                        else if(pl_.getBalance(i) < sl_.getShackPrice(pl_.getPosition(i)))
                        {
//                            cout << pl_.getBalance(i) << endl;
//                            cout << sl_.getShackPrice(pl_.getPosition(i))<< endl;
                            cout << "you do not have enough money to build a new shack "<< endl;

                        }

                        else
                        {
                            cout << "Some error in building shack" << endl;
                        }


                    }


                    /// if "board" is pressed this condition will be executed
                    else if (inputOption == "board")
                    {
                        drawBoard(pl_,sl_);
                    }

                    else if (inputOption == "bribe")
                    {
                        //

                        if(pl_.getPrisonStatus(i)== true &&
                                pl_.getBalance(i) > sl_.getSquarePrice(pl_.getPosition(i)) )

                        {
                            sl_.giveBribe(pl_.getPosition(i), i, pl_);
                            cout << "You bribed your way out of prison" << endl;

                        }
                        else if(pl_.getPrisonStatus(i)== false)
                        {
                            cout << "Check your medication. You are not in the prison" << endl;
                        }

                        else if(pl_.getBalance(i) < sl_.getSquarePrice(pl_.getPosition(i))
                                && pl_.getPrisonStatus(i)== true)
                        {
                            cout << pl_.getBalance(i) <<endl;
                            cout << sl_.getSquarePrice(pl_.getPosition(i)) << endl;
                            cout << pl_.getPrisonStatus(i) << endl;
                            cout << " You do not have enough money for bribe" << endl;
                        }

                        else
                        {
                            cout <<"some problem with 'bribe' command" << endl;
                        }


                    }

                    else if (inputOption == "next")
                    {
                        // Do nothing. Check is done in while
                    }

                    else
                    {
                        cout <<"Wrong Input for present location" << endl;
                    }

                }
                while (inputOption != "next");


            } // completion for human player


            else if(pl_.getType(i)==1)
            {
                cout << pl_.getName(i) << " \'" << pl_.getID(i) << "\' "
                    << pl_.getBalance(i) << " >";

                /// if "buy" is pressed this condition will be executed
                if (sl_.getSquareType(pl_.getPosition(i)) =="STREET")
                {

                    if(sl_.getSquareOwner(pl_.getPosition(i)) == 0 &&
                            pl_.getBalance(i) >= sl_.getSquarePrice (pl_.getPosition(i)) )
                    {
                        sl_.buyStreet(pl_.getPosition(i),i, pl_);
                        cout << "you bought "<< sl_.getSquareName(pl_.getPosition(i)) << endl;
                    }

                    if(sl_.getSquareOwner(pl_.getPosition(i)) == pl_.getID(i) &&
                            pl_.getBalance(i) >= sl_.getShackPrice(pl_.getPosition(i))&&
                            !sl_.checkAllowableShack(pl_.getPosition(i)) )
                    {
                        sl_.buildShack(pl_.getPosition(i),i, pl_);
                        cout << "you built a new shack on "<< sl_.getSquareName(pl_.getPosition(i)) << endl;
                    }


                }

                else if(pl_.getPrisonStatus(i)== true &&
                        pl_.getBalance(i) > sl_.getSquarePrice(pl_.getPosition(i)) )
                {
                    sl_.giveBribe(pl_.getPosition(i), i, pl_);
                    cout << "You bribed your way out of prison" << endl;

                }

            } // complete for AI player


        } // completion for single loop of all



        int s =0;
        int i1 = 0;
        s = pl_.sizePlayerList();

        while(i1<s)
        {
            if (pl_.getBalance(i1) < 0)
            {

                for(int j=0; j<16; j++)
                {
                    if(sl_.getSquareOwner(j) == pl_.getID(i1))
                    {
                        sl_.reset(j);

                    }
                }

//
                cout << endl << pl_.getName(i1) << " has been bankrupted" <<endl;
                pl_.deletePlayer(i1);

            }
            else
            {
                i1++;
            }

            s = pl_.sizePlayerList();
        }



        playerSize = pl_.sizePlayerList();
        cout << "New turn will begin. Press 'N' for ending or";
        cout << " anything for continuation. " << endl;
        string option;
        cin >> option;
        //ch = option[0];
        if (option[0] =='N' && option.length()==1)
        {
            break;
        }

        drawBoard(pl_,sl_);


    }
    while(playerSize > 1);

    if(playerSize == 1)
    {
        cout << pl_.getName(0) <<" won" << endl;

    }


    sl_.clearSquarelist();
}
