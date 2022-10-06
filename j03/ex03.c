#include <stdio.h>
#include <stdlib.h>

char * o_strjoin(int size,char **arr, char *sep);
char * o_strcat( char * destination, const char * source );
size_t o_strlen(const char * theString);

int main(){
    char *chaine[]={"yess","ahahah","hihi"};
    char *tab=o_strjoin(3,chaine,";\n");
    printf("%s",tab);
    free(tab);
    return (0);
}

char * o_strjoin(int size,char **arr, char *sep){
    int taille=0; 
    char *res=malloc(sizeof(char *)*size);

     for(int i=0;i<size;i++){
        o_strcat(res,arr[i]);
        o_strcat(res,sep);
    } 

    return (res);

}


char * o_strcat( char * destination, const char * source ){
    size_t t=o_strlen(destination);
    for(int i=0;i<o_strlen(source);i++){
        destination[t]=source[i];
        t++;
    }
    return (destination); 
}

size_t o_strlen(const char * theString){
    size_t i;
    for(i=0;theString[i]!='\0';i++){}
    return (i);
}