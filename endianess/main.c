/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/02/24 10:31:18 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "endian.h"
#include <stdio.h>

int main(){
    int val = machine_endianness_type();

    if( val ){
        printf("Little endian machine\n");
    }
    else{
        printf("Bit endian machine\n");
    }

    return 0;
}
