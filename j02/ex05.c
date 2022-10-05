#include <stdio.h>

void o_print_number(int nb);

int main(){
    o_print_number(3);
    return (0);
}

void o_print_number(int nb){
    char x=nb+'0';
    write(1,&x,1);
}