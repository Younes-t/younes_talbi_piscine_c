#include <stdio.h>
#include <string.h>


void o_print_number(int nb);
void o_print_string(char *str);

int main(int argc, char *argv[]){
    o_print_number(argc);
    write(1,"\n",2);
    //printArray(argv,2);
    for(int i=0;i<argc;i++){
        o_print_string(argv[i]);
        write(1,"\n",2);
    }
    return (0);
}


void o_print_string(char *str){
    for(int i=0;i<strlen(str);i++){
        write(1,&str[i],1);
    }
}

void o_print_number(int nb){
    char x=nb+'0';
    write(1,&x,1);
}

