// PA1 Assignment
// Author: Tyrus Malmstrom
// Date  : 1/23/2017
// Class : CS356
// Email : tyrus.alexander.malmstrom@gmail.com
// 'Symmetric-Key Encryption :: Block + Stream'


// Include headers:
#include <iostream>
#include <string.h>

// Include Custom headers:
#include "BlockCipher.h"
#include "StreamCipher.h"

using namespace std;


// function declarations:
void process_cargs( const int argc, char* argv[] );
int block_encryption( const string opt );
int stream_encryption( const string opt );

// Macros:
#define DEBUG false

int main( int argc, char *argv[] ){
  
  // Process commamnd line arguements:
  process_cargs( argc, argv );
  
  return 0;
}

// Your program should ensure there are 5 arguments, and that each argument is error-checked appropriately.
void process_cargs( const int argc, char* argv[]){

  
  
  
}

int block_encryption( const string opt  ){

  if(DEBUG) cout << "Method of Encryption: " << opt << endl;
  return (opt == "B") ? 1 : 0;
  
}

int stream_encryption( const string opt ){

  if(DEBUG) cout << "Method of Encryption: " << opt << endl;  
  return (opt == "S") ? 1 : 0;
  
}


