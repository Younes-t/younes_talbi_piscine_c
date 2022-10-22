#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "util.h"

char* chooseWord();
char * replaceLetters(char* word);
int isIn(char l,char* word, char *tword);
int playTurn();
int isFinished(char *word, char *tword, int lives);
char getLetter(char *l);
int isTheWord(char* word,char* tword);
char * toLower(char *word);
char * toUpper(char *word);
int checkChar(char c);
int checkWord(char *word);
int getChoice(char *p);
int testWord(char *tword,char *word,char *l);

int main(){
    srand(time(NULL)); 
    //char mot[100];
    /* scanf("%s",mot);
    printf("Votre mot : %s",mot); */
    //printf("%s",chooseWord());
   playTurn();
   
   
}

char* chooseWord(){
    char *listMots[8]={"Chien\0","Pomme\0","Poulpe\0","Iceberg\0","Sifflet\0","Coquelicot\0","Labyrinthe\0","Baccalauréat\0"};
    int r = rand() % 8;   
    return listMots[r];
}

char * replaceLetters(char* word){
    int taille=strlen(word);
    char *res=malloc(sizeof(char *)*taille);
    int r;
    for(int i=0;i<taille;i++){
        r=rand()%5;
        if(r%2==0){
            res[i]='_';
        }else{
            res[i]=word[i];
        }
    }
    res[taille]='\0';
    return res;
}

int isTheWord(char* word,char* tword){
    char p[20];
    printf("\n%s\n",tword);
    printf("\nEntrez votre proposition de mot : ");
    lire(p,21);
    if(strcmp(toLower(word),toLower(p))==0 || strcmp(toUpper(word),toUpper(p))==0) {
            return 1;
    }
    return 0;
}



int checkChar(char c){
    if((c>122 || c<97) || (c>90 || c<65)){
        return 0;
    }
    return 1;
}

char * toLower(char *word){
    int taille=strlen(word);
    char *res=malloc(sizeof(char)*taille);
    for(int i=0;i<taille;i++){
        res[i]=tolower(word[i]);
    }
    return res;

}

char * toUpper(char *word){
    int taille=strlen(word);
    char *res=malloc(sizeof(char)*taille);
    for(int i=0;i<taille;i++){
        res[i]=toupper(word[i]);
    }
    return res;
}





int testWord(char *tword,char *word,char *l){
    while(1){
        printf("Essayez une lettre : ");
        lire(l,2);
        if(checkChar(l[0])==0){
            break;
        }
        printf("Pas un une lettre.\n");
        printf("%s\n",tword);
    }
    
    if(isIn(l[0],word,tword)==1){
        printf("\nBien joué !  Tous les '%c' ont été ajoutés au mot!\n",l[0]);
        if(strcmp(word,tword)==0){
            return 3;
        }
        return 1;
    }else{
        printf("ça n'est pas dans le mot\n");
        return 2;
    }
    return 0;

}


int isIn(char l,char* word, char *tword){
    int cpt=0;
    int t=strlen(word);
    for(int i=0;i<t;i++){
        if(tolower(word[i])==tolower(l) || toupper(word[i])==toupper(l)){
            cpt=1;
            tword[i]=word[i];
        }
    }
    if(cpt!=0){
        return 1;
    }
    return 0;
}

int playTurn(){
    char *word=chooseWord();
    char p[2];
    char l[2];
    char *tword=replaceLetters(word);
    int lives=5,buff;
    int state=0;
    printf("\n\n------------------------- GUESS THE WORD -------------------------------\n\nRULES :\n[-] A chaque tour vous avez le choix entre :\n   - Essayer d'ajouter une lettre\n   - Essayer de deviner de quel mot il s'agit\n\n[-] Toute autre entrée qu'une lettre ou un mot ne sera pas prise en compte et pourrait vous couter des vies.\n\nGOOD LUCK !\n\n");
    while(state==0){
        printf("------------------------ GUESS THE WORD -------------------------------\n\n");
        printf("\n%s\n",tword);
        state=isFinished(word,tword,lives);
        getChoice(p);
        if(p[0]=='1'){
            buff=testWord(tword,word,l);
            if(buff==2){
                lives--;
            }else if(buff==3){
                printf("GG ! C'est gagné avec %d vies restantes !",lives);
                break;
            }
            printf("%d vie(s) restante(s).\n\n",lives);
        }else if(p[0]=='2'){
            if(isTheWord(word,tword)==1){
                printf("GG ! C'est gagné avec %d vies restantes !",lives);
                break;
            }
            printf("Faux, vous perdez une vie.\n");
            lives--;  
            printf("%d vie(s) restante(s).\n\n",lives);
        }
    }
    if(state==2){
        printf("Fin de la partie vous êtes a cours de vie.\nLe mot était %s.",word);
    }
    return 0;
}

int getChoice(char *p){
    while(1){
        printf("\n[-]Tenter d'ajouter une lettre (tapez 1)\n[-]Faire une proposition(tapez 2)\n\n");
        lire(p,2);
        if(*p=='1' || *p=='2'){
            break;
        }else{
            printf("Erreur de saisie.\n");
        }
    }
    return -1;
}


int isFinished(char *word, char *tword,int lives){
    if(strcmp(word,tword)==0){
        return 1;
    }else if(lives==1){
        return 2;
    }
    return 0;

}

// gerer les màj dans le mot
//sécure les input
//décomposer en fct