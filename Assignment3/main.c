/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/24 08:27:48 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "glthread.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct emp_ {



  char name[30];

  unsigned int salary;

  char designation[30];

  unsigned int emp_id;

  glthread_node_t glnode;

} emp_t ;

/*Function to print employee details*/

void
print_employee_info(emp_t *emp){

    printf("Employee name = %s\n", emp->name);

    printf("salary = %u\n", emp->salary);

    printf("designation = %s\n", emp->designation);

    printf("emp_id = %u\n", emp->emp_id);

}

glthread_to_object(glnode_to_employee,emp_t,glnode)

void
print_employee_details( glthread_node_t *glnode){

    emp_t * emp = glnode_to_employee(glnode);  
    print_employee_info(emp);
}

int main( int argc , char** argv ){

    /*Creating one employee object*/

    emp_t *emp1  = calloc(1, sizeof(emp_t));

    strncpy(emp1->name, "Neha", strlen("Neha"));

    emp1->salary = 50000;

    strncpy(emp1->designation, "HR", strlen("HR"));

    emp1->emp_id = 21;

    glthread_node_init((&emp1->glnode));

    print_employee_details((&emp1->glnode));
    return 0;
}
