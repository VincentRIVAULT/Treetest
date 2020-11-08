// compilation : gcc -Wall listeEntRep.c -o listeEntRep
// exécution : ./listeEntRep


#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>


/**
 * liste tous les fichiers présents dans le répertoire
 * */

void listeEntRep()
{
  DIR * rep = opendir("/var"); 
  
    if (rep != NULL) 
    { 
        struct dirent * ent; 
  
        while ((ent = readdir(rep)) != NULL) 
        { 
            printf("%s\n", ent->d_name); 
        } 
  
        closedir(rep); 
    } 
}