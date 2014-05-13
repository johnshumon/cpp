/// \file InitReader.hh
///
/// \brief InitReader -class for Dipoly initialization file

#ifndef InitReader_HH
#define InitReader_HH

#include "initexception.hh"
#include "utility.hh"

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

/// \brief Dipoly init file reader
///


class InitReader
{
public:

  /// Default constructor, creates an epty initReader
   InitReader();

  /// Destructor
   ~InitReader();

   /// \brief Reads the given file
   ///
   ///  - Parameters: filename - name of the init file
   ///  - Exceptions: throws fileExceptions if reading fails
   void readFile( const std::string& filename );


   /// \brief return the named field from the init file
   ///
   /// (Use readFile first, use the getter after that only.)
   /// Returns the chosen data as return value
   /// exceptions: FileError, TypeConversionError
   std::string boardName() const;
   int dieSeed() const;
   int startMoney() const;

   /// type definitions for street and card vectors
   typedef std::vector< Utility::Street > Streets;
   typedef std::vector< Utility::Card > Cards;

   /// \brief return the data (streets, cards) in vectors
   Streets getStreets() const;
   Cards getCards() const;


   /// Prints the data of init file reader as key value pairs
   /// in init file these are [keys] 
   void printData( std::ostream& out = std::cout ) const;

private:

   /// Disable these, there is no need to use these
   InitReader( const InitReader& );
   InitReader& operator =( const InitReader& );

   /// \brief fetch value of given type using a corresponding key
   ///
   /// The datatype we are asking needs to have:
   /// <<-operator
   ///  - parameters: key (e.g. the type of data field in init)
   ///  - return value: data corresponfing the key of chosen type
   ///  - example usage:
   ///    int money = reader.getValue<int>( "money" );
   template< typename DataType >
   DataType getValue( std::string key ) const;

   typedef std::pair< std::string, std::string > Keyvaluepair;
   typedef std::multimap< std::string, std::string  > Initdata;
   Initdata initdata_;

};


// Template implementations need to be in header...
template< typename DataType > 
DataType InitReader::getValue( std::string key ) const
{
   if( initdata_.find( key ) == initdata_.end() )
   { 
      std::string errorStr = "No \"" + key + 
                             "\" in the init file.";
      FileError fError( errorStr );
      throw fError; 
   }

   std::istringstream ss( initdata_.find( key )->second );
   try
   {
      DataType rVal;
      ss >> rVal;
      // if the stream we read from is corrupted
      if( ss.fail() || !ss.eof() )
      { 
         TypeConversionError error( "Type conversion failed: " + ss.str() );
         throw error; 
      }
      return rVal;
   }
   catch( TypeConversionError& tv )
   {
      throw tv;
   }
   catch(...)
   {

      // An exception of other kind, convert it to type conv err.
      TypeConversionError error( "Type conversion failed: " + ss.str() );
      throw error;       
   }
}

#endif

