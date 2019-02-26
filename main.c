/*	Christopher Flores 10-10824
	Maria Fernanda Magallanes 13-10787
	Main Tarea 1
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "LinkedList.c"

#define SIZE 27

int main()
{

	int opcion;
	char fecha1[12]={'0'};
	hashtable_t *ht = ht_create( 27 );
	struct  Node *lista = create_list(fecha1,ht,ht);
	char *d_ptr;
	char *c_ptr;
	

	while(1)
	{
		printf("BIENVENIDO AL PROGRAMA DE DESCIFRADO:\n\nOpciones:\n");
		printf("● (1) Registrar nuevos mensajes cifrados y sus descifrados\n");
		printf("● (2) Descifrar mensajes\n");
		printf("● (3) Cifrar mensajes\n");
		printf("● (4) Mostrar un esquema de cifrado\n");
		printf("● (5) Borrar un esquema de cifrado debido a un error\n");
		printf("● (6) SALIR\n\n");
		printf("Opcion: ");
		fflush(stdout);

		fflush(stdin);
		scanf("%d",&opcion);
		assert(getchar()=='\n');
		printf("\n\n");
		switch(opcion){
			case 1:
				while(1){
					
					char fecha[12];
					char cifrado[99];
					char descifrado[99];

					printf("Registrar nuevos mensajes:\n\n");
					printf("Fecha del mensaje de la forma DD-MM-AAAA : ");
					fgets (fecha, sizeof(fecha), stdin);
					if((int)fecha[0]==35){break;};

					printf("Mensaje cifrado: ");
					fgets (cifrado, sizeof(cifrado), stdin);
					if((int)cifrado[0]==35){break;};
					printf("Mensaje descifrado: ");
					fgets (descifrado, sizeof(descifrado), stdin);
					if((int)descifrado[0]==35){break;};

					//Lleno la tabla
					
					hashtable_t *encriptar = ht_create( 27 );
					hashtable_t *desencriptar = ht_create( 27 );
					
					
					for(int i=0;i<strlen(cifrado);i++){
						printf("AGREGA ELEMENTOS %c , %c",descifrado[i],cifrado[i]);
						ht_set(encriptar,descifrado[i],cifrado[i]);
						ht_set(desencriptar,cifrado[i],descifrado[i]);
						display_table(encriptar);

					};
					
					add2(fecha,encriptar,desencriptar);
					display_list();

				}
			case 2:
				while(1){
					/*
					Estrategia:
					Primero pido la fecha del mensaje a cifrar o descifrar.
					Con esa información busco en la linked list que elemento corresponde con ese esquema.
					Luego al tener el nodo le obtengo su atributo table y table desencriptar.
					Pido por consola el mensaje a cifrar o descifrar y con ht_get tomo letra
					por letra del mensaje y busco su correspondiente en la tabla de hash,
					para luego imprimir el mensaje encriptado o real, dependiendo del caso.
					
					Inicio del codigo:
					
					hashtable_t desencriptar = tail->table_desencriptar;
					hashtable_t encriptar = tail->table;
					char cifrado[150];
					char descifrado[150];
					printf("Descifrar mensajes:\n\n");
					printf("Escriba mensaje cifrado : ");
					fgets (cifrado, sizeof(cifrado), stdin);
					if((int)cifrado[0]==35){break;};
					for(int i=0;i<strlen(cifrado);i++){
						entry_t *elemento=ht_get(desencriptar,cifrado[i]);
						if (elemento==NULL){
							descifrado[i]=35;
						}
						else{
							descifrado[i]=(int)elemento->value;
						}

					}
					printf("El mensaje descifrado es: \n");
					printf("%s\n", descifrado);

				*/}
			case 3:
				while(1){/*
				
					Estrategia:
					Primero pido la fecha del mensaje a cifrar o descifrar.
					Con esa información busco en la linked list que elemento corresponde con ese esquema.
					Luego al tener el nodo le obtengo su atributo table y table desencriptar.
					Pido por consola el mensaje a cifrar o descifrar y con ht_get tomo letra
					por letra del mensaje y busco su correspondiente en la tabla de hash,
					para luego imprimir el mensaje encriptado o real, dependiendo del caso.
					
					Inicio del codigo:
					char cifrado[150];
					char descifrado[150];
					printf("Cifrar mensajes:\n\n");
					printf("Escriba mensaje real : ");
					fgets (descifrado, sizeof(descifrado), stdin);
					if((int)descifrado[0]==35){break;};
					for(int i=0;i<strlen(descifrado);i++){
						entry_t *elemento=ht_get(encriptar,descifrado[i]);
						if (elemento==NULL){
							descifrado[i]=35;
						}
						else{
							descifrado[i]=(int)elemento->value;
						}

					}
					printf("El mensaje descifrado es: \n");
					printf("%s\n", descifrado);

				*/}
			case 4: break ;
			case 5:	/* para borrar un esquema de cifrado	
				*
				*
				*  eliminamos de la lista el nodo que contiene el cifrado a borrar
				*  con la funcion delete_from_list() de nuestra LinkedList
				*
				*/
				break;
			case 6: break;
		}
			 
	}

	return 0;
}
