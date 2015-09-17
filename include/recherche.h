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
#include <utility>

using namespace std;

 class recherche{
 	map<string,double> MapDesMots;
 	

 	public :
 	map<string,double> mapDesMotsDuDoc(string nomFichierIndex, int indexDocument);
 	vector<int> calculDuVecteurRDunDocument(string nomFichierIndex, int indexDocument);
 	map<int indexDocument,Vector<int>> calculDuVecteurR(int nombreDeDocs);
 	vector<int indexDocument, int> calculDuCoeffDeSalton();
 	vector<int indexDocument> listeDesDocumentsAAfficher();


 };