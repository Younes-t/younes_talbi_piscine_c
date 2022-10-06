#include <stdio.h>
#include <stdlib.h>

void o_reverse_int_table(int *arr, int size);

int main(){
    int lst[]={10,9,8,7,6,5,4,3,2,1};
    printArray(lst,10);
    o_reverse_int_table(lst,10);
    printArray(lst,10);
    return (0);
}

void o_reverse_int_table(int *arr, int size){
    int buff,taille;
    if(size%2==0){taille=size/2;}
    else{taille=(size/2)+1;}

    for(int i=0;i<taille;i++){
        buff=arr[i];
        arr[i]=arr[(size-1)-i];
        arr[(size-1)-i]=buff;
    }
  
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

