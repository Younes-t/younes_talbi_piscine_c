#include <stdio.h>
#include <stdlib.h>


char ** initMat();
void printMat(char **mat);
int playTurn(char **mat,int x,int y,int p);
int isWinDiag(char **mat,int p);
int isWinLine(char **mat, int p);
int isWinColumn(char **mat, int p);
int isDraw(char **mat);
int playGame(char **mat,int p);
int getCoord(int *x, int *y);
int isOver(char **mat, int p);

int main(){
    char **mat=initMat();
    init(mat);
    return (0);
}

char ** initMat(){
    printf("\n ///////// TIC TAC TOE //////////////\n\n");
    printf("RULES :\n[-] Jeu au tour par tour\n[-] Les indices commencent a 0 et finissent a 2. \nPour qu'une position soit acceptée, l'indice donné doit être compris dans cette intervalle et la case doit être vide.\n\n");
    char **mat=malloc(sizeof(char *)*3);
    for(int l=0;l<3;l++){
        mat[l]=malloc(sizeof(char)*3);
        for(int c=0;c<3;c++){
            mat[l][c]='-';
        }
    }
    return (mat);
}


int init(char **mat){
    int current_player=0,isOverv;
    while(1){
        if(isOverv==1){
            printf("\nPartie terminée ! Le vainqueur est le joueur %d\n",current_player);
            break;
        }else if(isOverv==2){
            printf("\nPartie terminée ! C'est une égalité, personne ne gagne.\n");
            break;
        }
        printf("\n----------------------- Joueur %d ------------------------------\n",current_player+1);
        playGame(mat,current_player);
        isOverv=isOver(mat,current_player);
        current_player=!current_player;
    }
    return 0;
}


int playGame(char **mat, int p){
    int x,y;
    printMat(mat);
    getCoord(&x,&y);
    int res=playTurn(mat,x,y,p);
    if(res==-1){
        printf("Une erreur est survenue.");
        return -1;
    }else if(res==2){
        printf("La case est déjà occupée.");
        playGame(mat,p);
        return 2;
    };
        printMat(mat);
        return 1;
}

int getCoord(int *x, int *y){
    while(1){
        printf("\nEntrez les coordonnées de votre piece (ligne,colonne):");
        scanf("%d,%d",x,y);
        scanf("%*[^\n]%*1[\n]");
        if((*x==0 || *x==1 || *x==2 ) && (*y==0 || *y==1 || *y==2) && !((sizeof(x)+sizeof(y))<(sizeof(int)*2))){
            break;
        }else{
            printf("Erreur de saisie des coordonnées.");
        }
    }
    return (1);
}




int playTurn(char **mat,int x,int y,int p){
    if(mat[x][y]!='-'){
        return(2);
    }else{
        if(p==1){
        mat[x][y]='O';
        return (0);
        }else if(p==0){
            mat[x][y]='X';
            return (0);
        }
    }
    
    return (-1);
}

int isOver(char **mat, int p){
    if(isDraw(mat)==1){
        return(2);
    }else if(isWinColumn(mat,p) || isWinDiag(mat,p) || isWinLine(mat,p)){
        return(1);
    }else{
        return(0);
    }
}
int isWinLine(char **mat, int p){
    char charac;
    if(p==1){charac='O';}
    else{charac='X';}
    for(int i=0;i<3;i++){
        if(mat[i][0]==charac && mat[i][0]==mat[i][1] && mat[i][1]==mat[i][2]){
            return (1);
        }
    }
    return (0);
}

int isWinColumn(char **mat,int p){
    char charac;
    if(p==1){charac='O';}
    else{charac='X';}
    for(int i=0;i<3;i++){
        if(mat[0][i]==charac && mat[0][i]==mat[1][i] && mat[1][i]==mat[2][i]){
            return (1);
        }
    }
    return (0);

}

int isWinDiag(char **mat,int p){
    char charac;
    if(p==1){charac='O';}
    else{charac='X';}
    if(mat[0][0]==charac && mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2]){
        return (1);
    }else if(mat[0][2]==charac && mat[1][1]==mat[0][2] && mat[1][1]==mat[2][0]){
        return (1);
    }
    return (0);

}

int isDraw(char **mat){
    for(int i=0;i<3;i++){
        for(int n=0;n<3;n++){
            if(mat[i][n]=='-'){    
                return (0);
            }
        }
    }
    return(1);
}



void printMat(char **mat){
    printf(" 0   1   2");
    for(int l=0;l<3;l++){
        printf("\n");
        if(l!=0){
            printf("-----------\n");
        }
        for(int c=0;c<3;c++){
            if(c==1){
                printf(" | %c |",mat[l][c]);
            }else{printf(" %c",mat[l][c]);}
        }
    }
    printf("\n");
}