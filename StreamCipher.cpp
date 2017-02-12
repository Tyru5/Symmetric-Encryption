// Tyrus Malmstrom
// StreamCipher.cpp class to handle Block Encryption.


// directives:
#include <fstream>
#include <sstream>
#include <unistd.h> // for sleep.

#include "StreamCipher.h"

// namespace:
using namespace std;

// function declarations:
void Stream_ReadFile( char* buffer, const string& file_name );

// Macros:
#define DEBUG true


int stream_get_key_size( const string& key_file ){
        ifstream file( key_file );
        // get length of the file:
        file.seekg(0, file.end );
        int key_size = file.tellg();
        file.seekg(0, file.beg);
        file.close();

        // if(DEBUG) cout << "The size (length) of the key file is: " << key_size << endl;
        return key_size;
}


void stream_extract_key( char* key_buffer, const string& key_file ){
        ifstream file( key_file );
        // get length of file:
        file.seekg (0, file.end);
        int length = file.tellg();
        file.seekg (0, file.beg);

        // read data as a block:
        file.read ( key_buffer,length );
        file.close();
}

void StreamCipher::encrypt(){


        cout << "Encrypting the file..." << endl;
        /* As stated in the assignment description, Stream Cipher does NOT require padding*/

        // Regardless of procedure, need to extract the key from the file:
        int key_length = stream_get_key_size( key );
        char* the_key = new char[ key_length ];
        stream_extract_key( the_key, key );

        int file_length = get_length_of_file();
        char* file = new char[ file_length ];
        Stream_ReadFile( file, inputfile_name );

        // XOR algorithm:
        for(int i = 0; i < file_length; i++) {
                // ~~~XOR:~~~
                // if(DEBUG) cout << paddedFile[i] << " with " << the_key[ i % key_length ] << endl;
                file[i] ^= the_key[ i % key_length ]; // this will allow for wrap around of the key in case we exhaust the key.
        }

        // Now writing out to the file:
        ofstream outfile( outputfile_name );
        for( int i = 0; i < file_length; i++) {
                outfile << file[i];
                if( i == (file_length) ) { // don't really need this....
                        outfile << endl;
                }
        } // end of foor-loop.

        delete[] the_key;
        delete[] file;

        /*Some cool 'affects'*/
        for(int i = 0; i < 3; i++){
                cout << "." << flush;
                sleep(1);
        }

        cout << endl;
        cout << "Done encrypting the file." << endl;

} //  end of encrypt.


void StreamCipher::decrypt(){

        cout << "Decrypting the file..." << endl;

        // Regardless of procedure, need to extract the key from the file:
        int key_length = stream_get_key_size( key );
        char* the_key = new char[ key_length ];
        stream_extract_key( the_key, key );

        int cipher_file_length = get_length_of_file();
        char* cipher_file = new char[ cipher_file_length ];
        Stream_ReadFile( cipher_file, inputfile_name );

        // XOR algorithm:
        for(int i = 0; i < cipher_file_length; i++) {
                // ~~~XOR:~~~
                // if(DEBUG) cout << paddedFile[i] << " with " << the_key[ i % key_length ] << endl;
                cipher_file[i] ^= the_key[ i % key_length ]; // this will allow for wrap around of the key in case we exhaust the key.
        }

        // Now writing out to the file:
        ofstream outfile( outputfile_name );
        for( int i = 0; i < cipher_file_length; i++) {
                outfile << cipher_file[i];
                if( i == (cipher_file_length) ) { // don't really need this....
                        outfile << endl;
                }
        } // end of foor-loop.

        delete[] the_key;
        delete[] cipher_file;

        /*Some cool 'affects'*/
        for(int i = 0; i < 3; i++){
                cout << "." << flush;
                sleep(1);
        }

        cout << endl;
        cout << "Done decrypting the file." << endl;
}

int StreamCipher::get_length_of_file(){

        ifstream file( inputfile_name );
        // get length of the file:
        file.seekg(0, file.end );
        int file_length = file.tellg();
        // if(DEBUG) cout << "\"Decrypt\" :: The file size (bytes) = " << file_length << endl;
        file.seekg(0, file.beg);
        file.close();

        return file_length;
}

/* ~HELPER FUNCTIONS~ */

void Stream_ReadFile( char* buffer, const string& file_name ){
        ifstream file( file_name );
        // get length of file:
        file.seekg (0, file.end);
        int length = file.tellg();
        file.seekg (0, file.beg);
        // read data as a block:
        file.read (buffer,length);
        file.close();
}
