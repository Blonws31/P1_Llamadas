#include "persona.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    
    Person persona1;
    Person persona2; 

    /*Crear instancia de stat struct para obtener informacion del archivo*/    
    struct stat datosPrimerFichero;
    struct stat datosSegundoFichero;
    stat(argv[2],&datosPrimerFichero);
    stat(argv[3],&datosSegundoFichero);

    int fd1 = open (argv[1], O_RDONLY);
    int fd2 = open (argv[2], O_RDONLY);
    int fd3 = open (argv[3], O_RDWR | O_CREAT | O_TRUNC); /*Si el archivo no existe, se crea y si ya existe, se sobreescribe la informacion*/

    if(argc!=4){
	printf("Numero de argumentos invalidos\n");
	return -1;
    }

    int cont = 0;
    int cont2 = 0;

    if (fd1 != -1){
	if(fd2 != -1){
     	   if((datosPrimerFichero.st_size%sizeof(Person))==0){             /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/		
		if((datosSegundoFichero.st_size%sizeof(Person)) == 0){		/*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/
			while(read(fd1, &persona1, sizeof(Person))!= 0){	
				cont++;
			}

			while(read(fd2, &persona2, sizeof(Person))!= 0){
				cont2++;
			}

			int contador = 0;
			int suma = cont+cont2;
			while(contador < suma){
				if(cont <= 0 && cont2 > 0){
					cont2--;
					lseek(fd2,sizeof(Person)*cont2,SEEK_SET);
					read(fd2, &persona2, sizeof(Person));
		    			write(fd3, &persona2, sizeof(Person));

				}	
				else if(cont2 <= 0 && cont > 0){
					cont--;
					lseek(fd1,sizeof(Person)*cont,SEEK_SET);
					read(fd1, &persona1, sizeof(Person));
		    			write(fd3, &persona1, sizeof(Person));	

				}
				else if(cont <= 0 && cont2 <= 0){
					contador = suma;
				}
				else{
					cont--;
					lseek(fd1,sizeof(Person)*cont,SEEK_SET);
					read(fd1, &persona1, sizeof(Person));
		    			write(fd3, &persona1, sizeof(Person));

					cont2--;
					lseek(fd2,sizeof(Person)*cont2,SEEK_SET);
					read(fd2, &persona2, sizeof(Person));
		    			write(fd3, &persona2, sizeof(Person));

				}
				contador++;
			}
			close(fd1);
			close(fd2);
			close(fd3);
		}
		else{ /*Indica error si el tamaño del archivo no es valido*/
			printf("El tamaño del segundo archivo no es valido. Por favor intentelo de nuevo\n");
			return -1;	
	   	}
	   }
	   else{ /*Indica error si el tamaño del archivo no es valido*/
		printf("El tamaño del primer archivo no es valido. Por favor intentelo de nuevo\n");
		return -1;	
	   }
	}
	else{
		printf("No se pudo abir el segundo archivo\n");	
	}
    }
    else{
        printf ("No se pudo abrir el primer archivo\n");
    }

    return 0;
}
