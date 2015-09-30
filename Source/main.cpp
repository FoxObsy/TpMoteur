/**
* @file main.cpp
* @author Romain Tourrel et Virgile Trellu
* @date Septembre 2015
* @brief Traitement d'une requête
*/
#include "../include/recherche.h"
#include "../include/index.h"

using namespace std;
int main(){
	string requeteString;
	vector<string> tokens;
	vector<int> liste;
	int nombreDocs;
	string delimiters = " ,#()',.";
	string nomFichier= "../index/index.txt";
	cout << "Veuillez rentrer votre requête" << endl;
	cin >> requeteString;
	cout << "Veuillez rentrer le nombre de documents inférieur à 11" << endl;
	cin >> nombreDocs;

    Tokenize(requeteString, tokens, delimiters);
	recherche request1(nomFichier,tokens);
	liste = request1.listeDesDocumentsAAfficher(nombreDocs);

	for (unsigned int i = 0; i != liste.size(); i++){
    cout << liste[i] << endl;
	}

}