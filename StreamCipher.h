// Tyrus Malmstrom
// Header file for the StreamCipher.cpp

#ifndef STREAMCIPHER_H_INCLUDE
#define STREAMCIPHER_H_INCLUDE

// directives:
#include <iostream>
#include <string>
#include <vector>

using std::string;

class StreamCipher {

 public:

     // d-Constructor:
     StreamCipher(){};

     // v-Constructor:
     StreamCipher(const string& inputfile_name_, const string& outputfile_name_, const string& key_ ):
     inputfile_name( inputfile_name_),
     outputfile_name( outputfile_name_),
     key( key_)
     {};

     // Member functions:
     int get_length_of_file();

     // Encrypt && Decrypt member functions:
     void encrypt();
     void decrypt();

     // copy assignment operator: 1 of the BIG THREE
     const StreamCipher& operator= (const StreamCipher& rhs){
       if( this != &rhs ){ // Standard alias test...
         inputfile_name  = rhs.inputfile_name;
         outputfile_name = rhs.outputfile_name;
         key             = rhs.key;
       }
       return *this;
     }

protected:

     /*For Encryption*/
     string inputfile_name;
     string outputfile_name;
     string key;

};

#endif // STREAMCIPHER_H_INCLUDE
