/*
 * =====================================================================================
 *
 *       Filename:  complex_math.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/02/24 07:36:29 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __COMPLEX_MATH__
#define __COMPLEX_MATH__

typedef struct{
    double re;
    double imag;
} complex_n_t;

complex_n_t cadd(complex_n_t a, complex_n_t b);
complex_n_t csub(complex_n_t a, complex_n_t b);

#endif
