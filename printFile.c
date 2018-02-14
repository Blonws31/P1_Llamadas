#include "persona.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
    Person persona; 
    int fd1  = open (argv[1], O_RDONLY);
    if(argc!=2){
	printf("Numero de argumentos invalidos\n");
	exit(1);
    }

    if (fd1 != -1){
	while(read(fd1, &persona, sizeof(Person))!= 0){
		printf("%s\t%d\t%d\t%c\t%.0f \n", persona.name, persona.age, persona.id, persona.id_ctrl, persona.salary); 
	}
     close(fd1);
    }
    else
        printf ("No se pudo abrir el archivo\n");
      
 return 0;
}

