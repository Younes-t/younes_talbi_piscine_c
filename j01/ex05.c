#include <stdio.h>
#include <string.h>

int o_charpos(char *str, char c);

int main(){
       return (0);
}

int o_charpos(char *chaine, char c){
    for(int i=0;i<=strlen(chaine);i++){
        if(c==chaine[i]){
            return i;
        }
    }
    return (-1);
}