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
    stat(argv[2],&datosPrimerFichero);
    stat(argv[3],&datosSegundoFichero);

    /*Validar cantidad de argumentos*/
    if(argc != 4){
		printf("Numero de argumentos invalidos. Por favor intentelo de nuevo.\n");
		exit(-1);
    }

    /*Guardar el resto de los argumentos esperados*/
    /*Abrir o crear los archivos especificados*/
    int ficheroEntrada1 = open (argv[1], O_RDONLY);
    int ficheroEntrada2 = open (argv[2], O_RDONLY);
    int ficheroSalida = open (argv[3], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR); /*Si el archivo no existe, se crea y si ya existe, la informacion se añade al final*/

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
					return -1;	
			   	}
		    }
		    else{ /*Indica error si el tamaño del archivo no es valido*/
				printf("El tamaño del primer archivo no es valido. Por favor intentelo de nuevo\n");
				return -1;	
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
}
