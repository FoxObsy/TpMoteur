#include <iostream>
#include <ostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <fstream>
#include "../include/index.h"

using namespace std;

void index::indexDocument(list<string> document){
  list<string>::iterator it;
  vector<string>::iterator it2;
  list<string>::iterator it3;
  vector<string> listeMotTotal;
  int nbOccurence, occurenceDoc, res;
  for(it = document.begin(); it != document.end(); it++){
    extractCaractere((char*)(*it).c_str(), listeMotTotal);
  }
  for(it = document.begin(); it != document.end(); it++){
    for(it2 = listeMotTotal.begin(); it2 != listeMotTotal.end(); it2++){
      nbOccurence = calculOccurence(*it2, *it);
      map<string,double> inner;
      if(nbOccurence != 0){
	occurenceDoc = 0;
	for(it3 = document.begin(); it3 != document.end(); it3++){
	  if(calculOccurence(*it2, *it3) != 0){
	    occurenceDoc ++;
	  }
	}
	res = nbOccurence*(document.size()/occurenceDoc);
	inner.insert(make_pair(*it2, res));
	map_index.insert(make_pair(*it, inner));
      }else{
	inner.insert(make_pair(*it2, 0));
	map_index.insert(make_pair(*it, inner));
      }
    }
  }
}

void index::fichierIndex(){
  ofstream fichier("index.txt", ios::out | ios::trunc);
  map<string,map<string,double>>::iterator it;
  if(fichier){
    for(it = map_index.begin(); it != map_index.end(); it++){
      fichier << it->first << " ";
      map<string,double> inner;
      map<string,double>::iterator it2;
      for(it2 = inner.begin(); it2 != inner.end(); it2++){
	fichier << it2->first << " " << it2->second << " ";
      }
      fichier << endl;
    }
    fichier.close();
  }
}


int calculOccurence(string mot, string document){
  list<string> listeMot;
  extractCaractere((char*)document.c_str(), listeMot);
  list<string>::iterator it;
  int res = 0;
  for(it=listeMot.begin(); it!=listeMot.end(); it++){
    if(mot == *it){
      res++;
    }
  }
  return res;
}

template<typename T>
void extractCaractere(char* nomDocument, T& tokens){
  ifstream infile;
  infile.open(nomDocument, ios::in);
  string str;
  string delimiters = " ,#()',.";
  while(getline(infile, str)){
    Tokenize(str, tokens, delimiters);
  }
  infile.close();
}

template<typename T>
void Tokenize(const string& str, T& tokens, const string& delimiters = " ")
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
