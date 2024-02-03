/*
 * =====================================================================================
 *
 *       Filename:  A.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/02/24 10:24:10 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


struct emp_t{
    char name[32];
    unsigned int emp_id;
    struct occ_t occ;
};

struct occ_t{
    char designation[32];
    unsigned int salary;
    struct emp_t boss;
};
