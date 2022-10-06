#include <stdio.h>
#include <stdlib.h>

int **mat2(int n, int m);

int main(){
    //int *matrix=mat(3,4);
    int **matrix=mat2(4,4);
    //printf("%d",matrix[0][0]);
    printMat(matrix,4,4);
    free(matrix);
    return (0);
}

//without malloc
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

//with malloc
int **mat2(int n, int m){
    int **mat=(int *)malloc(sizeof(int)*n);

    for(int l=0;l<n;l++){
        mat[l]=(int *)malloc(sizeof(int)*m);
        for(int c=0;c<m;c++){
            //printf("%d/%d\n",l,c);
            if(l>c){mat[l][c]=l;}
            else{mat[l][c]=c;}
        }
    }
    return (mat);

}

//print a matrix (for test only)
void printMat(int **mat, int n, int m){
    for(int l=0;l<n;l++){
        printf("\n");
        for(int c=0;c<m;c++){
            printf("%d",mat[l][c]);
        }
    }
}