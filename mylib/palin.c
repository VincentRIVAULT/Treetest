// cc -Wall -o palin palin.c
// ./palin

#include <string.h>


int palind(char s[])
{
    int i, j, n=strlen(s);
    for (i=0, j=n-1 ; i<j && s[i]==s[j] ;  i++,j--) ;
    return s[i]==s[j] ;
}

