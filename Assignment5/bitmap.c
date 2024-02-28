/*
 * =====================================================================================
 *
 *       Filename:  bitmap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/02/24 08:02:40 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "bitmap.h"

#ifndef CHAR_SIZE
#define CHAR_SIZE 8
#endif

bool
bitmap_is_full(bit_array_t *bitmap){
    
    unsigned int sz = bitmap->size;
    unsigned int byte_block = sz/CHAR_SIZE;
    unsigned int residual_block = sz%CHAR_SIZE;

    char *ptr = NULL;
    for(int block_num = 0 ; block_num < byte_block ; block_num ){

        ptr = bitmap->array+block_num;

        if( block_num == byte_block - 1 ){
            if( (*ptr) != ~((1<<(CHAR_SIZE - residual_block))-1) ){
                return false;
            }
            continue;
        }

        if( (*ptr) != (1<<8)-1 ){
            return false;
        }
    }

    return true;

}

bool
bitmap_pattern_match( bit_array_t *bitmap, char *binary_string,int n_bits,int *i){
    
    if( n_bits > 32){
        printf("Number of bits is over the limit(32-bits).\n");
        exit(EXIT_FAILURE);
    }

    unsigned sz = bitmap->size;
       
    unsigned bitmap_num = 0;
    
    for(int idx = 0 ; idx < sz ; i++ ){
        if( is_bit_set(bitmap,idx) ){
            bitmap_num |= (1<<idx);
        }
    }

    //mask : should have all the bit as 1 except undefined bit
    //(i.e. X in binary_string) as 0.
    //template : change the X in binary_string to 0 and keep
    //rest as same.
    //check mask&num == template...
    unsigned mask = 0 , template = 0;

    for(int idx = 0 ; idx < n_bits ; idx++ ){
        if( binary_string[idx] == '0' ){
            mask |= (1<<(n_bits-1-idx));
        }
        else if( binary_string[idx] == '1' ){
            mask |= (1<<(n_bits-1-idx));
            template |= (1<<(n_bits-1-idx));
        }
    }

    unsigned mask_ch = (1<<n_bits)-1;

    for( int idx = 0 ; idx + n_bits < sz ; idx++ ) {
        if( mask&bitmap_num == template ){
            *i = idx;
            return true;
        }
        mask <<= 1;
        template <<= 1;
    }

    return false;
}
