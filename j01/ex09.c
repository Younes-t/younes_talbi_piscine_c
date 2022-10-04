#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int o_atoi(char *str);

int main(){
    printf("%d",o_atoi("123toto45"));
    return (0);
}
// 48 a 57
int o_atoi(char *str){
    int tailleS=strlen(&str);
    char res="";
    for(int i=0;i<tailleS;i++){
        int buff=(int)str[i];
        if(buff>57 || buff<48){
            return 0;
        }
        strcat(res,str[i]);
    }
    return (atoi(res));
}

