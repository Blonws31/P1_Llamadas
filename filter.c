#include "persona.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    /*Crear intancia de Person struct para guardar informacion de personas*/  
    Person persona; 

<<<<<<< HEAD
<<<<<<< HEAD
    /*Crear instancia de stat struct para obtener informacion del archivo*/    
    struct stat datosFichero;

    stat(argv[2],&datosFichero);

    /*Guardar caracter de control y verificar que sea solo un caracter*/
    char *caracterDeControl;
    if(strlen(argv[1]) > 1 || atoi(argv[1]) != 0){
      printf("El caracter de control es incorrecto. Por favor intentelo de nuevo.\n");
      return -1;
    }
    else{
     	caracterDeControl = argv[1];
    }

    /*Abrir ficheroFuente y crear archivoSalida*/
    int ficheroFuente = open (argv[2], O_RDONLY);
    int ficheroSalida = open (argv[3], O_RDWR | O_CREAT | O_TRUNC); /*Si el archivo no existe, se crea y si ya existe, se sobreescribe la informacion*/

    /*Validar cantidad de argumentos*/
    if(argc != 4){
  		printf("Numero de argumentos invalidos. Por favor intentelo de nuevo.\n");
  		return -1;
    }

    if (ficheroFuente != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
      if((datosFichero.st_size%sizeof(Person))==0){             /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/		
	      /*Mientras queden datos por leer en el archivo*/
	      while(read(ficheroFuente, &persona, sizeof(Person)) != 0){
	      	if(ficheroSalida != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
	      	    /*Por cada persona que tenga un caracter de control igual al especificao*/
		    if(persona.id_ctrl == toupper(*caracterDeControl)){
		      /*Escribe informacion a archivo de salida*/
		  		write(ficheroSalida, &persona, sizeof(Person));
		  	}
	      	}
	      	else{ /*Indica error si el archivo no existe o no se puede abrir*/
	      	    printf("Error en el segundo fichero. Por favor intentelo de nuevo.\n");
	      	}
	      }
	      
	      /*Cierra el archivo despues de usarlo*/
	      close(ficheroFuente);
	      close(ficheroSalida);
	}
     else{ /*Indica error si el tamaño del archivo no es valido*/
		printf("El tamaño del archivo no es valido. Por favor intentelo de nuevo\n");
		return -1;	
	}
    }
    else{ /*Indica error si el archivo no existe o no se puede abrir*/
        printf ("Error en el primer fichero. Por favor intentelo de nuevo.\n");
    }

    return 0;
}
=======
=======
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28
    /*Validar cantidad de argumentos*/
    if(argc != 4){
      printf("Numero de argumentos invalidos. Por favor intentelo de nuevo.\n");
      exit(-1);
    }

    /*Crear instancia de stat struct para obtener informacion del archivo*/    
    struct stat datosFichero;

    stat(argv[2], &datosFichero);

    /*Guardar caracter de control y verificar que sea solo un caracter*/
    char *caracterDeControl;
    if(strlen(argv[1]) > 1 || atoi(argv[1]) != 0){
      printf("El caracter de control es incorrecto. Por favor intentelo de nuevo.\n");
      exit(-1);
    }
    else{
      caracterDeControl = argv[1];
    }

    /*Abrir ficheroFuente y crear archivoSalida*/
    int ficheroFuente = open (argv[2], O_RDONLY);
    int ficheroSalida = open (argv[3], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); /*Si el archivo no existe, se crea y si ya existe, se sobreescribe la informacion*/

    if (ficheroFuente != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
        if((datosFichero.st_size % sizeof(Person)) == 0){ /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/    
          
          /*Mientras queden datos por leer en el archivo*/
          while(read(ficheroFuente, &persona, sizeof(Person)) != 0){
            if(ficheroSalida != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
                /*Por cada persona que tenga un caracter de control igual al especificao*/
              if(persona.id_ctrl == toupper(*caracterDeControl)){
                /*Escribe informacion a archivo de salida*/
                write(ficheroSalida, &persona, sizeof(Person));
              }
            }
            else{ /*Indica error si el archivo no existe o no se puede abrir*/
                printf("Error en el segundo fichero. Por favor intentelo de nuevo.\n");
            }
          }
          
          /*Cierra el archivo despues de usarlo*/
          close(ficheroFuente);
          close(ficheroSalida);
        }
       else{ /*Indica error si el tamaño del archivo no es valido*/
          printf("El tamaño del archivo no es valido. Por favor intentelo de nuevo\n");
          exit(-1);  
        }
    }
    else{ /*Indica error si el archivo no existe o no se puede abrir*/
        printf ("Error en el primer fichero. Por favor intentelo de nuevo.\n");
    }
<<<<<<< HEAD
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
=======
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28

    return 0;
}