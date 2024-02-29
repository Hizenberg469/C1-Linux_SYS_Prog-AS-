/*
 * =====================================================================================
 *
 *       Filename:  endian.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/02/24 10:13:18 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "endian.h"

int
machine_endianness_type(){
    
    unsigned short int a = 1;
    char ist_byte = *((char *)&a);
    if( ist_byte == 0 )
        return 0;
    else if( ist_byte == 1 )
        return 1;
}
