#include "persona.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    
    Person persona;
    Person persona2; 

    struct stat sb;
    stat(argv[1],&sb);
    struct stat bs;
    stat(argv[2],&bs);

    int fd1 = open (argv[1], O_RDONLY);
    int fd2 = open (argv[2], O_RDONLY);
    int fd3 = open (argv[3], O_RDWR | O_CREAT);

    if(argc!=4){
	printf("Numero de argumentos invalidos\n");
	exit(1);
    }

    int cont = 0;
    int cont2 = 0;

    char *cadena = "\0";
    char *cadena2 = "\0";	

    char aux[(sb.st_size/sizeof(Person))][sizeof(persona.name)];
    char aux2[(bs.st_size/sizeof(Person))][sizeof(persona.name)];

    char aux3[] = "NULL";


    if (fd1 != -1){
	if(fd2 != -1){

		while(read(fd1, &persona, sizeof(Person))!= 0){	
			cadena = persona.name;
			strcpy(aux[cont],cadena);
			cont++;
		}

		while(read(fd2, &persona2, sizeof(Person))!= 0){
			cadena2 = persona2.name;
			strcpy(aux2[cont2],cadena2);
			cont2++;
		}
		int contador = 0;
		int suma = cont+cont2-1;
		strcpy(aux3,aux[cont-1]);
		cont--;
		while(contador < suma){
			cont--;
			cont2--;
			if(cont < 0 && cont2 >= 0){
				strcat(aux3," ");
				strcat(aux3,aux2[cont2]);
			}
			else if(cont2 < 0 && cont >= 0){
				strcat(aux3," ");
				strcat(aux3,aux[cont]);	
			}
			else if(cont < 0 && cont2 < 0){
				contador = suma;
			}
			else{
			strcat(aux3," ");
			strcat(aux3,aux2[cont2]);			
			strcat(aux3," ");
			strcat(aux3,aux[cont]);
			}
			contador++;
		}
		write(fd3,aux3,strlen(aux3));
		close(fd1);
		close(fd2);
		close(fd3);
	}
	else{
		printf("No se pudo abir el segundo archivo\n");	
	}
    }
    else{
        printf ("No se pudo abrir el archivo\n");
    }

    return 0;
}
