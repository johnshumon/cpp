/// \file die.hh
///

#ifndef DIE_HH
#define DIE_HH

/// \brief Die-class for Dipoly game
///
/// Use instruction:
///
/// Create only one instance of this class.
/// The seed value is given in instantiation file of the game.
/// example of usage:
/// Die die( mySeed );
/// cout << "Casting the die: " << die.cast() << endl;
/// Only call cast function when a player casts a die and only once
/// for each player.

class Die
{
public:

  /// Constructor creates a new die and sets the seed.
  /// Number of faces the dice has (standard die and dipoly die have six faces)
  Die( unsigned long seed, unsigned long faces = 6 );
  ~Die();

   /// Casts the die. Return value is a number between 1-faces of die.
   unsigned long cast();

private:

   // No need to create copies of a die
   Die( const Die& );
   Die& operator =( const Die& );

   unsigned long rawCast();

   const unsigned long faces_;
   unsigned long seed1_;
   unsigned long seed2_;
   static unsigned long const rawmax_ = 0x7FFFFFFFul;
};


#endif
