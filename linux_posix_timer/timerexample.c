/*
 * =====================================================================================
 *
 *       Filename:  timerExample.c
 *
 *    Description: This file demonstrates the use of POSIX Timer routines
 *
 *        Version:  1.0
 *        Created:  10/12/2020 11:25:06 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ABHISHEK SAGAR (), sachinites@gmail.com
 *   Organization:  Juniper Networks
 *
 * =====================================================================================
 */

#include <signal.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

/* Example */

void
print_current_system_time(){
    time_t t;
    time(&t); /* Get the current time of the system */
    printf("%s ",ctime(&t));
}


typedef struct pair_{

	int a;
	int b;
} pair_t;

pair_t pair = { 10, 20 };


/* The Timer callback function which will be called every
 * time the timer expires. The signature of the function would be :
 * void <fn-name>(union sigval)
 * */
void
timer_callback(union sigval arg){

    print_current_system_time();

	pair_t *pair = (pair_t *)(arg.sival_ptr); /* extract the user data structure */
    
    printf("pair : [%u %u]", pair->a, pair->b );
}

void
timer_demo(){

	int ret;
	timer_t timer;
	struct sigevent evp;
    
    memset(&timer,0,sizeof(timer));

	/* evp variable is used to setup timer properties*/
	memset(&evp, 0, sizeof(struct sigevent));
	
    /* Fill the user defined data structure.
     * When timer expires, this will be passed as
     * argument to the timer callback handler */
	evp.sigev_value.sival_ptr = (void *)&pair;

	/* On timer Expiry, We want kernel to launch the
 	 * timer handler routine in a separate thread context */
	evp.sigev_notify = SIGEV_THREAD;
	
	/* Register the timer hander routine. This routine shall
 	 * be invoked when timer expires*/
	evp.sigev_notify_function = timer_callback; 

	/* Create a timer. It is just a timer initialization, Timer
 	 * is not fired (Alarmed)  */
	ret = timer_create (CLOCK_REALTIME,
						&evp,
						&timer);

	if ( ret < 0) {
		
		printf("Timer Creation failed, errno = %d\n", errno);
		exit(0);
	}

	/* Let us say, I want to start the timer after 5 seconds from now
 	 * (now =  say, t = 0) and once the 5 seconds elapsed, i 
 	 * want the timer to keep firing after every 2 seconds repeatedly.
 	 * It simply mean that - if i start the timer as time t = 0, then
 	 * timer handler routine (timer_callback) shall be called at t = 5,
 	 * t = 7, t = 9 ... so on*/

	/* Let us setup the time intervals */

	struct itimerspec ts;

	/* I want the timer to fire for the first time after 5 seconds
 	 * and 0 nano seconds*/
	ts.it_value.tv_sec = 5;
	ts.it_value.tv_nsec = 0;

	/* After the timer has fired for the first time, i want the timer
 	 * to repeatedly fire after every 2 sec and 0 nano sec */
	ts.it_interval.tv_sec = 2;
	ts.it_interval.tv_nsec = 0;

	/* Now start the timer*/
	ret = timer_settime (timer,
						 0,
						 &ts,
						 NULL);

	if ( ret < 0) {
		
		printf("Timer Start failed, errno = %d\n", errno);
		exit(0);
	}
    else{
        print_current_system_time();
        printf("Timer Alarmed Successfully\n");
    }
}

int
main(int argc, char **argv){

	timer_demo();
	pause();
	return 0;
}
