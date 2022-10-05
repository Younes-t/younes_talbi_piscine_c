#include <stdio.h>
#include <stdlib.h>

int* fct(int a, int b);

int main(){
    int *lst=fct(2,3);
    printf("[%d,%d]",lst[0],lst[1]);
    free(lst);
    return (0);
}

int* fct(int a, int b){
    int *res=(int *)malloc((sizeof(int)*2));
    res[0]=b;
    res[1]=a;
    return (res);
}