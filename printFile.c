#include "persona.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]){
	
    Person persona; 
    int fd1  = open (argv[1], O_RDONLY); 
    char buffer[sizeof(persona.name)+1] = "\0";
    if(argc!=2){
	printf("Numero de argumentos invalidos\n");
	exit(1);
    }

    if (fd1 != -1){
	while(read(fd1, &persona, sizeof(Person))!= 0){
		memcpy(buffer, persona.name,sizeof(persona.name));
		printf("%s\t%d\t%.08d\t%c\t%.0f \n", buffer, persona.age, persona.id, persona.id_ctrl, persona.salary); 
	}
     close(fd1);
    }
    else
        printf ("No se pudo abrir el archivo\n");
      
 return 0;
}