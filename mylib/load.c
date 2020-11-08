// compilation : gcc -Wall load.c -o load
// exécution : ./load

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <assert.h>


// structure du fichier recherché comprenant 3 paramètres
struct Fichier
{
    char * nom; // pointeur de type caractère pour indiquer le nom du fichier
    char * chemin; // pointeur de type caractère pour indiquer le chemin du fichier
    struct Fichier * suivant; // un pointeur de type struct Fichier pour indiquer l'élément suivant
};
// on renomme la liste en "Fichier"
typedef struct Fichier f_Fichier;


/**
 * @brief procédure pour afficher la liste qui prend comme seul paramètre un pointeur
 *        vers la liste des fichiers recherchés
 * 
 * @param liste 
 */
void afficherListe(f_Fichier * liste)
{
    // liste: pointeur sur le premier fichier de la liste
    while (liste != NULL){
        // tant que le fichier n'est pas NULL
        // on affiche son chemin et son nom
        printf("%s/%s\n", liste->chemin, liste->nom);
        // puis on passe au fichier suivant
        liste = liste->suivant;
    }
}


/**
 * @brief fonction qui permet d'ajouter un fichier au début de la liste
 *        cette fonction comprend 3 paramètres : un pointeur de caractère indiquant le chemin,
 *        un pointeur de caractère indiquant le nom du fichier et un pointeur de pointeur du premier élément de la liste
 *        la fonction modifie le pointeur sur le premier élément,
 *        d'où le besoin d'un pointeur de pointeur
 * 
 * @param chemin 
 * @param nom 
 * @param liste 
 * @return int 
 */
int ajouterFichier(char * chemin, char * nom, f_Fichier ** liste)
{
    // on crée un espace mémoire pour le nouveau fichier en utilisant une variable tmp
    f_Fichier * tmp;
    tmp = (f_Fichier *) malloc(sizeof(struct Fichier));

    // on réserve la mémoire pour la chaine de caractères correspondant au nom
    // (le +1 est pour le caractère fin de chaine)
    tmp->nom = (char *) malloc(sizeof(char) * (strlen(nom) + 1));
    // tmp->nom = (char *)malloc(strlen(nom) + 1);

    // on copie le nom dans le fichier
    strcpy(tmp->nom, nom);

    // on réserve la mémoire pour la chaine de caractères correspondant au chemin
    // (le +1 est pour le caractère fin de chaine)
    tmp->chemin = (char *)malloc(sizeof(char) * (strlen(chemin) + 1));
    // on copie le nom dans le fichier
    strcpy(tmp->chemin, chemin);

    // on met à jour le fichier suivant avec le fichier courant
    tmp->suivant = * liste;

    // on met à jour la liste pour la faire commencer sur le nouveau fichier
    * liste = tmp;

    return 0;
}




/**
 * @brief fonction qui permet de charger la liste des fichiers dans un tableau de Fichiers
 *        la fonction modifie le pointeur sur le premier élément, d'où le besoin d'un pointeur de pointeur
 *        rep correspond au chemin du repertoire à explorer
 * 
 * @param rep
 * @param liste 
 * @return int 
 */
int load(char * rep, f_Fichier ** liste)
{
    DIR * d; // pointeur vers un dossier
    struct dirent * entry; // entree pointant vers la structure dirent (entree de dossier)
    char newpath[FILENAME_MAX]; // variable stockant le nouveau chemin du fichier
    char * tmp_rep; // pour récupérer le nom et le chemin du dossier (repertoire) courant

    // printf("rep = %s\n", rep); sert pour deboggage

    // on ouvre le dossier et on le stocke dans variable d
    d = opendir(rep);
    
    // si l'ouverture echoue
    if (d == NULL)
    {
        // on retourne 1
        return 1;
    }
    
    // assert(d != NULL);

    // on lit le premier élément présent dans le dossier que l'on stocke dans la variable entry
    entry = readdir(d);
    // tant qu'il y a des éléments à lire dans le dossier
    while (entry != NULL)
    {
        // si l'élément à lire est un fichier
        if (entry->d_type == DT_REG){
            // on créé un nouveau fichier avec la fonction "ajouterFichier" et on l'ajoute à la liste
            ajouterFichier(rep, entry->d_name, liste);
        }
        // on passe à l'élément suivant dans le dossier courant
        entry = readdir(d);
    }

    // on ajoute le dossier à la liste des fichiers (de type Fichier *)
    // en réservant l'espace mémoire correspondant à la taille du chemin du dossier  
    tmp_rep = (char*) malloc(sizeof(char) * (strlen(rep)+1));
    // on copie la chaine de caractère rep dans tmp_rep
    strcpy(tmp_rep, rep);

    // on ferme le dossier ouvert
    closedir(d);

    return 0;
}


