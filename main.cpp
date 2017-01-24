// PA1 Assignment
// Author: Tyrus Malmstrom
// Date  : 1/23/2017
// Class : CS356
// Email : tyrus.alexander.malmstrom@gmail.com
// 'Symmetric-Key Encryption :: Block + Stream'


// Include headers:
#include <iostream>
#include <fstream>
#include <string.h>

// Include Custom headers:
#include "BlockCipher.h"
#include "StreamCipher.h"

using namespace std;


// function declarations:
int process_cargs( const int argc, char* argv[] );

// Macros:
#define DEBUG false

int main( int argc, char *argv[] ){
  
  // Process commamnd line arguements:
  if( !process_cargs( argc, argv ) ) exit(-1);
  
  return 0;
}

// Your program should ensure there are 5 arguments, and that each argument is error-checked appropriately.
int process_cargs( const int argc, char* argv[]){

  // first check:
  if( argc != 6 ){
    cout << "Not enough arguements passed. Please input 6 arguements." << endl;
    return 0;
  }

  // grab args:
  string var_encrypt = argv[1];
  string input_file  = argv[2];

  if( var_encrypt != "B" || var_encrypt != "S" ){
    cout << "Method of Encryption is either: B-lock or S-tream." << endl;
    return 0;
  }

  ifstream file( input_file );
  if( !file ){
    cout << "Sorry! " << input_file << " doesn't exist!" << endl;
    return 0;
  }

  return 1;
}
