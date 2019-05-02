
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "queue.h"

void teststqueue( )
{std::cout <<"\n\n";
std::cout <<"Test:\n";
queue q1 = { 1, 2, 3, 4, 5 };
std::cout << "Queue 1 is: "<< q1 << "\n";
//q1.checkinvariant();
queue q2 = q1; // Copy constructor.
//q1.checkinvariant( );
/*for( unsigned int j = 1; j <9 ; ++ j )
{
q1. push( j * j );
std::cout << q1. peek( ) << " ";
q1. pop( );
}*/
std::cout << "Queue 2 is: "<<q2 << "\n";
q1 = q2; // Assignment.
//q2.checkinvariant( );
q1 = { 1,2,3,4,5,6,7,8,9,10 };
//q1.checkinvariant( );
std::cout << "Queue 1 now is: "<< q1 << "\n";
queue q3 = { 1,2,3,4,5,6 };
std::cout << "Queue 3 is: "<< q3 << "\n";
for( unsigned int i = 1; i < 8; ++ i )
{q3. push(i); 
q3. checkinvariant( );
double d = q3. peek( ); 
q3. checkinvariant( );
q3. pop( ); 
q3. checkinvariant( );
q3. push(d); 
q3. checkinvariant( );}}


int main( int argc, char* argv [ ] )
{
   queue q;

   q. push(1); q. push(2); q. push(3);
   q. push(4); q. push(5); q. push(6);
   q. push(7); q. push(8);

   std::cout << q << "\n";
        
   while( q. size( ) > 3 )
   {
      double d = q. peek( );
      std::cout << d << "\n";
      q. pop( );
   }



   queue q2 = q;
   std::cout << q << "\n";

   std::cout << q2 << "\n";

   while( q. size( ) > 3 )
   {
      double d = q. peek( );
      std::cout << d << "\n";
      q. pop( );
   }
   q2 = q;
   std::cout << q << "\n";
   std::cout << q2 << "\n";

   queue q3 = { 1,2,3,4,5,6 };
   std::cout << q3 << "\n";
 teststqueue( );
   for( unsigned int i = 0; i < 10000; ++ i )
   {
      q3. push(i); q3. checkinvariant( );
      double d = q3. peek( ); q3. checkinvariant( );
      q3. pop( ); q3. checkinvariant( );
      q3. push(d); q3. checkinvariant( );
   }


   return 0;
}

