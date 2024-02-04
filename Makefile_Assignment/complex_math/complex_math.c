/*
 * =====================================================================================
 *
 *       Filename:  complex_math.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/24 07:36:03 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "complex_math.h"
complex_n_t cadd(complex_n_t a, complex_n_t b){
    complex_n_t res;
    res.re = a.re + b.re;
    res.imag = a.imag + b.imag;
    return res;
}


complex_n_t csub(complex_n_t a, complex_n_t b){
    complex_n_t res;
    res.re = a.re - b.re;
    res.imag = a.imag - b.imag;
    return res;
}

