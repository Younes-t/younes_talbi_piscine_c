#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t o_strlen( const char * theString );
int o_strcmp(const char * first, const char * second);
char * o_strcat( char * destination, const char * source );  

int main(){
    char* texte="yessaie";
    char* texte2="yessaie";
    printf("dest=%s\n",texte2);
    o_strcat(texte2,texte);
    printf("dest=%s",texte2);
    return (0);
}

//lenght of the array
size_t o_strlen(const char * theString){
    size_t i;
    for(i=0;theString[i]!='\0';i++){}
    return (i);
}

//find the first char wich is different
int o_strcmp(const char * first, const char * second){
    int buff;
    for(int i=0;i<strlen(second);i++){
        buff=first[i]-second[i];
        if(buff!=0){ return (buff);}
    }
    return 0;
}

//concat two string
char * o_strcat( char * destination, const char * source ){
    for(int i=0;i<o_strlen(destination);i++){
        destination[0]=source[0];
    }
    return (destination); 
}


