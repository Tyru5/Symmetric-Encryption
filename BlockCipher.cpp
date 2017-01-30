// Tyrus Malmstrom
// BlockCipher.cpp class to handle Block Encryption.


// directives:
#include <fstream>
#include <sstream>
#include <string.h>

#include "BlockCipher.h"

// namespace:
using namespace std;

// function  prototypes:
string Read8Bytes( ifstream& stream, uint8_t nchars);

// Macros:
#define DEBUG true

void BlockCipher::encrypt(){

  ifstream _key( key );
  string current_key;
  getline( _key, current_key );
  
  if(DEBUG) cout << "The key is: " << current_key << endl;

  if( need_to_pad() ){

      padding();
      
      
  }else{
    // didn't need to pad, work with original file:
    cout << "Didn't need to pad the input file!" << endl;
  }

}


string Read8Bytes( ifstream& stream, uint8_t nchars){
    string result(nchars, ' ');
    stream.read(&result[0], nchars);
    cout << "8 bytes are: " << result << endl;
    return result;
}

int BlockCipher::need_to_pad(){
  /* From my understanding, to tell if a plaintext file needs to be padded, is if the file size itself is not
     a multiple of 8. Thus I will get the length of the file (in bytes) and mod 8 */
  ifstream file( inputfile_name );
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
  int numPads = 8 - (file_size % 8 );
  if(DEBUG) cout << "numPads = " << numPads << endl;
  ofstream padding( inputfile_name, ofstream::app | ofstream::ate );
  while( numPads != 0 ){
    padding << static_cast<char>( 0x80 );
    numPads -=1;
  }
  if( DEBUG ) cout << "Done padding." << endl;
  padding.close();

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

