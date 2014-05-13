/// \file Utility.cc
///
/// \brief Utility functions, source file 

#include "utility.hh"
#include "chopper.hh"
#include "initexception.hh"

#include <cctype>
#include <sstream>
//#include <ctime>
//#include <cstdlib>

using std::string;
using std::toupper;

namespace Utility
{   
  /// For reading street srtuct from a string
  Street string2Street( std::string streetInfo )
  { 
    Street result;
    Chopper chop( streetInfo );
    result.stype = chop.getStr( 0 );
    result.name = chop.getStr( 1 );
    result.id = chop.getField<int>( 2 );
    result.price = chop.getField<int>( 3 );
    result.shackPrice = chop.getField<int>( 4 );
    result.shackMax = chop.getField<int>( 5 );
    return result;
  }
  

  Card string2Card( std::string cardInfo )
  {
     Card card;
     Chopper chop( cardInfo );
     card.description = chop.getStr( 0 );
     card.money = chop.getField<int>( 1 );
     card.move = chop.getField<int>( 2 );
     card.prison = chop.getField<bool>( 3 );
     return card;
  }

  std::ostream& operator <<( std::ostream& os,
			     const Utility::Street& tt )
  {
    os << tt.name << " - " << tt.stype << ":" << tt.shackMax << std::flush;
    return os;
  }
  
  
  std::ostream& operator <<( std::ostream& os,
			     const Utility::Card& cc )
  {
    os << cc.description << " - " << cc.money << " - ";
    return os;
  }
  
  
  string int2string( int toString )
  {   
    std::stringstream ss;
    ss << toString;
    return ss.str();
  }
  
  
  string upperCase( const string& target )
  {     
    string paluu;
    for( unsigned i = 0; i < target.size(); ++i )
    {
      switch( target.at(i) )
      {
      case 'å': paluu += 'Å';
	break;
      case 'ä': paluu += 'Ä';
	break;
      case 'ö': paluu += 'Ö';
	break;
      default:  paluu += static_cast<char>( toupper( target.at(i) ) );
      };
    }   
    return paluu;
  }
    
  /// removes white space from the begining and the end of the given string
  string removeWhiteSpace( const string& target, const string& empty )
  {  
    if( target.empty() ){ return target; }
    string rval = target.substr( target.find_first_not_of( empty ) );
    return rval.substr( 0, rval.find_last_not_of( empty )+1 );
  }
}
