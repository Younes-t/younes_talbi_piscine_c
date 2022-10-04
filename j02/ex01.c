#include <stdio.h>
#include <stdlib.h>

void o_print_string(char *str);


int main(){
    o_print_string("a string");
    return (0);
}

void o_print_string(char *str){
    for(int i=0;i<strlen(str);i++){
        write(1,&str[i],1);
    }
}


