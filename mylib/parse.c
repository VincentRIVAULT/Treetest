// cc -Wall -o parse parse.c
// ./parse

#include <stdio.h>
#include <string.h>

/*
 * parse une string s de la forme "variable = valeur"
 * en sortie, v1 contient "variable" et v2 "valeur"
 * la fonction renvoie 1 en cas de succès, 0 sinon
 * */

/**
 * @brief parse une string s de la forme "variable = valeur"
 *        en sortie, v1 contient "variable" et v2 "valeur"
 *        la fonction renvoie 1 en cas de succès, 0 sinon
 * 
 * @param s 
 * @param v1 
 * @param v2 
 * @return int 
 */
int parse(char *s, char *v1, char *v2)
{
  return sscanf(s,"%19[^=] = %39[^\n]",v1,v2)==2 ;
}