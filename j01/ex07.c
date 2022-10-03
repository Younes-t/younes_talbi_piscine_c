#include <stdio.h>
#include <string.h>

long o_arrsum(int *arr, int size);


int main(){
    return (0);
}

long o_arrsum(int* arr, int size){
    long res=0;
    for(int i=0;i<size;i++){
        res=res+arr[i];
    }
    return (res);
}