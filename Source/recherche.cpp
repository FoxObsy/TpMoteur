/**
* @file recherche.cpp
* @author Romain Tourrel et Virgile Trellu
* @date Septembre 2015
* @brief Définition de la classe Recherche permettant de sortir les documents selon la recherche effectuée par le client
*/

#include "../include/recherche.hpp"
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
	map<int,
	int compteur = 0;
	while (compteur < nombreDeDocs)
	{

	}
}