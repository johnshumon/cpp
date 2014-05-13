/// \file utility.hh
///
/// \brief Utility functions for Dipoly init file reader etc.

#ifndef UTILITY_HH
#define UTILITY_HH

#include <string>
#include <iostream>

namespace Utility
{
   const std::string WHITE_SPACE = " \t";
 
   /// converts integer to string
   std::string int2string( int toString );

   /// change string into UPPER case
   std::string upperCase( const std::string& target );

   /// removes whitespace from beginning and end of the string
   std::string removeWhiteSpace( const std::string& target, 
                                 const std::string& empty = WHITE_SPACE );

  /// Data type for presenting streets of in the game
  /// This is ONLY for acquiring the information from init file
  /// Do not use this as the bases of your street class!!!
   struct Street
   {
     /// a constructor for creating an empty street type
      Street(): stype(), name(), id( 0 ), price( 0 ), shackMax( 0 ){};

     /// Type of the street (would be better as enum...)
     std::string stype;
     ///
     std::string name;
     /// id of the street
      int id;
     /// The price of the square 
      int price;
     /// The price of one shack
     int shackPrice;
     /// max number of shacks
      int shackMax;
   };

  /// constructing a street from a string
  /// Throws: InitExceptions, if streetinfo is invalid
  Street string2Street( std::string streetInfo );

   /// \brief A datatype for cards
   ///
   /// The solely purpose of this datatype is to ease the 
   /// usage of init file reader. DO NOT USE THIS AS THE
   /// CARD DATATYPE in your own application!!!
   struct Card
   {
     /// An empty card...
     Card(): description(), money( 0 ), move( 0 ), prison ( false ){}
     /// 
     std::string description;
     /// money
     int money;
     /// how the player is moved
     int move;
     /// move to prison or not
     bool prison;
   };

  /// Creating a card from a string
  /// Throws: InitExceptions, if streetinfo is invalid
  Card string2Card( std::string streetInfo );

  /// << operator for printing Streets
  std::ostream& operator <<( std::ostream& os, 
                           const Utility::Street& tt );
  /// << operator for Card structs
  std::ostream& operator <<( std::ostream& os, 
                           const Utility::Card& kk );
}

#endif
