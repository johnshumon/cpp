/// \file Chopper.hh
///
/// \brief Chopper - chops strings to smaller pieces..
/// 
/// Despite the name the class has nothing to do with motor cycles...

#ifndef CHOPPER_HH
#define CHOPPER_HH

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "initexception.hh"

// separator symbol used by dipoly
const char DIPOLY_SEP( ':' );

/// \brief Chopping the strings using a separator char
///


class Chopper
{
public:

   Chopper( const std::string& target, 
             char erotinM = DIPOLY_SEP );

   ~Chopper();

   // number of fields in string
   unsigned size() const;

   // getField: returns the field of the string new format
   //          example. int i = chopped.getField<int>( 0 );
   //          esim. string s = chopped.getField<string>( 1 );
   // parameters: indeX (0...size-1)
   // return value: a datatype of asked type
   // exceptions: TypeConversionError
   template< typename Datatype >
   Datatype getField( unsigned index ) const;

   // getStr: gives the field in index as a string 
   // parametrit: index, [0...size-1]
   // paluuarvo: string
   std::string getStr( unsigned index ) const;

   // returns the separator char used
   char separator() const;

private:

   // No need to copies or assignments operations
   Chopper( const Chopper& );
   Chopper& operator =( const Chopper& );

   std::vector< std::string > fields_;
   char separator_;

};


// The implementation is here in header because getField is a template
// function...
template< typename Datatype >
Datatype Chopper::getField( unsigned index ) const
{
   std::stringstream ss;
   // if user indexes out from the parts
   if( index >= fields_.size() )
   { 
      IndexError error;
      throw error; 
   }
   try
   {
      ss << fields_.at( index );
      Datatype rval;
      ss >> rval;
      // If the stream is not good anymore
      if( ss.fail() )
      { 
         TypeConversionError error( "Error converting: " + ss.str() );
         throw error; 
      }
       return rval;
   }
   catch( TypeConversionError& tv )
   {
      throw tv;
   }
   catch(...)
   {
      // Something went wrong, we assume it was a
      // type conversion error...
      TypeConversionError error( "Error converting: " + ss.str() );
      throw error; 
   }
}

#endif


