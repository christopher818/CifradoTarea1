/* MODIFICACION DEL CODIGO DE
 * https://gist.github.com/tonious/1377667
 * 
 *  
 */

#define _XOPEN_SOURCE 500
/* Enable certain library functions (strdup) on linux. 
See feature_test_macros(7) */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

// Creo una estructura que va a ser insertada en cada posicion de la tabla
struct entry_s {
	char key; 
	char value;
	struct entry_s *next;
};

//Defino el nombre de esa estructura
typedef struct entry_s entry_t;

//Creo mi estructura de tabla
struct hashtable_s {
	int size;
	struct entry_s **table;	
};

//Le coloco nombre a esa estructura
typedef struct hashtable_s hashtable_t;


/* Creo una tabla de hash */
hashtable_t *ht_create( int size ) {

	hashtable_t *hashtable = NULL;

	if( size < 1 ) return NULL;

	// Reviso si hay espacio
	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}

	// Reviso si hay espacio para la tabla
	if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {
		return NULL;
	}

	//Relleno cada entrada de la tabla como null
	for(int i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;	
}

/* Funcion de hash para chars de la A-Z */
int ht_hash( hashtable_t *hashtable, char key ) {
	if(key==32){return 26;};
	return (key-65) % hashtable->size;
}

/* Crear un par key value */
entry_t *ht_newpair( char key, char value ) {
	entry_t *newpair;

	if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}
	
	newpair->next = NULL;

	return newpair;
}

/* Insertar un par en una tabla de hash 
No resuelve colisiones*/
void ht_set( hashtable_t *hashtable, char key, char value ) {
	int index;
	entry_t *newpair;
	newpair = ht_newpair( key, value );
	index = ht_hash( hashtable, key );
	//if(hashtable->table[ index ]==NULL){
	hashtable->table[ index ]=newpair;
}

/* Busca en la tabla su valor correspondiente */
entry_t *ht_get( hashtable_t *hashtable, char key ) {
	int index;
	entry_t *pair;

	index = ht_hash( hashtable, key );

	/* Busco en la tabla */
	pair = hashtable->table[ index ];
	
	return pair;
	
}
	
void display_table( hashtable_t *hashtable ) {

	for(int i = 0; i < hashtable->size; i++) {
		
		if(hashtable->table[ i ] != NULL)
			printf(" [%c:%c]",hashtable->table[ i ]->key,hashtable->table[ i ]->value);
		else
			printf("[ : ]");
   }
	
	printf("\n");
}
/*int main( int argc, char **argv ) {

	hashtable_t *hashtable = ht_create( 27 );

	ht_set( hashtable, 65, 66 );
	ht_set( hashtable, 66, 71 );
	//ht_set( hashtable, "V", "Y" );
	//ht_set( hashtable, "Z", "A" );
	display_table(hashtable);

	return 0;
}*/
