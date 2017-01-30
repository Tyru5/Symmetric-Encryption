// Tyrus Malmstrom
// BlockCipher.cpp class to handle Block Encryption.


// directives:
#include <fstream>
#include <sstream>
#include <string.h>

#include "BlockCipher.h"

// namespace:
using namespace std;

// function prototypes
void ReadFile( char* buffer, const string& file_name );

// Macros:
#define DEBUG true

void BlockCipher::encrypt(){

  if( need_to_pad() ){

    int numPads = 8 - (file_size % 8 );
    padded_file_size = file_size + numPads;
    if(DEBUG) cout << "numPads = " << numPads << endl;

    char buffer[file_size];
    ReadFile( buffer, inputfile_name );
    char* paddedFile = new char[ padded_file_size ];
    padding( paddedFile, buffer );

    cout << "Printing out the newly padded file with pad bytes:" << endl;
    ofstream test("test.txt");
    for(int i = 0; i < padded_file_size; i++){
      test << paddedFile[i];
    }

    delete paddedFile;

  }else{
    // didn't need to pad, work with original file:
    cout << "Didn't need to pad the input file!" << endl;
  }

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

/* for(int i = 0; i < padded file size; i++){
   ~~~XOR:~~~
   paddedFile[i] = paddedFile[i] ^ key[i % key_size]; for the wrap around.
}
*/

void BlockCipher::padding( char* paddedFile, char* buffer ){

  if(DEBUG) cout << "In the padding function!" << endl;

  // Copy file chars into char array:
  for( int i = 0; i < file_size; i++){
    cout << "in the buffer" << buffer[i] << endl;
    paddedFile[i] = buffer[i];
    if( i == file_size ){ // now start padding
      for(int c = 0; c < numPads; c++){
        paddedFile[i] = 0x80;        
      }
    }

  }

}

void ReadFile( char* buffer, const string& file_name ){

  ifstream file( file_name );

  // get length of file:
  file.seekg (0, file.end);
  int length = file.tellg();
  file.seekg (0, file.beg);

  // read data as a block:
  file.read (buffer,length);
  file.close();

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

