/*
 * =====================================================================================
 *
 *       Filename:  dll.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/01/24 07:59:34 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */



#include "dll.h"
#include <memory.h>
#include <stdlib.h>

/* Public Function Implementation to create and return
 * new empty doubly linked list*/

dll_t *
get_new_dll(){

    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    return dll;
}

/* Public Function Implementation to add a new application
 *  * data to DLL */
int
add_data_to_dll (dll_t *dll, void *app_data){

    if(!dll || !app_data) return -1;
    
    dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
    dll_new_node->left = NULL;
    dll_new_node->right = NULL;
    dll_new_node->data = app_data;

    /*Now add this to the front of DLL*/
    if(!dll->head){
        dll->head = dll_new_node;
        return 0;
    }

    dll_node_t *first_node = dll->head;
    dll_new_node->right = first_node;
    first_node->left = dll_new_node;
    dll->head = dll_new_node;
    return 0;
}

int
remove_data_from_dll_by_data_ptr (dll_t *dll, void *data ){

	if( !dll || !dll->head || !data ) return -1;

	/* Searching for data linearly and deleting the data*/
    dll_node_t *tp;
	dll_node_t *temp = dll->head;
	while( !temp ){
		if( *((int *)temp->data) == *((int *)data) ){
			tp = temp->left;
			tp->right = temp->right;
			free(temp);
			return 0;
		}
		temp = temp->right;
	}

	return -1;
}

int
is_dll_empty(dll_t *dll){

	if( !dll || !dll->head ) return 0;

	return -1;
}


