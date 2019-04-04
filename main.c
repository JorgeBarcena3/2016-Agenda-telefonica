#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//JORGE BARCENA LUMBRERAS

int menu(){
	
	int opc;
	
	do{
		
		system("cls");
		printf("BIENVENIDO A TU AGENDA DE CONTACTOS\n\n");
		printf("1.- Introducir primer contacto (Necesario para crear el primer contacto)\n");	
		printf("2.- Añadir mas contactos\n");
		printf("3.- Ver listado de contactos\n");	
		printf("4.- Salir\n\n");
		
		printf("Escoje una opcion: ");	
		fflush(stdin); scanf("%i", &opc);
		
	}while(opc <= 0 || opc >= 5);
	
	return opc;
	
}

void introducir(){
	
	FILE *numeros;
	int i;
	char cadena[255];
	
	system("cls");
	numeros = fopen("numeros.txt", "w");
	
	printf("Introduce el nombre del contacto: ");
	fflush(stdin); gets(cadena);
	
	for(i = 0; cadena[i] != '\0'; i++){
	
		fputc(cadena[i], numeros);
		
	}
	
	fputc('*', numeros);
	
	printf("Introduce el apellido del contacto: ");
	fflush(stdin); gets(cadena);
	
	for(i = 0; cadena[i] != '\0'; i++){
	
		fputc(cadena[i], numeros);
		
	}
	
	fputc('*', numeros);
	
	printf("Introduce el numero de telefono del contacto: ");
	fflush(stdin); gets(cadena);
	
	for(i = 0; cadena[i] != '\0'; i++){
	
		fputc(cadena[i], numeros);
		
	}
	
	fputc('\n', numeros);
	
	fclose(numeros);
	
	
	
	
}

void anadir(){
	
	FILE *numeros;
	int i;
	char cadena[255];
	
	system("cls");
	numeros = fopen("numeros.txt", "a");
	
	printf("Introduce el nombre del contacto: ");
	fflush(stdin); gets(cadena);
	
	for(i = 0; cadena[i] != '\0'; i++){
	
		fputc(cadena[i], numeros);
		
	}
	
	fputc('*', numeros);
	
	printf("Introduce el apellido del contacto: ");
	fflush(stdin); gets(cadena);
	
	for(i = 0; cadena[i] != '\0'; i++){
	
		fputc(cadena[i], numeros);
		
	}
	
	fputc('*', numeros);
	
	printf("Introduce el numero de telefono del contacto: ");
	fflush(stdin); gets(cadena);
	
	for(i = 0; cadena[i] != '\0'; i++){
	
		fputc(cadena[i], numeros);
		
	}
	
	fputc('\n', numeros);
	
	fclose(numeros);

	
}
	
void visualizar(){
	
	FILE *numeros;
	int i;
	char cadena;
	
	system("cls");
	numeros = fopen("numeros.txt", "r");
	
	while(!feof(numeros)){
		
		cadena = fgetc(numeros);
		
		if(cadena == '*'){
			
			printf("  ");
			
		}else {		
		
			printf("%c", cadena);
		
		}
		
	}
	
	
	fclose(numeros);
	printf("\n\n");	
	system("pause");
	
	
}
	
int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "spanish");
	
	int opc;
	
	do{
	
		opc = menu();
		
		switch (opc) {
			
			case 1:
				
				introducir();
				
				break;
			
			case 2:
				
				anadir();
				
				break;
				
			case 3:
				
				visualizar();
				
				break;
				
			}
				
			
		
	}while(opc != 4);
	
	
	return 0;
}
