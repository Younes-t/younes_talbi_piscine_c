#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Contact {
    char* nom;
    char* prenom;
    char *tel;
};

char **unparseString(char *str);
char * o_strcat( char * destination, const char * source );
struct Contact * readData(FILE* file);
int main(){
    FILE* ptr = fopen("data.csv", "r");
    if(ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    struct Contact* liste=readData(ptr);
    printf("%s,%s,%s",liste[0].nom,liste[0].prenom,liste[0].tel);
    return (0);
}

struct Contact * readData(FILE* file){
    char *buff[100];
    char **ligne=malloc(sizeof(char *)*3);
    struct Contact rep[100];
    struct Contact c;
    char * strToken;
    int cpt=0,n=0;
    while (fscanf(file, "%s,",buff)== 1){
        strToken = strtok ( buff, "," );
        while ( strToken != NULL ) {
            ligne[cpt]=strToken;
            cpt++;
            strToken = strtok ( NULL, "," );
        }
        c.nom=ligne[0];
        c.prenom=ligne[1];
        c.tel=ligne[2];
        rep[n]=c;
        cpt=0;
        n++;
    }
    printf("%s,%s,%s",rep[2].nom,rep[2].prenom,rep[2].tel);
    return (rep);
}

/* char **unparseString(char *str){
    char buff[100]=" ";
    char **res=malloc(sizeof(char *)*3);
    int cpt=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]==','){
            buff[i+1]='\0';
            res[cpt]=buff;
            //printf("res[cpt]=%s\n",res[cpt]);
            cpt++;
            //strcpy(buff," ");
        }
        //printf("buff[i]=%c\n",buff[i]);
        buff[i]=buff[i]+str[i];
    }
    return res;

} */ 
char * o_strcat( char * destination, const char * source ){
    size_t t=strlen(destination);
    for(int i=0;i<strlen(source);i++){
        destination[t]=source[i];
        t++;
    }
    return (destination); 
}

