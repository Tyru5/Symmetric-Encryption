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
void test( const int& file_length, const int& key_len, char* pf, char* key );
void ReadFile( char* buffer, const string& file_name );
void swap_chars( char *string,char *key, const int& key_size );
int can_swap( const int& idx, char *key );

// Macros:
#define DEBUG false

int get_key_size( const string& key_file ){
  ifstream file( key_file );
  // get length of the file:
  file.seekg(0, file.end );
  int key_size = file.tellg();
  file.seekg(0, file.beg);
  file.close();

  // if(DEBUG) cout << "The size (length) of the key file is: " << key_size << endl;
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

  cout << "Encrypting the file..." << endl;

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

    if(DEBUG){
      cout << "Printing out the newly padded file with pad bytes:" << endl;
      for(int i = 0; i < padded_file_size; i++){
	       cout << paddedFile[i] << endl;
      }
    }

    for(int i = 0; i < padded_file_size; i++){
      // ~~~XOR:~~~
      // if(DEBUG) cout << paddedFile[i] << " with " << the_key[ i % key_length ] << endl;
      paddedFile[i] ^= the_key[ i % key_length ]; // this will allow for wrap around of the key
    }

    // Testing after XOR operation:
    // if(DEBUG)test( padded_file_size, key_length, paddedFile, the_key );

    // Swap algorithm:
    swap_chars( paddedFile, the_key, key_length );

    // Now writing out to the file:
    ofstream outfile( outputfile_name );
    for( int i = 0; i < padded_file_size; i++){
      outfile << paddedFile[i];
      if( i == (padded_file_size) ){
	       outfile << endl;
      }
    }

    outfile.close();

    delete[] paddedFile;
    delete[] the_key;

  }else{

    if(DEBUG) cout << "Didn't need to pad the input file!" << endl;
    char* file_np = new char[ file_size ];
    ReadFile( file_np, inputfile_name );

    for(int i = 0; i < file_size; i++){
      // ~~~XOR:~~~
      // if(DEBUG) cout << paddedFile[i] << " with " << the_key[ i % key_length ] << endl;
      file_np[i] ^= the_key[ i % key_length ]; // this will allow for wrap around of the key
    }

    // Swap algorithm:
    swap_chars( file_np, the_key, key_length);


    // Now writing out to the file:
    ofstream outfile( outputfile_name );
    for( int i = 0; i < file_size; i++){
      outfile << file_np[i];
      if( i == (file_size) ){ // not really need as of now.
	       outfile << endl;
      }
    }

    outfile.close();

    delete[] file_np;

  }// end of else;

  cout << "Done encrypting the file..." << endl;

}// end of encrypt

void BlockCipher::decrypt(){

  cout << "Decypting the file now: " << endl;
  // Regardless of procedure, need to extract the key from the file:
  int key_length = get_key_size( key );
  char* the_key = new char[ key_length ];
  extract_key( the_key, key );

  int ret_file = get_length_of_file();
  char* cipher_buffer = new char[ ret_file ];
  ReadFile( cipher_buffer, inputfile_name );

  // First, now swap algorithm:
  swap_chars( cipher_buffer, the_key, key_length );

  // Second, XOR algorithm:
  for(int i = 0; i < ret_file; i++){
    // ~~~XOR:~~~
    // if(DEBUG) cout << paddedFile[i] << " with " << the_key[ i % key_length ] << endl;
    cipher_buffer[i] ^= the_key[ i % key_length ]; // this will allow for wrap around of the key
  }

  // Now writing out to the file:
  ofstream outfile( outputfile_name );
  for( int i = 0; i < ret_file; i++){
    outfile << cipher_buffer[i];
    if( i == (ret_file) ){ // don't really need this....
      outfile << endl;
    }
  }

  outfile.close();

  cout << "Done decrypting the file..." << endl;

  delete[] the_key;
  delete[] cipher_buffer;

}

int BlockCipher::get_length_of_file(){

  ifstream file( inputfile_name );
  // get length of the file:
  file.seekg(0, file.end );
  int file_length = file.tellg();
  // if(DEBUG) cout << "\"Decrypt\" :: The file size (bytes) = " << file_length << endl;
  file.seekg(0, file.beg);
  file.close();

  return file_length;
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

/* ~HELPER FUNCTIONS~ */

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


void test( const int& file_length, const int& key_len, char* pf, char* key ){

  cout << "Testing XOR main" << endl;
  for(int i = 0; i < file_length; i++){
    cout << pf[i] << endl;
  }

  cout << "Testing XOR main decrypt" << endl;
  for(int i = 0; i < file_length; i++){
    pf[i] ^=  key[ i % key_len ]; // this will allow for wrap around of the key
  }

  for(int i = 0; i < file_length; i++){
    cout << pf[i] << endl;
  }


}

int can_swap( const int& idx, char *key ){
  // cout << idx << endl;
  // if(DEBUG) cout << (int) key[idx] << endl;
  return ( (int) key[idx] % 2 == 0 ) ? 0 : 1;
}

void swap_chars( char *XORed_string, char *key, const int& key_size ){

  char* sp =  &XORed_string[0];
  char* ep = &XORed_string[ strlen(XORed_string) - 1];

  for( int i = 0; i < (int) strlen(XORed_string); i++){
    if( (*sp == *ep) || (ep < sp) ){ // added collision test as well
      break;
    }
    if( can_swap( ( i % key_size ), key ) ){
      // swap chars and increment pointers
      // cout << "Swapped at letter: " << key[i] << endl;
      char temp = *sp;
      *sp = *ep;
      *ep = temp;
      sp++;
      ep--;
      // cout << XORed_string << endl;
    }else{
      sp++;
    }
  }// end of for-loop

}
