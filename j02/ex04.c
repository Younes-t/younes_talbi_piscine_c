#include <stdio.h>
#include <stdlib.h>

void o_reverse_int_table(int *arr, int size);

int main(){
    int lst[]={2,3,4};
    printArray(lst,3);
    o_reverse_int_table(lst,3);
    printArray(lst,3);
    return (0);
}

void o_reverse_int_table(int *arr, int size){
    size=size-1;
    int buff[size];
    int n=0;
    for(int i=size;i>=0;i--){
        buff[n]=arr[i];
        n++;
    }
    for(int i=0;i<size;i++){
        arr[i]=buff[i];
    }
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}

