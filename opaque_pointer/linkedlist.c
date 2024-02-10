/*
 * =====================================================================================
 *
 *       Filename:  linkedlist.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/24 08:55:04 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "linkedlist.h"
#include <memory.h>
#include <stdlib.h>

typedef struct ll_node_{
    int data;
    struct ll_node_ *left;
    struct ll_node_ *right;
}ll_node_t;

void
linkedlist_insertion(
        ll_node_t *current_node,
        ll_node_t *new_node){
    
    if( !current_node ){
        current_node = new_node;
        return;
    }

    current_node->left = new_node;
    new_node->right = current_node;
    current_node = new_node;
    return;
}

ll_node_t *
malloc_new_node(){
    return (ll_node_t *)malloc(sizeof(ll_node_t));
}
