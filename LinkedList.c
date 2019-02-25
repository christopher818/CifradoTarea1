#include "LinkedList.h"
#include "HashTable.c"
#include <stdbool.h>
#include <string.h>

#define SIZE 27

struct Node {
        char *id;
        hashtable_t *table;
        struct Node *next;
        struct Node *prev;
        };

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node* create_node(char *id,hashtable_t *table,struct Node* next, struct Node* prev)
{
	struct  Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	if (ptr == NULL){
		printf("Fallo al crear\n");
		return NULL;
	}
	ptr->id = id;
	ptr->table = table;
	ptr->next = next;
	ptr->prev = prev;

	return ptr;
};

struct Node* create_list(char *id, hashtable_t *table)
{
	struct Node *ptr = create_node(id,table,NULL,NULL);

	head = ptr;
	tail = ptr;
	return ptr;
};



struct Node* add(char *id,hashtable_t *table, _Bool add_to_end)
{
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

}



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
        ptr = ptr->next;
    }
    printf("\n -------Final------- \n");
    }
    

    return;
}

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

struct Node* add2(char *id,hashtable_t *table)
{
	if(head == NULL){
		return (create_list(id,table));
	}

	struct Node* ptr= create_node(id,table,NULL,NULL);
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

	ht_set( hashtable, "A", "B" );
	ht_set( hashtable, "B", "T" );
	ht_set( hashtable, "V", "Y" );
	ht_set( hashtable, "Z", "A" );
	

	

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