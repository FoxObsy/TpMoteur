/**
 * @file index.h
 * @author Romain Tourrel et Virgile Trellu
 * @date Septembre 2015
 *
 * @brief Declaration de la classe index permettant d'initialiser la structure de donnée pour un moteur de recherche
 *
 */

#ifndef INDEX_H
#define INDEX_H

using namespace std;

/**
 * Classe permettent l'instanciation un modèle de donnée pour le stockage de l'index d'un moteur de recherche
 */
class index {
  map<string,map<string,double>> map_index;

 public :
  /**
   * Contructeur par default d'un index
   */
  index(){ }

  /**
   * Permet le stockage dans notre modèle de donnée de l'index d'un document
   */
  void indexDocument(list<string> document);

  /**
   * Contruit un fichier texte à partir de notre index
   */
  void fichierIndex();
};

/**
 * Calcul les occurences de mot qui apparaisse dans un fichier
 */
int calculOccurence(string mot, string document);

/**
 * Extrait tout les mots présent dans un texte
 */
template<typename T>
void extractCaractere(char* nomDocument, T& tokens);

/**
 * Permet de faire la séparation entre chaque mot en prenant des delimiters en compte
 */
template<typename T>
void Tokenize(const string& str, T& tokens, const string& delimiters = " ");

#endif
