/*
 * =====================================================================================
 *
 *       Filename:  trig_math.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/24 07:37:35 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "trig_math.h"
#include <math.h>

double sine(double x){
    return sin(x*(PI/180));
}


double cosine(double x){
    return cos(x*(PI/180));
}
