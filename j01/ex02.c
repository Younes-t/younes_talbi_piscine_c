#include <stdlib.h>


int main(){
	char nmb='1';
	for(int i=1; i<10;i++){
		write(1,&nmb,1);
		nmb=nmb+1;
	}
	write(1,"10",2);
}	

