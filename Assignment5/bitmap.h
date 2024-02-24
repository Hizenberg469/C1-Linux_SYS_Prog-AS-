/*
 * =====================================================================================
 *
 *       Filename:  bitmap.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/02/24 07:42:05 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __BITMAP_H_
#define __BITMAP_H_

#ifndef __BIT_ARRAY__
#include "bitsop.h"
#endif

#ifndef __BITS__
#include "bitarr.h"
#endif

#define ITERATE_BITMAP_BEGIN(bitmap_ptr ,bit_state) \
{                                                   \
    char *ptr = bitmap_ptr->array;                  \
    unsigned sz = bitmap_ptr->size;                 \
    unsigned n_blocks = sz/8;                       \
    unsigned residual_bit = sz%8;                   \
    for(int byte_block = 0 ; byte_block < n_blocks ; byte_block++ ){ \
       ptr = ptr + byte_block;                      \
       for( int idx = 7 ; idx >= (byte_block == n_blocks-1)?8-residual_bit:0 ; idx-- ){       \
          if( (*ptr)&(1<<idx) ){                    \
             bit_state = 1;                         \
          }                                         \
          else{                                     \
             bit_state = 0;                         \
          }

        
#define ITERATE_BITMAP_END(bitmap_ptr ,bit_state)   }}}

bool
bitmap_is_full(bit_arrya_t *bitmap);

bool
bitmap_pattern_match(bit_array_t *bitmap,char *binary_string,int n_bits,int *i);

#endif
