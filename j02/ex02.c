#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex03.c"

char * o_strcpy( char * destination, const char * source );
char * o_strncpy( char *  destination, const char *  source, size_t length );


int main(){
    return (0);
}

char * o_strcpy( char *destination, const char * source ){
    for(int i=0;i<=o_strlen(source);i++){
        destination[i]=source[i];
    }
    return (destination);
}

char * o_strncpy( char *  destination, const char *  source, size_t length ){
    for(int i=0;i<=length;i++){
        destination[i]=source[i];
    }
    return (destination);
}


