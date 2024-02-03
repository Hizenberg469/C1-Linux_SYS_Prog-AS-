/*
 * =====================================================================================
 *
 *       Filename:  dll_util.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/02/24 11:35:26 AM IST
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


void
drain_dll (dll_t *dll){
   if( !dll || !dll->head ) return;

   dll_node_t *tp = dll->head;
   dll_node_t * temp = dll->head;
   while( tp != NULL ){
        tp->right->left = NULL;
        temp = tp->right;
        tp->right = NULL;
        free(tp->data);
        free(tp);
        tp = temp;
   }

}

