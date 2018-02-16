#include "persona.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	
    Person persona; 
    char *busqueda = argv[1];
    int fd2 = open (argv[2], O_RDONLY);
    int fd3 = open (argv[3], O_RDWR | O_CREAT | O_TRUNC);

    if(argc!=4){
	printf("Numero de argumentos invalidos\n");
	exit(1);
    }
	
    if (fd2 != -1){
	while(read(fd2, &persona, sizeof(Person))!= 0){
		if(fd3 != -1){
		    if(persona.id_ctrl == toupper(*busqueda)){
		    		write(fd3, &persona, sizeof(Person));
                    	}
		}
		else{
		    printf("Error en el segundo fichero\n");
		}
	}
     close(fd2);
     close(fd3);
    }
    else
        printf ("Error en el primer fichero\n");
}

