/// \file game.hh
///
#ifndef GAME_HH
#define GAME_HH

#include "./julkinen/initreader.hh"
#include "squarelist.hh"
#include "playerlist.hh"

#include <vector>
#define MAX_SQUARE 16
#define FORTY_EIGHT 48

using std::vector;


class game
{

private:
    squarelist sl_;
    playerlist pl_;
    int seed_;
    InitReader::Cards cards_;


public:
    // Copy constructor
    game(){}
    game(const game &cSource)
    {
        sl_= cSource.sl_;
        pl_= cSource.pl_;
        seed_= cSource.seed_;
        cards_= cSource.cards_;
    }

// Assignment Operator
    game& operator= (const game &cSource);


    void createGame(playerlist&, squarelist&, int,InitReader::Cards);
    void playGame();
    void drawBoard(playerlist&, squarelist&);

};


#endif
