#include "persona.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	
    Person persona; 
    int fd1 = open (argv[2], O_RDONLY);
    int fd2 = open (argv[3], O_RDWR  | O_CREAT | O_APPEND);
    int fd3 = open (argv[4], O_RDWR  | O_CREAT | O_APPEND);
    char *p;
    int limite = strtol(argv[1],&p,10);

    if(argc!=5){
	printf("Numero de argumentos invalidos\n");
	exit(1);
    }


    if (fd1 != -1){
	while(read(fd1, &persona, sizeof(Person))!= 0){
		if(fd2 != -1){
		    if(fd3 != -1){
		    	if(persona.age < limite){
		    		write(fd2, &persona, sizeof(Person));
                    	}
		    	else if(persona.age >= limite){
		    		write(fd3, &persona, sizeof(Person));
                    	}
		    }
		    else{   
			    printf("Error en el tercer fichero\n");
				return -1;
		    }	
		   
		}
		else{
		    printf("Error en el segundo fichero\n");
		    return -1;
		}
	}
     close(fd1);
     close(fd2);
     close(fd3);
    }
    else
        printf ("Error en el primer fichero\n");
      
 return 0;
}

