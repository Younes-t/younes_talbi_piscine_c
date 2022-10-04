#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t o_strlen( const char * theString );
int o_strcmp(const char * first, const char * second);
char * o_strcat( char * destination, const char * source );  

int main(){
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
    size_t t=o_strlen(destination);
    for(int i=0;i<o_strlen(source);i++){
        destination[t]=source[i];
        t++;
    }
    return (destination); 
}


