#include<iostream>
#include<outstream>
#include<string>
#include"../include/index.h"

using namespace std;

void Index::indexDocument(string document){
  list<string> liste_mot = extractCaractere((char*)document.c_str);
  
}

list<string> extractCaractère(char * nomDocument){
  ifstream infile(nomDocument);
  string result;
  list<string> tokens;
  string delimiters = " ,#()',.";

  while(getline(infile, str)){
    Tokenize(str, tokens, delimiters);
  }
  
  return tokens;
}

void Tokenize(const string& str, list<string>& tokens, const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}
