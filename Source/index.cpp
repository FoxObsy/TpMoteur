#include<iostream>
#include<outstream>
#include<string>
#include"../include/index.h"

using namespace std;

void Index::indexDocument(list<string> document){
  list<string>::iterator it;
  vector<string>::iterator it2;
  vector<string>::iterator it3;
  vector<string> listeMotTotal;
  for(it = document.begin(); it != document.end(); it++){
    extractCaractere((char*)*it.c_str, listeMotTotal);
  }
  for(it = document.begin(); it != document.end(); it++){
    // listeMotDoc = extractCaractere((char*)*it.c_str);
    // TODO voir occurence
    for(it2 = listeMotTotal.begin(); it2 != listeMotTotal.end(); it++){
      nbOccurence = calculOccurence(*it2, *it);
      if(nbOccurence != 0){
	occurenceMot = 0;
	for(it3 = document.begin(); it3 != document.end(); it3++){
	  if(calculOccurence(*it2, *it3) != 0){
	    occurenceDoc ++;
	  }
	}
	res = nbOccurence*(document.size()/occurenceDoc);
      }else{
			
      }
    }
  }
}

int calculOccurence(string mot, string document){
  list<string> listeMot;
  extractCaractère((char*)document.c_str, listeMot);
  list<string>::iterator it:
    int res = 0;
  for(it=listeMot.begin(); it!=listeMot.end(); it++){
    if(mot == *it){
      res++;
    }
  }
  return res;
}

template<typename T>
void extractCaractère(char * nomDocument, T<string>& tokens){
  ifstream infile(nomDocument);
  string result;
  string delimiters = " ,#()',.";

  while(getline(infile, str)){
    Tokenize(str, tokens, delimiters);
  }
  return tokens;
}

template<typename T>
void Tokenize(const string& str, T<string>& tokens, const string& delimiters = " ")
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
