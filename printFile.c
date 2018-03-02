#include "persona.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

<<<<<<< HEAD
<<<<<<< HEAD
int main(int argc, char *argv[]){	
=======
int main(int argc, char *argv[]){   
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
=======
int main(int argc, char *argv[]){   
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28
    /*Crear intancia de Person struct para guardar informacion de personas*/ 
    Person persona; 

    /*Crear instancia de stat struct para obtener informacion del archivo*/    
    struct stat datosFichero;

<<<<<<< HEAD
<<<<<<< HEAD
    stat(argv[1],&datosFichero);
=======
    stat(argv[1], &datosFichero);
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
=======
    stat(argv[1], &datosFichero);
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28

    /*Abrir el fichero pasado como parametro y crear referencia a travez ficheroConFuente*/ 
    int ficheroFuente = open(argv[1], O_RDONLY); 
    
<<<<<<< HEAD
<<<<<<< HEAD
=======
    /*Usar buffer para evitar imprimir basura*/
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
=======
    /*Usar buffer para evitar imprimir basura*/
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28
    char buffer[sizeof(persona.name) + 1] = "\0";
    
    /*Validar los parametros esperados como entrada*/
    if (argc != 2){
<<<<<<< HEAD
<<<<<<< HEAD
    	printf("Numero de argumentos invalidos. Por favor intentelo de nuevo.\n");
    	exit(-1);
    }

    if (ficheroFuente != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
        if((datosFichero.st_size%sizeof(Person))==0){             /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/	
	    /*Mientras queden datos por leer en el archivo*/
            while(read(ficheroFuente, &persona, sizeof(Person)) != 0){

            /*Usar buffer para evitar que se imprima basura*/
            memcpy(buffer, persona.name, sizeof(persona.name));

            /*Impremelos a la consola usando los componentes de la struct Person*/
    	    printf("%s\t%d\t%.08d\t%c\t%.0f \n", buffer, persona.age, persona.id, persona.id_ctrl, persona.salary); 
    	}

        /*Cierra el archivo despues de usarlo*/
        close(ficheroFuente);
	}
	else{ /*Indica error si el tamaño del archivo no es valido*/
		printf("El tamaño del archivo no es valido. Por favor intentelo de nuevo\n");
		return -1;	
	}
        
    }
    else{ /*Indica error si el archivo no existe o no se puede abrir*/
        printf("El archivo no existe o no se puede abrir. Por favor intentelo de nuevo.\n");
	return -1;
    }
      
    return 0; /*Terminar el programa satiscactoriamente*/ 
}
=======
=======
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28
        printf("Numero de argumentos invalidos. Por favor intentelo de nuevo.\n");
        exit(-1);
    }

    if (ficheroFuente != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
        if((datosFichero.st_size % sizeof(Person)) == 0){ /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/  
            /*Mientras queden datos por leer en el archivo*/
            while(read(ficheroFuente, &persona, sizeof(Person)) != 0){
                /*Usar buffer para evitar que se imprima basura*/
                memcpy(buffer, persona.name, sizeof(persona.name));

                /*Impremelos a la consola usando los componentes de la struct Person*/
                printf("%s\t%d\t%.08d\t%c\t%.0f \n", buffer, persona.age, persona.id, persona.id_ctrl, persona.salary); 
            }

            /*Cierra el archivo despues de usarlo*/
            close(ficheroFuente);
        }
        else{ /*Indica error si el tamaño del archivo no es valido*/
            printf("El tamaño del archivo no es valido. Por favor intentelo de nuevo\n");
            return -1;  
        }
    }
    else{ /*Indica error si el archivo no existe o no se puede abrir*/
        printf("El archivo no existe o no se puede abrir. Por favor intentelo de nuevo.\n");
        return -1;
    }
      
    return 0; /*Terminar el programa satiscactoriamente*/ 
<<<<<<< HEAD
}
>>>>>>> 06916fd1ec4a8e8b917e154e8b94e6bdf0586ac9
=======
}
>>>>>>> 171514abfa8341571db85e9a1462dd254f7eab28
