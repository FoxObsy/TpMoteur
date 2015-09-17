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

/**
 * Classe permettent l'instanciation un modèle de donnée pour le stockage de l'index d'un moteur de recherche
 */
class Index {
  std::map<std::pair<string, double>, unsigned> map_index;

 public :
  /**
   * Contructeur par default d'un index
   */
  Index(){ }

  /**
   * Permet le stockage dans notre modèle de donnée de l'index d'un document
   */
  void indexDocument(std::string document);

  /**
   * Contruit un fichier texte à partir de notre index
   */
  void fichierIndex();
}
