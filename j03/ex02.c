#include <stdio.h>
#include <stdlib.h>

int main(){
    int *matrix=mat(3,4);
    return (0);
}

int mat(int n, int m){
    int mat[n][m];

    for(int l=0;l<n;l++){
        for(int c=0;c<m;c++){
            if(l>c){mat[l][c]=l;}
            else{mat[l][c]=c;}
        }
    }
    return (mat);
}


/*void printMat(int mat, int n, int m){
    for(int l=0;l<n;l++){
        printf("\n");
        for(int c=0;c<m;c++){
            printf("%d",mat[l][c]);
        }
    }
}*/