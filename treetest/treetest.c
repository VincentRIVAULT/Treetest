// compilation : gcc -Wall treetest.c -o treetest
// exécution : ./treetest

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "../mylib/mylib.h"


/**
 * @brief On récupère les arguments de la ligne de commande via les paramètres de calculatrice.
 *        Il suffit pour cela de doter calculatrice de 2 paramètres :
 *        1 int pour récupérer le nombre d’arguments
 *        et 1 tableau/pointeur de chaînes de caractères pour les arguments.
 * 
 * @param nbarg 
 * @param arg 
 * @return int 
 */
int calculatrice(int nbarg, char **arg)
{

  printf("%d argument(s)\n",nbarg) ;
  while (*++arg) printf("%s ",*arg) ;
}


// fonction load() définie dans le fichier load.c dans mylib
/*
char load()
{

}
*/


// fonction search() définie dans le fichier search.c dans mylib
/*
char search(char *arg)
{

}
*/


/**
 * @brief Fonction principale du programme qui comprend 2 paramètres :
 *        1 de type int et 1 tableau de chaine de caractères
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main (int argc, char *argv[])
{
/*
  if (argc != 3)
  {
    printf("2 arguments required\n");
    exit(1);
  }
*/


  // on cherche tous les fichiers qui sont situés dans le répertoire
  // indiqué dans la fonction load()

  // on initialise la liste pointant ver la structure Fichier à NULL
  struct Fichier * liste = NULL;

  // on appelle la fonction load() en précisant le dossier dans lequel effectuer la recherche de fichiers
  // load("/home/etudiant/Documents/COURS/AlgoProg/TEST", &liste); // pour tester sur l'ordinateur portablece l'UA
  
  load("/var", &liste);

  // on appelle la procédure afficherListe() pour afficher la liste des fichiers trouvés
  printf(" ---- LISTE ---- \n");
  afficherListe(liste);
  printf(" --------------- \n");
  

  return 0;
}
