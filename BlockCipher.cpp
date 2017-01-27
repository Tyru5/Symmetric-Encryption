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
#define DEBUG true
#define PADDING_VALUE = 0X80;

void BlockCipher::encrypt(){

  if( need_to_pad() ){
    padding();
  }

  // lets start encrypting!
  
  
}


int BlockCipher::need_to_pad(){

  /* From my understanding, to tell if a plaintext file needs to be padded, is if the file size itself is not
     a multiple of 8. Thus I will get the length of the file (in bytes) and mod 8 */
  ifstream file(inputfile_name);

  // get length of the file:
  file.seekg(0, file.end );
  file_size = file.tellg();
  if(DEBUG) cout << "The file size (bytes) = " << file_size << endl;
  file.seekg(0, file.beg);
  file.close();

  if( file_size % 8 != 0 ){
    return 1;
  }

  return 0;
  
}


void BlockCipher::padding(){

  if(DEBUG) cout << "In the padding function!" << endl;
  while( file_size % 8 != 0 ){
    file_size += 1; // ???
  }

  if(DEBUG) cout << "new file size = " << file_size << endl;
  
  // char* newFile = new char[file_size];
  ifstream file( inputfile_name );
  stringstream buf;
  buf << file.rdbuf();

  char temp;
  while( buf >> temp ){
    
  }
    
}





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

