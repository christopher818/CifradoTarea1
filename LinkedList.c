#include "LinkedList.h"
#include "HashTable.c"
#include <stdbool.h>
#include <string.h>

/* Creamos la estructura nodo */
struct Node {
        char *id;
        hashtable_t *table;
        hashtable_t *table_desencriptar;
        struct Node *next;
        struct Node *prev;
        };

/* Definimos cabeza y cola */
struct Node *head = NULL;
struct Node *tail = NULL;

/* create_node Recibe:
*  Un string para la fecha
*  Dos Tablas de Hash
*  el valor a los dos apuntadores de siguiente y anterior
* Funcion: Crea un nodo
*/
struct Node* create_node(char *id,hashtable_t *table,hashtable_t *table_desencriptar,struct Node* next, struct Node* prev)
{
	struct  Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	if (ptr == NULL){
		printf("Fallo al crear\n");
		return NULL;
	}
	ptr->id = id;
	ptr->table_desencriptar = table_desencriptar;
	ptr->table = table;
	ptr->next = next;
	ptr->prev = prev;

	return ptr;
};

/* create_list Recibe:
*  Un string para la fecha
*  Dos Tablas de Hash
* Funcion: Crea una lista
*/
struct Node* create_list(char *id, hashtable_t *table,hashtable_t *table_desencriptar)
{
	struct Node *ptr = create_node(id,table,table_desencriptar,NULL,NULL);

	head = ptr;
	tail = ptr;
	return ptr;
};


/* add Recibe:
*  Un string para la fecha
*  Una Tabla de Hash
*  Un booleano para saber si inserta al principio o al fina
* Funcion: Inserta solo al principio o al final
*/
struct Node* add(char *id,hashtable_t *table, _Bool add_to_end)
{/*
	if(head == NULL){
		return (create_list(id,table));
	}

	struct Node* ptr= create_node(id,table,NULL,NULL);
	
	if(add_to_end){
		ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }
    else{
    	ptr->next = head;
    	head->prev = ptr;
    	head = ptr;

    }
    return ptr;
*/
}


/* add Recibe:
*  Un string para la fecha
* Funcion: busca un nodo en la lista
*/
struct Node* search(char *id)
{
	
	struct Node *ptr = head;
	_Bool found = false;
	int i = 0;
	int count = 0;

	while(ptr != NULL){
		for(int i=0;i<strlen(id);i++){
			if(ptr->id[i],id[i]){
			count = count+1;	
		}
		if(count = strlen(id)){
			found = true;
			return ptr;
		}
		else{

			ptr = ptr->next;

		}

	}
	}
	return NULL;
};

/* delete Recibe:
*  Un string para la fecha
* Funcion: elimina un nodo de la lista
*/
int delete(char *id)
{
	struct Node *del = NULL;
	
	del = search(id);

	if (del == NULL){
		return -1;
	}
	else{
		if(del == tail){
			tail = del->prev;
			tail->prev = NULL;
			tail->next = NULL;
		}
		else if(del == head){
			head = del->next;
		}
		else{
			del->prev->next = del->next;
            del->next->prev = del->prev;
		}
	}
	free(del);
	del = NULL;

	return 0;
};


/* display
* Funcion: imprime la lista y la tablas tablas de Hash
*/
void display_list()
{
    struct Node *ptr = head;

    printf("\n -------Principio------- \n");
    if (ptr == NULL){
    	printf("\n Lista Vacia\n");
    }
    else{
    	while(ptr != NULL)
    {
        printf("%s\n",ptr->id);
        
        display_table(ptr->table);
        display_table(ptr->table_desencriptar);
        ptr = ptr->next;
    }
    printf("\n -------Final------- \n");
    }
    

    return;
}

/* Delete_from_lsit Recibe:
*  Un string para la fecha
*  Una Tabla de Hash
* Funcion: indica si se pudo borrar o no se encontro el elemento en la lista
*/
void delete_from_list(char *id,hashtable_t *table){
	int ret = 0;

	ret = delete(id);
   	if(ret != 0)
    {
        printf("\n Borrar [%s] Falló, no se encontro el elemento\n",id);
    }
    else
    {
        printf("\n [%s] fue borrado. \n",id);
    }

    display_list(table);

}

/* add2 Recibe:
*  Un string para la fecha
*  Dos Tablas de Hash
* Funcion: Inserta en cualquier parte de la lista y lo hace bien
*/
struct Node* add2(char *id,hashtable_t *table,hashtable_t *table_desencriptar)
{
	if(head == NULL){
		return (create_list(id,table,table_desencriptar));
	}

	struct Node* ptr= create_node(id,table,table_desencriptar,NULL,NULL);
	struct Node* point=head;
	
	while(point != NULL && strcmp(point->id,id)<0 ){
		point = point->next;
	}

	if(point==NULL){
		ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }
    else{
    	ptr->prev = point->prev;
    	point->prev->next = ptr;
    	ptr->next = point;
    	point->prev = ptr;

    }
    return ptr;

}

/*
int main( int argc, char **argv )
{
	char fecha[12], fecha2[12],fecha3[12],fecha4[12],fecha5[12];
	struct Node *ptr = NULL;
	hashtable_t *hashtable = ht_create( 27 );

	ht_set( hashtable, 65, 66 );
	ht_set( hashtable, 66, 68 );
	
	

	

	printf("Registrar nuevos mensajes:\n\n");		
	printf("Fecha del mensaje de la forma DD-M	M-AAAA : ");	
	fgets (fecha, sizeof(fecha), stdin);

	printf("Registrar nuevos mensajes:\n\n");		
	printf("Fecha del mensaje de la forma DD-M	M-AAAA : ");	
	fgets (fecha2, sizeof(fecha), stdin);

	printf("Registrar nuevos mensajes:\n\n");		
	printf("Fecha del mensaje de la forma DD-M	M-AAAA : ");	
	fgets (fecha3, sizeof(fecha), stdin);

	printf("Registrar nuevos mensajes:\n\n");		
	printf("Fecha del mensaje de la forma DD-M	M-AAAA : ");	
	fgets (fecha4, sizeof(fecha), stdin);



	
	ptr = create_list(fecha,hashtable);
	
	
	add2(fecha2,hashtable);
	add2(fecha3,hashtable);
	add2(fecha4,hashtable);
	
	display_list(hashtable);



	return 0;
}*/
