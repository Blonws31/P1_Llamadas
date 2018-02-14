#include "persona.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


char palabra_repetida(char cadena[]);
int main(int argc, char *argv[]){
    
    Person persona; 
    int fd1  = open (argv[1], O_RDONLY);
    double renta = 0.0; //principal
    int edad = 0; //principal
    int contador = 0;
    int edad_dni = 0; //principal

    char auxiliar[sizeof(Person)];
    int aux_numerico;
    int aux_numerico2;

    if(argc!=2){
	printf("Numero de argumentos invalidos\n");
	exit(1);
    }

    if (fd1 != -1){
	int i = 0;
	while(read(fd1, &persona, sizeof(Person))!= 0){
		renta = renta + persona.salary;
		edad = edad + persona.age;
		contador++;
		aux_numerico = persona.id_ctrl;
		auxiliar[i] = aux_numerico;
		i++;
	}
	lseek(fd1,0,SEEK_SET);
	printf("Renta media: %.0f\n",(renta/contador));	
	printf("Edad media: %d\n",edad/contador);
	contador = 0;
   	while(read(fd1, &persona, sizeof(Person))!= 0){
		aux_numerico = (palabra_repetida(auxiliar));
		aux_numerico2 = persona.id_ctrl;
		if(aux_numerico == aux_numerico2){
			edad_dni = edad_dni + persona.age;
			contador++;
		}
	}
	printf("Caracter de control de DNI mas frecuente: %c\n",palabra_repetida(auxiliar));
	printf("Edad media para el caracter de control de DNI más frecuente: %d\n",(edad_dni+1)/contador);
	close(fd1);
    }
    else
        printf ("No se pudo abrir el archivo\n");

    return 0;
}

char palabra_repetida(char cadena[]){
	int mayor = 0;
	char repetido;
	int aux_a;
	int aux_b;
	for(int i = 0; i <strlen(cadena); i++){
		int contador = 0;
		for(int j = i+1; j < strlen(cadena); j++){
			if(cadena[j] == cadena[i]){
				contador++;
			}
		}
		if(contador > mayor){
			repetido = cadena[i];
			mayor = contador;
		}
		else if(contador == mayor){
			aux_a = cadena[i];
			aux_b = repetido;
			if(aux_a < aux_b){
				repetido = cadena[i];
				mayor = contador;
			}
		}
	}

	return repetido;
}
