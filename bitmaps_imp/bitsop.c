/*
 * =====================================================================================
 *
 *       Filename:  bitsop.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/02/24 09:24:28 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

uint8_t
count_bit_set(uint32_t n){
    uint8_t bit_cnt = 0;
    
    for(int i = 0 ; i < 32 ; i++ ){
        if( n&(1<<i)){
            bit_cnt++;
        }
    }

    return bit_cnt;
}

void
rotate_bit(uint32_t* n,int k){

    int x=k,bit = 0;

    while(x--){
        if( (*n)&(1<<31) ){
            bit = 1;
        }
        else{
            bit = 0;
        }

        (*n)=(*n)<<1;
        (*n) |= 1; 
    }
}
