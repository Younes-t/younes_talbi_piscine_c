#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
       char nmb='9';
       write(1,"10\n",4);
       for(int i=10; i>1;i--){
                write(1,&nmb,1);
                write(1,"\n",2);
                nmb=nmb-1;
        }
}

