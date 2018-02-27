#include "persona.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

char encuentraCaracterMasFrecuente(char cadena[]);

int pruebasParaEncuentraCaracterMasFrecuente();

int main(int argc, char *argv[]){   
    /*Crear intancia de Person struct para guardar informacion de personas*/  
    Person persona; 

    /*Crear instancia de stat struct para obtener informacion del archivo*/    
    struct stat datosFichero;

    stat(argv[1],&datosFichero);

    /*Abrir el fichero pasado como parametro y crear referencia a travez ficheroConFuente*/ 
    int ficheroFuente = open (argv[1], O_RDONLY);

    /*Declaracion e inicializacion de variables*/
    double rentaTotal = 0.0; 
    int edadTotal = 0; 
    int contador = 0;
    int edadTotalPorDni = 0; 

    char caracteres[sizeof(Person)]; /*Cadena que contiene los caracteres de los DNI*/
    int caracterMasFrecuente;
    int aux_numerico; /*Variable auxiliar*/

    /*Validar los parametros esperados como entrada*/
    if(argc != 2){
		printf("Numero de argumentos invalidos. Por favor intentelo de nuevo.\n");
		return -1;
    }

    if (ficheroFuente != -1){ /*Si el archivo fue encontrado y se abrio correctament*/
        if((datosFichero.st_size % sizeof(Person)) == 0){ /*Valida que el archivo tenga el tamano apropiado respecto a struct Person*/	
			int i = 0;

			/*Mientras queden datos por leer en el archivo*/
			while(read(ficheroFuente, &persona, sizeof(Person)) != 0){
				/*Acumular el total de rente y edad*/
				rentaTotal += persona.salary;
				edadTotal += persona.age;
				contador++;
				caracteres[i] = persona.id_ctrl; /*Guardar cada caracter en cadena*/
				i++;
			}

			lseek(ficheroFuente, 0, SEEK_SET);

			/*Imprimir resultado a la consola*/
			printf("Renta media: %.0f\n", rentaTotal/contador);	
			printf("Edad media: %d\n", edadTotal/contador);

			contador = 0;
			/*Llamar a la funcion que se encarga de encontrar el caracter mas frecuente*/
			caracterMasFrecuente = encuentraCaracterMasFrecuente(caracteres);

			/*Mientras queden datos por leer en el archivo*/
		   	while(read(ficheroFuente, &persona, sizeof(Person)) != 0){
				aux_numerico = persona.id_ctrl;
				
				/*Contar las ocurrencias del caracter/DNI mas frecuente y al mismo
				tiempo la edad corespondiente*/
				if(caracterMasFrecuente == aux_numerico){
					edadTotalPorDni += persona.age;
					contador++;
				}
			}

			/*Imprimir el resto de los resultados a la consola*/
			printf("Caracter de control de DNI mas frecuente: %c\n", caracterMasFrecuente);
			printf("Edad media para el caracter de control de DNI más frecuente: %d\n", 
				edadTotalPorDni/contador);

			/*Cierra el archivo despues de usarlo*/
			close(ficheroFuente);
		}
		else{ /*Indica error si el tamaño del archivo no es valido*/
			printf("El tamaño del archivo no es valido. Por favor intentelo de nuevo\n");
			return -1;	
		}
    }
    else{/*Indica error si el archivo no existe o no se puede abrir*/
        printf ("No se pudo abrir el archivo. Por favor intentelo de nuevo.\n");
    }

	int pruebasFallidas = pruebasParaEncuentraCaracterMasFrecuente();
	printf("Cantidad de pruebas fallidas: %d\n", pruebasFallidas);
    
	return 0; /*Terminar el programa satiscactoriamente*/
}

/*Dado una lista de caracteres devuelve el caracter mas frecuente*/
char encuentraCaracterMasFrecuente(char cadena[]){
	int frecuenciaMayor = 0;
	char caracterMasFrecuente;
	int i = 0, j = 0;

	/*Iterar atravez de la lista*/
	for(i = 0; i < strlen(cadena); i++){
		int contador = 0;
		/*Volver a iterar para comparar cada caracter con el resto*/
		for(j = 0; j < strlen(cadena); j++){
			/*Cuenta los caracters diferentes sin contar el mismo dos veces*/
			if(cadena[j] == cadena[i] && i != j){
				contador++;
			}
		}

		/*Si aparece un caracter con mayor frecuencia*/
		if(contador > frecuenciaMayor){
			/*Actauliza los datos de caracter con mayor frecuencia*/
			caracterMasFrecuente = cadena[i];
			frecuenciaMayor = contador;
		}
		/*Si dos o mas caracteres tienen la misma frecuencia*/
		else if(contador == frecuenciaMayor){
			/*Escoge el primero en orden alfabetico*/
			if(cadena[i] < caracterMasFrecuente){
				caracterMasFrecuente = cadena[i];
				frecuenciaMayor = contador;
			}
		}
	}

	return caracterMasFrecuente;
}

int pruebasParaEncuentraCaracterMasFrecuente(){
	int pruebasFallidas = 0;

	char cadena1[8] = {'A', 'A', 'B', 'B', 'C', 'C', 'C', '\0'};
	int resultadoEsperado1 = 'C';
	int resultadoActual1 = encuentraCaracterMasFrecuente(cadena1);
	if(resultadoActual1 != resultadoEsperado1){
		pruebasFallidas++;
	}

	char cadena2[2] = {'A', '\0'};
	int resultadoEsperado2 = 'A';
	int resultadoActual2 = encuentraCaracterMasFrecuente(cadena2);
	if(resultadoActual2 != resultadoEsperado2){
		pruebasFallidas++;
	}

	char cadena3[11] = {'Z', 'Z', 'P', 'P', 'K', 'B', 'B', 'C', 'C', 'D', '\0'};
	int resultadoEsperado3 = 'B';
	int resultadoActual3 = encuentraCaracterMasFrecuente(cadena3);
	printf("Caracter de control de DNI mas frecuente: %c\n", resultadoActual3);
	if(resultadoActual3 != resultadoEsperado3){
		pruebasFallidas++;
	}

	return pruebasFallidas;
}