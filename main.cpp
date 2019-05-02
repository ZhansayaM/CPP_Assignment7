
#include <iostream>
#include <sstream>
#include <random>

#include "map.h"


int main( int argc, char * argv [ ] )
{
#if 0
   map english{ { "zero", 0 }, { "one", 1 }, { "two", 2 }, { "three", 3 }};

   std::cout << english. insert( "four", 4 ) << "\n"; 
   std::cout << english. insert( "five", 5 ) << "\n";
   std::cout << english. insert( "six", 6 ) << "\n";
   std::cout << english. insert( "seven", 7 ) << "\n";

   std::cout << english[ "seven" ] << "\n";
   english[ "eight" ] = 8;
   english[ "nine" ] = 9;
   english[ "ten" ] = 10;

   for( unsigned int i = 0; i != 11; ++ i )
      english[ "eleven" ] ++ ;

   std::cout << english. contains_key( "deux" ) << "\n";
   std::cout << english. contains_key( "quattro" ) << "\n";

   std::cout << english. remove( "eki" ) << "\n";

   auto& english2 = english; 
   english2. at( "seven" ) ++;
   english2. at( "seven" ) --; 
      // If you are born to be seven, you will never be eight.  

   std::cout << english << "\n";
   english. printstatistics( std::cout );

   std::cout << english << "\n";
   english. printstatistics( std::cout );

   std::cout << english << "\n";
   english. printstatistics( std::cout );

   map german = { { "eins", 1 }, { "zwei", 4 }, { "drei", 3 } };
   german. at( "zwei" ) = 2; // es ist mir ein Fehler unterlaufen. 
   try
   {
      german. at( "hundert" ) = 100; 
   }
   catch( std::out_of_range err )
   {
      std::cout << "error: " << err. what( ) << "\n";
   }
   german[ "vier" ] = 2 * german[ "zwei" ];
   std::cout << german << "\n";
#endif 
}


