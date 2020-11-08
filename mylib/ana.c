// cc -Wall -o exo3 exo3.c
// ./exo3

#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>



int ana(char *s1, char *s3)
{
	int trouve,i,j ;
	char *s2;

	if (strlen(s1)!=strlen(s3)) return 0 ;
	s2 = strdup(s3);
	
	for (i=0; s1[i]!='\0' ; i++)
		{
			trouve = 0 ;
			for (j=0 ; s2[j]!='\0' ; j++)
        {    

        if (s1[i]==s2[j])
			{
				s2[j] = ' ' ;
				trouve = 1 ;
				break ;
			}
		}

        if (trouve==0)
			{
				free(s2);
				return 0 ;
			}
    	}
	free(s2);
	return 1 ;      

}

