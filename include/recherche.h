/**
 * @file   recherche.h
 * @author Romain Tourrel et Virgile Trellu
 * @date   Septembre 2015
 * 
 * @brief  
 * 
 */
#ifndef RECHERCHE_H
#define RECHERCHE_H

#include <math.h> 
#include <iostream>
#include <ostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>
#include <utility>
#include <cstring>
#include <fstream>

using namespace std;

 class recherche{
 	string nomFichierIndex;
 	vector<string> requete;
 	
 	public :
 	recherche(string nomFichierIndex, vector<string> requete) : nomFichierIndex(nomFichierIndex), requete(requete){};
 	map<string,double> mapDesMotsDuDoc(int indexDocument);
 	vector<int> calculDuVecteurRDunDocument(int indexDocument);
 	map<int,vector<int> > calculDuVecteurR(int nombreDeDocs);
 	map<int, double> calculDuCoeffDeSalton(int nombreDeDocs);
 	vector<int> listeDesDocumentsAAfficher(int nombreDeDocs);
 	string NomDuDocSelonIndex(int indexDoc);
 };

 #endif