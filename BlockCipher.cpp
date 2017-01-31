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

int get_key_size( const string& key_file ){
  
  ifstream file( key_file );

  // get length of the file:
  file.seekg(0, file.end );
  int key_size = file.tellg();
  file.seekg(0, file.beg);
  file.close();

  if(DEBUG) cout << "The size (length) of the key file is: " << key_size << endl;
  return key_size;

}


void extract_key( char* key_buffer, const string& key_file ){

  ifstream file( key_file );

  // get length of file:
  file.seekg (0, file.end);
  int length = file.tellg();
  file.seekg (0, file.beg);

  // read data as a block:
  file.read ( key_buffer,length );
  file.close();

}

void BlockCipher::encrypt(){

  // Regardless of procedure, need to extract the key from the file:
  int key_length = get_key_size( key );
  char* the_key = new char[ key_length ];
  extract_key( the_key, key );

  if( need_to_pad() ){

    int numPads = 8 - (file_size % 8 );
    if(DEBUG) cout << "numPads = " << numPads << endl;
    padded_file_size = file_size + numPads;

    char buffer[file_size];
    ReadFile( buffer, inputfile_name );
    char* paddedFile = new char[ padded_file_size ];
    padding( paddedFile, buffer );

    cout << "Printing out the newly padded file with pad bytes:" << endl;
    for(int i = 0; i < padded_file_size; i++){
      cout << paddedFile[i] << endl;
    }


    /*for(int i = 0; i < padded file size; i++){
      // ~~~XOR:~~~
      paddedFile[i] = paddedFile[i] ^ key[i % key_size];
      }*/


    delete[] paddedFile;
    delete[] the_key;

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


void BlockCipher::padding( char* paddedFile, char* buffer ){

  if(DEBUG) cout << "In the padding function!" << endl;

  // Copy file chars into char array:
  for( int i = 0; i < padded_file_size; i++){
    if( i >= file_size ){ // now start padding
      paddedFile[i] = 0x80;
    }else{
      paddedFile[i] = buffer[i];
    }
  } // end of for loop

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

