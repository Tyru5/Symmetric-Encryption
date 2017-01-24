// PA1 Assignment
// Author: Tyrus Malmstrom
// Date  : 1/23/2017
// Class : CS355
// Email : tyrus.alexander.malmstrom@gmail.com
// 'Symmetric-Key Encryption'


// include headers:
#include <iostream>
#include <string>

// function declarations:
void process_cargs( const int argc, char* argv[] );

// Macros:
#define DEBUG true

using namespace std;

int main(int argc, char *argv[]){
  
  // Process commamnd line arguements:
  process_cargs( argc, argv );

  
  return 0;
}

void process_cargs( const int argc, char* argv[]){
  
  cout << "The amount of command line args is: " << argc << endl;
  cout << "And they are:" << endl;
  for(int i = 0; i < argc; i++){
    if(DEBUG) cout << "\"" << argv[i]<< "\"" << endl;
  }

}
