#include <stdio.h>
#include <stdlib.h>

int* fct(int a, int b);

int main(){
    int *lst=fct(50,10);
    free(lst);
    return (0);
}

int* fct(int a, int b){
    int nmbP,nmbG,t,cpt=0;
    if(a>b){nmbG=a;nmbP=b;}
    else{nmbG=b;nmbP=a;}

    t=nmbG-nmbP+1;
    int *res=(int *)malloc(sizeof(int)*t);
    for(int i=nmbP;i<=nmbG;i++){
        res[cpt]=i;
        cpt++;
    }
    printArr(res,t);
    return (res);
    
    
}

void printArr(int *arr, int t){
    for(int i=0;i<t;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
} 

