/*
 * =====================================================================================
 *
 *       Filename:  array_iterator.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/02/24 07:51:54 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#include <stdlib.h>



#define ITERATE_ARRAY_BEGIN(arrptr, array_size, start_index, scansize, out_index)  {  \
    unsigned int cnt;                                                              \
    for( cnt = 0, out_index = start_index ; cnt < scansize ; cnt++ , out_index = (out_index+1)%array_size ){
#define ITERATE_ARRAY_END   }}


int

main(int argc, char **argv){

    unsigned int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    unsigned int i;

    ITERATE_ARRAY_BEGIN(arr, 10, 5, 10, i) {

        printf("arr[%u] = %u\n", i, arr[i]);

    } ITERATE_ARRAY_END;

    return 0;

}
