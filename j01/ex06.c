#include <stdio.h>
#include <string.h>

//
int main(){
    char texte[100];
    scanf("%[^\n]", &texte);
    write(1,texte,strlen(texte));
    return (0);
}