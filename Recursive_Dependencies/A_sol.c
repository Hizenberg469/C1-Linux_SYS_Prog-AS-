/*
 * =====================================================================================
 *
 *       Filename:  A_sol.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/02/24 10:36:54 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


/* Solution to problem faced in A.c due to Recursive Dependencies*/


/**Forward Declarartion**/ 
struct occ_t;       /**Tells the compiler that struct occ_t will be defined in future, p                    please tolerate if it used as pointer. It is called Forwared Declara                    tion**/

struct emp_t{
    
    char name[32];
    unsigned int emp_id;
    struct occ_t* occ;

};

struct occ_t{
    
    char designation[32];
    unsigned int salary;
    struct emp_t boss;

};
