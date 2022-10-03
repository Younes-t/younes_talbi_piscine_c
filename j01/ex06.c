#include <stdio.h>
#include <string.h>


int main(){
    char texte[]="yessaie";
    scanf("%[^\n]", &texte);
    write(1,texte,strlen(texte)+1);


    return (0);
}