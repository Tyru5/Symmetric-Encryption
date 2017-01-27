// Tyrus Malmstrom
// Header file for the BlockCipher.cpp

#ifndef BLOCKCIPHER_H_INCLUDE
#define BLOCKCIPHER_H_INCLUDE

// directives:
#include <iostream>
#include <string>
#include <vector>


using std::string;

class BlockCipher {

 public:

  // d-Constructor:
  BlockCipher(){};

  // v-Constructor:
 BlockCipher(const string& inputfile_name_, const string& outputfile_name_, const string& key_ ):
  inputfile_name( inputfile_name_ ),
  outputfile_name( outputfile_name_ ),
  key( key_ )
  {};


  // Member functions:
  int can_swap( const int& idx, char key[] );
  void swap_chars( char string[], char key[] );

  int need_to_pad();
  void padding();

  // Encrypt || Decrpyt member functions:
  void encrypt();
  
  // copy assignment operator: 1 of the BIG THREE
  const BlockCipher& operator= (const BlockCipher& rhs){
    if( this != &rhs ){ // Standard alias test...
      inputfile_name  = rhs.inputfile_name;
      outputfile_name = rhs.outputfile_name;
      key             = rhs.key;
    }
    return *this;
  }


  
 protected:
  
  string inputfile_name;
  string outputfile_name;
  string key;

  int file_size;
  int new_file_size;
  int numPads;
  
  std::vector<unsigned char> padded_file;
  
  
};

#endif // BLOCKCIPHER_H_INCLUDE
