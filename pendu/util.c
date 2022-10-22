#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

/*

SOURCE : OPENCLASSROOM C PATH
https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16993-securisez-la-saisie-de-texte

*/


int lire(char *chaine, int longueur);
void viderBuffer();

int lire(char *chaine, int longueur){
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}



void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

