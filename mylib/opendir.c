// compilation : gcc -Wall opendir.c -o opendir
// exécution : ./opendir

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <assert.h>

int parcours(char * rep)
{
    DIR *d;
    struct dirent * entry;
    char newpath[FILENAME_MAX];

    printf("rep = %s\n", rep);

    d = opendir(rep);
    assert(d != NULL);
    entry = readdir(d);
    while (entry != NULL)
    {
        //printf("%s\n", entry->d_name);
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") && strcmp(entry->d_name, "."))
        {
            sprintf(newpath, "%s/%s", rep, entry->d_name);
            printf(newpath);
        }
        
        entry = readdir(d);
    }
    closedir(d);

    return 0;
}


int mail()
{
    parcours("/tmp");

    return 0;
}