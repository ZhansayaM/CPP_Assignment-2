#ifndef QUEUE_INCLUDED 
#define QUEUE_INCLUDED  1

#include <iostream>
#include <initializer_list>

struct queue
{ size_t current_size; 
  size_t current_capacity; 
  size_t begin;
  size_t end;   

   double* data; 
      // INVARIANТ: I wrote a function checkinvariant( ) const 
      // which checks the invariant as much as possible. Use this
      // function in your tests. 

   void ensure_capacity(size_t c );
      // Ensure that queue has capacity of at least c.
      // This function is given, so you don't have to write it. 
      // Return i+1, but 0 if we reach current_capacity.
 
  size_t next(size_t i ) const 
   {  i = i + 1; 
      if( i == current_capacity )
         i = 0; 
      return i;}

   void checkinvariant( ) const;
      // Call this function often during your tests. We will
      // call it during checking!

   void printfields( std::ostream& ) const;
      // Print the fields current_size, current_capacity,
      // begin, end. It should be used for debugging. 

public: 
   queue( ):
	   current_size{0},
	   current_capacity{20},
     begin{0},
     end{0},
	   data{new double[current_capacity]} {}

   queue( const queue& q ){
	   data = new double[q.current_capacity];
	   current_capacity = q.current_capacity;
     begin=q.begin;
     end=q.end;
	  size_t i = 0;
	   while (i < q.current_capacity){
		   data[i] = q.data[i];
		   i++;}
	   current_size = q.current_size;}

   ~queue( ){
	   delete[] data;}

   const queue& operator = ( const queue& q ){
	   ensure_capacity(q.current_size);
	  size_t i = q.begin;
    current_size=q.current_size;
    begin = 0;
    end = current_size;
    for(size_t s = 0; s < current_size; ++s){
         data[s] = q.data[i];
         i = q.next(i);}
	   return q;}

   queue(std::initializer_list<double> init) {
		size_t i = 0;
		   current_capacity = init.size()*2;
		   data = new double[init.size()*2];
       begin=0;
       end=current_size;
		   for (double d : init){
			   data[i++] = d;}
		   current_size = init.size();}

	   // So that you can write q = { 1,2,3 };
	  // You can use init. size( ) to see the size, and
	  // for( double d : init ) to go through all
	  // elements in the initializer_list.

   void push(double d) {
		ensure_capacity(current_size + 1);
	   data[end] = d;
     end = next(end);
	   current_size += 1;}

   void pop( ){
	  begin=next(begin);
    current_size--;}

   void clear( ){
   begin=end=0;
   current_size=0;}

   double peek( ) const {{return data[begin];}}
 
  size_t size( ) const { return current_size; } 

   bool empty( ) const { 
     if (current_size == 0)
		return true;
	else
		return false;}
   
   friend std::ostream& operator << ( std::ostream& , const queue& );
}; 

std::ostream& operator << ( std::ostream& , const queue& );

#endif