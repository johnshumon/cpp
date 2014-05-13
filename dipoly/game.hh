/// \file game.hh
///
#ifndef GAME_HH
#define GAME_HH

#include "julkinen/initreader.hh"
#include "player.hh"
#include "square.hh"
#include "createplayer.hh"

#include <vector>


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



class game
{

private:
    vector <square*>  squareList_;
    vector <player*>  pl_;
    int seed_;
    InitReader::Cards cards_;


public:
    // Copy constructor
    game(){}
    game(const game &cSource)
    {
        squareList_= cSource.squareList_;
        pl_= cSource.pl_;
        seed_= cSource.seed_;
        cards_= cSource.cards_;
    }

// Assignment Operator
    game& operator= (const game &cSource);

/// Methods for game class

    void createPlayerList(int);
    void createSquareList(InitReader::Streets);
    void clearSquarelist();
	void clearPlayerlist();
    void createGame(int,InitReader::Cards);
    void playGame();
    void deletePlayer(int currentPlayer);
//    void drawBoard(playerlist&, squarelist&);

};


#endif
