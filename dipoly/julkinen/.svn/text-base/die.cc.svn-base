#include "die.hh"

#include <cassert>

// 
Die::Die( unsigned long int seed, unsigned long faces )
  : faces_( faces), seed1_(seed), seed2_(seed%7+1)
{
}

Die::~Die()
{
   // Nothing to do
}

unsigned long int Die::rawCast()
{
  // update the seed
  seed1_ = 15625 * seed1_ + 22221;
  seed2_ = 15625 * seed2_ + ( seed1_ >> 16 );
  seed1_ &= 0xFFFFul; seed2_ &= 0xFFFFul;

  // allot a number between  0 .. rawmax_
  unsigned long int rawNumber = ( ( seed1_ & 0x7FFFul ) << 16 ) | seed2_;
  return rawNumber;
}

unsigned long int Die::cast()
{
  // create a limit 
  unsigned long int rawLimit = rawmax_ - (rawmax_ - faces_) % (faces_+1);

  // Cast as long as we get a number within the limit
  unsigned long int rawNumber = 0;
  do { rawNumber = rawCast(); } while (rawNumber > rawLimit);

  // scale the result between 1-faces 
  unsigned long int number = rawNumber % faces_ + 1;
  assert(number <= faces_);

  return number;
}
