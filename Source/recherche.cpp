/**
* @file recherche.cpp
* @author Romain Tourrel et Virgile Trellu
* @date Septembre 2015
* @brief Définition de la classe Recherche permettant de sortir les documents selon la recherche effectuée par le client
*/

#include "../include/recherche.h"
using namespace std;
map<string,double> mapDesMotsDuDoc(char * nomFichierIndex, int indexDocument){
	int index = 0, index2 = -1, index3 = 0;
	string result ="";
    string str="";
    char * result2;
    char * result3;
    string * ListeDesMotsDuDoc;
    map<string,double> MapDesMotsDuDoc;


    ifstream infile(nomFichierIndex);

    while(getline(infile,str))
    {
    	if(index==indexDocument){
        	result = result + str +"\n";
    	}
    	index++;
    }
    
    result2 =(char*)result.c_str();
    result3 = strtok (result2, " #€&([|-`_^@)]=}+");

    while(result3 != NULL)
    {
    	if(index2!=-1)
    	{
    		ListeDesMotsDuDoc[index]=(result3);
   		}
   		result3 = strtok (NULL, " #€&([|-`_^@)]=}+");
   		index2++;
    }

    while(index3 < result3.length())
    {
    	MapDesMotsDuDoc.insert(pair::<string,double>(result3[index3],result3[index3+1]));
    	index3 += 2;
    }

    return MapDesMotsDuDoc;
}

vector<int> calculDuVecteurRDunDocument(char * nomFichierIndex, int indexDocument)
{
	vector<int> VecteurR;
	index = 0;
    map<string,double> MapDesMotsDuDoc;
    map<string,double>::iterator it = MapDesMotsDuDoc.begin();
    map<string,double>::iterator it2 = MapDesMots.begin();

    MapDesMotsDuDoc = mapDesMotsDuDoc(nomFichierIndex,indexDocument);
    
    while(it2 != MapDesMots.end())
    {
    	VecteurR.insert(index4, 0);
    	while(it != MapDesMotsDuDoc.end())
    	{
    		if(it->first == it2->first)
    		{
    			VecteurR[index] = 1;
    		}
    		it++;
    	}
    	it = MapDesMotsDuDoc.begin();
    	index++;
    	it2++;
    }
    return VecteurR;

}

map<int,vector<int>> calculDuVecteurR(int nombreDeDocs)
{
	map<int,vector<int>> MapR;
	int compteur = 0;
	while (compteur < nombreDeDocs)
	{
		MapR.insert(pair::<int,vector<int>>(compteur,calculDuVecteurRDunDocument("../index/index.txt",compteur)));
	}
	return MapR;
}

map<int,double> calculDuCoeffDeSalton(int nombreDeDocs)
{
	int compteur = 0, somme1, somme2, somme3;
	map<int,vector<int>> MapR = calculDuVecteurR(nombreDeDocs);
	vector<int>::iterator it2;
	map<int,vector<int>>::iterator it = MapR.begin();
	map<int,double> MapCoeffDeSalton;
	map<string,double> MapDesMotsDuDoc;
	map<string,double>::iterator it3;

	while (it != MapR.end())
	{
		it2 = it->second.begin();
		it3 = MapDesMotsDuDoc.begin();
		MapDesMotsDuDoc = mapDesMotsDuDoc("index.txt",compteur);
		while (it2 != it->second.end())
		{
			somme1 += *(it3->second)*(*it2);
			somme2 += *(it3->second)*(*(it3->second));
			somme3 += (*it2)*(*it2);
			it2++;
			it3++;
		}
		MapCoeffDeSalton.insert(pair::<int,double>(compteur,(somme1/(sqrt(somme2*somme3))));
		compteur++;
		it++;
	}
}

vector<int> listeDesDocumentsAAfficher(int nombreDeDocs)
{
	map<int,double> MapCoeffDeSalton= calculDuCoeffDeSalton(nombreDeDocs);
	map<int,double>::iterator it = MapCoeffDeSalton->begin();
	map<double,int> MapCoeffDeSaltonInverse;
	map<double,int>::iterator it2 = MapCoeffDeSaltonInverse->end();
	vector<int> ListeDesDocumentsAAfficher;

	while(it != MapCoeffDeSalton->end())
	{
		MapCoeffDeSaltonInverse.insert(pair::<double,int>(*(it->second),*(it->first)));
		it++;
	}

	while(it2 != MapCoeffDeSaltonInverse->begin())
	{
		ListeDesDocumentsAAfficher.insert(*(it2->second));
		it2--;
	}

	return ListeDesDocumentsAAfficher;
}

string NomDuDocSelonIndex(int indexDoc){
	int index = 0;
	string result ="";
    string str="";
    char * result2;
    char * nomDuDoc;


    ifstream infile(nomFichierIndex);

    while(getline(infile,str))
    {
    	if(index==indexDocument){
        	result = result + str +"\n";
    	}
    	index++;
    }
    
    result2 =(char*)result.c_str();
    nomDuDoc = strtok (result2, " #€&([|-`_^@)]=}+");

    return nomDuDoc;

}