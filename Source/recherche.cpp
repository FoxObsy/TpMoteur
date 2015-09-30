/**
* @file recherche.cpp
* @author Romain Tourrel et Virgile Trellu
* @date Septembre 2015
* @brief Définition de la classe Recherche permettant de sortir les documents selon la recherche effectuée par le client
*/

#include "../include/recherche.h"

using namespace std;
map<string,double> recherche::mapDesMotsDuDoc(int indexDocument){
	int index = 0, index2 = -1, index3 = 0;
	string result ="";
    string str="";
    char * result2;
    char * result3;
    string * ListeDesMotsDuDoc=NULL;
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

    while((unsigned)index3 < strlen((char*)result.c_str()))
    {
    	MapDesMotsDuDoc.insert(pair<string,double>(ListeDesMotsDuDoc[index3],stod(ListeDesMotsDuDoc[index3+1])));
    	index3 += 2;
    }

    return MapDesMotsDuDoc;
}

vector<int> recherche::calculDuVecteurRDunDocument(int indexDocument)
{
	vector<int> VecteurR;
	int index = 0;
    map<string,double> MapDesMotsDuDoc;

    MapDesMotsDuDoc = mapDesMotsDuDoc(indexDocument);
    
    map<string,double>::iterator it = MapDesMotsDuDoc.begin();
    vector<string>::iterator it2 = requete.begin();

    
    while(it2 != requete.end())
    {
    	VecteurR.push_back(0);
    	while(it != MapDesMotsDuDoc.end())
    	{
    		if(it->first == *it2)
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

map<int,vector<int>> recherche::calculDuVecteurR(int nombreDeDocs)
{
	map<int,vector<int>> MapR;
	int compteur = 0;
	while (compteur < nombreDeDocs)
	{
		MapR.insert(pair<int,vector<int>>(compteur,calculDuVecteurRDunDocument(compteur)));
	}
	return MapR;
}

map<int,double> recherche::calculDuCoeffDeSalton(int nombreDeDocs)
{
	int compteur = 0, somme1, somme2, somme3, mult1, mult2, mult3;
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
		MapDesMotsDuDoc = mapDesMotsDuDoc(compteur);
		while (it2 != it->second.end())
		{
            mult1 = it3->second;
            mult1 *= *it2;
			somme1 +=  mult1 ;
            mult2 = it3->second;
            mult2 *= it3->second;
			somme2 += mult2;
            mult3 = *it2;
            mult3 *= *it2;
			somme3 += mult3;
			it2++;
			it3++;
		}

		MapCoeffDeSalton.insert(pair<int,double>(compteur,(somme1/(sqrt(somme2*somme3)))));
		compteur++;
		it++;
	}
    return MapCoeffDeSalton;
}

vector<int> recherche::listeDesDocumentsAAfficher(int nombreDeDocs)
{
	map<int,double> MapCoeffDeSalton= calculDuCoeffDeSalton(nombreDeDocs);
	map<int,double>::iterator it = MapCoeffDeSalton.begin();
	map<double,int> MapCoeffDeSaltonInverse;
	map<double,int>::iterator it2 = MapCoeffDeSaltonInverse.end();
	vector<int> ListeDesDocumentsAAfficher;

	while(it != MapCoeffDeSalton.end())
	{
		MapCoeffDeSaltonInverse.insert(pair<double,int>(it->second,it->first));
		it++;
	}

	while(it2 != MapCoeffDeSaltonInverse.begin())
	{
		ListeDesDocumentsAAfficher.push_back(it2->second);
		it2--;
	}

	return ListeDesDocumentsAAfficher;
}

string recherche::NomDuDocSelonIndex(int indexDoc){
	int index = 0;
	string result ="";
    string str="";
    char * result2;
    char * nomDuDoc;


    ifstream infile(nomFichierIndex);

    while(getline(infile,str))
    {
    	if(index==indexDoc){
        	result = result + str +"\n";
    	}
    	index++;
    }
    
    result2 =(char*)result.c_str();
    nomDuDoc = strtok (result2, " #€&([|-`_^@)]=}+");

    return nomDuDoc;

}