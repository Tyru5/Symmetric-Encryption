// PA1 Assignment
// Author: Tyrus Malmstrom
// Date  : 1/23/2017
// Class : CS355
// Email : tyrus.alexander.malmstrom@gmail.com
// 'Symmetric-Key Encryption'


// include headers:
#include <iostream>
#include <string>
#include <string.h>

// function declarations:
void process_cargs( const int argc, char* argv[] );
int block_encryption( string test );
int stream_encryption( char& opt );

// Macros:
#define DEBUG true

using namespace std;

int main(int argc, char *argv[]){
  
  // Process commamnd line arguements:
  process_cargs( argc, argv );

  
  return 0;
}

// Your program should ensure there are 5 arguments, and that each argument is error-checked appropriately.
void process_cargs( const int argc, char* argv[]){

  if( block_encryption( argv[1] ) || stream_encryption( argv[1] ) ){
    // then good! perform specified encryption
    cout << "Ready to rock main!" << endl;
  }
  
}

int block_encryption( string option ){

  cout << option << endl;
  
}

int stream_encryption( char& option ){

  cout << option << endl;
  
}


