#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
       for(char i='A'; i!=('Z'+1);i++){
                write(1,&i,1);
                write(1,"\n",2);
        }
}