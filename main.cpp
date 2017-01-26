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
void usage( string message, string argv );


// Macros:
#define DEBUG false

int main( int argc, char *argv[] ){
  
  // Process commamnd line arguements:
  if( !process_cargs( argc, argv ) ){
    usage( "Incorrect Command Line Arguements:", argv[0] );
    exit(-1);
  }

  
  
  
  return 0;
}

// defines the usage of my program:
void usage( string message, string argv ){

  cout << message << " for program: " << argv << endl;
  cout << "The first argument is either a \'B\' or an \'S\'." << endl;
  cout << " --> \'B\' means you will use the Block Cipher encryption function." << endl;
  cout << " --> \'S\' means you will use the Stream Cipher encryption function." << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl;
  cout << "The second arguement is the input file name." << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl;
  cout << "The third arguement is the output file name." << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl;
  cout << "The fourth arguement is the keyfile name." << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~." << endl;
  cout << "The fifth and last arguement, is the \'mode of operatoin\'."     << endl;
  cout << " --> Can be either \'E\' for Encryption or \'D\' for decryption." << endl;
  
  
}

// Your program should ensure there are 5 arguments, and that each argument is error-checked appropriately.
int process_cargs( const int argc, char* argv[]){

  // first check:
  if( argc != 6 ){
    cout << "<Error>: Not enough arguements passed. Please input 6 arguements." << endl << endl;
    return 0;
  }

  // grab args:
  string var_encrypt = argv[1];
  string input_file  = argv[2];

  if( var_encrypt != "B" || var_encrypt != "S" ){
    cout << "<Error>: Method of Encryption is either: B-lock or S-tream." << endl << endl;
    return 0;
  }

  ifstream file( input_file );
  if( !file ){
    cout << "<Error>: Sorry! " << input_file << " doesn't exist!" << endl << endl;
    return 0;
  }

  return 1;
}
