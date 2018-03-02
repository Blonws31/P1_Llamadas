#include "persona.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int isDigit(char input[]);

int main(int argc, char *argv[]){
    /*Crear intancia de Person struct para guardar informacion de personas*/ 	
<<<<<<< HEAD
<<<<<<< HEAD
    Person persona; 
=======
=======
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28
    Person persona;

    /*Validar cantidad de argumentos*/
    if(argc != 5){
		printf("Numero de argumentos invalidos. Por favor intentelo de nuevo.\n");
		exit(-1);
    } 
<<<<<<< HEAD
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
=======
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28

    /*Crear instancia de stat struct para obtener informacion del archivo*/    
    struct stat datosFichero;

<<<<<<< HEAD
<<<<<<< HEAD
    stat(argv[2],&datosFichero);
=======
    stat(argv[2], &datosFichero);
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
=======
    stat(argv[2], &datosFichero);
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28

    /*Guardar el valor del primer argumento*/
    int edadLimite = 0;
    char *p;
<<<<<<< HEAD
<<<<<<< HEAD
    /*Verificar que sea un entero*/
	if(isDigit(argv[1]) == 0){
		printf("Primero argumente tiene que ser un entero. Por favor intentelo de nuevo.\n");
		return -1;
	}
    else{
    	edadLimite = strtol(argv[1], &p, 10);

    	/*Verificar que la edad limite este en el rango logico*/
    	if(edadLimite > 150 || edadLimite < 0){
    		printf("Edad limite tiene que ser entre 0 y 150. Por favor intentelo de nuevo.\n");
    		return -1;
    	}
    }
    
    /*Guardar el resto de los argumentos esperados*/
    /*Abrir o crear los archivos especificados*/
    int ficheroFuente = open (argv[2], O_RDONLY);
    int ficheroSalidaMenores = open (argv[3], O_RDWR  | O_CREAT | O_APPEND); /*Si el archivo no existe, se crea y si ya existe, la informacion se añade al final*/
    int ficheroSalidaMayores = open (argv[4], O_RDWR  | O_CREAT | O_APPEND); /*Si el archivo no existe, se crea y si ya existe, la informacion se añade al final*/

    /*Validar cantidad de argumentos*/
    if(argc != 5){
		printf("Numero de argumentos invalidos. Por favor intentelo de nuevo.\n");
		return -1;
    }

    if (ficheroFuente != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
	if((datosFichero.st_size%sizeof(Person))==0){             /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/		
    	/*Mientras queden datos por leer en el archivo*/
		while(read(ficheroFuente, &persona, sizeof(Person)) != 0){
			if(ficheroSalidaMenores != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
			    /*Si el archivo fue encontrado y se abrio correctament*/
			    if(ficheroSalidaMayores != -1){ 
			    	/*Si la edad es menor que edadLimite, escribe datos a ficheroSalidaMenores*/
			    	if(persona.age < edadLimite){
			    		write(ficheroSalidaMenores, &persona, sizeof(Person));
                	}
                	/*Si la edad es mayor que edadLimite, escribe datos a ficheroSalidaMayores*/
			    	else if(persona.age >= edadLimite){
			    		write(ficheroSalidaMayores, &persona, sizeof(Person));
                	}
			    }
			    else{ /*Indica error si el archivo no existe o no se puede abrir*/
				    printf("Error en el tercer fichero. Por favor intentelo de nuevo.\n");
					return -1;
			    }	
			}
			else{ /*Indica error si el archivo no existe o no se puede abrir*/
			    printf("Error en el segundo fichero. Por favor intentelo de nuevo.\n");
			    return -1;
			}
		}
	    
	    /*Cierra el archivo despues de usarlo*/
	    close(ficheroFuente);
	    close(ficheroSalidaMenores);
	    close(ficheroSalidaMayores);
	}
	else{ /*Indica error si el tamaño del archivo no es valido*/
		printf("El tamaño del archivo no es valido. Por favor intentelo de nuevo\n");
		return -1;	
	}
    }
    else{
        printf ("Error en el primer fichero. Por favor intentelo de nuevo.\n");
    }
=======
=======
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28

    /*Verificar que sea un entero*/
	if(isDigit(argv[1]) == 0){
		printf("Primer argumento tiene que ser un entero positivo. Por favor intentelo de nuevo.\n");
		exit(-1);
	}
    else{
    	edadLimite = strtol(argv[1], &p, 10);

    	/*Verificar que la edad limite este en el rango logico*/
    	if(edadLimite > 150){
    		printf("Edad limite tiene que ser entre 0 y 150. Por favor intentelo de nuevo.\n");
    		exit(-1);
    	}
    }
    
    /*Guardar el resto de los argumentos esperados*/
    /*Abrir o crear los archivos especificados*/
    int ficheroFuente = open (argv[2], O_RDONLY);
    int ficheroSalidaMenores = open (argv[3], O_RDWR  | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR); /*Si el archivo no existe, se crea y si ya existe, la informacion se añade al final*/
    int ficheroSalidaMayores = open (argv[4], O_RDWR  | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR); /*Si el archivo no existe, se crea y si ya existe, la informacion se añade al final*/

    if (ficheroFuente != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
		if((datosFichero.st_size % sizeof(Person)) == 0){ /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/		
	    	
	    	/*Mientras queden datos por leer en el archivo*/
			while(read(ficheroFuente, &persona, sizeof(Person)) != 0){
				if(ficheroSalidaMenores != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
				    
				    /*Si el archivo fue encontrado y se abrio correctament*/
				    if(ficheroSalidaMayores != -1){ 
				    	
				    	/*Si la edad es menor que edadLimite, escribe datos a ficheroSalidaMenores*/
				    	if(persona.age < edadLimite){
				    		write(ficheroSalidaMenores, &persona, sizeof(Person));
	                	}
	                	/*Si la edad es mayor que edadLimite, escribe datos a ficheroSalidaMayores*/
				    	else if(persona.age >= edadLimite){
				    		write(ficheroSalidaMayores, &persona, sizeof(Person));
	                	}
				    }
				    else{ /*Indica error si el archivo no existe o no se puede abrir*/
					    printf("Error en el tercer fichero. Por favor intentelo de nuevo.\n");
						exit(-1);
				    }	
				}
				else{ /*Indica error si el archivo no existe o no se puede abrir*/
				    printf("Error en el segundo fichero. Por favor intentelo de nuevo.\n");
				    exit(-1);
				}
			}
		    
		    /*Cierra el archivo despues de usarlo*/
		    close(ficheroFuente);
		    close(ficheroSalidaMenores);
		    close(ficheroSalidaMayores);
		}
		else{ /*Indica error si el tamaño del archivo no es valido*/
			printf("El tamaño del archivo no es valido. Por favor intentelo de nuevo\n");
			exit(-1);	
		}
    }
    else{
        printf ("Error en el primer fichero. Por favor intentelo de nuevo.\n");
    }
<<<<<<< HEAD
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
=======
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28
      
 	return 0;
}

/*Retorna 1 si es una cadena de enteros o 0 de no se asi*/
int isDigit(char input[]){
	int i; 
	/*Recorre la cadena, si algun caracter no es entero returna 0*/
	for (i = 0; i < strlen(input); i++){
		/*No es entero */
        if (input[i] > '9' || input[i] < '0')
            return 0;
    }

    return 1;
<<<<<<< HEAD
<<<<<<< HEAD
}
=======
}
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
=======
}
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28
