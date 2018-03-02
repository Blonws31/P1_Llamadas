#include "persona.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	/*Crear intancias de Person struct para guardar informacion de personas*/
    Person persona1;
    Person persona2; 

    /*Crear instancia de stat struct para obtener informacion del archivo*/    
    struct stat datosPrimerFichero;
    struct stat datosSegundoFichero;
<<<<<<< HEAD
    stat(argv[2],&datosPrimerFichero);
    stat(argv[3],&datosSegundoFichero);

    int fd1 = open (argv[1], O_RDONLY);
    int fd2 = open (argv[2], O_RDONLY);
    int fd3 = open (argv[3], O_RDWR | O_CREAT | O_TRUNC); /*Si el archivo no existe, se crea y si ya existe, se sobreescribe la informacion*/

    if(argc!=4){
	printf("Numero de argumentos invalidos\n");
	return -1;
=======
    stat(argv[1], &datosPrimerFichero);
    stat(argv[2], &datosSegundoFichero);

    /*Validar cantidad de argumentos*/
    if(argc != 4){
		printf("Numero de argumentos invalidos. Por favor intentelo de nuevo.\n");
		exit(-1);
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
    }

    /*Guardar el resto de los argumentos esperados*/
    /*Abrir o crear los archivos especificados*/
    int ficheroEntrada1 = open (argv[1], O_RDONLY);
    int ficheroEntrada2 = open (argv[2], O_RDONLY);
    int ficheroSalida = open (argv[3], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); /*Si el archivo no existe, se crea y si ya existe, la informacion se añade al final*/

<<<<<<< HEAD
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
=======
    /*Index para moverse entre el tamano del fichero y 0*/
    int fichero1Index = 0;
    int fichero2Index = 0;

    /*Si el archivo fue encontrado y se abrio correctament*/
    if (ficheroEntrada1 != -1){

		if(ficheroEntrada2 != -1){ /*Si el archivo fue encontrado y se abrio correctament*/

    		if((datosPrimerFichero.st_size % sizeof(Person)) == 0){ /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/		
				
				if((datosSegundoFichero.st_size % sizeof(Person)) == 0){ /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/

		    		/*Mientras queden datos por leer en el archivo*/
					while(read(ficheroEntrada1, &persona1, sizeof(Person)) != 0){	
						/*Incrementa contador, que contendra total de personas en el archivo*/
						fichero1Index++;
					}

					/*Mientras queden datos por leer en el archivo*/
					while(read(ficheroEntrada2, &persona2, sizeof(Person)) != 0){
						/*Incrementa contador, que contendra total de personas en el archivo*/
						fichero2Index++;
					}

					/*Mientras queden personas en fichero1 y en fichero2*/
					while(fichero1Index > 0 && fichero2Index > 0){
						/*Leer de fichero1 de atras para adelante y escribir resultado en fichero salida*/
						fichero1Index--;
						lseek(ficheroEntrada1, sizeof(Person) * fichero1Index, SEEK_SET);
						read(ficheroEntrada1, &persona1, sizeof(Person));
			    		write(ficheroSalida, &persona1, sizeof(Person));

						/*Leer de fichero2 de atras para adelante y escribir resultado en fichero salida*/
						fichero2Index--;
						lseek(ficheroEntrada2, sizeof(Person) * fichero2Index, SEEK_SET);
						read(ficheroEntrada2, &persona2, sizeof(Person));
			    		write(ficheroSalida, &persona2, sizeof(Person));
					}

					/*Mientras queden personas en fichero1*/
					while (fichero1Index > 0){
						/*Leer de fichero1 de atras para adelante y escribir resultado en fichero salida*/
						fichero1Index--;
						lseek(ficheroEntrada1, sizeof(Person) * fichero1Index, SEEK_SET);
						read(ficheroEntrada1, &persona1, sizeof(Person));
			    		write(ficheroSalida, &persona1, sizeof(Person));				
					}

					/*Mientras queden personas en fichero2*/
					while(fichero2Index > 0){
						/*Leer de fichero2 de atras para adelante y escribir resultado en fichero salida*/
						fichero2Index--;
						lseek(ficheroEntrada1, sizeof(Person) * fichero1Index, SEEK_SET);
						read(ficheroEntrada1, &persona1, sizeof(Person));
			    		write(ficheroSalida, &persona1, sizeof(Person));	
					}

					/*Cierra el archivo despues de usarlo*/
					close(ficheroEntrada1);
					close(ficheroEntrada2);
					close(ficheroSalida);
				}
				else{ /*Indica error si el tamaño del archivo no es valido*/
					printf("El tamaño del segundo archivo no es valido. Por favor intentelo de nuevo\n");
					exit(-1);	
			   	}
		    }
		    else{ /*Indica error si el tamaño del archivo no es valido*/
				printf("El tamaño del primer archivo no es valido. Por favor intentelo de nuevo\n");
				exit(-1);	
		    }
		}
	    else{ /*Indica error si el archivo no existe o no se puede abrir*/
			printf("No se pudo abrir el segundo archivo. Por favor intentelo de nuevo.\n");	
		}
    }
    else{ /*Indica error si el archivo no existe o no se puede abrir*/
        printf ("No se pudo abrir el archivo. Por favor intentelo de nuevo.\n");
    }

    return 0; /*Terminar el programa satiscactoriamente*/ 
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
}
