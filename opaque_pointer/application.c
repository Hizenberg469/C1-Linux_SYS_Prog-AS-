/*
 * =====================================================================================
 *
 *       Filename:  application.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/24 10:17:06 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "linkedlist.h"

int
main(){
    ll_node_t *node1 = malloc_new_node();
    ll_node_t *node2 = malloc_new_node();

    linkedlist_insertion(node1,node2);

    return 0;
}
