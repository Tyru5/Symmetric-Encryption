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
  if( process_cargs( argc, argv ) ){
    usage( "Incorrect Command Line Arguements:", argv[0] );
    exit(-1);
  }

  // grabbing command line args (already checked them):
  string type_of_encryption = argv[1];
  int toei = ( type_of_encryption == "B" ) ? 1 : 0;
  string input_file         = argv[2];
  string output_file        = argv[3];
  string key_file           = argv[4];
  string mode_of_operation  = argv[5];

  switch( toei ){
  case 1:

    {
    BlockCipher bce = BlockCipher( input_file, output_file, key_file );
    if( mode_of_operation == "E"){
      bce.encrypt();
    }
    if( mode_of_operation == "D"){
      bce.decrypt();
    }
    break;
    }

  case 0:
    {
    // StreamCipher sce = StreamCipher( input_file, output_file, key_file );
    break;
    }

  default:
    break;
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
    return 1;
  }

  // grab args:
  string var_encrypt = argv[1];
  string input_file  = argv[2];
  string moe         = argv[5];
 
  if( var_encrypt != "B" && var_encrypt != "S" ){
    cout << "<Error>: Method of Encryption is either: B-lock or S-tream." << endl << endl;
    return 1;
  }

  ifstream file( input_file );
  if( !file ){
    cout << "<Error>: Sorry! " << input_file << " doesn't exist!" << endl << endl;
    return 1;
  }
  file.close();

  if( moe != "E" && moe != "D" ){
    cout << "<Error>: Mode of operation is either: E-cryption or D-ecryption." << endl << endl;
    return 1;
  }
  

  return 0;
}
