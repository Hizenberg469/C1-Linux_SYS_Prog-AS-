/*
 * =====================================================================================
 *
 *       Filename:  linkedlist.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/24 08:40:52 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __LINKEDLIST__
#define __LINKEDLIST__

typedef
struct ll_node_ ll_node_t;


/*public APIs*/
void
linkedlist_insertion(
        ll_node_t *current_node,
        ll_node_t *new_node);

ll_node_t *
malloc_new_node();
#endif
