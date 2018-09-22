/*
############################################################
#                                                          #
#                       ACE FIGUEROA                       #
#                                                          #
#                   SEPTEMBER 21TH, 2018                   #
#                                                          #
#                PARTIAL BIT MAP CONVERSION                #
#                                                          #
#              THIS PROGRAM TAKES HEXADECIMAL              #
#           INPUT FROM .TXT FILE. OUTPUT IS .BMP           #
#                           FILE.                          #
#                                                          #
#                PLEASE COMPILE WITH C++11!                #
#                                                          #
#                     VERSION: 1.0.0                       #
#                LASTED EDITED: 09/21/2018                 #
#                                                          #
############################################################
*/

// TODO: Add formating to console

#include <iostream>
#include <fstream>
using namespace std;

int main(int args, char* arg[]) {

  ifstream hex_file;                                                                     // HEX_FILE INPUT
  ofstream bit_map;                                                                      // BIT_MAP OUTPUT
  
  string file_in = "input.txt";                                                          // NAME OF HEX_FILE INPUT
  string file_out = "output.bmp";                                                        // NAME OF BIT_MAP OUTPUT

  string string_hex;                                                                     // E.G. 0xA7
  
  char HEX;                                                    

  // TODO: Detect if user inputed a valid .extension
  // TODO: Smart .extension detection
  if(args == 2)   
    file_in = arg[1];
  else if(args == 3) {
    file_in = arg[1];
    file_out = arg[2];
  } 
  else if(args > 3) {
    cout << "ERROR: Too many arguments!" << endl;
    
    return 1;
  }
  else {
    cout << "WARNING: No arguments found! Setting Default arguments..." << endl;
  }

  cout << "INITIALIZING: Initializing file_in to '" << file_in << "'" << endl;
  cout << "INITIALIZING: Initializing file_out to '" << file_out << "'" << endl;

  cout << "ATTEMPT: Trying to open '" << file_in << "'" << endl;

  hex_file.open(file_in);                                                                // OPEN FILE NAME
  
  if(!hex_file)                                                                          // CHECK IF FILE EXIST
    cout << "ERROR: Failed to find file '" << file_in << "'" << endl;
  
  else {
    cout << "SUCCESS: File '" << file_in << "' opened successfully." << endl;            // IF FILE EXIST    
    bit_map.open(file_out);                                                              // CREATE .BMP FILE

    cout << "ATTEMPT: Parsing file '" << file_in << "'" << endl;
    
    while(hex_file >> string_hex) {                                                      // READ TILL hex_file IS NULL
      string_hex.insert(0, "0x");                                                        // A7 => 0xA7
      //    cout << string_hex << endl;

      HEX = stoul(string_hex, nullptr, 16);                                              // CONVERTS STRING -> UNSIGNED LONG -> CHARACTER
      bit_map << HEX;                                                                    // INSERTS DATA INTO BIT_MAP FILE
    }
    bit_map.close();                                    

    cout << "SUCCESS: Parsing done... saved as '" << file_out << "'" <<  endl;
  }

  hex_file.close();
return 0;
}
