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
 	map<string,double> MapDesMots;
 	
 	public :
 	map<string,double> mapDesMotsDuDoc(string nomFichierIndex, int indexDocument);
 	vector<int> calculDuVecteurRDunDocument(string nomFichierIndex, int indexDocument);
 	map<int,vector<int>> calculDuVecteurR(int nombreDeDocs);
 	map<int, double> calculDuCoeffDeSalton(int nombreDeDocs);
 	vector<int> listeDesDocumentsAAfficher(int nombreDeDocs);
 };

 #endif