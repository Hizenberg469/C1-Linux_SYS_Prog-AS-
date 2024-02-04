/*
 * =====================================================================================
 *
 *       Filename:  common_math.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/24 07:32:41 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "common_math.h"
#include <stdio.h>

double add (double a, double b){return b + a;}
double sub (double a, double b){return a - b;}
double mul (double a, double b){return a * b;}
double div (double a, double b){
    if (b == 0){
        printf("divide by zero not allowed\n");
        return 0;
    }
    return a / b;
}

double max (double a, double b){
    if(a > b) 
        return a;
    return b;
}

double min (double a, double b){
    if(a > b)
        return b ;
    return a;
}

