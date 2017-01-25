// Tyrus Malmstrom
// BlockCipher.cpp class to handle Block Encryption.


// directives:
#include <fstream>
#include <sstream>
#include <string.h>

#include "BlockCipher.h"

// namespace:
using namespace std;

// Macros:
#define DEBUG false



int BlockCipher::can_swap( const int& idx, char key[] ){
  // cout << idx << endl;
  return ( (int) key[idx] % 2 == 0 ) ? 0 : 1;
}

void BlockCipher::swap_chars( char string[], char key[] ){

  char* sp =  &string[0];
  char* ep = &string[ strlen(string) - 1];
  
  for( int i = 0; i < (int) strlen(string); i++){

    if( *sp == *ep ) break;
    
    if( can_swap( i, key ) ){
      // swap chars and increment pointers
      char temp = *sp;
      *sp = *ep;
      *ep = temp;
      sp++;
      ep--;
    }else{
      sp++;
    }
    
  }
   
}

