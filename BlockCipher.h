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
 BlockCipher(const string& inputfile_name_, const string& outputfile_name_, const string& key_):
  inputfile_name( inputfile_name_ ),
  outputfile_name( outputfile_name_ ),
  key( key_ )
  {};


  // Member functions:
  int can_swap( const int& idx, char key[] );
  void swap_chars( char string[], char key[] );

 protected:
  
  string inputfile_name;
  string outputfile_name;

  string key;
  
  
};

#endif // BLOCKCIPHER_H_INCLUDE
