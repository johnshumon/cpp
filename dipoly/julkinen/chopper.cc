/// \file Chopper.cc
///
/// \brief Chopper - source file


#include "chopper.hh"


using std::string;

Chopper::Chopper( const string& target, char separ ): 
   fields_(), separator_( separ )
{
   string chop( target );
   while( chop.find_first_of( separator_ ) != string::npos )
   {
      string temp = chop.substr( 0, chop.find_first_of( separator_ ) );
      fields_.push_back( temp );

      // remove the separator and the field we found
      chop.erase( 0, chop.find_first_of( separator_ )+1 );
   }

   // is there still something in the end of the target
   if( chop.size() > 0 )
   {
      fields_.push_back( chop );
   }
}

Chopper::~Chopper()
{
   // ei teht‰v‰‰
}

unsigned Chopper::size() const
{
   return static_cast<unsigned>( fields_.size() );
}

char Chopper::separator() const
{
   return separator_;
}

std::string Chopper::getStr( unsigned index ) const
{
   if( index >= fields_.size() )
   { 
      IndexError err;
      throw err; 
   }
   return fields_.at( index );
}


